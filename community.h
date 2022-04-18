#ifndef __COMMUNITY_H__
#define __COMMUNITY_H__

class Community{
    int id;
    int len;
    Text* title;
    Text* description;
    Post* posts[];

public:
    //Constructors
    Community(); 
    Community(Text *t, Text *d);
    //Member Functions
    Text get_title();
    Text get_description();
    void change_title(Text *t);
    void change_description(Text *d);
    void add_post(Post *p);
    void remove_post(int id);
    Post* get_post(int id);
    int get_open_id();
    void expand_posts();
};