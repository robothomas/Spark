#include<string>
#include"post.h"
#include"../text/text.h"
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

void Post::read_from(char* mem){
    id = _get_int(mem);
    mem += 2;
    int j = 0;
    while( _get_char(mem) != "~"){j++;}
    communityID = new int[j];
    for(int i = 0; i < j; i++){
        communityID[i] = _get_int(mem);
        mem += 2;
    }
    title = _get_tilde_terminated_string(mem); 
    mem += title.size() + 1;
    string d = _get_tilde_terminated_string(mem);
    mem += d.size() + 1;
    description = Text desc(d);
}