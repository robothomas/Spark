#include "NewPost.h"

NewPost::NewPost() : Post() {
    titleAdded = false;
    descriptionAdded = false;
    communityAdded = false;
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