#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
#include"community.h"
using namespace std;

//Constructors
Community::Community();{
    id = Database.get_community_id();
    len = 1;
    title = Text();
    description = Text();
    posts = new Post[len];
}
Community::Community(Text *t, Text *d){
    id = Database.get_community_id();
    len = 1;
    title = t;
    description = d;
    posts = new Post[len];
}

//Title
Text Community::get_title(){ 
    return title;
}
void Community::change_title(Text *t){
    delete [] title;
    title = t;
}

//Description
Text Community::get_description(){
    return description;
}
void Community::change_description(Text *d){
    delete [] description;
    description = d;
}

//Alter posts
void Community::add_post(Post *p){
    int i = get_open_id();
    posts[i] = p; 
}
void Community::remove_post(int id){
    posts[id] = 0;
}
Post* Community::get_post(int id){
    return posts[id];
}

//post array
int Community::get_open_id(){
    for(int i = 0; i < len; i++){
        if(posts[i] == 0){
            return i;
        }
    }
    if(posts[len] != 0){
        expand_posts();
        return get_open_id();
    }
}
void Community::expand_posts(){
    len = len * 2;
    Post* tmp = new Post[len];
    for(int i = 0; i < len; i++){
        tmp[i] = posts[i];
    }
    delete [] posts;
    posts = tmp;
}


