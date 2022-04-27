#include <string>
#include <cstring>
using namespace std;

#ifndef __TEXT_H__
#define __TEXT_H__

class Text {
    private:
        char *text;
        bool *bold;
        bool *italicized;
        bool *underlined;
        int findLength(const char *c);
        void copyCharArray(char *&to, const char *&from, int length); // may be replaced by strcpy soon
        void copyCharArray(char *&to, const string &from, int length);
        void copyBoolArray(bool *&to, const bool *&from, int length);
        void setBoolSecton(bool *&array, bool val, int start, int end);
        void setBoolSecton(bool *&array, bool val, int length);

    public:
        int len;
        int fontSize;

        Text();
        Text(const char *words);
        Text(const char *words, int sizeFont);
        Text(const Text &otherText);
        Text(string words);
        Text(string words, int sizeFont);
        const char *getText();
        const bool *getBold();
        const bool *getItalicized();
        const bool *getUnderlined();
        void read_from();
        void write_to();
        void setDefault(int length);
        void setDefault(int length, int sizeFont);
        void setText();
        void setText(const char *words);
        void setText(const string words);
        void setBold(bool isBold);
        void setBold(bool isBold, int start, int end);
        void setItalics(bool isItalicized);
        void setItalics(bool isItalicized, int start, int end);
        void setUnderline(bool isUnderlined);
        void setUnderline(bool isUnderlined, int start, int end);

        void read_from(char *mem);
        void write_to(char *mem);
};

#endif