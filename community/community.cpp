#include<iostream>
#include<string>
#include"/usr/local/cs/cs251/react.h"
#include"community.h"
using namespace std;

//Constructors
Community::Community(){
    id = 1;
    len = 1;
    string t = " ";
    title = t;
    Text d = Text();
    description = &d;
    posts = new Post[len]; 
}
Community::Community(int i, string t, Text *d){
    id = i; 
    len = 1;
    title = t;
    description = d;
    posts = new Post[len]; 
}
Community::Community(const Community &c){
    id = c.id;
    len = c.len;
    title = c.title;
    description = c.description;
    posts = new Post[len]; 
    for(int i = 0; i < len; i++){
        posts[i] = c.posts[i];
    }
}
Community& Community::operator=(const Community &c){
    id = c.id;
    len = c.len;
    title = c.title;
    description = c.description;
    posts = new Post[len]; 
    for(int i = 0; i < len; i++){
        posts[i] = c.posts[i];
    }
    return *this;
}

int Community::get_id(){return id;}

//Title
Text Community::get_title(){ 
    return title;
}
void Community::change_title(string t){
    title.clear();
    title += t;
}

//Description
Text* Community::get_description(){
    Text* d = description;
    return d;
}
void Community::change_description(Text *d){
    delete [] description;
    description = d;
}

//Alter posts
void Community::add_post(Post *p){
    int i = get_open_id();
    posts[i] = *p; 
}
void Community::remove_post(int id){
    delete &posts[id];
}
Post* Community::get_post(int id){
    return &posts[id];
}

//post array
int Community::get_open_id(){
    for(int i = 0; i < len; i++){
        if(posts[i].get_id() == 0){
            return i;
        }
    }
    expand_posts();
    return get_open_id();
}
void Community::expand_posts(){
    len = len * 2;
    Post* tmp = new Post[len];
    for(int i = 0; i < len; i++){
        tmp[i] = posts[i];
    }
    delete posts;
    posts = tmp;
}

//Read/write
/*
Needs method to store and select what posts get displayed
for now, reverse order of database index
need to resprend in txt file?
*/
void Community::read_from(char *mem){
    id = _get_int(mem, 2);
    mem++;
    title = _get_tilde_terminated_string(mem);
    mem += title.size() + 1;
    //description->read_from(mem);
}
void Community::write_to(char *mem){
    _put_int(id, mem, 2);
    mem += 2;
    _print_newline();
    mem++;
    _put_tilde_terminated_string(title, mem);
    mem += title.length() + 1;
    _print_newline();
    mem++;
    description->write_to(mem);
}
