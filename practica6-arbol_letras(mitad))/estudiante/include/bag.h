#ifndef __BAG_H__
#define __BAG_H__

#include <vector>
#include <cstdlib>
#include <ctime>

template <class T>

/**
 *  @brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */
class Bag {
private:
    std::vector<T> v;
public:
    /**
     * @brief Añade un elemento a la bolsa.
     * @tparam element elemento del tipo T a añadir a la bolsa.
     */
    void add(const T & element){
        v.push_back(element);
    }

    /**
     * @brief Extrae un elemento aleatorio de la bolsa.
     *
     * Devuelve un elemento aleatorio de la bolsa y lo elimina de la misma.
     * @return Elemento de tipo T extraido de la bolsa.
     * @pre La bolsa no está vacía.
     * @post El elemento devuelto se ha eliminado de la bolsa.
     */
    T get(){
        srand(time(NULL));
        T val;
        if (!v.empty()) {
            int ind = rand()%size();
            val = v[ind];
            v[ind] = v[v.size()-1];
            v.pop_back();
            return val;
        }
    }

    /**
     * @brief Elimina todos los elementos de la bolsa.
     *
     * Borra todos los elementos almacenados en la bolsa.
     */
    void clear(){
        v.clear();
    }

    /**
     * @brief Tamaño de la bolsa.
     * @return Número de elementos que hay en la bolsa.
     */
    unsigned int size() const{
        return v.size();
    }

    /**
     * @brief Comprueba que la bolsa está vacía.
     * @return Si la bolsa está vacía.
     */
    bool empty(){
        return v.empty();
    }

    /**
     * @brief Sobrecarga el operador de asignación
     * @param other Bag<T> a copiar.
     * @return Referencia a this para poder encadenar el operador.
     */
    const Bag<T> & operator=(const Bag<T> & other){
        v = other.v;
        return *this;
    }

};

#endif
