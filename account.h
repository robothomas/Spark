#ifndef __COMMUNITY_H__
#define __COMMUNITY_H__

class Account{
    string user;
    string password;
    string email;
    Posts* your_posts;
    Post* saved_posts;
    Community* saved_communities;
public:
    string get_user();
    string get_password();
    string get_email();
    void change_password(string pw);
    void change_email(string em);
    void add_saved_post(Post* p);
    void remove_saved_post(Post* p);
    void add_saved_community(Community* c);
    void removed_saved_community(Community* c);
    void add_new_post(Post* p);
    int get_your_posts_id();
    int get_saved_post_id();
    int get_saved_communities_id();
    void expand_your_posts();
    void expand_saved_posts();
    void expand_saved_communities();
    

}