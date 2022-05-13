a.out:  State.o account.o community.o post.o text.o display.o test_display.o NewPost.o IdeaGenerator.o update.o
	g++ -Wall State.o account.o community.o post.o text.o display.o test_display.o NewPost.o IdeaGenerator.o update.o /usr/local/cs/cs251/react.o -lcurl

