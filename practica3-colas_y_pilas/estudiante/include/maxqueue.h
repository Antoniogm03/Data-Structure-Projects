/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Antonio Rodríguez Rodríguez y José Antonio Carmona Molina.
 */

#include <iostream>
#include <stack>

struct element {
private:

    int value;
    int maximum;

public:

    /**
     * @brief Nos muestra value
     * @return value
     */
    int getValue();

    /**
     * @brief Inserta un valor
     * @param val Entero a insertar.
     */
    void setValue(int val);

    /**
     * @brief Nos muestra maximum
     * @return maximum
     */
    int getMax();

    /**
     * @brief Introduce el máximo
     * @param max Méximo a introducir.
     */
    void setMax(int max);
};

class MaxQueue {
private:

    std::stack<element> elements_stack;

public:

     /**
     * @brief Comprueba si la cola está vacía.
     * @return Si está vacía.
      */
    bool empty() const;

    /**
     * @brief Devuelve el número de elementos de la cola.
     * @return Número de elementos de la cola.
     */
    int size() const;

    /**
     * @brief Inserta un elemento en la cola.
     * @param val Elemento a insertar.
     */
    void push (int val);

    /**
     * @brief Elimina el elemento de la cola.
     */
    void pop();

    /**
     * @brief Consulta el elemento posterior de la cola.
     * @return Elemento posterior.
     */
    element back();

    /**
     * @brief Consulta el elemento posterior de la cola.
     * @return Elemento posterior.
     */
    const element back() const;

    /**
     * @brief Consulta el elemetno anterior de la cola.
     * @return Elemento anterior.
     */
    element front();
};

/**
 * @brief Operador de impresión para element.
 * @param flujo Flujo de salida
 * @param a element a imprimir
 * @return Salida
 */
std::ostream & operator<<(std::ostream & flujo, element a);

/**
 * @brief Operador de impresión para la coal.
 * @param flujo Flujo de salida.
 * @param a Cola a imprimir.
 * @return Salida.
 */
std::ostream & operator<<(std::ostream & flujo, MaxQueue &a);