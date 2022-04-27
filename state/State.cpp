#include <fstream>
#include "State.h"

void State::read_from(const char *mem) {
    //ideaGen.read_from(mem);
    //newPost.read_from(mem);
    //community.read_from(mem);
    Post.read_from(mem);
    //account.read_from(f);
    //results.read_from(f);
    //ideaGen.read_from(f);
}

void State::write_to(char *mem) {
    //ideaGen.write_to(mem);
    //newPost.write_to(mem);
    //community.write_to(mem);
    Post.write_to(mem);
    //account.write_to(mem);
    //results.write_to(mem);
    //ideaGen.write_to(mem);
}