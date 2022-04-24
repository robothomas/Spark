#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
#include"database.h"
#include"post/post.h"
#include"community.h"
using namespace std;

//Constructors
Database::Database(){
        pLen = 1;
        cLen = 1;
        pStorage = new Post[pLen];
        cStorage = new Community[cLen]];
    }
Database::Database(int p, int c){
    pLen = p;
    cLen = c;
    pStorage = new Post[pLen];
    cStorage = new Community[cLen];
}

//Get storage ids
int Database::get_post_id(){
    for(int i = 0; i < pLen; i++){
        if(pStorage[i] == 0){
            return i;
        }
    }
    if(pStorage[pLen] != 0){
        expand_pStorage();
        return get_post_id();
    }
}
int Database::get_community_id(){
    for(int i = 0; i < cLen; i++){
        if(cStorage[i] == 0){
            return i;
        }
    }
    if(cStorage[cLen] != 0){
        expand_cStorage();
        return get_community_id();
    }
}

//Expand storage
void Database::expand_pStorage(){
    pLen = pLen * 2;
    Post* tmp = new Post[pLen];
    for(int i = 0; i < pLen; i++){
        tmp[i] = pStorage[i];
    }
    delete [] pStorage;
    pStorage = tmp;
}
void Database::expand_cStorage(){
    cLen = cLen * 2;
    Community* tmp = new Community[pLen];
    for(int i = 0; i < cLen; i++){
        tmp[i] = cStorage[i];
    }
    delete [] cStorage;
    cStorage = tmp;
}

//add item to storage
void Database::add_post(Post* p){
    int i = get_post_id();
    pStorage[i] = p;
}
void Database::add_community(Community* c){
    int i = get_community_id();
    cStorage[i] = c;
}

//get item ids
Post* Database::get_post(int id){
    return pStorage[id];
}
Community* Database::get_community(int id){
    return cStorage[id];
}
