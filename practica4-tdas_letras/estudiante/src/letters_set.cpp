#include "letters_set.h"
#include <map>

using namespace std;

LettersSet::LettersSet() {
    /*LetterInfo a;
    a.repetitions = 0;
    a.score = 0;
    letters.insert(std::pair<char,LetterInfo>(0,a));*/
}

LettersSet::LettersSet(const LettersSet & c) {
    letters = c.letters;
}

bool LettersSet::insert(const pair <char, LetterInfo> & val) {
    /*bool comprobar = true;
    if(letters.find(val.first)->first == val.first)
        comprobar = false;
    letters.insert(val);*/
    pair<map<char, LetterInfo>::iterator, bool> ret;
    ret = letters.insert(val);
    return ret.second;
}

bool LettersSet::erase(const char & key) {
    /*bool comprobar = true;
    if(letters.find(key)->first == key)
        comprobar = false;*/
    int size1 = letters.size();
    letters.erase(key);
    int size2 = letters.size();
    return size1 > size2;
}

void LettersSet::clear() {
    letters.clear();
}

bool LettersSet::empty() const {
    return letters.empty();
}

unsigned int LettersSet::size() const {
    return letters.size();
}

int LettersSet::getScore(string &word) {
    int score = 0;
    for (int i = 0; i < word.length(); i++) {
        score += letters[word[i]].score;
    }
    return score;
}

LettersSet & LettersSet::operator=(const LettersSet &cl) {
    letters = cl.letters;
    return *this;
}

LetterInfo & LettersSet::operator[](const char &val) {
    return letters[val];
}

ostream & operator<<(ostream & os, const LettersSet & cl) {
    os << "Letra Cantidad Puntos" << endl;
    map<char, LetterInfo>::const_iterator pos;
    for (pos = cl.letters.begin(); pos != cl.letters.end(); ++pos) {
        os << pos->first << " " << pos->second.repetitions << " " << pos->second.score << endl;
    }
    return os;
}

istream & operator>>(istream & is, LettersSet & cl) {
    string quitar;
    getline(is, quitar); // Eliminamos la línea Letra Cantidad Puntos.

    char key;
    int valor, repeticiones;
    while(!is.eof()) {
        is >> key >> repeticiones >> valor;
        LetterInfo info;
        info.score = valor;
        info.repetitions = repeticiones;
        cl.insert(std::pair<char, LetterInfo>(tolower(key), info));
    }
    return is;
}