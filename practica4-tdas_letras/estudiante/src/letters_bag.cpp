#include "letters_bag.h"

LettersBag::LettersBag() {}

LettersBag::LettersBag(const LettersSet &letterset) {
    int repeticiones;
    for (auto it = letterset.begin(); it != letterset.end(); it++) {
        repeticiones = (*it).second.repetitions;
        for (int i = 0; i < repeticiones; i++)
            insertLetter((*it).first);
    }
}

void LettersBag::insertLetter(const char &I) {
    letters.add(I);
}

char LettersBag::extractLetter() {
    return letters.get();
}

std::vector<char> LettersBag::extractLetters(int num) {
    std::vector<char> aux;
    for (int i = 0; i < num; i++) {
        aux.push_back(extractLetter());
    }
    return aux;
}

void LettersBag::clear() {
    letters.clear();
}

unsigned int LettersBag::size() const {
    letters.size();
}

LettersBag &LettersBag::operator=(const LettersBag &other) {
    letters = other.letters;
    return *this;
}




