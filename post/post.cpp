#include <string>
#include "post.h"
#include "../text/text.h"
#include"/usr/local/cs/cs251/react.h"


Post::Post(int id_num, int communityID, string postTitle) : id(id_num), title(postTitle) {
    communityIDs = new int[1];
    communityIDs[0] = communityID;
}

Post::Post(int id_num, int communityID, string postTitle; Text postDescription) : id(id_num), title(postTitle) {
    communityIDs = new int[1];
    communityIDs[0] = communityID;
    description = postDescription;
}

Post::Post(int id_num, int communityIDs[], string postTitle);
Post::Post(int id_num, int communityIDs[], string postTitle, Text postDescription);

int Post::get_id() {
    return id;
}

string Post::get_title() {
    return title;
}

Text Post::get_description() {
    return description;
}

void Post::read_from(const char* mem){
    title = _get_char(mem, 1); //find \n
    mem += //find \n 
    string desc = _get_char(mem, 1); //find \n
    mem += //find \n 
    description = Text(desc); //Make desc into a char*

}

void Post::write_to(const char *mem) {
    _put_int(id, mem, 2);
    mem += 2;

    _put_char('\n', mem, 1);
    mem += 1;

    for (i = 0; communityIDs[i]; i++) {
        put_int(communityIDs[i], mem, 2);
        mem += 2;
    }

    _put_tilde_terminated_string(title, mem);
    
    mem += title.length() + 1;

    text.write_to(mem);
}