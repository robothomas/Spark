#include "NewPost.h"
#include "/usr/local/cs/cs251/react.h"

NewPost::NewPost() : Post() {
    titleAdded = false;
    descriptionAdded = false;
    communityAdded = false;
    communities = new string[communityNum];
    communities[0] = "Template";
}

NewPost::~NewPost() {
    delete [] communities;
}

int NewPost::getQueryOffset() const{
    return query_offset;
}

int NewPost::getCommunityStringOffset(int communityIndex) const{
    int offset = communityStringOffset;

    for (int i = 0; i < communityIndex; i++) {
        offset += communities[i].size();
    }

    return offset;
}

bool NewPost::checkTitle() {
    if (title == "") {
        titleAdded = false;

    } else {
        titleAdded = true;
    }

    return titleAdded;
}

bool NewPost::checkDescription() {
    if (description.isDefault()) {
        descriptionAdded = false;

    } else {
        descriptionAdded = true;
    }

    return descriptionAdded;
}

bool NewPost::checkCommunities() {
    if (communityIDs[0] != 0) {
        communityAdded = true;

    } else {
        communityAdded = false;
    }

    return communityAdded;
}

bool NewPost::checkValidID() {
    if (id == 0) {
        return false;
    }
    else{
        return true;
    }
}

bool NewPost::checkFormError() {
    if (checkTitle() && checkDescription() && checkCommunities()) {
        return true;

    } else {
        return false;
    }
}

string NewPost::showFormError() {
    int errors= 0;
    bool titleError = !checkTitle();
    bool descriptionError = !checkDescription();
    bool communityError = !checkCommunities();

    string errorMsg = "FORM ERROR: ";

    if (titleError) {
        errorMsg += "title";
        errors++;
    }

    if (titleError && descriptionError) {
        errorMsg += " and ";
    }

    if (titleError && descriptionError && communityError) {
        errorMsg += ", ";
    }

    if (descriptionError) {
        errorMsg += "description";
        errors++;
    }

    if ((titleError && communityError) || (descriptionError && communityError)) {
        errorMsg += " and ";
    }

    if (titleError && descriptionError && communityError) {
        errorMsg += ", and ";
    }

    if (communityError) {
        errorMsg += "communities";
        errors++;
    }

    if (errors == 1) {
        errorMsg += " was not filled out correctly (1)\n";

    } else {
        errorMsg += " were not filled out correctly (";
        errorMsg += to_string(errors);
        errorMsg += ")\n";
    }

    return errorMsg;

}

int NewPost::size_in_bytes() {
    int size = Post::size_in_bytes();
    size += query.size();

    for (int i = 0; i < communityNum; i++) {
        size += communities[i].size();
    }

    size++; // for extra newline

    return size;
}

void NewPost::read_from(const char *mem) {
    //Post::read_from(mem);
    int memPos = Post::size_in_bytes();

    query_offset = memPos;
    query = _get_tilde_terminated_string(mem + memPos);
    memPos = query.size() + 2;
    
    communityStringOffset = memPos;

    delete [] communities;
    communities = new string[communityNum];

    for (int i = 0; i < communityNum; i++) {
        communities[i] = _get_tilde_terminated_string(mem + memPos);
        memPos += query.size() + 1;
    }

}

void NewPost::write_to(char *mem) {
    //Post::write_to(mem);
    mem += Post::size_in_bytes();
    _put_tilde_terminated_string(query, mem);
    mem += query.size() + 1;
    
    *mem = '\n';
    mem += 2;

    for (int i = 0; i < communityNum; i++) {
        _put_tilde_terminated_string(communities[i], mem);
        mem += query.size() + 1;
    }

    *mem = '\n';
}