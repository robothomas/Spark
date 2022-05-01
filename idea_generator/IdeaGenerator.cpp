#include <IdeaGenerator.h>
#include "/usr/local/cs/cs251/react.h"
using namespace std;

IdeaGenerator::IdeaGenerator() {
    format = 0;
    type = 0;
    recent = 0;
    difficulty = 0;
    searchQuery = "";
}

IdeaGenerator::IdeaGenerator(const IdeaGenerator &idea) {
    format = idea.format;
    type = idea.type;
    recent = idea.recent;
    difficulty = idea.difficulty;
    searchQuery = idea.searchQuery;
}

IdeaGenerator IdeaGenerator::operator=(const &idea) {
    IdeaGenerator(idea);
}

void IdeaGenerator::read_from(const char *mem) {
    format = _get_int(mem, 2);
    type = _get_int(mem + 2, 2);
    recent = _get_int(mem + 4, 2);
    difficulty = _get_int(mem + 6, 2);
}

void IdeaGenerator::write_to(char *mem) {
    _put_int(format, mem, 2);
    mem += 2;

    _put_int(type, mem, 2);
    mem += 2;

    _put_int(recent, mem, 2);
    mem += 2;

    _put_int(difficulty, mem, 2);
    mem += 2;

    _put_tilde_terminated_string(searchQuery, mem);
    while (++mem != '~') {} // adds to mem until tilde is found
}