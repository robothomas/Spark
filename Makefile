a.out:  State.o account.o community.o post.o text.o display.o test_display.o NewPost.o IdeaGenerator.o update.o
	g++ -Wall State.o account.o community.o post.o text.o display.o test_display.o NewPost.o IdeaGenerator.o update.o /usr/local/cs/cs251/react.o -lcurl

State.o: state/State.cpp state/State.h
	g++ -Wall -c state/State.cpp

account.o: account/account.cpp account/account.h
	g++ -Wall -c account/account.cpp

community.o: community/community.cpp community/community.h
	g++ -Wall -c community/community.cpp

post.o: post/post.cpp post/post.h
	g++ -Wall -c post/post.cpp

text.o: text/text.cpp text/text.h
	g++ -Wall -c text/text.cpp

NewPost.o: new_post/NewPost.cpp new_post/NewPost.h
	g++ -Wall -c new_post/NewPost.cpp

IdeaGenerator.o: idea_generator/IdeaGenerator.cpp idea_generator/IdeaGenerator.h
	g++ -Wall -c idea_generator/IdeaGenerator.cpp

update.o: state/update.cpp state/State.h
	g++ -Wall -c state/update.cpp

display.o: display.cpp
	g++ -Wall -c display.cpp

test_display.o: test_display.cpp
	g++ -Wall -c test_display.cpp