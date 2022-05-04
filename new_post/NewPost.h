#include "../post/post.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef __NEWPOST_H__
#define __NEWPOST_H__

class NewPost : public Post {
    private:
        bool titleAdded;
        bool descriptionAdded;
        bool communityAdded;

    public:
        NewPost();
        bool checkTitle();
        bool checkDescription();
        bool checkCommunities();
        bool checkValidID();
        bool checkFormError();
        string showFormError();
};

#endif