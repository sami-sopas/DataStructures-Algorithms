#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<exception>
#include<string>

template <class T>
class Queue{///Creacion de la cola usando de base la LDLCED
    private:
        class Node{
            private:
                T* dataPTR;
                Node* next;
                Node* prev;
            public:
        class Exception : public std::exception {
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

        Node();
        Node(const T&);

        ~Node();

        T* getDataPTR() const;
        T getData() const;
        Node* getNext() const;
        Node* getPrev() const;

        void setDataPTR(T*);
        void setData(const T&);
        void setNext(Node*);
        void setPrev(Node*);

        };

        Node* header; //Encabezado

        void copyAll(const Queue<T>&);

        void deleteAll();

    public:
        typedef Node* Position; //Manejar posiciones directamente

    class Exception : public std::exception {
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

    Queue();
    Queue(const Queue<T>&);

    bool isEmpty() const;

    void enqueue(const T&);

    T dequeue();

    T getFront() const;

    std::string toString() const;

    Queue<T>& operator = (const Queue<T>&);

    ~Queue();

};

///IMPLEMENTACIONES NODO------------------------------

template <class T> ///Se setean los punteros en nulo
Queue<T>::Node::Node() : dataPTR(nullptr), next(nullptr), prev(nullptr) {}

template <class T>
Queue<T>::Node::Node(const T& e) : dataPTR(new T(e)), next(nullptr), prev(nullptr) {
    if(dataPTR == nullptr) { ///Para cuando no se puedan crear mas nodos
        throw Exception("Memoria insuficiente, creando nodo");
    }
}

template <class T>
Queue<T>::Node::~Node() { ///Destructor
    delete dataPTR;
}

template <class T>
T* Queue<T>::Node::getDataPTR() const {
    return dataPTR;
}

template <class T>
T Queue<T>::Node::getData() const {
    if(dataPTR == nullptr) {
        throw Exception("Dato inexistente, getData");
    }
    return *dataPTR;
}

template <class T> //Retorna nodo
typename Queue<T>::Node* Queue<T>::Node::getPrev() const {
    return prev;
}

template <class T> //Retorna nodo
typename Queue<T>::Node* Queue<T>::Node::getNext() const {
    return next;
}

template <class T>
void Queue<T>::Node::setDataPTR(T* ele) {
    dataPTR = ele;
}

template <class T>
void Queue<T>::Node::setData(const T& e) {
    if(dataPTR == nullptr) {
        if((dataPTR = new T(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
        } else {
            *dataPTR = e;
        }
    }
}

template <class T>
void Queue<T>::Node::setPrev(Node* p) {
    prev = p;
}

template <class T>
void Queue<T>::Node::setNext(Node* p) {
    next = p;
}

///IMPLEMENTACION COLA---------------------------------------

template <class T> //FUncion para copiar
void Queue<T>::copyAll(const Queue<T>& cola1) {
    Node* aux(cola1.header->getNext());
    Node* nuevoNodo;

    while(aux != cola1.header) {
        try {
            if((nuevoNodo = new Node(aux->getData())) == nullptr) {
                throw Exception("Memoria no disponible, copyAll");
            }
        } catch(typename Node::Exception ex) {
            throw Exception(ex.what());
        }

        nuevoNodo->setPrev(header->getPrev());
        nuevoNodo->setNext(header);

        header->getPrev()->setNext(nuevoNodo);
        header->setPrev(nuevoNodo);

        aux = aux->getNext();
    }
}

template <class T> //Inicializa, recibe el encabezado
Queue<T>::Queue() : header(new Node) {
    if(header == nullptr){
        throw Exception("Memoria no disponible, inicialziando lista");
    }
    //Circularidad el encabezado en su campo siguiente apunta a si mismo, lo mismo con anterior
    header->setPrev(header);
    header->setNext(header);
}

template <class T>
Queue<T>::Queue(const Queue<T>& cola1) : Queue() {
    copyAll(cola1); //Constructor copia que manda a llamar a copyAll
}

template <class T>
bool Queue<T>::isEmpty() const {
    return header->getNext() == header;
}

template <class T>
void Queue<T>::enqueue(const T& ele) {

    Node* aux; ///Se crea un nodo auxiliar

    try {
        aux = new Node(ele); //En el auxiliar se ponen los datos del elemento a encolar
    } catch(typename Node::Exception ex) {
        throw Exception(ex.what());
    }

    if(aux == nullptr) { //Si es uno es porque no hay memoria
        throw Exception("Memoria no disponible, insertData");
    }

    /// El nodo se conecta a la lista
    aux->setPrev(header->getPrev());
    aux->setNext(header);

    ///La lista se conecta al nodo
    header->getPrev()->setNext(aux);
    header->setPrev(aux);
}

template <class T>
T Queue<T>::dequeue() { ///Desencolar
    if(isEmpty()) { ///Verificar si esta vacia
        throw("Insuficiencia de datos, dequeue");
    }
    T salvado(header->getNext()->getData()); ///Dato que se va desencolar

    Node* aux(header->getNext()); ///Nodo auxiliar que apunta al siguiente elemento del encabezado

    aux->getPrev()->setNext(aux->getNext()); ///Aqui se conecta el encabezado al nodo siguiente del auxiliar
    aux->getNext()->setPrev(aux->getPrev()); ///Aqui se conecta el nodo despues del encabezado al encabezado

    delete aux; ///Borramos el auxiliar que es de donde se desencolo

    return salvado; ///Regresamos ese elemento desencolado
}

template <class T>
std::string Queue<T>::toString() const {
    std::string resultado;
    Node* aux(header->getNext());

    while(aux != header) {
        resultado += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return resultado;
}

template <class T>
void Queue<T>::deleteAll() {
    Node* aux;

    while(header->getNext() != header) {
        aux = header->getNext();

        header->setNext(aux->getNext());

        delete aux;
    }

    header->setPrev(header);
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& cola1) {
    deleteAll();

    copyAll(cola1);

    return *this;
}

template <class T>
T Queue<T>::getFront() const {
    if(isEmpty()) {
        throw Exception("Insuficiencia de datos, getFront");
    }

    return header->getNext()->getData();
}


template <class T>
Queue<T>::~Queue() {
    deleteAll();

    delete header;
}
#endif // QUEUE_H_INCLUDED
