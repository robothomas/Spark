#include "../post/post.h"
#include <string>

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
        bool checkFormError();
        string showFormError();
}

#endif