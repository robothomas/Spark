#ifndef __DATABASE_H__
#define __DATABASE_H__
#include<iostream>
#include"../community/community.h"
#include"../post/post.h"
using namespace std;

class Database {
    int pLen;
    int cLen;
    Post *pStorage;
    Community *cStorage;
public:
    //Constructors
    Database();
    Database(int p, int c);
    //Member Functions
    int get_post_id();
    int get_community_id(); 
    void expand_pStorage();
    void expand_cStorage();
    void add_post(Post* p);
    void add_community(Community* c);
    Post* get_post(int id);
    Community* get_community(int id);
};

#endif