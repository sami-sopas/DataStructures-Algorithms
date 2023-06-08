#include"HashTable.h"

using namespace std;

HashTable::HashTable(void) : anchorIndex(nullptr) { }

bool HashTable::isEmpty(void)
{
    return anchorIndex == nullptr;
}

int HashTable::HashFunction(Student& student)
{
    return student % 10; //Sencillona vaya
}

Index* HashTable::findIndex(const int& index) const
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

Node* HashTable::findData(Student& student)
{
    int index = HashFunction(student); //Buscamos la posicion en donde esta el dato

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
        if(aux->getData() == student)
        {
            return aux;
        }
        aux = aux->getNext();
    }

    return nullptr; //Cuando no existe regresamos nulo

}

Student HashTable::retrieveData(Node* node) const
{
    return node->getData();
}

void HashTable::deleteData(Student& student)
{
    int index = HashFunction(student); //Indice donde estara el dato a eliminar

    Index* nodeIndex = findIndex(index); //En esta posicion (nodo) esta el dato que queremos borrar

    if(nodeIndex == nullptr)
    {
        //cout << "El dato a eliminar no existe" << endl;
    }

    Node* aux = nodeIndex->getAnchor();

    if(aux->getData() == student) //Eliminar dato cuando es el primero
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
            if(act->getData() == student)
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


void HashTable::insertData(Student& student)
{
    int index = HashFunction(student); //Calculamos el indice en el que se guardara, depende del code del student

    Index* found = findIndex(index);

    /** INSERCION CUANDO EL INDICE QUE CALCULAMOS NO ESTA OCUPADO, INSERTAMOS EN LISTA PRINCIPAL **/

    if(found == nullptr) //Cuando no existe el indice, lo crearemos
    {
        Index* aux;

         aux = new Index(index); //Creamos un nuevo nodo que almacenara el indice

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
             nodeList = new Node(student); //Creamos un nuevo nodo, ahora con el dato

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

            newNode = new Node(student); //Creamos el nodo con su dato

            while(temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode); //Con esto se inserta el nuevo nodo, en el indice que ya estaba y al final de la lista
    }

}


string HashTable::toString(void) const
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
            result+= " -> " + node->getData().toString();

            node = node->getNext();
        }

        result+= "\n";
        index = index->getNextIndex(); //Pasamos al siguiente nodo de la lista principal
    }

    return result;
}

string HashTable::toStringIndexes(void) const
{
    string result;

    Index* aux(anchorIndex);

    while(aux != nullptr)
    {
        result+= "Indices : " + to_string(aux->getIndex()) + "\n";
        aux = aux->getNextIndex();
    }

    return result;

}



void HashTable::deleteAllCollisions(Index* index)
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

void HashTable::deleteAll(void)
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

HashTable::~HashTable(void)
{
    deleteAll();
}

