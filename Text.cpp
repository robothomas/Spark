#include "Text.h"
#include <string>

// Helper function that finds the length of a given dynamically allocated char string
int findLength(const char *c) {
    int length = 0;
    while (c[length++]) {}
    return length;
}

// Copies one dynamically allocated char array to another
void copyCharArray(char *&to, const char *&from, int length) {
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

Text::Text(const Text &otherText) {
    setDefault(otherText.len, otherText.fontSize);
    copyCharArray(text, otherText, len);
}

// Sets text to a default state (excluding font size). Assumes that all memory is unallocated or deallocated
void Text::setDefault(int length) : len(length) {
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
void Text::setDefault(int length, int sizeFont) : len(length), fontSize(sizeFont) {
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
    if (len < findLength(words)) {
        len = findLength(words);

        delete [] text;
        delete [] bold;
        delete [] italicized;
        delete [] underlined;

        setDefault(len);
    }

    copyCharArray(text, words, len);
}

// Helper function that sets a particular part of a dynamically allocated bool array to a particular value
void setBoolSecton(bool *&array, bool val, int start, int end) {
    for (int i = start; i <= end; i++) {
        array[i] = val;
    }
}

// Helper function to set entire bool array to a particular value
void setBoolSecton(bool *&array, bool val, int length) {
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
    setBoolSecton(italics, isItalicized, len);
}

void Text::setItalics(bool isItalicized, int start, int end) {
    setBoolSecton(italics, isItalicized, start, end);
}

void Text::setUnderline(bool isUnderlined) {
    setBoolSecton(underlined, isUnderlined, len);
}

void Text::setUnderline(bool isUnderlined, int start, int end) {
    setBoolSecton(underlined, isUnderlined, start, end);
}

