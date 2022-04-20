#ifndef __STATE_H__
#define __STATE_H__

#include<string>
#include "/usr/local/cs/cs251/show_mem.h"
#include "IdeaGenerator.h"
#include "NewPost.h"
#include "Post.h"
#include "community.h"
#include "account.h"
#include "SearchResults.h"
#include "Text.h"
using namespace std;

class State {
  int panelType = 0; // 0 is idea generator, 1 is new post, 2 is community, 3 is post, 4 is account, 5 is search results
  
  IdeaGenerator ideaGen;
  NewPost newPost;
  Community community;
  Post post;
  Account account;
  SearchResults results;

  void read_from(string file);
  void display();
};

#endif
