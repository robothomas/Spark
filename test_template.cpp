#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"

void addRatingBulb(bool on, float left) {
    if (on) {
        add_yaml("ratingBulb.yaml", {"left", left}, {"ratingColor", yelow});
    } else {
        add_yaml("ratingBulb.yaml", {"left", left}, {"ratingColor", white});
    }
}

void addRatingArray(int rating) {
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
  add_yaml("searchBar.yaml", {{"top", 5}});
  add_yaml("postCommunity.yaml", {"width", 33}, {"left", 10})
  add_yaml("postCommunity.yaml", {"width", 36}, {"left", 45})
  add_yaml("textBox.yaml", {{"top", 25}, {"height", 8}, {"fontSize", 18}}, {"text_index", 0})
  add_yaml("textBox.yaml", {{"top", 35}, {"height", 33}, {"fontSize", 15}, {"text_index", 1}})
  addRatingArray(3);
  add_yaml("baseTemplate.yaml");
  _write_global_yaml_to_file("react.yaml");
}