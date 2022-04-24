#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
#include"community.h"
using namespace std;

void test_get_title(){
    Community c;
    Text* t = c.get_title();
}

void test_get_description(){
    Community c;
    Text* d = c.get_description();
}

void test_change_title(){
    Community c;
}

void test_change_description(){
    Community c;
}

void test_add_post(){
    Community c;
}

void test_remove_post(){
    Community c;
}

void test_get_post(){
    Community c;
}

void test_get_open_id(){
    Community c;
    Post p;
    assert(c.get_open_id() == 0);
    c.add_post(p);
    assert(c.get_open_id() == 1);
}

void test_expand_posts(){
    Community c;
    assert(c.len == 1);
    c.expand_posts();
    assert(c.len == 2);
    c.expand_posts();
    assert(c.len == 4);
}



int main(){ //Needs to be tested
    test_get_title();
    test_get_description();
    test_change_title();
    test_change_description();
    test_add_post();
    test_remove_post();
    test_get_post();
    test_get_open_id();
    test_expand_posts();
}