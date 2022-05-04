#include<iostream>
#include"/usr/local/cs/cs251/react.h"
#include"database.h"
#include"../community/community.h"
#include"../post/post.h"
using namespace std;

//Constructors
Database::Database(){
    pID = 1;
    pLen = 1;
    cLen = 1;
    pStorage = new Post[pLen];
    cStorage = new Community[cLen];
}
Database::Database(int p, int c){
    pID = 1;
    pLen = p;
    cLen = c;
    pStorage = new Post[pLen];
    cStorage = new Community[cLen];
}

//Get storage ids
int Database::get_post_id(){
    for(int i = 0; i < pLen; i++){
        if(pStorage[i].get_id() == 0){
            return i;
        }
    }
    expand_pStorage();
    return get_post_id();
}
int Database::get_community_id(){ 
    for(int i = 0; i < cLen; i++){
        if(cStorage[i].get_id() == 0){
            return i;
        }
    }
    expand_cStorage();
    return get_community_id();
}

//Expand storage
void Database::expand_pStorage(){
    pLen = pLen * 2;
    Post* tmp;
    tmp = new Post[pLen];
    for(int i = 0; i < pLen; i++){
        tmp[i] = pStorage[i];
    }
    delete pStorage;
    pStorage = tmp;
}
void Database::expand_cStorage(){
    cLen = cLen * 2;
    Community* tmp = new Community[cLen];
    for(int i = 0; i < cLen; i++){
        tmp[i] = cStorage[i];
    }
    delete cStorage;
    cStorage = tmp;
}

//add items to storage
void Database::add_post(Post* p){
    int i = get_post_id();
    p->assignID(pID);
    pID++;
    pStorage[i] = *p;
}
void Database::add_community(Community* c){
    int i = get_community_id();
    cStorage[i] = *c;
}

//get item ids
Post* Database::get_post(int id){
    return &pStorage[id];
}
Community* Database::get_community(int id){
    return &cStorage[id];
}

char *Database::write_to(char *mem) {
    for (int i = 0; i < pLen; i++) {
        pStorage[i].write_to(mem);
        _put_char('\n', mem, 1);
    }

    for (int i = 0; i < cLen; i++) {
        cStorage[i].write_to(mem);
        _put_char('\n', mem, 1);
    }

    return mem;
}

char *Database::read_from( char *mem) {
    for (int i = 0; i < pLen; i++) {
        mem = pStorage[i].read_from(mem);
        mem++;
    }

    for (int i = 0; i < cLen; i++) {
        mem = cStorage[i].read_from(mem);
        mem++;
    }

    return mem;
}
