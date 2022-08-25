//
// Created by antonio on 11/10/21.
//
/*
#include <iostream>
#include <fstream>
#include <ctime>

#include "image.h"

using namespace std;

int main(int argc, char *argv[]) {
    clock_t ti, tf;
    int n_datos;
    string salida;
    Image image;

    // Comprobar validez de la llamada
    if (argc != 2){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: Eficiencia <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    salida = argv[1];

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero resultado: " << salida << endl;

    ofstream a(salida);
    if (!a.is_open()) {
        cerr << "Fail creating " << salida << " file" << endl;
    }

    for (n_datos = 10000; n_datos < 100000; n_datos += 5000) {

        Image imagen(n_datos,n_datos);

        // Mostrar los parametros de la Imagen
        cout << endl;
        cout << "Dimensiones: " << endl;
        cout << "   Imagen   = " << imagen.get_rows()  << " filas x " << imagen.get_cols() << " columnas " << endl;

        ti = clock();
        imagen.ShuffleRows();
        tf = clock();
        a << n_datos << "," << tf - ti << endl;
        ti=0; tf=0;
    } // Guardar salida en el finchero destino que será tipo txt.
    a.close();
}*/
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "image.h"

using namespace std;

int main(int argc, char *argv[]) {

    string salida;

    // Comprobar validez de la llamada
    if (argc != 2){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: Eficiencia <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    salida = argv[1];

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero resultado: " << salida << endl;

    ofstream a(salida);
    if (!a.is_open()) {
        cerr << "Fail creating " << salida << " file" << endl;
    }

    vector<chrono::microseconds> times;
    vector<int> sizes;
    for (int n_datos = 1000; n_datos <= 10000; n_datos+=1000){
        // Initialization
        Image imagen(n_datos, n_datos);
        int k = 0;
        // Chrono start, operation to measure, chrono stop
        auto start = chrono::high_resolution_clock::now();
        while (k <= 10) {
            imagen.ShuffleRows();
            k++;
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>((stop - start)/k);
        k = 0;

        // Info storing
        times.push_back(duration);
        sizes.push_back(n_datos);
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

    for (int i = 0; i < times.size(); ++i){
        a << sizes[i] << "," << times[i].count() << endl;
    }
    return 0;
}