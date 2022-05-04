#ifndef __POST_H__
#define __POST_H__

#include <string>
#include "post.h"
#include "../text/text.h"

class Post {
    int id;
    int *communityIDs;
    string title;
    Text description;
    public:
        Post();
        Post(int id_num, int communityID, string postTitle);
        Post(int id_num, int communityID, string postTitle, Text postDescription);
        Post(int id_num, int *communityIDNums, string postTitle);
        Post(int id_num, int *communityIDNums, string postTitle, Text postDescription);
        //Post(const Post &p);
        int get_id();
        string get_title();
        Text get_description();
        void assignID(int id_num);
        char *read_from(char* mem);
        char *write_to(char* mem);
};

#endif