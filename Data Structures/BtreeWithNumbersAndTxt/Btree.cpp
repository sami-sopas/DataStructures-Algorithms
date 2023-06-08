#include"Btree.h"

using namespace std;

Btree::Node::Node() : left(nullptr), right(nullptr) { }

int Btree::Node::getData()
{
    return data;
}

Btree::Btree() : root(nullptr) { }

typename Btree::Node* Btree::getRoot()
{
    return root;
}


/** Metodo pa insertar. Recibe
    como parámetros un apuntador (la primera vez es la raíz del árbol) y
    la información que se quiere almacenar en el nuevo nodo.  **/
void Btree::insertData(Node*actual,const int& dato)
{
    Node* aux; //Creamos un nodo auxiliar

    if(actual == nullptr) //La primera vez es la raiz, cuando es nula...
    {
        aux = new Node(); /* se crea el nuevo nodo, se almacena la información
                            y se hace el religado entre el nuevo nodo y su padre. */
        aux->data = dato;
        root = aux;
    }
    else ///Cuando el nodo actual es diferente de nulo
    {
        if(dato < actual->data) //se pregunta si el dato a insertar es menor que el dato visitado. */
        {
            insertData(actual->left,dato); //Insercion recursiva hacia la izquierda
            actual->left = root;
        }else
        {
            insertData(actual->right,dato); //Insercion recursiva hacia la derecha
            actual->right = root;
        }

        root = actual; //actualizamos la raiz
    }

}

/** Metodoo pa eliminar
Se busca el valor deseado y quitar el nodo que lo contiene. Este último paso se lleva a cabo
dependiendo si el nodo eliminado es hoja o no. entonces se quita directamente.
En otro caso, para no perder las ligas a sus descendientes, se debe reemplazar por el nodo que se encuentra más a
la derecha del subárbol izquierdo o por el que se encuentra más a la izquierda del
subárbol derecho.
**/
void Btree::deleteData(Node* actual,const int& dato)
{
    if(actual) //Evaluamos si el nodo actual (primero sera la raiz) esta definido (!= null)
        if(dato < actual->data)
        {
            deleteData(actual->left,dato);
            actual->left = root;
        }
        else
            if(dato > actual->data)
            {
                deleteData(actual->right,dato);
                actual->right = root;

            }
            else
            {
                Node *aux1,*aux2,*aux3;
                aux3 = actual;
                if(!aux3->right)
                    if(!aux3->left)
                    actual= nullptr;
                    else
                        actual= aux3->left;
                else
                    if(!aux3->left)
                        actual = aux3->right;
                    else
                    {
                        aux1 = aux3->left;
                        aux2 = aux3;
                        while(aux1->right)
                        {
                            aux2 = aux1;
                            aux1 = aux1->right;
                        }
                        aux3->data = aux1->data;
                        if(aux3==aux2)
                            aux3->left=nullptr;
                        else
                            if(!aux1->left)
                                aux2->right = nullptr;
                            else
                                aux2->right = aux1->left;
                            aux3 = aux1;

                    }
                delete(aux3);
            }
            root = actual;
}

void Btree::inOrder(Node* actual)
{
    if(actual)
    {
        inOrder(actual->left);
        cout << actual->data << ", ";
        inOrder(actual->right);
    }

}
/*
void Btree::readFile()
{
    ifstream file("file01.txt");

    if(!file.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        while(!file.eof())
        {
            Player playerAux;
            string myStr;

            getline(file,myStr,'|');
            playerAux.setName(myStr);

            getline(file,myStr,'|');
            playerAux.setCountry(myStr);

            getline(file,myStr,'*');
            playerAux.setYears(myStr);

            if(file.eof())
            {
                break;
            }

            insertData(getRoot(),playerAux);

        }
    }

    file.close();
}

void Btree::writeFile(Node* actual)
{
    ofstream file("file01.txt");

    if(actual)
    {
        inOrder(actual->left);
        file << actual->data.toString();
        inOrder(actual->right);
    }

    file.close();

}*/
