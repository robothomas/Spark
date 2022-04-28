#include "state/State.h"

void display(State &state) {
    switch(state.panelType)
        case 3:
            _add_yaml("postTemplate.yaml", {{"title", 7}, {"description", 25}});
}