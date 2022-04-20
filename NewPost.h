#include <ifstream>
#include <string>
#include "Text.h"

#ifndef __NEWPOST_H__
#define __NEWPOST_H__

class NewPost {
    string title;
    Text description;
    string attachFile;
    void read_from(ifstream filestream);
    void write_to();
    void display();
}

#endif