#include "NewPost.h"

NewPost::read_from(fstream filestream) {
    f >> title;
    f.get();

    string text;
    f >> text;
    description.setText(text);
    for(int i = 0; )
}