#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"

void addRatingBulb(bool on, float left) {
    if (on) {
        _add_yaml("new_post/ratingBulb.yaml", {{"left", left}, {"ratingColor", "yelow"}, {"leftWithOffset", left + 4.5}});
    } else {
        _add_yaml("new_post/ratingBulb.yaml", {{"left", left}, {"ratingColor", "white"}, {"leftWithOffset", left + 4.5}});
    }
}

void addRatingArray(int rating) {
    _add_yaml("new_post/reviewBox.yaml");
    for (int i = 0; i < 5; i++) {
        float left = 1;
        if (i < rating) {
            addRatingBulb(true, left);
            left += 19.5;
        } else {
            addRatingBulb(false, left);
        }
    }
}

int main() {
    _add_yaml("PhoneView.yaml");
    _add_yaml("searchBar.yaml", {{"top", 5}});
    _add_yaml("new_post/postCommunity.yaml", {{"width", "33%"}, {"left", "10%"}});
    _add_yaml("new_post/postCommunity.yaml", {{"width", "36%"}, {"left", "45%"}});
    _add_yaml("textBox.yaml", {{"top", "25%"}, {"height", "8%"}, {"fontSize", 18}, {"text_index", 0}});
    _add_yaml("textBox.yaml", {{"top", "35%"}, {"height", "33%"}, {"fontSize", 15}, {"text_index", 1}});
    addRatingArray(3);
    _add_yaml("baseTemplate.yaml");
    _write_global_yaml_to_file("react.yaml");
    _write_global_mem_to_file("end_mem");
}