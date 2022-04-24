#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
#include"account.h"
#include"post/post.h"
#include"community.h"
using namespace std;

//Constructor
Account::Account(){
    ypl = 1;
    spl = 1;
    scl = 1;
    user = " ";
    password = " ";
    email = " ";
}
Account::Account(string u, string p, string e){
    ypl = 1;
    spl = 1;
    scl = 1;
    user = u;
    password = p;
    email = e;
}

//Login info
string Account::get_user(){return user;}
string Account::get_password(){return password;}
string Account::get_email(){return email;}
void Account::change_password(string pw){
    password.clear();
    password += pw;
}
void Account::change_email(string em){
    email.clear();
    email += em;
}

//Saved posts
void Account::add_saved_post(Post* p){
    int i = get_saved_posts_id();
    saved_posts[i] = p;
}
void Account::remove_saved_post(int id){
    saved_posts[id] = 0; 
}

//Saved communities
void Account::add_saved_community(Community* c){
    int i = get_saved_communities_id();
    saved_communities[i] = c;
}
void Account::remove_saved_community(int id){
    saved_communities[id] = 0;
}

//New posts
void Account::add_new_post(Post* p){
    int i = get_your_posts_id();
    your_posts[i] = p;
}
void Account::remove_your_post(int id){
    your_posts[id] = 0;
}

//get ids
int Account::get_your_posts_id(){
    for(int i = 0; i < ypl; i++){
        if(your_posts[i] == 0){
            return i;
        }
    }
    if(your_posts[ypl] != 0){
        expand_your_posts();
        return get_your_posts_id();
    }
}
int Account::get_saved_post_id(){
    for(int i = 0; i < spl; i++){
        if(saved_posts[i] == 0){
            return i;
        }
    }
    if(saved_posts[spl] != 0){
        expand_saved_posts();
        return get_saved_posts_id();
    }
}
int Account::get_saved_communities_id(){
    for(int i = 0; i < scl; i++){
        if(saved_communities[i] == 0){
            return i;
        }
    }
    if(saved_communities[scl] != 0){
        expand_saved_communities();
        return get_saved_communities_id();
    }
}

//Exapnd libraries
void Account::expand_your_posts(){
    ypl = ypl * 2;
    Post* tmp = new Post[ypl];
    for(int i = 0; i < ypl; i++){
        tmp[i] = your_posts[i];
    }
    delete [] your_posts;
    your_posts = tmp;
}
void Account::expand_saved_posts(){
    spl = spl * 2;
    Post* tmp = new Post[spl];
    for(int i = 0; i < spl; i++){
        tmp[i] = saved_posts[i];
    }
    delete [] saved_posts;
    saved_posts = tmp;
}
void Account::expand_saved_communities(){
    scl = scl * 2;
    Community* tmp = new Community[scl];
    for(int i = 0; i < scl; i++){
        tmp[i] = saved_communities[i];
    }
    delete [] saved_communities;
    saved_communities = tmp;
}

//Read/write
void Account::read_from(ifstream filestream){

}
void Account::write_to(){
    
}

