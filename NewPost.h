#include <ifstream>

#ifndef __NEWPOST_H__
#define __NEWPOST_H__

class NewPost {
    void read_from(ifstream filestream);
    void write_to();
    void display();
}

#endif