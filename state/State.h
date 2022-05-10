#ifndef __STATE_H__
#define __STATE_H__

#include<string>
#include"/usr/local/cs/cs251/react.h"
#include "../idea_generator/IdeaGenerator.h"
#include "../new_post/NewPost.h"
#include "../post/post.h"
//#include "../community/community.h"
#include "../account/account.h"
//#include "../results/SearchResults.h"
#include "../text/text.h"
using namespace std;

class State {
  int label_offset;

  IdeaGenerator ideaGen;
  NewPost newPost;
  //Community community;
  Post post;
  Account account;
  //SearchResults results;

  public:
    int panelType = 0; // 0 is idea generator, 1 is new post, 2 is community, 3 is post, 4 is account, 5 is search results
    int get_label_offset();
    void read_from(char *mem); //20 25114
    void write_to(char *mem);
    void update();
    void updateNewPost();
    void handle_button_event(int i); 
};

void display(State &);

#endif
