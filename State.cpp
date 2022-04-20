#include "State.h"

State::read_from(string file) {
    
}

State::display() {
    switch (panelType) // 0 is idea generator, 1 is new post, 2 is community, 3 is post, 4 is account, 5 is search results
        case 0:
            ideaGen.display();
        case 1:
            newPost.display();
            break;
        case 2:
            community.display();
            break;
        case 3:
            post.display();
            break;
        case 4:
            account.display();
            break;
        case 5:
            results.display();
            break;
        default:
            ideaGen.display();
            break;
}