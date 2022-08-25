//
// Created by antonio on 17/11/21.
//
#include "dictionary.h"
#include "letters_set.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: conjunto_letras <FichEntrada><palabra>\n";
        exit (1);
    }

    string archivo_diccionario = argv[1];
    string archivo_letter = argv[2];

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
    cout << "Letra\tFAbs.\tFrel." << endl;
    for (auto it = letterset.begin(); it != letterset.end(); ++it) {
        char letra = (*it).first;
        double ocurrencias = diccionario.getOccurrences((*it).first);
        double frec_rel = ocurrencias / diccionario.getTotalLetters();
        cout << char(toupper(letra)) << "\t" << ocurrencias << "\t" << frec_rel << endl;
    }

    File1.close();
    File2.close();
}
