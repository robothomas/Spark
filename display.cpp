#include "state/State.h"

void display(State &state) {
    switch(state.panelType) {
        case 0:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        case 1:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        case 2:
            //_add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
            break;
        case 3:
            _add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
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