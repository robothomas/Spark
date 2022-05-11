#include "State.h"

int State::get_ideaGen_offset() {
    return idea_offset;
}

int State::get_newPost_offset() {
    return newPost_offset;
}

int State::get_account_offset() {
    return account_offset;
}

void State::read_from(char *mem) {
    panelType = _get_int(mem, 1);

    mem += 2; // + 1 extra for newline
    idea_offset = 2;

    ideaGen.read_from(mem);

    mem += ideaGen.size_in_bytes();
    newPost_offset = idea_offset + ideaGen.size_in_bytes();

    newPost.read_from(mem);
    
    mem += newPost.size_in_bytes();
    account_offset = newPost_offset + newPost.size_in_bytes();

    account.read_from(mem);

    //mem += account.size_in_bytes(); // not implemented yet

    //community.read_from(mem);
    
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