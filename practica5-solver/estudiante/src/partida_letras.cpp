//
// Created by antonio on 23/11/21.
//
#include "solver.h"

#include "dictionary.h"
#include "letters_set.h"
#include "letters_bag.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 5){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: partida_letras <Diccionario><LettersSet><Modo><Cantidad_Letras>\n";
        exit (1);
    }

    string archivo_letter = argv[1];
    string archivo_diccionario = argv[2];
    string modo = argv[3];
    int cantidad_letras = stoi(argv[4]);

    ifstream File1, File2;
    File1.open(archivo_diccionario);
    File2.open(archivo_letter);
    if (File1.fail() || File2.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    Dictionary diccionario;
    string a;
    while(!File1.eof()) {
        getline(File1, a);
        diccionario.insert(a);
    }
    LettersSet letterset;
    File2 >> letterset;

    LettersBag bolsa(letterset);
    vector<char> palabrasJuego = bolsa.extractLetters(cantidad_letras);
    bool score_game;
    if (modo == "P") {
        score_game = true;
    } else if(modo == "L") {
        score_game = false;
    } else {
        cout << "No la has metido bien" << endl;
        exit(1);
    }

    Solver resuelve(diccionario, letterset);
    pair<set<string>, int> par_sol = resuelve.getSolutions(palabrasJuego, score_game);

    cout << "LETRAS DISPONIBLES:" << endl;
    for (int i = 0; i < palabrasJuego.size(); i++) {
        cout << char(toupper(palabrasJuego[i])) << " ";
    }
    cout << endl;
    cout << "SOLUCIONES:" << endl;
    for (auto it = par_sol.first.begin(); it != par_sol.first.end(); it++) {
        cout << *it << endl;
    }
    cout << "PUNTUACION:" << endl;
    cout << par_sol.second << endl;

    File1.close();
    File2.close();
}
