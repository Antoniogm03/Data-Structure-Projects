#include "dictionary.h"

bool Dictionary::exist(const string &val) const {
    set<string>::iterator it;
    it = words.find(val);
    return words.end() != it;
}

bool Dictionary::insert(const string &val) {
    words.insert(val);
    return !exist(val);
}

bool Dictionary::erase(const string &val) {
    bool aux = false;
    if (exist(val)) {
        words.erase(val);
        aux = true;
    }
    return aux;
}

void Dictionary::clear() {
    words.clear();
}

bool Dictionary::empty() const {
    return words.empty();
}

unsigned int Dictionary::size() const {
    return words.size();
}

int Dictionary::getOccurrences(const char c) {
    int a = 0;
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it) {
        for (int i = 0; i < it->length(); i++) {
            if(it->at(i) == c)
                a++;
        }
    }
    return a;
}

int Dictionary::getTotalLetters() {
    int a = 0;
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it) {
        a += (it->length());
    }
    return a;
}

vector<string> Dictionary::wordsOfLength(int length) {
    vector<string> aux;
    int i = 0;
    for (auto it = words.begin(); it != words.end(); ++it) {
        if (length == it->length()) {
            aux.push_back(*it);
        }
        i++;
    }
    return aux;
}