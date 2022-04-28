#include "State.h"
#include "/usr/local/cs/cs251/react.h"

void State::update(){
    if(_received_event()){
        for (int i = 0; i < 5; ++i) {
            if(_event_id_is("button_", i)){
            panelType = i;
            }
        } 
    }
}
