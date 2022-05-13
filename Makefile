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
