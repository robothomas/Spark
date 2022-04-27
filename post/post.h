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
    Post(int id_num, int communityID, string postTitle);
    Post(int id_num, int communityID, string postTitle, Text postDescription);
    Post(int id_num, int *communityIDNums, string postTitle);
    Post(int id_num, int *communityIDNums, string postTitle, Text postDescription);
    int get_id();
    string get_title();
    Text get_description();
    void read_from(char* mem);
    void write_to(char* mem);
};

#endif