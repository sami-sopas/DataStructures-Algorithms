#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include"PilaExcepcion.h"
#include<cstdlib>
#include<string>
#include"album.h"

template <class T, int ARRAYSIZE = 1024> ///Asignacion del tamaño de la pila. y uso de templates para manejar todo tipo de datos
class Pila {
    private:
        T dato[ARRAYSIZE]; ///el dato que manejara y su tamaño
        int tope; ///Tope (ultimo elemento)
        void copyAll(const Pila<T, ARRAYSIZE>&); ///Funcion para copiar

    public:
        Pila(); ///Constructor
        Pila(const Pila<T, ARRAYSIZE>&); ///Constructor copia

        bool estaVacia(); ///Booleanos para verificar si esta vacia o llena la pila
        bool estaLLena();

        string toString(); ///Imprimir todo lo que hay en la pila

        void pushPila(const T&); ///Push (insertar) Recibe el elemento
        T popPila(); /// Pop (eliminar)
        T getTope(); ///Tope (Obtener el elemento que hay en el tope)

        Pila<T, ARRAYSIZE>& operator = (const Pila<T, ARRAYSIZE>&); ///Sobrecarga de constructor para copiar
};

using namespace std;

template <class T, int ARRAYSIZE> ///CopyAll-----------------------------
void Pila<T, ARRAYSIZE>::copyAll(const Pila<T, ARRAYSIZE>& pila1) {
    int aux(0);
    while(aux <= pila1.tope) {
        this->dato[aux] = pila1.dato[aux]; //Se hace el copiado de la pila actual a la pila que recibe en la misma posicion
        aux++;
    }
}

template <class T, int ARRAYSIZE>///Constructor-----------------------
Pila<T, ARRAYSIZE>::Pila() : tope(-1) {} ///Aqui se inicializa la pila con el tope en la posicion -1

template <class T, int ARRAYSIZE>
Pila<T, ARRAYSIZE>::Pila(const Pila<T, ARRAYSIZE>& pila1) {
    copyAll(pila1);
}

template <class T, int ARRAYSIZE>///Vacia---------------------------
bool Pila<T, ARRAYSIZE>::estaVacia() {
    return tope == -1; /// Si el tope esta en -1. esto quiere decir que esta vacia y regresa true
}

template <class T, int ARRAYSIZE>
bool Pila<T, ARRAYSIZE>::estaLLena() {//LLena----------------------
    return tope == ARRAYSIZE; ///Si el tope es igual a el tamaño total del arreglo, esto quiere decir que llego a el limite (llena)

}

template <class T, int ARRAYSIZE> ///ToString----------------------
string Pila<T, ARRAYSIZE>::toString() {
    string resultado;
    int aux(0);
    while(aux <= tope) { //Se recorre la pila desde 0 hasta el tope
        resultado += dato[aux].toString() + "\n"; //Aqui se concatenan todas las cadenas
        aux++;
    }

    return resultado; //Se regresa todo el resultado
}

template <class T, int ARRAYSIZE>///Push---------------------------------------
void Pila<T, ARRAYSIZE>::pushPila(const T& elemento) {
    if(estaLLena()) { ///Primero se verifica si la pila esta llena
        throw PilaExcepcion("Desbordamiento de datos, push");
    }
    ///Si no es el caso. primero aumentamos el tope
    tope++;

    dato[tope] = elemento; ///y el elemnto que recibio se coloca en esa posicion (tope)
}

template <class T, int ARRAYSIZE>///Pop-------------------------
T Pila<T, ARRAYSIZE>::popPila() {
    if(estaVacia()) { ///Arroja un error si se hace pop con la pila vacia
        throw PilaExcepcion("Insuficiencia de datos, pop");
    }
    return dato[tope--]; ///se reduce el tope y regresa ese dato
}

template <class T, int ARRAYSIZE> ///Tope-----------------------
T Pila<T, ARRAYSIZE>::getTope() {
    if(estaVacia()) {
        throw PilaExcepcion("Insuficiencia de datos, gettope");
    }

    return dato[tope]; ///Regresa el dato que esta en la posicion del tope (la ultima que se inserto)
}

template <class T, int ARRAYSIZE>
Pila<T, ARRAYSIZE>& Pila<T, ARRAYSIZE>::operator=(const Pila<T, ARRAYSIZE>&pila1) {
    copyAll(pila1);

    return *this;
}



#endif // PILA_H_INCLUDED
