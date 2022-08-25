/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author Antonio Rodríguez Rodríguez y José Antonio Carmona Molina.
 */

#include <iostream>
#include <queue>
#include "maxstack.h"

using namespace std;

int element::getValue() {
    return value;
}

int element::getMax() {
    return maximum;
}

void element::setValue(int val) {
    value = val;
}

void element::setMax(int max) {
    maximum = max;
}

bool MaxStack::empty() const {
    return elements_queue.empty();
}

int MaxStack::size() const {
    return elements_queue.size();
}

void MaxStack::push(int val) {
    element aux;
    aux.setValue(val);
    if (elements_queue.empty()) {
        aux.setMax(val);
    } else {
        if (elements_queue.back().getMax() < val)
            aux.setMax(val);
        else
            aux.setMax(elements_queue.back().getMax());
    }
    elements_queue.push(aux);
}

void MaxStack::pop() {
    queue<element> aux;
    while (elements_queue.size() > 1) {
        aux.push(elements_queue.front());
        elements_queue.pop();
    }
    elements_queue.pop();
    while (!aux.empty()) {
        elements_queue.push(aux.front());
        aux.pop();
    }
}

element MaxStack::top() {
    return elements_queue.back();
}

const element MaxStack::top() const {
    return elements_queue.back();
}

ostream & operator<<(ostream & flujo, element a) {
    flujo << a.getValue() << "," << a.getMax();
    return flujo;
}

ostream & operator<<(ostream & flujo, MaxStack & a) {
    if (!a.empty()) {
        while (!a.empty()) {
            flujo << a.top() << endl;
            a.pop(); // Esto borraría el objeto.
        }
    } else {
        flujo << "Está  vacia" << endl;
    }
    return flujo;
}
