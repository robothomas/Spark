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
        float left = 0.01;
        if (i < rating) {
            addRatingBulb(true, left);
        } else {
            addRatingBulb(false, left);
        }
    }
}

int main() {
  add_yaml("searchBar.yaml", {{"top", 5}});
  addRatingArray(3);
  add_yaml("baseTemplate.yaml");
  _write_global_yaml_to_file("react.yaml");
}