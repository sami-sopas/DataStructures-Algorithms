#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <string>

template <class T>
class List {
  private:
    class Node {
      private:
        T data;
        Node* next;
        Node* prev;
      public:
        Node();
        Node(const T&);

        T getData() const;
        Node* getNext() const;
        Node* getPrev() const;

        void setData(const T&);
        void setNext(Node*);
        void setPrev(Node*);

        friend class List;
    };

    Node* anchor;

    void copyAll(const List<T>&);

    bool isValidPos(Node*) const;

  public:
    typedef Node* Position;
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

    List();
    List(const List<T>&);

    bool isEmpty() const;

    void insertData(Node*, const T&);

    void deleteData(Node*);

    Node* getFirstPos() const;
    Node* getLastPos() const;
    Node* getPrevPos(Node*) const;
    Node* getNextPos(Node*) const;

    Node* findData(const T&) const;

    T retrieve(Node*) const;

    std::string toString() const;

    void deleteAll();

    List<T>& operator = (const List<T>&);

    ~List(); ///Dildre El destructor solo se usa cuando es memoria dinamica
};

///Implementaciones
///Nodo

template <class T>
List<T>::Node::Node() : next(nullptr), prev(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e) : data(e), next(nullptr), prev(nullptr) {}

template <class T>
T List<T>::Node::getData() const {
    return data;
}

template <class T>
typename List<T>::Node* List<T>::Node::getPrev() const {
    return prev;
}


template <class T>
typename List<T>::Node* List<T>::Node::getNext() const {
    return next;
}

template <class T>
void List<T>::Node::setData(const T& e) {
    data = e;
}

template <class T>
void List<T>::Node::setPrev(Node* p) {
    prev = p;
}

template <class T>
void List<T>::Node::setNext(Node* p) {
    next = p;
}

/// Lista
template <class T>
void List<T>::copyAll(const List<T>& lista1) {
    Node* aux(lista1.anchor);
    Node* last(nullptr);
    Node* nuevoNodo;

    while(aux != nullptr) {
        /// Al nodo nuevo, le colocamos los datos de la lista original
        if((nuevoNodo = new Node(aux->getData())) == nullptr) {
            throw Exception("Memoria no disponible, copyAll");
        }

        if(last == nullptr) { /// Es porque la nueva lista esta vacia
            anchor = nuevoNodo;
        } else { /// Ya hay por lo menos 1 elemento dentro de la nueva lista
            nuevoNodo->setPrev(last);
            last->setNext(nuevoNodo);
        }
        /// Hacemos que el ultimo nodo este apuntando al agregado recientemente
        last = nuevoNodo;

        /// Seguimos copeando
        aux = aux->getNext();
    }

}

template <class T>
bool List<T>::isValidPos(Node* posi) const {
    Node* aux(anchor);
    while(aux != nullptr) {
        if(aux == posi) {
            return true;
        }
        aux = aux->getNext();
    }

    return false;
}

template <class T>
List<T>::List() : anchor(nullptr) {}

template <class T>
List<T>::List(const List<T>& lista1) : anchor(nullptr) {
    copyAll(lista1);
}

template <class T>
bool List<T>::isEmpty() const {
    return anchor == nullptr;
}

template <class T>
void List<T>::insertData(Node* pos, const T& ele) {
    if(pos != nullptr and !isValidPos(pos)) {
        throw Exception("Posicion invalida, inserData()");
    }

    Node* aux(new Node(ele));

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, tratando de crear new Node, insertData");
    }

/// Ubicamos que tipo de insercion es
    if(pos == nullptr) {        ///Insertar al principio
        aux->setNext(anchor);
        if(anchor != nullptr) {
            aux->setPrev(anchor);
        }
        anchor = aux;
    } else {                    /// En cualquier otra posicion (contando la ultima)
        aux->setPrev(pos);
        aux->setNext(pos->getNext());
        if(pos->getNext() != nullptr) {
            pos->getNext()->setPrev(aux);
        }
        pos->setNext(aux);
    }
}

template <class T>
void List<T>::deleteData(Node* pos) {
    if(!isValidPos(pos)) {
        throw("Posición inválida, deleteData");
    }
    /// Eliminar cualquiera menos el primero
    if(pos->getPrev() != nullptr) {
        pos->getPrev()->setNext(pos->getNext());
    }
    if(pos->getNext() != nullptr) {
        pos->getNext()->setPrev(pos->getPrev());
    }
    /// Eliminar siempre el primero
    if(pos == anchor) {
        anchor = anchor->getNext();
    }
    delete pos;
}

template <class T>
typename List<T>::Node* List<T>::getFirstPos() const {
    return anchor;
}

template <class T>
typename List<T>::Node* List<T>::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
    }

    Node* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
typename List<T>::Node* List<T>::getPrevPos(Node* pos) const {
    if(!isValidPos(pos)) {
        return nullptr;
    }

    return pos->getPrev();
}

template <class T>
typename List<T>::Node* List<T>::getNextPos(Node* pos) const {
    if(!isValidPos(pos)) {
        return nullptr;
    }

    return pos->getNext();
}

template <class T>
typename List<T>::Node* List<T>::findData(const T& ele) const {
    Node* aux(anchor);

    while(aux != nullptr and aux->getData() != ele) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
T List<T>::retrieve(Node* pos) const {
    if(!isValidPos(pos)) {
        throw Exception("Posición invalida, retrieve");
    }

    return pos->getData();
}

template <class T>
std::string List<T>::toString() const {
    std::string resultado;
    Node* aux(anchor);

    while(aux != nullptr) {
        resultado += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return resultado;
}

template <class T>
void List<T>::deleteAll() {
    Node* aux;

    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();

        /// Liberamos memoria
        delete aux;
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& lista1) {
    deleteAll();

    copyAll(lista1);

    return *this;
}

template <class T>
List<T>::~List() {
    deleteAll();
}


#endif // LIST_H_INCLUDED
