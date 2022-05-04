#include "state/State.h"
#include <string>
using namespace std;

void addRatingBulb(bool on, float left) {
    // converts the numeric value to two usable strings (for percentages)

    string leftPercent = to_string(left) + '%';

    float offset = left + 4.5;
    string leftWithOffset = to_string(offset) + '%';

    if (on) {
        _add_yaml("new_post/ratingBulb.yaml", {{"left", leftPercent}, {"ratingColor", "yellow"}, {"leftWithOffset", leftWithOffset}});
    } else {
        _add_yaml("new_post/ratingBulb.yaml", {{"left", leftPercent}, {"ratingColor", "white"}, {"leftWithOffset", leftWithOffset}});
    }
}

void addRatingArray(int rating) {
    _add_yaml("new_post/reviewBox.yaml");
    
    float left = 1;

    for (int i = 0; i < 5; i++) {
        if (i < rating) {
            addRatingBulb(true, left);
        } else {
            addRatingBulb(false, left);
        }

        left += 19.5;
    }
}

void display(State &state) {
    switch(state.panelType) {
        case 0:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        case 1:
            _add_yaml("PhoneView.yaml");
            _add_yaml("searchBar.yaml", {{"top", "5%"}, {"query", 226}});
            _add_yaml("new_post/postCommunity.yaml", {{"width", "33%"}, {"left", "10%"}, {"name", 226}});
            _add_yaml("new_post/postCommunity.yaml", {{"width", "36%"}, {"left", "45%"}, {"name", 244}});
            _add_yaml("textBox.yaml", {{"top", "25%"}, {"height", "8%"}, {"fontSize", 18}, {"text_index", 9}});
            _add_yaml("textBox.yaml", {{"top", "35%"}, {"height", "33%"}, {"fontSize", 15}, {"text_index", 27}});
            addRatingArray(3);
            _add_yaml("baseTemplate.yaml");
            break;
        case 2:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        case 3:
            _add_yaml("PhoneView.yaml");
            _add_yaml("postTemplate.yaml", {{"title", 9}, {"description", 27}});
            _add_yaml("baseTemplate.yaml");
            break;
        case 4:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        case 5:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        default:
            _add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
    }
}