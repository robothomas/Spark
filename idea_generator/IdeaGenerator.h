#ifndef __IDEAGENERATOR_H__
#define __IDEAGENERATOR_H__

#include <string>
using namespace std;

class IdeaGenerator {
    private:
        int recent_offset;
        int difficulty_offset;
        int query_offset;
        string recent;
        string difficulty;

        bool checkValidRecency(string recency);
        bool checkValidDifficulty(string range);
        
    public:
        string searchQuery;
        IdeaGenerator();
        IdeaGenerator(const IdeaGenerator &idea);
        IdeaGenerator operator=(const IdeaGenerator &idea);

        int size_in_bytes();
        int getRecencyOffset();
        int getDifficultyOffset();
        int getQueryOffset();

        string getRecency();
        string getDifficulty();
        
        void setDifficulty(string range);
        void setRecency(string recency);

        void read_from(const char *mem);
        void write_to(char *mem);
};

#endif