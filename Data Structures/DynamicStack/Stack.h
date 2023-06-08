#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#include<exception>
#include<string>

template <class T>
class Stack{ //Creacion de la pila
    private:
        class Node{ //Creacion del nodo
            private: ///Se usa de base la LSLLSE
                T data;
                Node* next;
            public:
                Node(); //Constructor vacio
                Node(const T&); //Constructor copia

                T getData() const;
                Node* getNext() const;

                void setData(const T&);
                void setNext(Node*);

                friend class Stack;
        };

        Node* anchor; //Ancla

        void copyAll(const Stack<T>&);

        bool isValidPos(Node*) const;

        void deleteAll();

    public:
        typedef Node* Position; //Para manejar posiciones directamente

    class Exception : public std::exception { //Creacion de la clase excepcion
      private:
        std::string msg;

      public:
        explicit Exception(const char* message) : msg(message) { }

        explicit Exception(const std::string& message) : msg(message) { }

        virtual ~Exception() throw () { }

        virtual const char* what() const throw () {
            return msg.c_str();
        }
    };

    Stack(); //Constructor
    Stack(const Stack<T>&); //Constructor copia

    bool isEmpty() const;

    void push(const T&);

    T pop();

    T getTop() const;

    std::string toString() const;

    Stack<T>& operator = (const Stack<T>&);

    ~Stack();
};

///IMPLEMENTACIONES NODO------------------------------

template <class T> //En el constructor vacio se setea el puntero a siguiente como nulo
Stack<T>::Node::Node() : next(nullptr) {}

template <class T> //Constructor
Stack<T>::Node::Node(const T& e): data(e), next(nullptr) {}

template <class T>
T Stack<T>::Node::getData() const {
    return data; ///Regresa un dato de tipo T
}

template <class T>
typename Stack<T>::Node* Stack<T>::Node::getNext() const {
    return next;
} ///Regresa el nodo de su campo siguiente

template <class T> ///Aqui se setea la info en la pila
void Stack<T>::Node::setData(const T& e) {
    data = e;
}

template <class T> ///Recibe un nodo y se guarda como el siguiente
void Stack<T>::Node::setNext(Node* p) {
    next = p;
}

///IMPLEMENTACION PILA---------------------------------

template <class T>
void Stack<T>::copyAll(const Stack<T>& pilaCopia) {
    Node* aux(pilaCopia.anchor);
    Node* ultimoIngresado(nullptr);
    Node* nuevoNodo;

    while(aux != nullptr) {
        nuevoNodo = new Node(aux->getData());

        if(ultimoIngresado == nullptr) {
            anchor = nuevoNodo;
        } else {
            ultimoIngresado->setNext(nuevoNodo);
        }
        ultimoIngresado = nuevoNodo;
        aux = aux->getNext();
    }

}

template <class T> ///Dada una posicion verificar si es valida
bool Stack<T>::isValidPos(Node* posi) const {
    Node* aux(anchor); ///Crea un nodo auxiliar que apunte al ancla
    while(aux != nullptr) { ///La va recorriendo mientras sea diferente de uno
        if(aux == posi) {
            return true; ///Si existe algo, es porque si es valida la posicion para realizar una accion
        }
        aux = aux->getNext();
    }

    return false; ///Si no es valido regresara falso
}

template <class T> ///En el constructor vacio se setea el ancla en nulo
Stack<T>::Stack() : anchor(nullptr) {}

template <class T> ///Cuando queramos copiar, mandamos a llamar a copyAll y ponemos en nulo la pila a recibior
Stack<T>::Stack(const Stack<T>& pila1) : anchor(nullptr) {
    copyAll(pila1);
}

template <class T> ///La pila esta vacia si el ancla apunta a nulo
bool Stack<T>::isEmpty() const {
    return anchor == nullptr;
}

template <class T>
void Stack<T>::push(const T& ele) {
    Node* aux(new Node(ele)); ///Se crea un nuevo nodo auxiliar con el elemento

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, tratando de crear new Node, push");
    }

    aux->setNext(anchor);
    ///El nodo apunta al que se encuentre en el campo siguiente de la ancla (Tope)


    anchor = aux; ///Se inserta en el tope
}

template <class T>
T Stack<T>::pop() { ///Pop
    if(anchor == nullptr) { ///Si el ancla es nula, es porque no hay datos y esta vacia
        throw("Insuficiencia de datos, pop");
    }
    T result(anchor->getData()); ///Al ser una pila, el elemento a quitar sera al que este apuntando el ancla

    Node* aux(anchor); ///Se crea un auxiliar que apunte al acnla

    anchor = anchor->getNext(); ///Religado: el ancla ahora apunta al elemento siguiente al que apunta primero

    delete aux; ///Se elimina el nodo auxiliar

    return result; ///Regresamos el elemento que se elimino
}

template <class T>
T Stack<T>::getTop() const {
    if(anchor == nullptr) { ///Si el ancla es nula, es porque la pila esta vacia
        throw Exception("Insuficiencia de datos, getTop");
    }

    return anchor->getData(); ///regresamos los datos de adonde apunta ancla (tope)
}

template <class T>
std::string Stack<T>::toString() const {
    std::string resultado;
    Node* aux(anchor);

    while(aux != nullptr) {
        resultado += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return resultado;
}

template <class T>
void Stack<T>::deleteAll() { ///Recorrido destructivo

    Node* aux; ///Creamos un nodo auxiliar

    while(anchor != nullptr) { ///Mientras el ancla no sea nula(vacia)
        aux = anchor;
        anchor = anchor->getNext(); ///Vamos recorriendo y eliminando

        /// Liberamos memoria
        delete aux;
    }
}


template <class T> ///Sobrecarga del operador
Stack<T>& Stack<T>::operator=(const Stack<T>& pila1) {
    deleteAll();

    copyAll(pila1);

    return *this;
}

template <class T>
Stack<T>::~Stack() {
    deleteAll();
}




#endif // STACK_H_INCLUDED
