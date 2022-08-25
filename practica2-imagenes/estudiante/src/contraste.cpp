//
// Created by antonio on 5/10/21.
//

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
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: Contraste <FichImagenOriginal> <FichImagenDestino> <e1> <e2> <s1> <s2>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    int e1 = stoi(argv[3]);
    int e2 = stoi(argv[4]);
    int s1 = stoi(argv[5]);
    int s2 = stoi(argv[6]);


    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << e1 << " " << e2 << " " << s1 << " " << s2 << endl;
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

////////////////////////// PRUEBA FUNCIÓN ADJUST_CONTRAST.
    image.AdjustContrast(e1,e2,s1,s2);
    if (image.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}
