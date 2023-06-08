#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include<exception>
#include<string>
#include<fstream>
#include<sstream>
#include"Student.h"
/** DEFINICION **/
template <class T>
class HashTable
{
    private: //Tabla privado----------------------------------------

        class Node //Nodo donde se guardaran los datos de la tabla
        {
            private:
                T data;
                Node* next;

            public:
                Node();
                Node(const T&);

                void setData(const T&);
                void setNext(Node*);

                T getData() const;
                Node* getNext() const;

                friend class HashTable;
        };

        class Index //Nodo que guardara la posicion en donde estan los datos
        {
            private:
                int index;
                Index* nextIndex;
                Node* anchor; //ancla de la lista de listas

            public:
                Index();
                Index(const int&);

                void setIndex(const int&);
                void setNextIndex(Index*);
                void setAnchor(Node*);

                int getIndex() const;
                Index* getNextIndex() const;
                Node* getAnchor() const;

                friend class HashTable;
        };

        Index* anchorIndex; //Ancla de la lista de indices

    public: //Tabla public -----------------------------------

        class Exception : public std::exception
        {
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

        HashTable(void); //ctor

        bool isEmpty(void); //Saber si la tabla esta vacia

        int HashFunction(T&); //Funcion hash

        void insertData(T&); //Metodo para insertar un nuevo dato y un indice si hace falta

        Index* findIndex(const int&) const; //Recibe un indice y regresa el nodo que lo tenga

        Node* findData(T&); //Dado un dato, retorna el nodo en el que esta

        T retrieveData(Node*) const; //Dado un nodo, retorna el dato que tiene dentro

        void deleteData(T&); //Deja

        std::string toString(void) const; //Imprime indices y datos

        std::string toStringIndexes(void) const; //Imprime solo indices que existen

        void writeFile(void); //Guardar en txt

        int stringToInt(const std::string&); //No servia el stoi del compilador lol

        void readFile(void); //Leer en txt

        void deleteAllCollisions(Index*);  //Trabaja en conjunto con delete all para dejar la tabla vacia

        void deleteAll(void); //Borra todos los datos en la tabla, la deja vacia


        ~HashTable(void);

};//Fin tabla

/** Implementacion **/

using namespace std;

///Implementacion Nodo ------------------------------------------

template <class T>
HashTable<T>::Node::Node() : next(nullptr) { }

template <class T>
HashTable<T>::Node::Node(const T& s) : data(s), next(nullptr) { }

template <class T>
void HashTable<T>::Node::setData(const T& s)
{
    data = s;
}

template <class T>
void HashTable<T>::Node::setNext(Node* n)
{
    next = n;
}

template <class T>
T HashTable<T>::Node::getData() const
{
    return data;
}

template <class T>
typename HashTable<T>::Node* HashTable<T>::Node::getNext() const
{
    return next;
}

///Implementacion Index ----------------------------------------------

template <class T>
HashTable<T>::Index::Index() : index(0), nextIndex(nullptr), anchor(nullptr) { }

template <class T>
HashTable<T>::Index::Index(const int& i) : index(i), nextIndex(nullptr), anchor(nullptr) { }

template <class T>
void HashTable<T>::Index::setIndex(const int& i)
{
    index = i;
}

template <class T>
void HashTable<T>::Index::setNextIndex(Index* i)
{
    nextIndex = i;
}

template <class T>
void HashTable<T>::Index::setAnchor(Node* a)
{
    anchor = a;
}

template <class T>
int HashTable<T>::Index::getIndex() const
{
    return index;
}

template <class T>
typename HashTable<T>::Index* HashTable<T>::Index::getNextIndex() const
{
    return nextIndex;
}

template <class T>
typename HashTable<T>::Node* HashTable<T>::Index::getAnchor() const
{
    return anchor;
}

///Implementacion Tabla ------------------------------------------------

template <class T>
HashTable<T>::HashTable(void) : anchorIndex(nullptr) { }

template <class T>
bool HashTable<T>::isEmpty(void)
{
    return anchorIndex == nullptr;
}

template <class T>
int HashTable<T>::HashFunction(T& data)
{
    return data % 10; //Sencillona vaya
}

template <class T>
typename HashTable<T>::Index* HashTable<T>::findIndex(const int& index) const
{
    Index* aux;

    aux = anchorIndex; //Nos posicionamos al inicio de la lista de indices

    while(aux != nullptr)
    {
        if(aux->getIndex() == index) //Encontramos el nodo que tiene ese indice que me pasaron
        {
            return aux;
        }
        aux = aux->getNextIndex(); //Pasamos al nodo indice siguiente
    }

    return nullptr; // Si no lo encontramos regresamos nulo

}

template <class T>
typename HashTable<T>::Node* HashTable<T>::findData(T& data)
{
    int index = HashFunction(data); //Buscamos la posicion en donde esta el dato

    Index* found = findIndex(index); //Nos retorna el nodo que tiene ese indice

    if(found == nullptr)
    {
        //cout << "El dato a buscar no existe" << endl;
        return nullptr;
    }

    //Si existe el dato...

    Node* aux = found->getAnchor(); //Nos vamos al ancla de ese nodo

    while(aux != nullptr)
    {
        if(aux->getData() == data)
        {
            return aux;
        }
        aux = aux->getNext();
    }

    return nullptr; //Cuando no existe regresamos nulo

}

template <class T>
T HashTable<T>::retrieveData(Node* node) const
{
    return node->getData();
}


template <class T>
void HashTable<T>::deleteData(T& data)
{
    int index = HashFunction(data); //Indice donde estara el dato a eliminar

    Index* nodeIndex = findIndex(index); //En esta posicion (nodo) esta el dato que queremos borrar

    if(nodeIndex == nullptr)
    {
        //cout << "El dato a eliminar no existe" << endl;
    }

    Node* aux = nodeIndex->getAnchor();

    if(aux->getData() == data) //Eliminar dato cuando es el primero
    {
        nodeIndex->setAnchor(nodeIndex->getAnchor()->getNext()); //religamos

        //cout << "Dato a eliminar: " << aux->getData().toString() << endl;

        delete aux;
    }
    else //Eliminar otro dato
    {
        Node* prev = nodeIndex->getAnchor();
        Node* act = prev->getNext();

        while(act != nullptr)
        {
            if(act->getData() == data)
            {
                prev->setNext(act->getNext());

                //cout << "Dato a eliminar: " << act->getData().toString() << endl;

                delete act;
                break;
            }
            prev = act;
            act = act->getNext();
        }

    }

    /** Si eliminamos y resulta que nuestro nodo indice se quedo sin elementos a los que apuntar
        eliminamos ese nodo, ya que deja de ser relevante **/

    if(nodeIndex->getAnchor() == nullptr)
    {
        Index* aux = anchorIndex; //Nos vamos al ancla de la lista de indices

        if(aux->getIndex() == nodeIndex->getIndex()) //Cuando el nodo a eliminar es el primero
        {
            anchorIndex = anchorIndex->getNextIndex(); //religamos

            delete aux;
        }
        else //No es el primero el que se va eliminar
        {
            Index* prev = anchorIndex;
            Index* act = prev->getNextIndex();

            while(act != nullptr)
            {
                if(act->getIndex() == nodeIndex->getIndex())
                {
                    prev->setNextIndex(act->getNextIndex());

                    delete act;
                    break;
                }
                prev = act;
                act = act->getNextIndex();
            }

        }
    }


}

template <class T>
void HashTable<T>::insertData(T& data)
{
    int index = HashFunction(data); //Calculamos el indice en el que se guardara, depende del code del student

    Index* found = findIndex(index);

    /** INSERCION CUANDO EL INDICE QUE CALCULAMOS NO ESTA OCUPADO, INSERTAMOS EN LISTA PRINCIPAL **/

    if(found == nullptr) //Cuando no existe el indice, lo crearemos
    {
        Index* aux;

         aux = new Index(index); //Creamos un nuevo nodo que almacenara el indice

         if(aux == nullptr)
         {
             throw Exception("Memoria no disponible tratando de crear New Node, insertData");
         }

         Index* temp = anchorIndex; //Temporal inicializado al inicio de la lista de indices

         if(temp == nullptr) //Insercion cuando la lista esta vacia
         {
             anchorIndex = aux;

         }
         else //Insercion cuando ya hay elementos (insercion al final)
         {
             while(temp->getNextIndex() != nullptr)
             {
                 temp = temp->getNextIndex();
             }
             temp->setNextIndex(aux); //Ultimo nodo, apuntara al que acabamos de crear
         }

         /** En este punto ya tenemos creado un nodo con el indice y el ancla de la lista donde se
             guardaran los demas datos **/

             Node* nodeList;
             Node* nodeTemp;

         if(aux->getAnchor() == nullptr) //Insercion del primer dato dentro de la lista nueva
         {
             nodeList = new Node(data); //Creamos un nuevo nodo, ahora con el dato

             if(nodeList == nullptr)
             {
                 throw Exception("Memoria no disponible para crar mas nodos,InsertData");
             }

             nodeTemp = aux->getAnchor(); //Nos posicionamos en el ancla de el nodo indice

             aux->setAnchor(nodeList);
         }
         else //Cuando ya hay mas datos
         {
             while(nodeTemp->getNext() != nullptr)
             {
                 nodeTemp = nodeTemp->getNext();
             }
             nodeTemp->setNext(nodeList); //El ultimo apunta al nuevo nodo (insercion al final)
         }
    }
    else
    {
        /** INSERCION CUANDO EL INDICE YA EXISTE, Y POR LO TANTO YA TENDRA ELEMENTOS
            SOLO BUSCAMOS EL NODO INDICE, NOS VAMOS A SU PARTE ANCLA DE LA OTRA LISTA
            , LA RECORREMOS E INSERTAMOS AL FINAL **/

            Node* newNode;
            Node* temp;

            temp = found->getAnchor(); //Nos vamos al ancla del nodo indice

            newNode = new Node(data); //Creamos el nodo con su dato

            while(temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode); //Con esto se inserta el nuevo nodo, en el indice que ya estaba y al final de la lista
    }

}

template <class T>
string HashTable<T>::toString(void) const
{
    string result;

    Index* index = anchorIndex; //Nodo auxiliar inicializado en el header de la lista principal
    Node* node = nullptr; //Nodo auxiliad de header de la lista secundaria, de momento inicializado en nulo

    while(index != nullptr) //Iteramos sobre la lista principal
    {
        node = index->getAnchor();
        result+= "Indice -> " + to_string(index->getIndex()) + " : ";

        while(node != nullptr) //Aqui se imprimiran los datos que tengan el mismo indice (posibles colisiones)
        {
            result+= "-> " + node->getData().toString();

            node = node->getNext();
        }

        result+= "\n";
        index = index->getNextIndex(); //Pasamos al siguiente nodo de la lista principal
    }

    return result;
}

template <class T>
string HashTable<T>::toStringIndexes(void) const
{
    string result;


    Index* index = anchorIndex; //Nodo auxiliar inicializado en el header de la lista principal
    Node* node(nullptr); //Nodo auxiliad de header de la lista secundaria, de momento inicializado en nulo

    while(index != nullptr) //Iteramos sobre la lista principal
    {
        node = index->getAnchor();
        result+= "Indice -> " + to_string(index->getIndex()) + "\n";
        index = index->getNextIndex(); //Pasamos al siguiente nodo de la lista principal
    }

    return result;

}

template <class T>
void HashTable<T>::writeFile(void)
{
//Guardar los datos en el txt

    ofstream file;
    string result;

    Index* indexAux = anchorIndex; //Nos ponemos denuevo en el inicio de la lista
    Node* nodeAux(nullptr);

    file.open("file01.bin",ios::binary);

    if(file.fail())
    {
        throw Exception("Error al abrir el archivo, writeData");
    }
    else
    {
        while(indexAux != nullptr)
        {
            nodeAux = indexAux->getAnchor();
            while(nodeAux != nullptr)
            {
                result+= nodeAux->getData().toString();

                nodeAux = nodeAux->getNext();
            }
          indexAux = indexAux->getNextIndex();
        }

        file << result;

        file.close();

    }
}

template <class T>
int HashTable<T>::stringToInt(const std::string& str)
{
    int num = 0;
    int n = str.length();

    for (int i = 0; i < n; i++)

        num = num * 10 + (int(str[i]) - 48);

    return num;
}


template <class T>
void HashTable<T>::readFile(void)
{
    ifstream file;
    Student s;
    string aux,s_code;
    int code;

    file.open("file01.bin",ios::binary);

    if(file.fail())
    {
        throw Exception("Fallo al abrir el archivo, readFile");
    }
    else
    {
        while(!file.eof())
        {

            getline(file,aux,'|');
            s.setCode(stringToInt(aux));

            getline(file,aux,'|');
            s.setName(aux);

            getline(file,aux,'*');
            s.setCarrer(aux);

            //insertData(s);

            if(file.eof()) break;

            insertData(s);
        }

    }

    file.close();


}

template <class T>
void HashTable<T>::deleteAllCollisions(Index* index)
{
    if(index->getAnchor() == nullptr) return;

    Node* aux;

    while(index->getAnchor() != nullptr)
    {
        aux = index->getAnchor();
        index->setAnchor(index->getAnchor()->getNext());
        delete aux;
    }
}

template <class T>
void HashTable<T>::deleteAll(void)
{
    Index* aux(anchorIndex);

    while(anchorIndex != nullptr)
    {
        aux = anchorIndex;
        anchorIndex = anchorIndex->getNextIndex();
        deleteAllCollisions(aux);
        delete aux;
    }

}

template <class T>
HashTable<T>::~HashTable(void)
{
    deleteAll();
}



#endif // HASHTABLE_H_INCLUDED
