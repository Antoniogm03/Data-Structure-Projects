#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "solver.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 4){
        cerr << "Número de parámetros incorrecto. Los parametros son: " << endl;
        cerr << "1.- El fichero con las letras" << endl;
        cerr << "2.- El fichero con el diccionario" << endl;
        cerr << "3.- Tipo de puntuación usada en la partida (L para longitud, P para puntuación)" << endl;
        return 1;
    }

    ifstream letters_file(argv[1]);
    ifstream dict_file(argv[2]);

    bool score_game;
    if (argv[3][0] == 'L') {
        score_game = false;
    } else if (argv[3][0] == 'P') {
        score_game = true;
    } else {
        cerr << "El parámetro asociado al tipo de juego puede tomar los valores L o C, se ha recibido ";
        cerr << argv[3] << endl;
        return 1;
    }

    if(!letters_file){
        cerr << "No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }

    if(!dict_file){
        cerr << "No puedo abrir el fichero " << argv[2] << endl;
        return 0;
    }

    vector<chrono::microseconds> times;
    vector<int> sizes;
    for (int n_letras = 0; n_letras <= 25; n_letras++){
        int k = 0;
        // Chrono start, operation to measure, chrono stop
        Dictionary dictionary;
        dict_file >> dictionary;

        LettersSet letters_set;
        letters_file >> letters_set;

        LettersBag letters_bag(letters_set);

        Solver solver(dictionary, letters_set);

        vector<char> letters = letters_bag.extractLetters(n_letras);

        auto start = chrono::high_resolution_clock::now();
        while (k <= 10) {
            solver.getSolutions(letters, score_game);
            k++;
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>((stop - start)/k);
        k = 0;

        // Info storing
        times.push_back(duration);
        sizes.push_back(n_letras);
    }

    // Printing
    cout << "Sizes: ";
    for (int i = 0; i < sizes.size(); ++i){
        cout << sizes[i] << ",";
    }
    cout << endl;

    cout << "Times: ";
    for (int i = 0; i < times.size(); ++i){
        cout << times[i].count() << ",";
    }
    cout << endl;

    return 0;
}