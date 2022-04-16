class Text {
    int len;
    int fontSize;
    char *text;
    bool *bold;
    bool *italicized;
    bool *underlined;

    Text();
    Text(const char *words);
    Text(const char *words, int sizeFont);
    Text(const Text &otherText);
    void setDefault(int length);
    void setDefault(int length, int sizeFont);
    void setText();
    void setText(const char *words);
    void setBold(bool isBold);
    void setBold(bool isBold, int start, int end);
    void setItalics(bool isItalicized);
    void setItalics(bool isItalicized, int start, int end);
    void setUnderline(bool isUnderlined);
    void setUnderline(bool isUnderlined, int start, int end);
}