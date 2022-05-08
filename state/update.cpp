#include "State.h"

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