#include "../post/post.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef __NEWPOST_H__
#define __NEWPOST_H__

class NewPost : public Post {
    private:
        int query_offset;
        int communityStringOffset;
        string query;
        string *communities;
        bool titleAdded;
        bool descriptionAdded;
        bool communityAdded;

    public:
        NewPost();
        ~NewPost();
        int getQueryOffset() const;
        int getCommunityStringOffset(int communityIndex) const;
        bool checkTitle();
        bool checkDescription();
        bool checkCommunities();
        bool checkValidID();
        bool checkFormError();
        string showFormError();
        int size_in_bytes();
        void read_from(char *mem);
        void write_to(char *mem);
};

#endif