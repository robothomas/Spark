#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include<iostream>
#include<string> 
#include"../post/post.h"
#include"../community/community.h"
using namespace std;

class Account{
    private:
        int user_offset;
        int password_offset;
        int email_offset;
        int ypl;
        int spl;
        int scl;
        string user;
        string password;
        string email;
        Post* your_posts;
        Post* saved_posts;
        Community* saved_communities;
    public:
        Account();
        Account(string user, string password, string email);
        int get_user_offset();
        int get_password_offset();
        int get_email_offset();
        string get_user();
        string get_password();
        string get_email();
        void change_password(string pw);
        void change_email(string em);
        void add_saved_post(Post* p);
        void remove_saved_post(int id);
        void add_saved_community(Community* c);
        void remove_saved_community(int id);
        void add_new_post(Post* p);
        void remove_your_post(int id);
        int get_your_posts_id();
        int get_saved_post_id();
        int get_saved_communities_id();
        void expand_your_posts();
        void expand_saved_posts();
        void expand_saved_communities();
        void read_from(char* mem);
        void write_to(char* mem);
        void display();
};

#endif