#ifndef __TEXT_H__
#define __TEXT_H__

class Text {
    int len;
    int fontSize;
    char *text;
    bool *bold;
    bool *italicized;
    bool *underlined;

    public:
        Text();
        Text(const char *words);
        Text(const char *words, int sizeFont);
        Text(const Text &otherText);
        Text(string words);
        int getLength() {return len;}
        int getFontSize() {return fontSize;}
        char *getTextInfo(); // sends text information with the char array, boldness, italicization, and underlining of each char
        void read_from();
        void write_to();
        void setDefault(int length);
        void setDefault(int length, int sizeFont);
        void setText();
        void setText(const char *words);
        void setText(string words);
        void setBold(bool isBold);
        void setBold(bool isBold, int start, int end);
        void setItalics(bool isItalicized);
        void setItalics(bool isItalicized, int start, int end);
        void setUnderline(bool isUnderlined);
        void setUnderline(bool isUnderlined, int start, int end);
}

#endif