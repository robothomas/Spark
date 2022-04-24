#include<iostream>
#include"/usr/local/cs/cs251/show_mem.h"
#include"database.h"
using namespace std;

void test_get_post_id(){
    Database d;
}

void test_get_community_id(){
    Database d;
    Community c;
}

void test_expand_pStorage(){
    Database d;
    assert(d.pLen == 1);
    d.expand_pStorage();
    assert(d.pLen == 2);
    d.expand_pStorage();
    assert(d.pLen == 4);
}

void test_expand_cStorage(){
    Database d;
    assert(d.cLen == 1);
    d.expand_cStorage();
    assert(d.cLen == 2);
    d.expand_cStorage();
    assert(d.cLen == 4);
}

void test_add_post(){
    Database d;
    Post p;
    assert(d.get_post_id() == 0);
    d.add_post(p);
    assert(d.get_post_id() == 1);
}

void test_add_community(){
    Database d;
    Community c;
    assert(d.get_community_id() == 0);
    d.add_community(c);
    assert(d.get_community_id() == 1);
}



int main(){ //Needs to be tested
    test_get_post_id();
    test_get_community_id();
    test_expand_pStorage();
    test_expand_cStorage();
    test_add_post();
    test_add_community();
}