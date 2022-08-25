//
// Created by antonio on 13/11/21.
//

#include <letters_set.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: conjunto_letras <FichEntrada><palabra>\n";
        exit (1);
    }

    string archivo = argv[1];
    string palabra = argv[2];

    ifstream File1;
    File1.open(archivo);
    if (File1.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    LettersSet ejemplo;
    File1 >> ejemplo;
    cout << ejemplo.getScore(palabra) << endl;

    File1.close();
}