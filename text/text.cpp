#include "text.h"
#include <string>
#include <cstring>
#include <iostream>
#include"/usr/local/cs/cs251/react.h"
using namespace std;

// Helper function that finds the length of a given dynamically allocated char string
int Text::findLength(const char *c) {
    int length = 0;
    while (c[length++]) {}
    return length;
}

// Helper function that finds the length of a string up until a certain character
int Text::findLength(const char *c, char s) {
    int length = 0;
    while (c[length++] != 's') {}
    return length;
}

// Copies one dynamically allocated char array to another
void Text::copyCharArray(char *&to, const char *&from, int length) {
    for (int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}

// Copies a string to a dynamically allocated char array
void Text::copyCharArray(char *&to, const string &from, int length) {
    for (int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}

void Text::copyBoolArray(bool *to, const bool *from, int length) {
    for (int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}

// Default constructor
Text::Text() {
    setDefault(40, 20);
}

Text::Text(const char *words) {
    int length = findLength(words);
    setDefault(length, 20);
    copyCharArray(text, words, len);
}

Text::Text(const char *words, int sizeFont) : fontSize(sizeFont) {
    int length = findLength(words);
    setDefault(length);
    copyCharArray(text, words, len);
}

Text::Text(string words) {
    setDefault(words.length(), 20);
    //strcpy(text, words.c_str);
    copyCharArray(text, words, len); // alternatively, apparently strcpy() already does the exact same thing
}

Text::Text(string words, int sizeFont) : fontSize(sizeFont) {
    setDefault(words.length());
    copyCharArray(text, words, len); // alternatively, apparently strcpy() already does the exact same thing
}

// Cannot Work! - cannot bind non-const lvalue reference of type ‘const bool*&’ to an rvalue of type ‘const bool*’
Text::Text(const Text &otherText) {
    setDefault(otherText.len, otherText.fontSize);
    copyCharArray(text, otherText.text, len);
    copyBoolArray(bold, otherText.bold, len);
    copyBoolArray(italicized, otherText.italicized, len);
    copyBoolArray(underlined, otherText.underlined, len);
}

Text Text::operator=(const Text &otherText) {
    return Text(otherText);
}

const char *Text::getText() {
    return text;
}

const bool *Text::getBold() {
    return bold;
}

const bool *Text::getItalicized() {
    return italicized;
}

const bool *Text::getUnderlined() {
    return underlined;
}

// Sets text to a default state (excluding font size). Assumes that all memory is unallocated or deallocated
void Text::setDefault(int length) {
    len = length;

    text = new char[len];
    setText();

    bold = new bool[len];
    setBold(false);

    italicized = new bool[len];
    setItalics(false);

    underlined = new bool[len];
    setUnderline(false);
}

// Sets text to a default state. Assumes that all memory is unallocated or deallocated
void Text::setDefault(int length, int sizeFont) {
    len = length;
    fontSize = sizeFont;

    text = new char[len];
    setText();

    bold = new bool[len];
    setBold(false);

    italicized = new bool[len];
    setItalics(false);

    underlined = new bool[len];
    setUnderline(false);
}

void Text::setText() {
    for (int i = 0; i < len; i++) {
        text[i] = ' ';
    }
}

void Text::setText(const char *words) {
    if (len != findLength(words)) {
        len = findLength(words);

        delete [] text;
        delete [] bold;
        delete [] italicized;
        delete [] underlined;

        setDefault(len);
    }

    copyCharArray(text, words, len);
}

void Text::setText(const string words) {
    if (len != int(words.length())) {
        len = words.length();

        delete [] text;
        delete [] bold;
        delete [] italicized;
        delete [] underlined;

        setDefault(len);
    }

    copyCharArray(text, words, len);
}

// Helper function that sets a particular part of a dynamically allocated bool array to a particular value
void Text::setBoolSecton(bool *&array, bool val, int start, int end) {
    for (int i = start; i <= end; i++) {
        array[i] = val;
    }
}

// Helper function to set entire bool array to a particular value
void Text::setBoolSecton(bool *&array, bool val, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = val;
    }
}

void Text::setBold(bool isBold) {
    setBoolSecton(bold, isBold, len);
}

void Text::setBold(bool isBold, int start, int end) {
    setBoolSecton(bold, isBold, start, end);
}

void Text::setItalics(bool isItalicized) {
    setBoolSecton(italicized, isItalicized, len);
}

void Text::setItalics(bool isItalicized, int start, int end) {
    setBoolSecton(italicized, isItalicized, start, end);
}

void Text::setUnderline(bool isUnderlined) {
    setBoolSecton(underlined, isUnderlined, len);
}

void Text::setUnderline(bool isUnderlined, int start, int end) {
    setBoolSecton(underlined, isUnderlined, start, end);
}

void Text::read_from(const char *mem) {
    int memPos = 0; // keeps track of spot in mem

    fontSize = _get_int(mem, 2);
    memPos += 2;

    setText(_get_tilde_terminated_string(mem + memPos));
    memPos += len + 1; // + 1 used for tilde (or newline, later)
    
    for (int i = 0; mem[memPos + i] != '\n'; i++) {
        bold[i] = mem[memPos + i];

        if (mem[memPos + i + 1] == '\n') {
            memPos += i + 2;
        }
    }

    for (int i = 0; mem[memPos + i] != '\n'; i++) {
        italicized[i] = mem[memPos + i];

        if (mem[memPos + i + 1] == '\n') {
            memPos += i + 2;
        }
    }

    for (int i = 0; mem[memPos + i] != '\n'; i++) {
        underlined[i] = mem[memPos + i];
        
        if (mem[memPos + i + 1] == '\n') {
            memPos += i + 2;
        }
    }
}

void Text::write_to(char *mem) {
    _put_int(fontSize, mem, 2);
    mem += 2;

    _put_tilde_terminated_string(text, mem);
    mem += len + 1;

    _put_char('\n', mem, 1);
    mem++;

    for (int i = 0; i < len; i++) {
        _put_bool(bold[i], mem, 2);
        mem += 2;
    }

    _put_char('\n', mem, 1);
    mem++;

    for (int i = 0; i < len; i++) {
        _put_bool(italicized[i], mem, 2);
        mem += 2;
    }

    _put_char('\n', mem, 1);
    mem++;

    for (int i = 0; i < len; i++) {
        _put_bool(underlined[i], mem, 2);
        mem += 2;
    }

    _put_char('\n', mem, 1);
    mem++;
}

