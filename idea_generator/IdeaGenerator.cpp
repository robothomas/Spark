#include "IdeaGenerator.h"
#include <string>
#include <iostream>
#include "/usr/local/cs/cs251/react.h"
using namespace std;

int countBeyondTilde(const char *mem) {
    int len = 0;
    while (mem[++len] != '~') {}
    len++; // in order to go one beyond the tilde

    return len;
}

IdeaGenerator::IdeaGenerator() {
    recent = "All-Time";
    difficulty = "Any";
    searchQuery = "";
}

IdeaGenerator::IdeaGenerator(const IdeaGenerator &idea) {
    recent = idea.recent;
    difficulty = idea.difficulty;
    searchQuery = idea.searchQuery;
}

IdeaGenerator IdeaGenerator::operator=(const IdeaGenerator &idea) {
    recent = idea.recent;
    difficulty = idea.difficulty;
    searchQuery = idea.searchQuery;
    return *this;
}

bool IdeaGenerator::checkValidRecency(string recency) {
    return (recency == "Today" || recency == "Week" || recency == "Month" || recency == "Year" || recency == "All-Time");
}

bool IdeaGenerator::checkValidDifficulty(string range) {
    return (range == "Any" || range == "1-2" || range == "2-3"|| range == "3-4" || range == "4-5");
}

string IdeaGenerator::getRecency() {
    if (checkValidRecency(recent)) {
        return recent;
        
    } else {
        cerr << "WARNING: Contains invalid recency. Returning All-Time by default" << endl;
        recent = "All-Time";
        return recent;
    }
}

string IdeaGenerator::getDifficulty() {
    if (checkValidDifficulty(difficulty)) {
        return difficulty;

    } else {
        cerr << "WARNING: Contains invalid range. Returning Any by default.";
        difficulty = "Any";
        return difficulty;
    }
}

void IdeaGenerator::setDifficulty(string range) {
    if (checkValidDifficulty(range)) {
        difficulty = range;

    } else {
        cerr << "WARNING: Invalid range. Setting to Any by default.";
        difficulty = "Any";
    }
}

// Can be set to Today, Week, Month, Year, All-Time
void IdeaGenerator::setRecency(string recency) {
    if (checkValidRecency(recency)) {
        recent = recency;

    } else {
        cerr << "WARNING: Invalid string. Setting recent to All-Time by default" << endl;
        recent = "All-Time";
    }
}

void IdeaGenerator::read_from(const char *mem) {
    int memPos = 0;

    recent_offset = 0;
    recent = _get_tilde_terminated_string(mem);
    memPos += countBeyondTilde(mem);
    
    difficulty_offset = memPos;
    difficulty = _get_tilde_terminated_string(mem);
    memPos += countBeyondTilde(mem);

    query_offset = memPos;
    searchQuery = _get_tilde_terminated_string(mem);
}

void IdeaGenerator::write_to(char *mem) {
    _put_tilde_terminated_string(recent, mem);
    mem += countBeyondTilde(mem);

    _put_tilde_terminated_string(difficulty, mem);
    mem += countBeyondTilde(mem);

    _put_tilde_terminated_string(searchQuery, mem);
}

int IdeaGenerator::getRecencyOffset() {
    return recent_offset;
}

int IdeaGenerator::getDifficultyOffset() {
    return difficulty_offset;
}

int IdeaGenerator::getQueryOffset() {
    return query_offset;
}