#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include"ListaExcepcion.h"
#include<cstdlib>
#include<string>
#include"album.h"

using namespace std;

/** Se hace uso de Templates, para que la lista pueda manejar datos
     de tipo T, es decir, objetos, enteros cadenas etc. **/

template <class T, int ARRAYSIZE = 1024> //Aqui se le asigna un tamaño (ya que es estatico)
class Lista{
    private:
        T dato[ARRAYSIZE]; ///Datos. Esta lista manejara principalmente Objetos tipo Album
        int ultimo; ///Variable para saber cual es el ultimo elemento que hay dentro de la lista

        bool esPosicionValida(const int&); ///Booleano que recibe una posicion y determinara si es una posicion valida o no

        void copyAll(const Lista<T, ARRAYSIZE>&); ///Metodo para copiar de una lista a otra

    public:
        Lista(); ///Constructor
        Lista(const Lista<T, ARRAYSIZE>&); ///Constructor copia parametrizado

        bool estaVacia(); ///Booleano para verificar si esta vacia
        bool estaLLena(); ///Booleano para verificar si esta llena

        void insertarDato(const int&, const T&); ///Recibe una posicion y un elemento
        void borrarDato(const int&); ///Recibe la posicion de donde se borrara

        int getPrimeraPos(); ///Regresa la primera posicion de la lista. error si esta vacia
        int getUltimaPos(); ///Regresa la ultima posicion de la lista
        int getPreviaPos(const int&);///Reciben una posicion, y regresa la anterior a esa
        int getSiguientePos(const int&); ///Recibe una posicion y regresa la siguiente de esa

        T& recuperarDato(const int&); ///Recibe la posicion y regresa el elemento (T)

        string toString(); ///Imprime todos los elementos que tenga la lista

        void borrarTodo(); ///Deja la lista vacia

        Lista<T, ARRAYSIZE>& operator = (const Lista <T, ARRAYSIZE>&); ///Sobrecarga del operador =

};

///METODOS PRIVADOS////////////////////////////////////////////

/** VERIFICAR SI LA POSICION ES VALIDA
Recibe una posicion. es valida si es mayor o igual a 0 o
si es menor o igual a la la posicion en donde esta el ultimo elemento **/
template <class T, int ARRAYSIZE>
bool Lista<T, ARRAYSIZE>::esPosicionValida(const int& posicion)
{
    return posicion >= 0 and posicion <= ultimo;
}

/**COPIAR LISTA
No regresa nada, recibe una lista. mediante un auxiliar inicializado en 0. Se recorre mientras sea
igual o menor al ultimo elemento de la lista. Los datos de la lista en la posicion auxiliar se copian a los datos de la nueva lista
en la misma posicion. se aumenta el auxiliar para poder copiar todos los elementos. esto gracias a la sobrecarga antes hecha
por ultimo. el ultimo elemento se iguala al ultimo de la nueva lista **/
template <class T, int ARRAYSIZE>///Copiar lista
void Lista<T, ARRAYSIZE>::copyAll(const Lista<T, ARRAYSIZE>& lista)
{
    int aux(0);

    while(aux <= lista.ultimo){
        dato[aux] = lista.dato[aux];
        aux++;
    }
    ultimo = lista.ultimo;
}

///METODOS PUBLICOS////////////////////////////////////////////////////////////

template <class T, int ARRAYSIZE> ///Constructor-------------------------------
Lista<T, ARRAYSIZE>::Lista() : ultimo(-1) {} ///Se inicializa la lista con el ultimo en la posicion -1 (vacia)

template <class T, int ARRAYSIZE>///Constructor copia--------------------------
Lista<T, ARRAYSIZE>::Lista(const Lista<T, ARRAYSIZE>& lista)
{
    copyAll(lista);
}

template <class T, int ARRAYSIZE>///Si esta vacia la lista---------------------
bool Lista<T, ARRAYSIZE>::estaVacia()
{
    return ultimo == - 1; /** Revisa el ultimo elemento. Si este es igual a -1 (Posicion invalida)
                               regresa true es decir, que si esta vacia, si no false **/
}

template <class T, int ARRAYSIZE>///Si esta llena la lista----------------------
bool Lista<T, ARRAYSIZE>::estaLLena()
{
    return ultimo == ARRAYSIZE - 1; /** Si el ultimo es igual a el tamaño del arreglo menos 1
                                         esto quiere decir que la lista esta llena. regresa true, caso contrario, false **/
}

template <class T, int ARRAYSIZE>///Insertar Dato--------------------------------
void Lista<T, ARRAYSIZE>::insertarDato(const int& posicion, const T& elemento) ///Recibe posicion, elemento y la lista(internamente)
{
    if(estaLLena()) {
        throw ListaExcepcion("Desbordamiento de datos en InsertarDato");
    }
    if(posicion != -1 and !esPosicionValida(posicion)) {
        throw ListaExcepcion("Posicion invalida en InsertarDato");
    }

    int aux(ultimo); ///Variable auxiliar se iguala al ultimo elemento de la lista

    while( aux > posicion) { //Mientras aux sea mayor que la posicion dada
        dato[aux + 1] = dato[aux]; //Los datos en la posicion aux mas uno seran iguales a los de la posicion aux

        aux--; //Se disminuye el auxiliar. ya que se va iterando de ultimo a la posicion que dio
    }
    dato[posicion + 1] = elemento; //Finalmente el dato en la posicion que se dio mas 1 se igualo al elemento recibido
    ultimo++; //Se aumenta el ultimo ya que se termino de insertar la informacion

}

template <class T, int ARRAYSIZE> ///Eliminar Dato------------------------------
void Lista<T, ARRAYSIZE>::borrarDato(const int& posicion)
{
    if(!esPosicionValida(posicion)) { //Primero se valida que la posicion que se recibe sea valida
        throw ListaExcepcion("Posicion invalida en borrar dato");
    }

    int aux(posicion); ///Variable auxiliar igualada a la posicion que recibio

    while(aux < ultimo) { //Mientras el auxiliar sea menor que la ultima posicion
        dato[aux] = dato[aux + 1];  //se van copiando los datos

        aux++; //Aumenta el auxiliar para que se le pueda darle fin al ciclo while
    }
    ultimo--; //Ya que se elimino. el ultimo disminuye ya que se libero un posicion
}

template <class T, int ARRAYSIZE>///Primera pos------------------------------------
int Lista<T, ARRAYSIZE>::getPrimeraPos()
{
    if(estaVacia()) {
        return -1; ///Si la lista esta vacia. regresa un -1, ya que este es por definicion una posicion invalida
    }
    return 0; ///Si es una posicion valida. solo regresa 0 porque esa seria la posicion del primer elemento
}

template <class T,int ARRAYSIZE>///Ultima pos---------------------------------------
int Lista<T,ARRAYSIZE>::getUltimaPos()
{
    return ultimo; ///Regresa la posicion del ultimo elemento de la lista
}

template <class T,int ARRAYSIZE>///Posicion antes-----------------------------------
int Lista<T,ARRAYSIZE>::getPreviaPos(const int& posicion)
{
    if(posicion == getPrimeraPos() or !esPosicionValida(posicion)){
        return -1; ///Si la posicion es la misma que la primera o si no es valida. Regresa -1, es decir posicion invalida
    }

    return posicion - 1; ///Si no es el caso. entonces se regresa la posicion que me dio menos 1 (la anterior)
}

template <class T,int ARRAYSIZE>///Posicion despues-----------------------------------
int Lista<T,ARRAYSIZE>::getSiguientePos(const int& posicion)
{
    if(posicion == getUltimaPos() or !esPosicionValida(posicion)) {
        return -1; ///Si la posicion que me dio es igual que la ultima o no es una posicion valida. Regresa -1 (Posicion invalida)
    }
    return posicion + 1; ///Si la posicion es valida, regresa la pos que me dio + 1 (la siguiente)
}

template <class T, int ARRAYSIZE>///Recuperar el elemento dada una posicion-----------
T& Lista<T, ARRAYSIZE>::recuperarDato(const int& posicion)
{
    if(!esPosicionValida(posicion)) {
        throw ListaExcepcion("Posicion invalida en recuperar dato");
    }
    return dato[posicion]; ///Retorna el elemento que se encuentre en la posicion dada
}

template <class T,int ARRAYSIZE>///Para imprimir--------------------------------------
string Lista<T, ARRAYSIZE>::toString()
{
    string impresion; ///Variable string para imprimir todo

    int aux(0); ///Variable auxiliar inicializada en 0

    while(aux <= ultimo){
        impresion = impresion + dato[aux].toString() + "\n"; ///Lo mismo que impresion+= data[aux].toString() + "\n";

        aux++; ///Aumentamos aux
    }
    return impresion; ///Retorna la variable impresion con todo el contenido
}

template <class T,int ARRAYSIZE>///Borrar todo------------------------------------
void Lista<T,ARRAYSIZE>::borrarTodo()
{
    ultimo = -1; ///Simplemente se coloca la ultima posicion en -1. y toda la informacion se pierde
}

///SOBRECARGA DE OPERADOR/////------------------------------------------------------
template <class T, int ARRAYSIZE>
Lista<T, ARRAYSIZE>& Lista<T, ARRAYSIZE>::operator =(const Lista<T, ARRAYSIZE>& lista)
{
    copyAll(lista); //Recibe una lista. con el metodo la copia, y regresa esa nueva lista

    return *this;
}


#endif // LISTA_H_INCLUDED
