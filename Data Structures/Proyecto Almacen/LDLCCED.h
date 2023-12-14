#ifndef LDLCCED_H_INCLUDED
#define LDLCCED_H_INCLUDED

#include <exception>
#include <string>


template <class T> ///Template para manejar todo tipo de datos
class List{
    private:
        class Node { ///Todo se maneja con punteros
            private:
                T* dataPTR;
                Node* next;
                Node* prev;

            public:
                class Exception : public std::exception{
                    private:
                        std::string msg;
                    public:
                        explicit Exception(const char* message) : msg(message) {}

                        explicit Exception(const std::string& message) : msg(message) {}

                        virtual ~Exception() throw () { }

                        virtual const char* what() const throw () {
                            return msg.c_str();
                        }
                };

        Node();
        Node(const T&);

        ~Node(); ///Destructor

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

    Node* header; ///No es un nodo, es el encabezado DUMMY

    void copyAll(const List<T>&); ///Para poder copiar lista

    bool isValidPos(Node*) const;

    public:
        typedef Node* Position; ///Para llamar solo a Position y no a todo

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

        void insertData(Node*,const T&);

        void deleteData(Node*);

        void bubbleSort(Node*,const T&);

        Node* getFirstPos() const;
        Node* getLastPos() const;
        Node* getPrevPos(Node*) const;
        Node* getNextPos(Node*) const;

        Node* findData(const T&) const;

        T retrieve(Node*) const;

        std::string toString() const;

        void deleteAll();

        List<T>& operator = (const List<T>&);

        ~List(); ///El destructor se usa solo cuando se usa memoria dinamica
};

///IMPLEMENTACIONES NODO-------------------------------

template <class T> ///Aqui es donde se inicializan en NULO
List<T>::Node::Node() : dataPTR(nullptr), next(nullptr), prev(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e) : dataPTR(new T(e)), next(nullptr), prev(nullptr) {
    if(dataPTR == nullptr) {
        throw Exception("Memoria insuficiente, creando nodo");
    }
}

template <class T>
List<T>::Node::~Node() { //Destructor
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

///IMPLEMENTACION LISTA ------------------------------------

template <class T> ///Para copiar
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

template <class T> ///Validar posicion
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

template <class T> ///INICIALIZA
List<T>::List() : header(new Node) { ///Recibe encabezado, no regresa nada
    if(header == nullptr){
        throw Exception("Memoria no disponible, inicialziando lista");
    }
    header->setPrev(header); ///Encabezado en su campto anterior apunta a si mismo
    header->setNext(header); ///Encabezado en su campo siguiente apunta a si mismo
}

template <class T>
List<T>::List(const List<T>& lista1) : List() {
    copyAll(lista1);
}

template <class T> ///VACIA
bool List<T>::isEmpty() const {
    return header->getNext() == header;
    /** La lista esta vacia si el encabezado en su posicion siguiente
        apunta a si mismo. tambien se puede validar con el anterior**/
}

template <class T> ///INSERTAR
void List<T>::insertData(Node* pos, const T& ele) {
    if(pos != nullptr and !isValidPos(pos)) { ///Pro,erp se valida la posicion
        throw Exception("Posicion invalida, inserData()");
    }

    Node* aux; ///Se crea un nodo auxiliar en caso de que sea posicion valida
    try {
        aux = new Node(ele);
    } catch(typename Node::Exception ex) {
        throw Exception(ex.what());
    }

    if(aux == nullptr) { ///En caso de no tener memoria disponible se arroja una excepcion
        throw Exception("Memoria no disponible, insertData");
    }

    /// Insertamos
    if(pos == nullptr) { ///Si la posicion es nula
        pos = header; ///Ahora la posicion sera en encabezado
    }

    ///Nodo se conecta a la lista
    aux->setPrev(pos); ///Auxiliar en su campo anterior apunta a donde se encuentra la posicion
    aux->setNext(pos->getNext()); ///Auxiliar en su campo siguiente apunta al elemento siguiente de posicion

    ///Lista se conecta al nodo
    pos->getNext()->setPrev(aux); ///Posicion en su campo siguiente en su campo anteior apuntara al auxiliar
    pos->setNext(aux);
}

template <class T> ///ELIMINAR
void List<T>::deleteData(Node* pos) {
    if(!isValidPos(pos)) { ///Se valida la posicion
        throw("Posición inválida, deleteData");
    }

    ///Se hace el religado y finalmente se elimina la posicion dada
    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());

    delete pos;
}

/*template <class T>
void List<T>::bubbleSort(Node* pos, const T& ele) {
    if(pos != nullptr and !isValidPos(pos)) {
        throw Exception("Posicion invalida, inserData()");
    }

    Node* aux(new Node(ele));

    while(pos->getNext()!=nullptr){
            aux=pos->getNext();
            while(aux!=nullptr){
                if(pos->getData()>aux->getData()){
                    pos=aux->getData();
                    aux->getData()=pos->getData();
                    pos->getData()=pos;
                }
                aux=aux->getNext();
            }
            pos=pos->getNext();
    }
}*/

template <class T> ///PRIMERO
typename List<T>::Node* List<T>::getFirstPos() const {
    if(isEmpty()){
        return nullptr;
    }
    return header->getNext(); ///El elemento en el campo siguiente del encabezado es el primero de la lista
}

template <class T> ///ULTIMO
typename List<T>::Node* List<T>::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
    }

    return header->getPrev(); ///Del encabezado. en su campo anterior a donde apunta es el ultimo elemento (recordar que es circular)
}

template <class T> ///ANTERIOR recibe una posicion
typename List<T>::Node* List<T>::getPrevPos(Node* pos) const {
    if(!isValidPos(pos) or pos == header->getNext()) {
        return nullptr;
    }

    return pos->getPrev();
}

template <class T> ///SIGUIENTE recibe una posicion
typename List<T>::Node* List<T>::getNextPos(Node* pos) const {
    if(!isValidPos(pos) or pos == header->getPrev()) {
        return nullptr;
    }

    return pos->getNext();
}


template <class T> ///LOCALIZA
typename List<T>::Node* List<T>::findData(const T& ele) const { ///Recibe un elemento
    Node* aux(header->getNext()); ///Se crea un nodo auxiliar que apunte al siguiente del encabezado

    while(aux != header)  {///Recorre toda la lista comparando cada elemento
        if(aux->getData() == ele) {
            return aux; ///Si coincide, regresa un nodo donde se encontro
        }
        aux = aux->getNext();
    }
    return nullptr; ///Si regresa al encabezado es porque no lo encontro y regresa null
}

template <class T> ///RECUPERA
T List<T>::retrieve(Node* pos) const { ///Recibe una posicion
    if(!isValidPos(pos)) { ///Valida
        throw Exception("Posición invalida, retrieve");
    }

    return pos->getData(); ///Regresa el valor que se encuentra en la posicion dada
}

template <class T> ///IMPRIMIR
std::string List<T>::toString() const {
    std::string resultado;
    Node* aux(header->getNext());

    while(aux != header) {
        resultado += "\n"+aux->getData().toString();

        aux = aux->getNext();
    }

    return resultado;
}

template <class T> ///ANULA
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


#endif // LDLCCED_H_INCLUDED
