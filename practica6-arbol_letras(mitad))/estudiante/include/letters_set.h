#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
 struct LetterInfo {
     /**
      * @brief Número de veces que puede repetirse la letra.
      */
    int repetitions;

    /**
     * @brief Puntuación de la letra.
     */
    int score;
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */
 class LettersSet {
 private:
     map <char, LetterInfo> letters;
 public:
     /**
      * @brief Constructor por defecto.
      *
      * Crea un LettersSet vacío.
      */
     LettersSet();

     /**
      * @brief Constructor por copia.
      * @param c LettersSet a copiar.
      */
     LettersSet(const LettersSet & c);

     /**
      * @brief Inserta un elemento en el LettersSet.
      * @param val Pareja de letra y LetterInfo asociada a insertar.
      * @return Booleano que marca si se ha podido insertar la letra en el LettersSet. La letra sólo se inserta correctamente si no estaba aún incluida en la colección.
      */
     bool insert(const pair <char, LetterInfo> & val);

     /**
      * @brief Elimina un carácter del LettersSet.
      * @param key Carácter a eliminar.
      * @return Booleano que indica si se ha podido eliminar correctamente la letra del LettersSet.
      */
     bool erase(const char & key);

     /**
      * @brief Limpia el contenido del LettersSet.
      * @return
      */
     void clear();

     /**
      * @brief Consulta si el LettersSet está vacío.
      * @return si el LettersSet está vacío.
      */
     bool empty() const;

     /**
      * @brief Tamaño del LettersSet.
      * @return Número de elementos del LettersSet.
      */
     unsigned int size() const;

     /**
      * @brief Calcula la puntuación dada una palabra.
      * @param word string con la palabra cuya puntuación queremos calcular.
      * @return Puntuación de la palabra calculada como la suma de las puntuaciones de cada una de sus letras.
      */
     int getScore(string & word);

     /**
      * @brief Sobrecarga el operador de asignacion.
      * @param cl LettersSet a copiar.
      * @return Referencia al objeto this para poder encadenar el operador.
      */
     LettersSet & operator=(const LettersSet & cl);

     /**
      * @brief Sobrecarga el operador de consulta.
      * @param val Caracter a consultar.
      * @return Estructura tipo LetterInfo con la informacion de caracter consultado: Numero de repeticiones y puntuacion.
      */
     LetterInfo & operator[](const char & val);

     /**
  * @brief Iterador de la clase
  */
     class iterator{
     private:
         map<char, LetterInfo>::iterator it;
     public:
         iterator(){}
         iterator(const map<char, LetterInfo>::iterator& other): it(other){}
         iterator(const iterator& other):it(other.it){}
         ~iterator(){}
         iterator& operator=(const map<char, LetterInfo>::iterator& other){ it=other;return *this;}
         iterator& operator=(const iterator& other){it=other.it;return *this;}
         const pair<char, LetterInfo> operator*()const{return *it;}
         iterator& operator++(){++it;return *this;}
         iterator& operator--(){--it;return *this;}
         iterator& operator++(int){it++;return *this;}
         iterator& operator--(int){it--;return *this;}
         bool operator!=(const iterator& other){return it != other.it;}
         bool operator==(const iterator& other){return it == other.it;}
     };

     /**
      * @brief Iterador constante de la clase
      */
     class const_iterator{
     private:
         map<char, LetterInfo>::const_iterator const_it;
     public:
         const_iterator(){}
         const_iterator(const map<char, LetterInfo>::const_iterator& other): const_it(other){}
         const_iterator(const const_iterator& other):const_it(other.const_it){}
         ~const_iterator(){}
         const_iterator& operator=(const map<char, LetterInfo>::const_iterator& other){ const_it = other;return *this;}
         const_iterator& operator=(const const_iterator& other){const_it = other.const_it;return *this;}
         const pair<char, LetterInfo> operator*()const{return *const_it;}
         const_iterator& operator++(){++const_it;return *this;}
         const_iterator& operator--(){--const_it;return *this;}
         const_iterator& operator++(int){const_it++;return *this;}
         const_iterator& operator--(int){const_it--;return *this;}
         bool operator!=(const const_iterator& other){return const_it != other.const_it;}
         bool operator==(const const_iterator& other){return const_it == other.const_it;}
     };

     iterator begin(){iterator i = letters.begin();return i;}
     iterator end(){iterator i = letters.end();return i;}
     const_iterator begin()const{const_iterator i = letters.begin();return i;}
     const_iterator end()const{const_iterator i = letters.end();return i;}

     friend ostream & operator<<(ostream & os, const LettersSet & cl);
     friend istream & operator>>(istream & is, LettersSet & cl);
 };

/**
     * @brief Sobrecarga el operador de salida
     * @param os Flujo de salida, donde escribir el LettersSet.
     * @param cl LettersSet que se escribe.
     * @return
     */
ostream & operator<<(ostream & os, const LettersSet & cl);

/**
 * @brief Sobrecarga el operador de entrada
 * @param is Flujo de entrada, del que leer el LettersSet.
 * @param cl LettersSet en el que se va a almacenar la informacion leida.
 * @return
 */
istream & operator>>(istream & is, LettersSet & cl);

#endif

