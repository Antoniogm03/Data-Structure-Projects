//
// Created by antonio on 23/11/21.
//
/*
if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/partida.cpp)
    add_executable(partida
            ${BASE_FOLDER}/src/partida.cpp
            ${BASE_FOLDER}/src/letters_set.cpp
            ${BASE_FOLDER}/src/letters_bag.cpp
            ${BASE_FOLDER}/src/solver.cpp
            ${BASE_FOLDER}/src/dictionary.cpp estudiante/src/partida.cpp estudiante/src/partida.cpp)
endif()
*/
#include "solver.h"

#include "dictionary.h"
#include "letters_set.h"
#include "letters_bag.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: partida_letras <Diccionario><LettersSet><Modo><Cantidad_Letras><Jugadores>\n";
        exit (1);
    }

    string archivo_letter = argv[1];
    string archivo_diccionario = argv[2];
    string modo = argv[3];
    int cantidad_letras = stoi(argv[4]);
    int jugadores = stoi(argv[5]);

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

    Solver sol(diccionario, letterset);
    cout << "LETRAS DISPONIBLES:" << endl;
    for (int i = 0; i < palabrasJuego.size(); i++) {
        cout << char(toupper(palabrasJuego[i])) << " ";
    }
    cout << endl;
    cout << "SOLUCIONES:" << endl;
    vector<string> soluciones;
    string aux;
    for (int i = 0; i < jugadores; i++) {
        cin >> aux;
        if (sol.isValid(palabrasJuego, aux)) {
            soluciones.push_back(aux);
        } else {
            cout << "Palabra no valida" << endl;
            i--;
        }
    }
    vector<string> validas = sol.VectorPalabras(palabrasJuego);
    for (int i = 0; i < jugadores; i++) {
        bool encontrado = false;
        for (int n = 0; n < validas.size(); n++) {
            if (validas[n] == soluciones[i]) {
                encontrado = true;
                n = validas.size();
            }
        }
        if (!encontrado) {
            cout << "Palabra no valida del jugador" << i << endl;
            cin >> aux;
            soluciones[i] = aux;
        }
    }

    string palabra_ganadora;
    int puntuacion = 0, ganador;
    if (score_game) {
        for (int i = 0; i < soluciones.size(); i++) {
            int val = letterset.getScore(soluciones[i]);
            if(val > puntuacion) {
                puntuacion = val;
                palabra_ganadora = soluciones[i];
                ganador = i;
            }
        }
    } else if(!score_game){
        for (int i = 0; i < soluciones.size(); i++) {
            int val = soluciones[i].length();
            if(val > puntuacion) {
                puntuacion = val;
                palabra_ganadora = soluciones[i];
                ganador = i;
            }
        }
    }

    cout << "La palabra ganadora es: " << palabra_ganadora << " con puntuación " << puntuacion << " del jugador " << ganador << endl;

    File1.close();
    File2.close();
}