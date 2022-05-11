#ifndef __POST_H__
#define __POST_H__

#include <string>
#include "post.h"
#include "../text/text.h"

class Post {
    protected:
        int id_offset;
        int community_id_offset;
        int title_offset;
        int description_offset;
        int id;
        int communityNum;
        int *communityIDs;
        string title;
        Text description;
    public:
        Post();
        Post(int id_num, int communityID, string postTitle);
        Post(int id_num, int communityID, string postTitle, Text postDescription);
        Post(int id_num, int *communityIDNums, string postTitle);
        Post(int id_num, int *communityIDNums, string postTitle, Text postDescription);
        ~Post();
        //Post(const Post &p)
        int getIDOffset();
        int getCommunityIDsOffset();
        int getTitleOffset();
        int getDescriptionOffset();
        int get_id();
        int size_in_bytes();
        int getCommunityNum();
        string get_title();
        Text get_description();
        void assignID(int id_num);
        void read_from(const char* mem);
        void write_to(char* mem);
};

#endif