//
// Created by antonio on 17/11/21.
//
#include "dictionary.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: conjunto_letras <FichEntrada><palabra>\n";
        exit (1);
    }

    string archivo = argv[1];
    int longitud = stoi(argv[2]);

    ifstream File1;
    File1.open(archivo);
    if (File1.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    Dictionary diccionario;
    string a;
    while(!File1.eof()) {
        getline(File1, a);
        diccionario.insert(a);
    }

    vector<string> aux;
    aux = diccionario.wordsOfLength(longitud);
    cout << "Palabras de longitud " << longitud << endl;
    for (int i = 0; i < aux.size(); i++) {
        cout << aux[i] << endl;
    }

    File1.close();
}
