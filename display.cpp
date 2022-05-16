#include "state/State.h"
#include <string>
using namespace std;

void addRatingBulb(int rank, bool on, float left) {
    // converts the numeric value to two usable strings (for percentages)

    string leftPercent = to_string(left) + '%';

    float offset = left + 4.5;
    string leftWithOffset = to_string(offset) + '%';

    if (on) {
        _add_yaml("new_post/ratingBulb.yaml", {{"rating", rank}, {"left", leftPercent}, {"ratingColor", "yellow"}, {"leftWithOffset", leftWithOffset}});
    } else {
        _add_yaml("new_post/ratingBulb.yaml", {{"rating", rank}, {"left", leftPercent}, {"ratingColor", "white"}, {"leftWithOffset", leftWithOffset}});
    }
}

void addRatingArray(int rating) {
    _add_yaml("new_post/reviewBox.yaml");
    
    float left = 1;

    for (int i = 0; i < 5; i++) {
        if (i < rating) {
            addRatingBulb(i, true, left);
        } else {
            addRatingBulb(i, false, left);
        }

        left += 19.5;
    }
}

void display(State &state) {
    _add_yaml("PhoneView.yaml"); // always here regardless of the panel - the main view

    switch(state.panelType) {
        case 0: // Idea Generator
            _add_yaml("searchBar.yaml", {{"top", "50%"}, {"query", state.get_ideaGen_offset() + state.ideaGen.getQueryOffset()}});
            _add_yaml("ideaGenTemplate.yaml", {{"recency", 5/*_get_label_index("recency", state.label_offset())*/}, {"recencyType", state.get_ideaGen_offset() + state.ideaGen.getRecencyOffset()}, 
                {"difficulty", 6/*_get_label_index("difficulty", state.label_offset())*/}, {"difficultyType", state.get_ideaGen_offset() + state.ideaGen.getDifficultyOffset()}});
            break;
 
        case 1: //Community search
            _add_yaml("searchBar.yaml", {{"top", "10%"}, {"query", 226}});
            _add_yaml("previewCommunity.yaml", {{"top", "20%"},{"color","blue"},{"index",268}});
            _add_yaml("previewCommunity.yaml", {{"top", "25%"},{"color","red"},{"index", 285}});
            _add_yaml("previewCommunity.yaml", {{"top", "30%"},{"color","yellow"},{"index", 268}});
            _add_yaml("previewCommunity.yaml", {{"top", "35%"},{"color","green"},{"index",285}});
            break;

        case 2:// New Post
            _add_yaml("searchBar.yaml", {{"top", "5%"}, {"query", state.get_newPost_offset() + state.newPost.getQueryOffset()}});
            _add_yaml("new_post/postCommunity.yaml", {{"width", "33%"}, {"left", "10%"}, {"name", 285}});
            _add_yaml("new_post/postCommunity.yaml", {{"width", "36%"}, {"left", "45%"}, {"name", 268}});
            _add_yaml("textBox.yaml", {{"top", "25%"}, {"height", "8%"}, {"fontSize", 18}, {"text_index", 50/*state.get_newPost_offset() + state.newPost.getTitleOffset()*/}});
            _add_yaml("textBox.yaml", {{"top", "35%"}, {"height", "33%"}, {"fontSize", 15}, {"text_index", 70/*state.get_newPost_offset() + state.newPost.getDescriptionOffset()*/}});
            addRatingArray(3);
            _add_yaml("add_post_button.yaml");
            break;

        case 3: // Account
            _add_yaml("accountTemplate.yaml", {{"user", state.get_account_offset() + state.account.get_user_offset()}, {"email", state.get_account_offset() + state.account.get_email_offset()}});
            break;

        case 4: //Post
            break;

        case 5: // Search Results
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;

        default:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
    }

    _add_yaml("baseTemplate.yaml"); // always calls this last - the base template with a button to each tab
}