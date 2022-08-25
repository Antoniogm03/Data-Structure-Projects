/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include <iostream>
#include <stack>
#include "maxqueue.h"

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

bool MaxQueue::empty() const {
    return elements_stack.empty();
}

int MaxQueue::size() const {
    return elements_stack.size();
}

void MaxQueue::push (int val) {
    element a;
    a.setValue(val);
    stack<element> aux;
    if (elements_stack.empty()) {
        a.setMax(val);
    } else {
        if (elements_stack.top().getMax() < val) {
            a.setMax(val);
            while(!elements_stack.empty()) {
                if (elements_stack.top().getMax() < val) {
                    elements_stack.top().setMax(val);
                }
                aux.push(elements_stack.top());
                elements_stack.pop();
            }
            while(!aux.empty()) {
                elements_stack.push(aux.top());
                aux.pop();
            }
        } else {
            a.setMax(val);
        }
    }
    elements_stack.push(a);
}

void MaxQueue::pop() {
    stack<element> aux;
    while (elements_stack.size() > 1) {
        aux.push(elements_stack.top());
        elements_stack.pop();
    }
    elements_stack.pop();
    while (!aux.empty()) {
        elements_stack.push(aux.top());
        aux.pop();
    }
}

element MaxQueue::front() {
    stack<element> aux;
    while (!elements_stack.empty()) {
        aux.push(elements_stack.top());
        elements_stack.pop();
    }
    element elemento = aux.top();
    while (!aux.empty()) {
        elements_stack.push(aux.top());
        aux.pop();
    }
    return elemento;
}

element MaxQueue::back() {
    return elements_stack.top();
}

const element MaxQueue::back() const {
    return elements_stack.top();
}

ostream & operator<<(ostream & flujo, element a) {
    flujo << a.getValue() << "," << a.getMax();
    return flujo;
}

ostream & operator<<(ostream & flujo, MaxQueue & a) {
    MaxQueue aux;
    while (!a.empty()) {
        aux.push(a.front().getValue());
        a.pop();
    }
    if (!aux.empty()) {
        while (!aux.empty()) {
            flujo << aux.front() << endl;
            a.push(aux.front().getValue());
            aux.pop();
        }
    } else {
        flujo << "Está  vacia" << endl;
    }
    return flujo;
}