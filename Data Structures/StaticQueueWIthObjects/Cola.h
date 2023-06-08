#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include"ColaExcepcion.h"

///DEFINICION DE CLASE///////////////
template <class T, int ARRAYSIZE = 1024> ///Asignacion del tamaño de la Cola
class Cola {
    private:
        T dato[ARRAYSIZE];
        int posFrente; ///Posicion del frente y del final
        int posFinal;

        void copyAll(const Cola&); ///Metodo para copiar
    public:
        Cola(); ///Constructor
        Cola(const Cola&); ///Constructor copia

        bool estaVacia(); ///Booleanos para verificar si esta vacia o llena
        bool estaLLena();

        void encolar (const T&); ///Metodo para insertar (encolar)

        T desencolar(); ///Metodo para eliminar (desencolar)
        T getFrente(); ///Metodo para obtener el dato de el frente

        std::string toString(); ///Funcion para imprimir los elementos

        Cola& operator = (const Cola&); ///Sobrecarga de operador igual para copiar
};

using namespace std;
///METODOS//////////////////////////
template <class T, int ARRAYSIZE>
void Cola<T, ARRAYSIZE>::copyAll(const Cola<T, ARRAYSIZE>& cola1) {
    int aux(cola1.posFrente);

    posFinal=cola1.posFinal; ///Aqui se copia de la cola actual a la cola nueva su frente i final
    posFrente=cola1.posFrente;

    while(aux != cola1.posFinal + 1) { ///Aqui se copian los datos
        dato[aux] = cola1.dato[aux];
        aux++;

        if(aux==ARRAYSIZE) {
            aux = 0;
        }
    }
}

///CONSTRUCTOR-----------------------------------------------------
template <class T, int ARRAYSIZE> ///Inicializamos la cola con el frente en 0 y el final en la posicion total del arreglo menos uno
Cola<T, ARRAYSIZE>::Cola() : posFrente(0), posFinal(ARRAYSIZE - 1) { }

///CopyAll
template <class T, int ARRAYSIZE>
Cola<T, ARRAYSIZE>::Cola(const Cola<T, ARRAYSIZE>& cola1) {
    copyAll(cola1);
}

///VACIA-----------------------------------------------------------
template <class T, int ARRAYSIZE>
bool Cola<T, ARRAYSIZE>::estaVacia() {
    return posFrente == posFinal+1 ///La cola esta vacia si el frente es igual a la posicion final + 1
            or (posFrente == 0 and posFinal == ARRAYSIZE-1); //o cuando el frente es 0 y la posicion final es el tamaño del arreglo menos uno
}

///LLENA-----------------------------------------------------------
template <class T, int ARRAYSIZE>
bool Cola<T, ARRAYSIZE>::estaLLena() {
    return posFrente == posFinal + 2 ///La cola esta llena cuando el frente es igual al final mas 2
            or (posFrente == 0 and posFinal == ARRAYSIZE + 2) ///o el frente es 0 y el final es el tamaño total mas 2
            or (posFrente == 1 and posFinal == ARRAYSIZE - 1); // o el frente es uno y la posicion final es el tamaño total menos uno
}

///ENCOLAR ---------------------------------------------------------
template <class T, int ARRAYSIZE>
void Cola<T, ARRAYSIZE>::encolar(const T& elemento) { ///Recibe la cola (internamente) y el elemento a encolar
    if(estaLLena()) { ///Si esta llena. arroja una excepcion (error)
        throw ColaExcepcion("Desbordamiendo de datos, encolar");
    }
    if(++posFinal == ARRAYSIZE) { ///Si al aumentar la posicion final. esta se iguala al tamaño total del arreglo. este pasa a ser 0
        posFinal =0;
    }

    dato[posFinal] = elemento; ///Si no. el elemento en la posicion final sera igual al elemento que recibio

    /*Otra manera podria ser:
    dato[posFinal = ++posFinal == ARRAYSIZE ? 0 : endPos] = elemento*/
}

///DESENCOLADO---------------------------------------------------------
template <class T, int ARRAYSIZE>
T Cola<T, ARRAYSIZE>::desencolar() {
    if(estaVacia()) {
        throw ColaExcepcion("Insuficiencia de datos, desencolar");
    }
    T resultado(dato[posFrente]);///Declaramos tipo de dato T i se iguala al dato que hay en el frente

    if(++posFrente == ARRAYSIZE) { ///Si al aumentar el frente es igual al tamaño maximo. el frente pasa a ser 0
        posFrente = 0;
    }

    return resultado; ///Regresa ese elemento desencolado. el cual si se quiere saber cual era. se puede hacer con un toString
}

///GET_FRENTE------------------------------------------------------------
template <class T, int ARRAYSIZE>
T Cola<T, ARRAYSIZE>::getFrente() {
    if(estaVacia()) {
        throw ColaExcepcion("Insuficiencia de datos,getFrente");
    }
    return dato[posFrente]; ///Solo regresa el dato en la posicion de frente
}

///IMPRIMIR-----------------------------------------------------------------
template <class T, int ARRAYSIZE>
string Cola<T, ARRAYSIZE>::toString() {
   /* string resultado;
    int aux(0);
    int aux2(ARRAYSIZE);
    while(aux <= posFinal) {
        resultado += dato[aux].toString() + "\n-------------------";
        aux++;
    }

    return resultado;*/
    string impresion;

    int aux(posFrente); ///Se inicializa un auxiliar en la posicion del frente
    int limite = posFinal + 1; ///Un limite en la posicion final + 1
    if(posFinal == ARRAYSIZE - 1) { ///Si esa posicion final es igual a el tamaño completo menos 1. el limite pasa a ser 0
        limite = 0;
    }
    while(!estaVacia() && (aux != limite)) { ///Mientras no este vacia y el auxiliar no sea el limite
        impresion+= dato[aux].toString() + "\n------------------ "; ///Se hace la concatenacion de los datos
        aux++;
        if(aux == ARRAYSIZE) {
            aux = 0; ///Si el auxiliar llega a ser igual al tamaño. el auxiliar lo pasamos a 0
        }
    }
    return impresion; ///Regresamos ya todos los elementos de la lista
}


template <class T, int ARRAYSIZE>
Cola<T, ARRAYSIZE>& Cola<T, ARRAYSIZE>::operator=(const Cola<T, ARRAYSIZE>& cola1) {
    copyAll(cola1);
}

#endif // COLA_H_INCLUDED
