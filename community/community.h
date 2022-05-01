#ifndef __COMMUNITY_H__
#define __COMMUNITY_H__
#include<iostream>
#include<string>
#include"../text/text.h"
#include"../post/post.h"
using namespace std;

class Community{
    int id;
    int len;
    string title;
    Text* description;
    Post* posts[];

public:
    //Constructors
    Community(); 
    Community(string t, Text *d);
    Community(const Community &c);
    Community& operator=(const Community &c);
    //Member Functions
    int get_id();
    Text get_title();
    Text* get_description();
    void change_title(string t);
    void change_description(Text *d);
    void add_post(Post *p);
    void remove_post(int id);
    Post* get_post(int id);
    int get_open_id();
    void expand_posts();
    void read_from(char *mem);
    void write_to(char *mem);
};

#endif