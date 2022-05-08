#include "State.h"

<<<<<<< HEAD
void State::updateNewPost() {
    if (panelType == 1) {
        if (_event_id_is("+")) {
            // create pop-up
        }
        if (_event_id_is("Yes")) {
            panelType = 3;
            // put data into Post here, likely through database
        }
        if (_event_id_is("No")) {
            // delete pop-up
        }
=======
void State::update(){
    if(_received_event()) {
        for (int i = 0; i < 4; ++i) {
            if(_event_id_is("menu_", i)) {
                panelType = i;
            }
        }

        switch (panelType) {
            case 1:
                updateNewPost();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        } 
    }
}

void updateNewPost() {
    if (_event_id_is("+")) {
        _add_yaml("../confirmPopUp.yaml", {{"confirmation", index}, {"affirmative", yesSpot}, {"negative", noSpot}})
    }

    if (_event_id_is("Yes")) {
        panelType = 3;
        // put data into Post here, likely through database
    }

    if (_event_id_is("No")) {
        // delete pop-up
>>>>>>> df0f258476095b47be26372a6e7e469451994528
    }
}

void State::update(){
    if(_received_event()) {
        for (int i = 0; i < 4; ++i) {
            if(_event_id_is("menu_", i)) {
                panelType = i;
            }
        }
        updateNewPost();  
    }
}