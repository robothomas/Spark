#ifndef __IDEAGENERATOR_H__
#define __IDEAGENERATOR_H__

#include <string>

class IdeaGenerator {
    private:
        int format;
        int type;
        int recent;
        int difficulty;

    public:
        string searchQuery;
        IdeaGenerator();
        IdeaGenerator(const IdeaGenerator &idea);
        IdeaGenerator operator=(const IdeaGenerator &idea);

        string getFormat();
        string getType();
        string getRecency();
        int getDifficulty();

        void setFormat(string format);
        void setFormat(int format);
        
        void setDifficulty(int difficulty);

        void setType(string type);
        void setType(int type);

        void setRecency(string recency);
        void setRecency(int recency);

        void read_from(const char *mem);
        void write_to(char *mem);
}

#endif