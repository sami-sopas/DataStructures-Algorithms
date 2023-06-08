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
      public:
        Node();
        Node(const T&);

        T getData() const;
        Node* getNext() const;

        void setData(const T&);
        void setNext(Node*);

        friend class List;
    };

    Node* anchoir;

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
List<T>::Node::Node() : next(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e) : data(e), next(nullptr) {}

template <class T>
T List<T>::Node::getData() const {
    return data;
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
void List<T>::Node::setNext(Node* p) {
    next = p;
}

/// Lista
template <class T>
void List<T>::copyAll(const List<T>& lista1) {
    Node* aux(lista1.anchoir);
    Node* last(nullptr);
    Node* nuevoNodo;

    while(aux != nullptr) {
        /// insertData(getLastPos(), aux->getData());

        /// Al nodo nuevo, le colocamos los datos de la lista original
        nuevoNodo = new Node(aux->getData());

        if(last == nullptr) { /// Es porque la nueva lista esta vacia
            anchoir = nuevoNodo;
        } else { /// Ya hay por lo menos 1 elemento dentro de la nueva lista
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
    Node* aux(anchoir);
    while(aux != nullptr) {
        if(aux == posi) {
            return true;
        }
        aux = aux->getNext();
    }

    return false;
}

template <class T>
List<T>::List() : anchoir(nullptr) {}

template <class T>
List<T>::List(const List<T>& lista1) : anchoir(nullptr) {
    copyAll(lista1);
}

template <class T>
bool List<T>::isEmpty() const {
    return anchoir == nullptr;
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
        aux->setNext(anchoir);
        anchoir = aux;
    } else {                    /// En cualquier otra posicion (contando la ultima)
        aux->setNext(pos->getNext());
        pos->setNext(aux);
    }
}

template <class T>
void List<T>::deleteData(Node* pos) {
    if(!isValidPos(pos)) {
        throw("Posición inválida, deleteData");
    }
/// Buscamos que tipo de eliminacion es para hacer el RELIGADO
    if(pos == anchoir) { /// Eliminar el primero
        ///RELIGANDO el primero
        anchoir = anchoir->getNext();
    } else { /// Eliminar cualquier otra posición (Tambien la ultima)
        /// RELIGANDO cualquier otra posición
        getPrevPos(pos)->setNext(pos->getNext());
    }

/// Cualquier caso, liberamos la memoria reservada
    delete pos;
}

template <class T>
typename List<T>::Node* List<T>::getFirstPos() const {
    return anchoir;
}

template <class T>
typename List<T>::Node* List<T>::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
    }

    Node* aux(anchoir);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
typename List<T>::Node* List<T>::getPrevPos(Node* pos) const {
    if(pos == anchoir) {
        return nullptr;
    }

    Node* aux(anchoir);

    while(aux != nullptr and aux->getNext() != pos) {
        aux = aux->getNext();
    }

    return aux;
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
    Node* aux(anchoir);

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
    Node* aux(anchoir);

    while(aux != nullptr) {
        resultado += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return resultado;
}

template <class T>
void List<T>::deleteAll() {
    Node* aux;

    while(anchoir != nullptr) {
        aux = anchoir;
        anchoir = anchoir->getNext();

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
