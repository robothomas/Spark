#include <fstream>
#include "State.h"

State::read_from(string file) {
    ifstream f(file);
    f >> panelType;
    f.get(); // reads in the newline

    switch (panelType) // 0 is idea generator, 1 is new post, 2 is community, 3 is post, 4 is account, 5 is search results
        case 0:
            ideaGen.read_from(f);
            break;
        case 1:
            newPost.read_from(f);
            break;
        case 2:
            community.read_from(f);
            break;
        case 3:
            post.read_from(f);
            break;
        case 4:
            account.read_from(f);
            break;
        case 5:
            results.read_from(f);
            break;
        default:
            ideaGen.read_from(f);
            break;
}

State::display() {
    switch (panelType) // 0 is idea generator, 1 is new post, 2 is community, 3 is post, 4 is account, 5 is search results
        case 0:
            ideaGen.display();
            break;
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