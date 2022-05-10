#include <string>
#include <iostream>
#include "post.h"
//#include "../text/text.h"
#include "/usr/local/cs/cs251/react.h"
using namespace std;

// may need to be fixed later
Post::Post() {
    id = 0;
    title = "";
    communityNum = 1;
    communityIDs = new int[communityNum];
    communityIDs[0] = 0;
}

Post::Post(int id_num, int communityID, string postTitle) {
    id = id_num;
    title = postTitle;
    communityNum = 1;
    communityIDs = new int[communityNum];
    communityIDs[0] = communityID;
}

Post::Post(int id_num, int communityID, string postTitle, Text postDescription) {
    id = id_num;
    title = postTitle;
    communityNum = 1;
    communityIDs = new int[communityNum];
    communityIDs[0] = communityID;
    description = postDescription;
}

Post::~Post() {
    delete [] communityIDs;
}

/* May not really need either of these since the automatic constructors should do the same thing 
// copy constructor
Post::Post(const Post &p){
    id = p.id;
    communityIDs = p.communityIDs;
    title = p.title;
    description = p.description;
}

// operator= definition
Post::operator=(const Post &p) {
    Post(p);
}
*/

/*
Post::Post(int id_num, int communityIDs[], string postTitle) {

}

Post::Post(int id_num, int communityIDs[], string postTitle, Text postDescription) {

}
*/

int Post::size_in_bytes() {
    int size = 3; // id + newline

    for (int i = 0; i < numCommunities; i++) {
        size += 2; //
    }

    size++; // for newline

    size += title.size() + 1;
    size += description.size_in_bytes();

    return size;
}

int Post::get_id() {
    return id;
}

string Post::get_title() {
    return title;
}

Text Post::get_description() {
    return description;
}

void Post::assignID(int id_num) {
    id = id_num;
}

void Post::read_from(const char* mem){
    int memPos = 0;

    id = _get_int(mem, 2);
    memPos += 2;

    memPos++; // for newline
    
    numCommunities = 0;
    for (int i = 0; mem[i + memPos] != '~'; i++) {
        if (mem[i + memPos] != ' ') {
            numCommunities++;
        }
    }

    delete [] communityIDs; 
    communityIDs = new int[numCommunities];

    for(int i = 0; i < numCommunities; i++){
        communityIDs[i] = _get_int(mem + memPos, 2);
        memPos += 2;
    }

    memPos++; // counts extra new line

    title = _get_tilde_terminated_string(mem + memPos);
    memPos += title.size() + 1;

    description.read_from(mem);
}


void Post::write_to(char *mem) {
    _put_int(id, mem, 2);
    mem += 2;

    *mem = '\n';
    mem++;

    for (int i = 0; i < numCommunities; i++) {
        _put_int(communityIDs[i], mem, 1);
        mem++;

        *mem = ' ';
        mem++;
    }

    *mem = '~';
    mem++;

    _put_tilde_terminated_string(title, mem);
    mem += title.length() + 1;

    *mem = '\n';
    mem++;

    description.write_to(mem);
}