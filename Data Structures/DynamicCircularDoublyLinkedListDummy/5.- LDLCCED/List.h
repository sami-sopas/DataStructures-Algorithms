#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <string>

template <class T>
class List {
  private:
    class Node {
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

        friend class List;
    };

    Node* header;

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

    void bubbleSort();

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
List<T>::Node::Node() : dataPTR(nullptr), next(nullptr), prev(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e) : dataPTR(new T(e)), next(nullptr), prev(nullptr) {
    if(dataPTR == nullptr) {
        throw Exception("Memoria insuficiente, creando nodo");
    }
}

template <class T>
List<T>::Node::~Node() {
    delete dataPTR;
}

template <class T>
T* List<T>::Node::getDataPTR() const {
    return dataPTR;
}

template <class T>
T List<T>::Node::getData() const {
    if(dataPTR == nullptr) {
        throw Exception("Dato inexistente, getData");
    }
    return *dataPTR;
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
void List<T>::Node::setDataPTR(T* ele) {
    dataPTR = ele;
}

template <class T>
void List<T>::Node::setData(const T& e) {
    if(dataPTR == nullptr) {
        if((dataPTR = new T(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
        } else {
            *dataPTR = e;
        }
    }
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
    Node* aux(lista1.header->getNext());
    Node* nuevoNodo;

    while(aux != lista1.header) {
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

template <class T>
bool List<T>::isValidPos(Node* posi) const {
    Node* aux(header->getNext());

    while(aux != header) {
        if(aux == posi) {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template <class T>
List<T>::List() : header(new Node) {
    if(header == nullptr){
        throw Exception("Memoria no disponible, inicialziando lista");
    }
    header->setPrev(header);
    header->setNext(header);
}

template <class T>
List<T>::List(const List<T>& lista1) : List() {
    copyAll(lista1);
}

template <class T>
bool List<T>::isEmpty() const {
    return header->getNext() == header;
}

template <class T>
void List<T>::insertData(Node* pos, const T& ele) {
    if(pos != nullptr and !isValidPos(pos)) {
        throw Exception("Posicion invalida, inserData()");
    }

    Node* aux;
    try {
        aux = new Node(ele);
    } catch(typename Node::Exception ex) {
        throw Exception(ex.what());
    }

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, insertData");
    }

    /// Insertamos
    if(pos == nullptr) {
        pos = header;
    }

    aux->setPrev(pos);
    aux->setNext(pos->getNext());

    pos->getNext()->setPrev(aux);
    pos->setNext(aux);
}

template <class T>
void List<T>::deleteData(Node* pos) {
    if(!isValidPos(pos)) {
        throw("Posición inválida, deleteData");
    }

    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());

    delete pos;
}

template <class T>
void List<T>::bubbleSort()
{
    Node *ptr, *dummy = new Node();


}



template <class T>
typename List<T>::Node* List<T>::getFirstPos() const {
    if(isEmpty()){
        return nullptr;
    }
    return header->getNext();
}

template <class T>
typename List<T>::Node* List<T>::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
    }

    return header->getPrev();
}

template <class T>
typename List<T>::Node* List<T>::getPrevPos(Node* pos) const {
    if(!isValidPos(pos) or pos == header->getNext()) {
        return nullptr;
    }

    return pos->getPrev();
}

template <class T>
typename List<T>::Node* List<T>::getNextPos(Node* pos) const {
    if(!isValidPos(pos) or pos == header->getPrev()) {
        return nullptr;
    }

    return pos->getNext();
}

template <class T>
typename List<T>::Node* List<T>::findData(const T& ele) const {
    Node* auc(header->getNext());

    while(auc != header) {
        if(auc->getData() == ele) {
            return auc;
        }
        auc = auc->getNext();
    }
    return nullptr;
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
    Node* aux(header->getNext());

    while(aux != header) {
        resultado += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return resultado;
}

template <class T>
void List<T>::deleteAll() {
    Node* aux;

    while(header->getNext() != header) {
        aux = header->getNext();

        header->setNext(aux->getNext());

        delete aux;
    }

    header->setPrev(header);
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

    delete header;
}


#endif // LIST_H_INCLUDED
