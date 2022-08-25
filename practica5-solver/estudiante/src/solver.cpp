#include "solver.h"
#include <string>

using namespace std;

Solver::Solver(const Dictionary &dict, const LettersSet &letters_set) {
    dictionary = dict;
    lettersset = letters_set;
}

pair<set<string>, int> Solver::getSolutions(const vector<char> &available_letters, bool score_game) {
    pair<set<string>, int> a;
    if (score_game) {
        a = ScoreSolution(available_letters);
    } else {
        a = LenghtSolution(available_letters);
    }
    return solutions;
}

pair<set<string>, int> Solver::LenghtSolution(const vector<char> &available_letters) {
    vector<string> aux = VectorPalabras(available_letters);
    solutions.second = aux[0].length();
    for (int i = 0; i < aux.size(); i++) {
        if (solutions.second < aux[i].length()) {
            solutions.first.clear();
            solutions.second = aux[i].length();
            solutions.first.insert(aux[i]);
        }
        if (solutions.second == aux[i].length()) {
            solutions.first.insert(aux[i]);
        }
    }
    return solutions;
}

pair<set<string>, int> Solver::ScoreSolution(const vector<char> &available_letters) {
    vector<string> aux = VectorPalabras(available_letters);
    solutions.second = lettersset.getScore(aux[0]);
    for (int i = 0; i < aux.size(); i++) {
        if (solutions.second < lettersset.getScore(aux[i])) {
            solutions.first.clear();
            solutions.second = lettersset.getScore(aux[i]);
            solutions.first.insert(aux[i]);
        }
        if (solutions.second == lettersset.getScore(aux[i])) {
            solutions.first.insert(aux[i]);
        }
    }
    return solutions;
}

bool Solver::isValid(vector<char> available_letters, string aux) const {
    bool si = true;
    for (int i = 0; i < aux.size(); i++) {
        bool encontrado = false;
        vector<char>::iterator n;
        for (n = available_letters.begin(); n != available_letters.end() && !encontrado; n++) {
            if (aux.at(i) == *n) {
                available_letters.erase(n);
                n = available_letters.end();
                encontrado = true;
            }
        }
        if (!encontrado) {
            i = aux.size();
            si = false;
        }
    }
    return si;
} // Nota en este caso me interesa que se haga la copia de available_letters.

vector<string> Solver::VectorPalabras(const vector<char> &available_letters) const {
    vector<string> aux, completo;
    for (int i = available_letters.size(); i > 0; i--) {
        aux = dictionary.wordsOfLength(i);
        for (int a = 0; a < aux.size(); a++) {
            if(isValid(available_letters, aux[a]))
                completo.push_back(aux[a]);
        }
    }
    return completo;
}

set<string> Solver::VectortoSet(const vector<string> & a){
    set<string> aux;
    for (auto it = a.begin(); it != a.end(); ++it) {
        aux.insert(*it);
    }
    return aux;
} // No la hemos utilizado al final!!!