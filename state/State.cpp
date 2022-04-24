#include <fstream>
#include "State.h"

State::read_from(string file) {
    ifstream f(file);
    f >> panelType;
    f.get(); // reads in the newline

    ideaGen.read_from(f);
    newPost.read_from(f);
    community.read_from(f);
    post.read_from(f);
    account.read_from(f);
    results.read_from(f);
    ideaGen.read_from(f);
}

State::write_to(string file) {
    ofstream f(file);
    f << panelType << endl;

    ideaGen.write_to(f);
    newPost.write_to(f);
    community.write_to(f);
    post.write_to(f);
    account.write_to(f);
    results.write_to(f);
    ideaGen.write_to(f);
}