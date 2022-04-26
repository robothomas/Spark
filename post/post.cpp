#include <string>
#include "post.h"
#include "../text/text.h"
#include"/usr/local/cs/cs251/show_mem.h"


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