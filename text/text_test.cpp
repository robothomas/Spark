#include "Text.h"
#include <cassert>

void testDefinition() {
    Text t0;

    char *words = new char[10];
    words[3] = 'i'; 

    Text t1(words);
    assert(t1.getText()[3] == 'i');
    
    Text t2(words, 15);
    assert(t2.getText()[3] == 'i');
    assert(t2.fontSize == 15);

    Text t3("hello");
    assert(t3.getText()[2] == 'l');

    Text t4("hello", 15);
    assert(t2.getText()[3] == 'l');
    assert(t2.fontSize == 15);

    delete [] words;
}

void testDefault() {
    Text t;
    t.setDefault(50);
    assert(t.len == 50);
    assert(t.fontSize == 20);
    assert(t.getText()[5] == ' ');
    assert(t.getBold()[1] == false);
    assert(t.getItalicized()[17] == false);
    assert(t.getUnderlined()[43] == false);

    Text t2("hello!");
    t2.setDefault(20, 30);
    assert(t2.len == 20);
    assert(t2.fontSize == 30);
    assert(t2.getText()[7] == ' ');
    assert(t2.getBold()[4] == false);
    assert(t2.getItalicized()[15] == false);
    assert(t2.getUnderlined()[18] == false);
}

int main() {
    testDefinition();
    testDefault();
}