#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<exception>
#include<string>

template <class T>
class List{  ///En este caso usaremos la Lista Doblemente Ligada Lineal Sin Encabezado
    private:
        class Node{ ///Se agrega un nodo anterior y uno siguiente
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

        Node* anchor; ///Ancla

        void copyAll(const List<T>&);

        bool isValidPos(Node*) const;

    public:
        typedef Node* Position; ///Con esto manejamos directamente posiciones

        class Exception : public std::exception{
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

        void bubbleSort() const;

        Node* getFirstPos() const;
        Node* getLastPos() const;
        Node* getPrevPos(Node*) const;
        Node* getNextPos(Node*) const;

        Node* findData(const T&) const;

        T retrieve(Node*) const;

        std::string toString() const;

        void deleteAll();

        List<T>& operator = (const List<T>&);

        ~List();
};

///IMPLEMENTACIONES DEL NODO -------------------------------

template <class T> ///Aqui se inicialiazan los punteros de anterior y siguiente en nuki
List<T>::Node::Node() : next(nullptr), prev(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e) : data(e), next(nullptr), prev(nullptr) { }

template <class T>
T List<T>::Node::getData() const {
    return data;
}

///Estos dos metodos tienen typename ya que regresan un nodo
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

///IMPLEMENTACION LISTA--------------------------------

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

        /// Seguimos copiando
        aux = aux->getNext();
    }

}

template <class T>
bool List<T>::isValidPos(Node* pos) const {
    Node* aux(anchor); ///Se crea un nodo aux que apunta a la ancla
    while(aux != nullptr) { ///Aqui va recorriendola mientras no sea nula
        if(aux == pos) { ///Si existe regresara verdad
            return true;
        }
        aux = aux->getNext();
    }

    return false; ///En ccaso de que aux sea nulo, es porque no sera valido y regresa false
}

template <class T> ///Se inicializa el ancla de la lista en NULO
List<T>::List() : anchor(nullptr) {}

template <class T>
List<T>::List(const List<T>& lista1) : anchor(nullptr) {
    copyAll(lista1);
}

template <class T>
bool List<T>::isEmpty() const {
    return anchor == nullptr; ///Si el ancla apunta a nulo, es porque la lista esta vaica
}

template <class T> ///Insercion
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
void List<T>::bubbleSort() const
{
    int bandera;
    Node* ptr;
    Node* ptr2(nullptr);

    if(anchor == nullptr)
        return;

    do
    {
        bandera = 0;
        ptr = anchor;

        while(ptr->next != ptr2)
        {
            if(ptr->data > ptr->next->data)
            {

                std::swap(ptr->data,ptr->next->data);

                bandera = 1;
            }
            ptr = ptr->next;
        }
        ptr2 = ptr;
    }
    while(bandera);

}


template <class T>
typename List<T>::Node* List<T>::getFirstPos() const {
    return anchor; ///La primera posicion siempre sera la del ancla
}

template <class T>
typename List<T>::Node* List<T>::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
    }

    Node* aux(anchor); ///Se crea un nodo auxiliar que apunte a donde apunta el ancla

    while(aux->getNext() != nullptr) { ///En el campo siguiente del nodo al que apunta, pregunta si es nulo
        aux = aux->getNext(); ///Si no es nulo, se recorre a la siguiente posicion
    }

    return aux; ///Cuando sea nulo, esto significara que este es el ultimo elemento
}

template <class T>
typename List<T>::Node* List<T>::getPrevPos(Node* pos) const {
    if(!isValidPos(pos)) {
        return nullptr;
    }

    return pos->getPrev(); ///Regresa la posicion anteior
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
    Node* aux(anchor); ///Se vuelve a crear un nodo que apunta a donde apunta la ancla

    while(aux != nullptr and aux->getData() != ele) {
        aux = aux->getNext(); ///Recorre nodo por nodo hasta que sea nulo no encuentre el elemento
    }

    return aux; ///En caso de encontrarlo, aqui regresa la POSICION
}

template <class T>
T List<T>::retrieve(Node* pos) const {
    if(!isValidPos(pos)) {
        throw Exception("Posición invalida, retrieve");
    }
///Ya teniendo la posicion del dato a recuperar, solo regresamos el valor que tiene dentro de tipo T
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

template <class T> ///Recorrido destructivo
void List<T>::deleteAll() {
    Node* aux;

    while(anchor != nullptr) { ///Mientras el ancla no deje de apuntar a nulo
        aux = anchor; ///Mediante un nodo auxiliar liberamos memoria y nos pasamos al siguiente nodo, hasta que el ancla sea nula y esto significa que quedo vacia
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
