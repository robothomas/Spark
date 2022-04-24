#include "post.h"

Post(int id_num, int communityID, string postTitle) : id(id_num), title(postTitle) {
    communityIDs = new int[1];
    communityIDs[0] = communityID;
}

Post(int id_num, int communityID, string postTitle; Text postDescription) : id(id_num), title(postTitle) {
    communityIDs = new int[1];
    communityIDs[0] = communityID;
    description = postDescription;
}

Post(int id_num, int communityIDs[], string postTitle);
Post(int id_num, int communityIDs[], string postTitle, Text postDescription);

int get_id() {
    return id;
}

string get_title() {
    return title;
}

Text get_description() {
    return description;
}