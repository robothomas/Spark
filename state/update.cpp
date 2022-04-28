#include "State.h"

void State::update(){
        if(_received_event()){
            for (int i = 0; i < 5; ++i) {
                if(_event_id_is("button_", i)){
                    panelType = i;
                }
            } 
        }
}

void State::handle_button_event(int i){
//Displays screen based on what button is pressed
//display(panelType);
}
