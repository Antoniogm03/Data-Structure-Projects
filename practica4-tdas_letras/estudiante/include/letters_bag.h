#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"
#include <vector>

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */
class LettersBag {
private:
    Bag<char> letters;
public:
    /**
     * @brief Constructor por defecto.
     */
    LettersBag();

    /**
     * @brief Constructor dado un LettersSet.
     *
     * Dado un LettersSet como argumento debe rellenar la LettersBag con las letras que contiene el LettersSet, introduciendo cada letra el número de veces indicado por el campo LetterInfo::repetitions. Un ejemplo de ejecución en el que se utilice este constructor es el siguiente:
     * @image html EjemploDoxygen1.png
     * @param lettersBag TDA LettersSet a parsear.
     */
    LettersBag(const LettersSet & letterset);

    /**
     * @brief Introduce una letra en la bolsa.
     * @param I letra a añadir a la LettersBag.
     */
    void insertLetter(const char & I);

    /**
     * @brief Extrae una letra aleatoriamente de la bolsa, eliminándola del conjunto.
     * @return char representa la letra extraída.
     */
    char extractLetter();

    /**
     * @brief Extrae un conjunto de letras eliminándolas del conjunto.
     * @param num Número de letras a extraer.
     * @return Lista con letras extraídas aleatoriamente.
     */
    std::vector<char> extractLetters(int num);

    /**
     * @brief Vacía la LettersBag, eliminando el contenido de la misma.
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa.
     * @return int con el tamaño de la bolsa.
     */
    unsigned int size() const;

    /**
     * @brief Sobrecarga el operador de asignación.
     * @param other LettersBag a copiar.
     * @return Referencia a this de esta forma el operador puede ser encadenado.
     */
    LettersBag & operator=(const LettersBag & other);
};

#endif
