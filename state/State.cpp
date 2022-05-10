#include <fstream>
#include "State.h"

void State::read_from(char *mem) {
    panelType = _get_int(mem, 1);
    mem += 2; // + 1 extra for newline

    switch (panelType) {
        case 0://Idea Generator
            ideaGen.read_from(mem);
            break;
        case 1:
            break;
        case 2://New Post
            newPost.read_from(mem);
            break;
        case 3://Account
            account.read_from(mem);
            break;
        case 4:
            break;
        case 5:
            break;
        } 
    //ideaGen.read_from(mem);
    //mem += ideaGen.size_in_bytes();
    //newPost.read_from(mem);
    //mem += newPost.size_in_bytes();
    //account.read_from(mem);
    //mem += account.size_in_bytes();
    //community.read_from(mem);
    //mem = post.read_from(mem);

    
    //results.read_from(f);
}

void State::write_to(char *mem) {
    _put_int(panelType, mem, 1);
    mem++;

    *mem = '\n';
    mem++;

    switch (panelType) {
        case 0:
            ideaGen.write_to(mem);
            break;
        case 1:
            break;
        case 2://New Post
            newPost.write_to(mem);
            break;
        case 3://Account
            account.write_to(mem);
            break;
        case 4:
            break;
        case 5:
            break;
    } 
    //ideaGen.write_to(mem);
    //newPost.write_to(mem);
    //mem += newPost.size_in_bytes();
    //community.write_to(mem);
    //mem = post.write_to(mem);
    //account.write_to(mem);
    //results.write_to(mem);
    //ideaGen.write_to(mem);
}
