#include <fstream>
#include "State.h"

void State::read_from(char *mem) {
    panelType = _get_int(mem, 2);
    mem += 3;

    //ideaGen.read_from(mem);
    //mem += ideaGen.size_in_bytes();
    newPost.read_from(mem);
    //mem += newPost.size_in_bytes();
    account.read_from(mem);
    //mem += account.size_in_bytes();
    //community.read_from(mem);
    //mem = post.read_from(mem);

    
    //results.read_from(f);
}

void State::write_to(char *mem) {
    _put_int(panelType, mem, 2);
    mem += 2;

    _put_char('\n', mem, 1);
    mem++;

    //ideaGen.write_to(mem);
    newPost.write_to(mem);
    mem += newPost.size_in_bytes();
    //community.write_to(mem);
    //mem = post.write_to(mem);
    account.write_to(mem);
    //results.write_to(mem);
    //ideaGen.write_to(mem);
}
