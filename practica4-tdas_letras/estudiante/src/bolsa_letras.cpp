//
// Created by antonio on 15/11/21.
//
#include "letters_set.h"
#include "letters_bag.h"
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {

    if (argc != 2){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: bolsa_letras <FichEntrada>\n";
        exit (1);
    }

    string archivo = argv[1];

    ifstream File1;
    File1.open(archivo);
    if (File1.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    LettersSet ejemplo;
    File1 >> ejemplo;
    LettersBag aux(ejemplo);
    vector<char> salida;
    salida = aux.extractLetters(aux.size());
    for (int i = 0; i < salida.size(); i++)
        cout << char(toupper(salida[i])) << endl;

    return 0;
}