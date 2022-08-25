/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <cmath>

#include <image.h>
#include <imageIO.h>

using namespace std;

/********************************
      FUNCIONES PRIVADAS
********************************/
void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    for (int i = 0; i < rows; i++) {
        img[i] = new byte [cols];
    }

    int contador = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (buffer != 0) {
                img[i][j] = buffer[contador];
                contador++;
            }
        }
    }

    /*for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;*/
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            set_pixel(i,j,orig.get_pixel(i,j));
        }
    }
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

void Image::Destroy(){
    if (!Empty()) {
        for (int i = 0; i < rows; i++) {
            delete[] img[i];
            img[i] = nullptr;
        }
        delete[] img;
    }
    img = nullptr;
}

LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            set_pixel(i, j, value);
        }
    }
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor
Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    if (i < rows && j < cols)
        img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    int i = k%cols;
    int j = k/cols;
    img[i][j] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?
    int i = k%cols;
    int j = k/cols;
    return img[i][j];
}

// Métodos para almacenar y cargar imagenes en disco
bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    byte * p = new byte [rows*cols];
    int contador = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            p[contador] = img[i][j];
            contador++;
        }
    }
    return WritePGMImage(file_path, p, rows, cols);
}

void Image::Invert() {
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            this->set_pixel( i, j, 255 - this->get_pixel(i, j));
}

double Image::Mean (int i, int j, int height, int width) const {
    double media = 0;
    for (int a = i; a < height + i; a++) {
        for (int b = j; b < width + j; b++) {
            media += this->get_pixel(a, b);
        }
    }
    media /= (height * width);
    return media;
}

Image Image::Crop(int nrow, int ncol, int height, int width) const {
    Image fich_rdo(height, width);
    int filas = nrow;
    int columnas = ncol;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fich_rdo.set_pixel(i,j,this->get_pixel(filas, columnas));
            columnas++;
        }
        filas++; columnas = ncol;
    }
    return fich_rdo;
}

Image Image::Zoom2X() const {

    int lado = (this->get_rows()*2)-1;
    Image dest(lado, lado);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest.img[i*2][j*2] = img[i][j];
        }
    } // Matriz sin valores intermedios.

    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            if (j%2!=0) {
                dest.set_pixel(i,j,round((dest.img[i][j-1] + dest.img[i][j+1]) / 2.0));
            }
        }
    }

    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            if (j%2!=0) {
                dest.set_pixel(j,i,round((dest.img[j-1][i] + dest.img[j+1][i]) / 2.0));
            }
        }
    }

    for(int i = 1; i < lado; i+=2) {
        for (int j = 1; j < lado; j+=2) {
            dest.img[i][j] = round((dest.img[i + 1][j + 1] + dest.img[i + 1][j - 1] + dest.img[i - 1][j + 1] + dest.img[i - 1][j - 1]) / 4.0);
        }
    }


    return dest;

}

Image Image::Subsample(int factor) const {
    int filas = rows/factor;
    int columnas = cols/factor;
    Image dest(filas,columnas);

    int a = 0, b = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            dest.set_pixel(i,j, round(this->Mean(a,b,factor,factor)));
            if (b+factor < cols)
                b+=factor; // Idea ir avanzando en la matriz original en orden de factor
            else
                j = columnas;
        }
        b = 0;
        if (a+factor < rows)
            a+=factor;
        else
            i = columnas;
    }

    return dest;
}

void Image::AdjustContrast (byte in1, byte in2, byte out1, byte out2) {
    double max, min, a, b;
    byte resultado;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            byte z = get_pixel(i,j);
            if (0 <= z && z <= in1-1) {
                a=0; b=in1;
                max=out1; min=0;
            }
            if (in1 <= z && z <= in2) {
                a=in1; b=in2;
                max=out2; min=out1;
            }
            if (in2 + 1 <= z && z <= 255) {
                a=in2; b=255;
                max=255; min = out2;
            }
            double constante = (max-min)/(b-a);
            resultado = round(min + (constante*(z-a)));
            this->set_pixel(i,j, resultado);
        }
    }

    // IMPLEMENTACIÓN SIN LÓGICA DE FILAS Y COLUMNAS.
     /*double max, min, a, b;
     byte resultado;
     for (int i = 0; i < rows*cols; i++) {
        byte z = get_pixel(i);
        if (0 <= z && z <= in1-1) {
            a=0; b=in1-1;
            if (out1 > 0)
                max=out1-1;
            min=0;
        }
        if (in1 <= z && z <= in2) {
            a=in1; b=in2;
            max=out2;
            min=out1;
        }
        if (in2 + 1 <= z && z <= 255) {
            a=in2+1; b=255;
            max=255;
            if (out2 < 255)
                min=out2+1;
            else min = out2;
        }
        double constante = (max-min)/(b-a);
        resultado = round(min + (constante*(z-a)));
        this->set_pixel(i, resultado);
    }*/
}

void Image::ShuffleRows() {
    byte ** aux;
    aux= new byte * [rows];
    for (int r=0; r<rows; r++) {
        int newr = r*9973 % get_rows();
        aux[r] = img[newr];
    }
    delete [] img;
    img = aux;
}