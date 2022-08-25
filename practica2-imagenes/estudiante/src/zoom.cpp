//
// Created by antonio on 28/9/21.
//

#include <image.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    Image image;

    // Comprobar validez de la llamada
    if (argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: zoom <FichImagenOriginal> <FichImagenDestino> <fila> <col> <lado>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    int fila = stoi(argv[3]);
    int col = stoi(argv[4]);
    int lado = stoi(argv[5]);


    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << fila << " " << col << " " << lado << endl;
    cout << "Fichero resultado: " << destino << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

////////////////////////// PRUEBA FUNCIÓN ZOOM
    Image rdo, rdo1;
    rdo = image.Crop(fila, col, lado, lado);
    rdo1 = rdo.Zoom2X();
    if (rdo1.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}
