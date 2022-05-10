#include "State.h"

void State::update(){
    _read_event_info_file("event_info");
    if(_received_event()) {
        for (int i = 0; i < 4; ++i) {
            if(_event_id_is("menu_", i)) {
                panelType = i;
            }
        }

        switch (panelType) {
            case 0://Idea Generator
                break;
            case 1:
                break;
            case 2://New Post
                updateNewPost();
                break;
            case 3://Account
                break;
            case 4:
                break;
            case 5:
                break;
        } 
    }
    
}

void State::updateNewPost() {
    if (_event_id_is("+")) {
       // _add_yaml("../confirmPopUp.yaml", {{"confirmation", index}, {"affirmative", yesSpot}, {"negative", noSpot}})
    }

    if (_event_id_is("Yes")) {
        // panelType = 3;
        // put data into Post here, likely through database
    }

    if (_event_id_is("No")) {
        // delete pop-up
    }
}
