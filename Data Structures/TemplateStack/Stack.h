#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "StackException.h"
#include <cstdlib>
#include<string>

template <class T, int ARRAYSIZE = 1024>
class Stack {
  private:
    T data[ARRAYSIZE];
    int top;
    void copyAll(const Stack<T, ARRAYSIZE>&);

  public:
    Stack();
    Stack(const Stack<T, ARRAYSIZE>&);

    bool isEmpty();
    bool isFull();
    std::string toString();
    std::string toStringNumbers();

    void pushStack(const T&);
    T popStack();
    T getTop();

    Stack<T, ARRAYSIZE>& operator = (const Stack<T, ARRAYSIZE>&);
};
using namespace std;

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& pila1) {
    int aux(0);
    while(aux <= pila1.top) {
        this->data[aux] = pila1.data[aux];
        aux++;
    }
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) {}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE>& pila1) {
    copyAll(pila1);
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() {
    return top == -1;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() {
    return top == ARRAYSIZE;

}

template <class T, int ARRAYSIZE>
string Stack<T, ARRAYSIZE>::toString() {
    string resultado;
    int aux(0);
    while(aux <= top) {
        resultado += data[aux].toString() + "\n";
        aux++;
    }

    return resultado;
}
template <class T, int ARRAYSIZE>
string Stack<T, ARRAYSIZE>::toStringNumbers() {
    string impresion;

    int aux(0);
    while(aux <= top) {
        impresion+= to_string(data[aux]) + "\n ";

        aux++;
    }

    return impresion;
}



template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::pushStack(const T& elemento) {
    if(isFull()) {
        throw StackException("Desbordamiento de datos, push");
    }
    top++;

    data[top] = elemento;
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::popStack() {
    if(isEmpty()) {
        throw StackException("Insuficiencia de datos, pop");
    }
    return data[top--];
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() {
    if(isEmpty()) {
        throw StackException("Insuficiencia de datos, getTop");
    }

    return data[top];
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator=(const Stack<T, ARRAYSIZE>&pila1) {
    copyAll(pila1);

    return *this;
}



#endif // STACK_H_INCLUDED
