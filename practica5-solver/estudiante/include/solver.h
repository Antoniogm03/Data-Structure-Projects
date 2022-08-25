#include "dictionary.h"
#include "letters_set.h"

/**
 *   \file solver.h
 *   \brief Archivo de declaración de la clase Solver
 */
class Solver {
private:
    Dictionary dictionary;
    LettersSet lettersset;
    pair<set<string>, int> solutions;
public:

    /**
     * @brief Constructor por parámetros.
     *
     * Crea un Solver que tiene asociado un Dictionary y un LettersSet.
     * @param dict Dictionary a asociar.
     * @param letters_set LettersSet a asociar.
     */
    Solver(const Dictionary & dict, const LettersSet & letters_set);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una partida.
     *
     * @param available_letters Vector de letras disponibles para la partida.
     * @param score_game Bool indicando el tipo de partida. True indica que la partida se juega a puntuació, false que se juega a longitud.
     * @return Par <vector<string>, int>, con el vector de palabras que constituyen las mejores soluciones (puede haber empates) y la puntuación que obtienen.
     */
    pair<set<string>, int> getSolutions(const vector<char> & available_letters, bool score_game);

    /**
     * @brief Da la solución para una partida por longitud.
     * @param available_letters Vector de letras disponibles para la partida.
     * @return Par <vector<string>, int>, con el vector de palabras que constituyen las mejores soluciones (puede haber empates) y la puntuación que obtienen.
     */
    pair<set<string>, int> LenghtSolution(const vector<char> & available_letters);

    /**
     * @brief Da la solución para una partida por longitud.
     * @param available_letters Vector de letras disponibles para la partida.
     * @return Par <vector<string>, int>, con el vector de palabras que constituyen las mejores soluciones (puede haber empates) y la puntuación que obtienen.
     */
    pair<set<string>, int> ScoreSolution(const vector<char> & available_letters);

    /**
     * @brief Genera un vector con las palabras validas a partir del diccionario.
     * @param available_letters vector cuyo tamaño nos indicará las longitudes posibles y cuyos elementos nos permitirá saber si una palabra es válida.
     * @return Vector con las palabras validas.
     */
    vector<string> VectorPalabras(const vector<char> &available_letters) const;

    /**
     * @brief Comprueba si la palabra formada con las letras del vector existe en el diccionario mediante búsqueda binaria.
     * @param available_letters Vector que contiene las letras que se han sacado de la bolsa.
     * @return Si es válida.
     */
    bool isValid(vector<char> available_letters, string aux) const;

    /**
     * @brief Función que pasa de vector<string> a set<string>
     * @param a <vector<string> a pasar a vector.
     * @return Devuelve el set<string> correspondiente.
     */
    set<string> VectortoSet(const vector<string> & a);
};