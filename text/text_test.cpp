#include "text.h"
#include <cassert>
#include <iostream>
using namespace std;

void testDefinition() {
    Text t0;
    assert(t0.getText()[0] == ' ');

    char *words = new char[10];
    
    for (int i = 0; i < 10; i += 2) {
        words[i] = 'i'; 
        words[i + 1] = 'j';
    } 

    Text t1(words);
    assert(t1.getText()[2] == 'i');
    
    Text t2(words, 15);
    assert(t2.getText()[2] == 'i');
    assert(t2.fontSize == 15);

    Text t3("hello");
    assert(t3.getText()[2] == 'l');

    Text t4("hello", 15);
    assert(t4.getText()[3] == 'l');
    assert(t4.fontSize == 15);

    t4.setUnderline(true, 0, 3);

    Text t5(t4);
    assert(t5.getText()[3] == 'l');
    assert(t5.fontSize == 15);
    assert(t5.getUnderlined()[0] == true);
    assert(t5.getUnderlined()[1] == true);
    assert(t5.getUnderlined()[2] == true);
    assert(t5.getUnderlined()[3] == true);

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

void testSetText() {
    char *words = new char[6];
    words[0] = 'h';
    words[1] = 'e';
    words[2] = 'l';
    words[3] = 'l';
    words[4] = 'o';
    words[5] = '\0';

    Text t0;
    t0.setText(words);
    assert(t0.len == 6);

    for (int i = 0; i < 6; i++) {
        assert(t0.getText()[i] == words[i]);
    }

    Text t1;
    t1.setText("hello");

    assert(t1.len == 6);

    for (int i = 0; i < 6; i++) {
        assert(t1.getText()[i] == words[i]);
    }
    
}

int main() {
    testDefinition();
    testDefault();
    testSetText();
}