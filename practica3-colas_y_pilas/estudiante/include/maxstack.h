/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Antonio Rodríguez Rodríguez y José Antonio Carmona Molina.
 */

#include <queue>

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

class MaxStack {
private:

    std::queue<element> elements_queue;

public:

    /**
     * @brief Comprueba si la pila está vacía.
     * @return Si está vacía.
     */
    bool empty() const;

    /**
     * @brief Devuelve el número de elementos de la pila.
     * @return Número de elementos de la pila.
     */
    int size() const;

    /**
     * @brief Inserta un elemento en la pila.
     * @param val Elemento a insertar.
     */
    void push (int val);

    /**
     * @brief Elimina el elemento superior de la pila.
     */
    void pop();

    /**
     * @brief Consulta el elemento superior de la pila.
     * @return Elemento superior.
     */
    element top();

    /**
     * @brief Consulta el elemento superior de la pila.
     * @return Elemento superior.
     */
    const element top() const;
};

/**
 * @brief Operador de impresión para element.
 * @param flujo Flujo de salida
 * @param a element a imprimir
 * @return Salida
 */
std::ostream & operator<<(std::ostream & flujo, element a);

/**
 * @brief Operador de impresión para la pila.
 * @param flujo Flujo de salida.
 * @param a Pila a imprimir.
 * @return Salida.
 */
std::ostream & operator<<(std::ostream & flujo, MaxStack &a);