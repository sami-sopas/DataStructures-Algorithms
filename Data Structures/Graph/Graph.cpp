#include"Graph.h"

using namespace std;

Graph::Graph() : anchor(nullptr) { }

bool Graph::isEmpty(void) const
{
    return anchor == nullptr;
}

NodeVertex* Graph::findVertex(const Place& name) const
{
    NodeVertex* aux; //Creamos un nodoVertice auxiliar

    aux = anchor; //Inicializamos el auxiliar en el ancla de la lista de vertices

    while(aux != nullptr) //Mientras auxiliar sea diferente de nulo (que no llegue al final de la lista)
    {
        if(aux->getData() == name) //Cuando auxiliar en su campo nombre coincida con el nombre que me dieron
        {
            return aux; //Retornaremos ese nodo auxiliar
        }
        aux = aux->getNext(); //pasamos al nodo siguiente

    }

    //Si salio del while fue porque no lo encontro
    return nullptr; //asi que solo regresamos nulo como fracaso

}

NodeVertex* Graph::getPrevVertex(NodeVertex* pos) const
{
    if(pos == anchor)
    {
        return nullptr;
    }

    NodeVertex* aux(anchor); //Inicializamos un auxiliar que apunte al ancla

    while(aux != nullptr and aux->getNext() != pos) //iteramos al siguiente
    {
        aux = aux->getNext(); //aumentamos
    }

    return aux;

}

void Graph::insertVertex(const Place& name)
{
    NodeVertex* aux; //Creamos un nodo auxiliar
    aux = new NodeVertex(name); //Le reservamos memoria dinamica

    NodeVertex* temp(anchor); //Nodo temporal inicializado en el ancla de la lista de vertices

    if(temp == nullptr) //Caso cuando la lista de vertices esta vacia
    {
        anchor = aux; //Hacemos que el ancla apunte a auxiliar (primer elemento)
    }
    else //Caso cuando ya hay elementos en la lista
    {
        while(temp->getNext() != nullptr) //Hacemos un recorrido hasta que encontremos el nodo que apunta a null (el ultimo)
        {
            temp = temp->getNext();
        }
        temp->setNext(aux);
      //  temp->getNext() = aux; //En este punto ya estamos en el nodo final por lo que solo ligamos el nuevo nodo al final de la lista
    }

}

void Graph::insertEdge(const Place& origin, const Place& destiny, const string& weight)
{
    NodeVertex* originVertex = findVertex(origin);
    NodeVertex* destinyVertex = findVertex(destiny);

    //Validaciones para comprobar que si hay origen y destino
    if(originVertex == nullptr)
    {
        cout << "Origen no encontrado" << endl;
        //return;
    }

    if(destinyVertex == nullptr)
    {
        cout << "Destino no encontrado" << endl;
        return;
    }

    //si existe origen y destino

    NodeEdge* newEdge = new NodeEdge(weight,destinyVertex); //Creamos un nuevo nodo arista que tenga el peso que recibimos

    if(originVertex->getAnchor() == nullptr) //Caso cuando la lista de aristas esta vacia
    {
        originVertex->setAnchor(newEdge);
        //originVertex->getAnchor() = newEdge; //Hacemos que el ancla de la lista de aristas apunte a auxiliar el cual sera el primer elemento
    }
    else //Ya hay elementos en la lista de aristas
    {
        NodeEdge* aux = originVertex->getAnchor(); //Inicializamos un nodoArista auxiliar en el ancla del nodo origen

        while(aux->getNext() != nullptr) //Recorremos la lista de aristas para encontrar el nodo que esta al final (el que apunta a nulo)
        {
            aux = aux->getNext(); //Aumentamos
        }
        aux->setNext(newEdge);
      //  aux->getNext() = newEdge; //Hacemos que la ultima arista apunte a la nueva y se inserta
    }
}

void Graph::displayGraph(void)
{
    NodeVertex* auxVertex(anchor); //Nodo auxiliar inicializado en el header de la lista de veritces
    NodeEdge* auxEdge(nullptr); //Nodo auxiliad de arista, de momento inicializado en nulo

    while(auxVertex != nullptr) //Iteramos sobre la lista de vertices
    {
        auxEdge = auxVertex->getAnchor(); //auxEdge tiene el ancla de la lista de aristas del vertice actual
        cout << "Vertice " << auxVertex->getData().toString() << " : ";

        while(auxEdge != nullptr) //Iteramos sobre la lista de aristas
        {                     //origen                         peso                            destino
            cout << auxVertex->getData().toString() << "-" << auxEdge->getWeight() << "-" << auxEdge->getDestiny()->getData().toString() << " | ";
            //cout << " | " << auxEdge->getDestiny()->data << ":" << auxEdge->getWeight();
            auxEdge = auxEdge->getNext(); //Pasamos a la siguiente arista
        }

        cout << endl;
        auxVertex = auxVertex->getNext();
    }

}

void Graph::deleteAllEdges(NodeVertex* nodeV)
{
    if(nodeV == nullptr) return;

    NodeEdge* aux; //Auxiliar con el que recorreremos la lista de aristas

    while(nodeV->getAnchor() != nullptr) //recorreremos desde el ancla de las aristas
    {
        aux = nodeV->getAnchor();
        nodeV->setAnchor(nodeV->getAnchor()->getNext());
    //    nodeV->getAnchor() = nodeV->getAnchor()->getNext(); //nos movemos al siguiente

        delete aux; //Liberamos memoria
    }

}

void Graph::deleteEdgesConnections(const Place& destiny)
{
    NodeVertex* auxVertex = anchor; //auxiliar inicializado en el ancla para primero recorrer la lista de vertices

    while(auxVertex != nullptr)
    {
        if(auxVertex->getData() == destiny or auxVertex->getAnchor() == nullptr)
        {
            auxVertex = auxVertex->getNext();
            continue;//nothing to do here lol

        }

        if(auxVertex->getAnchor()->getDestiny()->getData() == destiny) //Cuando la primera arista tiene como destino el que queremos borrar
        {
            NodeEdge* auxEdge = auxVertex->getAnchor();

            auxVertex->setAnchor(auxVertex->getAnchor()->getNext()); //Hacemos que el ancla de arista apunte al su siguiente
            //cout << "arista: " << auxVertex->getData() << " --- " << destiny << " eliminado";
            delete auxEdge;
        }
        else //Cuando no es la primera arista la que queremos eliminar
        {
            NodeEdge* prev = auxVertex->getAnchor(); //Nodo anterior al que queremos borrar
            NodeEdge* act = prev->getNext(); //Nodo actual al que queremos eliminar

            while(act != nullptr)
            {
                if(act->getDestiny()->getData() == destiny)
                {
                    prev->setNext(act->getNext()); //prev->getNext() = act->getNext();
                   //cout << "arista: " << auxVertex->getData() << " --- " << destiny << " eliminado";
                    //delete act; wtf why if i comment this part now delete??!!

                }

                prev = act;
                act = act->getNext();
            }

        }

        auxVertex = auxVertex->getNext();


       /* if(auxVertex->getData() != destiny)
        {
            NodeEdge* auxEdge = auxVertex->getAnchor(); //Nodo auxiliar que apunta al ancla de la lista de aristas

        } */

       // auxVertex = auxVertex->getNext();
    }
}


void Graph::deleteVertex(const Place& name)
{
    NodeVertex* validation = findVertex(name);

    if(validation == nullptr)
    {
        cout << "El vertice dado no existe" << endl;
        return;
    }

    if(anchor->getData() == name) //Eliminacion cuando es el primer vertice
    {
        NodeVertex* aux(anchor); //Creamos un auxiliar apuntando al ancla


        anchor = anchor->getNext(); //Hacemos que ancla apunte a su siguiente

        deleteAllEdges(aux); //Eliminamos las aristas de ese nodo

        deleteEdgesConnections(aux->getData()); //Eliminamos las aristas que apuntes al destino(vertice) que queremos eliminar
        //cout << "Vertice: " << name << " fue eliminado" << endl;
               // cout << "entro" << endl;

        delete aux; //Finalmente eliminamos el nodo
    }
    else //no es el primer vertice el que queremos eliminar
    {
        NodeVertex* prev = anchor; //Nodo anterior
        NodeVertex* act = prev->getNext(); //Nodo actual (el que queremos eliminar)

        while(act != nullptr)
        {

            if(act->getData() == name) //Encontramos el nodo que queremos eliminar dado el nombre
            {
                prev->setNext(act->getNext()); //Ligamos el anterior con el siguiente del actual

                deleteAllEdges(act); //Eliminamos las aristas que tenga ese nodo

                deleteEdgesConnections(act->getData()); //Eliminamos las aristas que apuntes al destino(vertice) que queremos eliminar

                prev->setNext(act->getNext()); //Ligamos el anterior con el siguiente del actual
               // prev->getNext() = act->getNext();
                //cout << "deleting: " << name << endl;
                delete act; //Finalmente eliminamos el nodo
                break;

            }

            prev = act;
            act = act->getNext(); //Recorremos el vertice

        }


    }


   /* another method that didnt work :(
    NodeVertex* act;
    NodeVertex* prev;

    act = anchor; //Inicializamos el nodo actual apuntando al ancla

    while(act != nullptr) //Recorremos la lista de vertices
    {
        if(act->getData() == name) //Encontramos el nodo que queremos eliminar
        {
            if(act->getAnchor() != nullptr) //Si en el vertice tenemos aristas, llamamos la funcion que las elimina
                deleteAllEdges(act);

            if(act == anchor) //Caso cuando queremos eliminar el primer vertice
            {
                anchor = anchor->getNext();
                //delete act
                return;
            }
            else //Caso cuando queremos eliminar cualquier otro vertice
            {
                prev->setNext(act->getNext());
              //  prev->getNext() = act->getNext(); //Religado entre el nodo anterior al siguiente del actual
                delete(act);
                return;
            }
        }
        else //Cuando nodo actual no es el que buscamos
        {
           //Avanzamos al siguiente nodo, haciendo que el anterior sea el actual y que actual sea su siguiente
            prev = act;
            act = act->getNext();
        }

    } */
}

void Graph::deleteEdge(const Place& origin, const Place& destiny) //Eliminar arista
{
    NodeVertex* originVertex = findVertex(origin);
    NodeVertex* destinyVertex = findVertex(destiny);

    //Validaciones para comprobar que si hay origen y destino
    if(originVertex == nullptr)
    {
        cout << "Origen no encontrado" << endl;
    }

    if(destinyVertex == nullptr)
    {
        cout << "Destino no encontrado" << endl;
        return;
    }

    //si existe origen y destino


    if(originVertex->getAnchor()->getDestiny()->getData() == destiny) //Cuando queremos eliminar la primera arista
    {
        NodeEdge* aux = originVertex->getAnchor();
        originVertex->setAnchor(originVertex->getAnchor()->getNext());

                                   //origen
        //cout << "Arista: " << origin << " - " <<  destiny << " eliminada";
        delete aux;

    }
    else //Eliminar cualquier otra arista
    {
        NodeEdge* prev = originVertex->getAnchor();
        NodeEdge* act = prev->getNext();

        while(act != nullptr)
        {
            if(act->getDestiny() == destinyVertex) //Encontramos arista que queremos eliminar
            {
                prev->setNext(act->getNext()); // prev->getNext() = act->getNext();

                 //cout << "Arista: " << origin << " - " <<  destiny << " eliminada";

                delete(act);
                break;

            }

            prev = act;
            act = act->getNext();
        }

    }

}

string Graph::toString(void) const
{
    string result;

    NodeVertex* auxVertex(anchor); //Nodo auxiliar inicializado en el header de la lista de veritces
    NodeEdge* auxEdge(nullptr); //Nodo auxiliad de arista, de momento inicializado en nulo

    while(auxVertex != nullptr) //Iteramos sobre la lista de vertices
    {
        auxEdge = auxVertex->getAnchor(); //auxEdge tiene el ancla de la lista de aristas del vertice actual
        //cout << "Vertice " << auxVertex->getData() << " : ";
        result+= "Vertice -> " + auxVertex->getData().toString();

        while(auxEdge != nullptr) //Iteramos sobre la lista de aristas
        {                     //origen                         peso                            destino
            //cout << auxVertex->getData() << "-" << auxEdge->getWeight() << "-" << auxEdge->getDestiny()->getData() << " | ";
            result+= " Aristas -> " + auxVertex->getData().toString() + " - " + auxEdge->getWeight() + " - " + auxEdge->getDestiny()->getData().toString() + " ; ";
            //cout << " | " << auxEdge->getDestiny()->data << ":" << auxEdge->getWeight();
            auxEdge = auxEdge->getNext(); //Pasamos a la siguiente arista
        }

        //cout << endl;
        result+= "\n";
        auxVertex = auxVertex->getNext();
    }

    return result;

}

void Graph::displayVertexes(void)
{
    NodeVertex* aux(anchor);

    while(aux != nullptr)
    {
        cout << aux->getData().toString() << endl;
        aux = aux->getNext();
    }
}


void Graph::deleteAll(void)
{
    NodeVertex* aux(anchor);

    while(anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        //cout << "";
        deleteAllEdges(aux);
        delete(aux);
    }

}

void Graph::saveData(void)
{
    fstream file;
    string vertices,aristas;
    NodeVertex* auxVertex(anchor);
    NodeEdge* auxEdge(nullptr);

    file.open("file01.txt",ios::out);

    if(file.fail())
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        while(auxVertex != nullptr)
        {
            auxEdge = auxVertex->getAnchor();
            //Vertice
            vertices+= auxVertex->getData().toString();

            while(auxEdge != nullptr)
            {
                auxEdge = auxEdge->getNext();
            }
            auxVertex = auxVertex->getNext();
        }

        auxVertex = anchor;
        auxEdge = nullptr;


        while(auxVertex != nullptr)
        {
            auxEdge = auxVertex->getAnchor();
            while(auxEdge != nullptr)
            {                  //origen                               //peso       delimitador peso (-)     destino
                aristas+= auxVertex->getData().toString() + auxEdge->getWeight() + "-" + auxEdge->getDestiny()->getData().toString();
                auxEdge = auxEdge->getNext();
            }
            auxVertex = auxVertex->getNext();
        }
        file << vertices + "\n" + aristas;
        /* De esta manera, en el txt quedara asi
        Linea 1: todas las vertices
        Linea 2: todas las aristas */
    }

    file.close();

}

void Graph::readData(void)
{
    Place p,ori,dest;
    string aux,weight; //Variables para leer los objetos

    string vertices, aristas; //Variables donde se guardaran los vertices y aristas de manera separada

    fstream file;

    file.open("file01.txt",ios::in); //Abrimos el archivo en modo lectura

    if(file.fail())
    {
        cout << "Error al abrir el archivo !" << endl;
        return;
    }

    getline(file,vertices,'\n'); //Leyendo vertices
    getline(file,aristas,'\n'); //Leyendo aristas y guardandolas en sus respectivas variables

    cout << "vertices: " << vertices << endl;
    cout << "aristas: " << aristas << endl;

    file.close(); //Ya que leimos tanto vertices como aristas cerramos el archivo
    remove("file01.txt"); //Borramos el txt file01

    //fstream file("file01.txt",ios::app | ios::out)
    file.open("file01.txt",ios::app | ios::out | ios::in); //Creamos denuevo file01 y lo abrimos en lectura y escritura

    file << vertices; //En el nuevo txt, le escribimos todas las vertices

    file.seekg(0,ios::beg); //Posicionamos el cursor en el inicio del archivo

    while(!file.eof()) //Metodo para leer vertices
    {
        getline(file,aux,'|');
        p.setCountry(aux);

        getline(file,aux,'|');
        p.setState(aux);

        getline(file,aux,'*');
        p.setCity(aux);

        if(file.eof()) break;

        insertVertex(p);
    }

    file.close(); //Cerramos
    remove("file01.txt"); //Eliminamos de nuevo el archivo que tenia solo vertices

    file.open("file01.txt",ios::app | ios::out | ios::in); //Nuevamente lo volvemos a crear en modo escritura y lectura

    file << aristas; //Escribimos todas las aristas dentro del nuevo txt vacio

    file.seekg(0,ios::beg);

    while(!file.eof()) //Metodo para leer aristas
    {
        //Leyendo origen
        getline(file,aux,'|');
        ori.setCountry(aux);

        getline(file,aux,'|');
        ori.setState(aux);

        getline(file,aux,'*');
        ori.setCity(aux);

        //Leyendo peso
        getline(file,weight,'-');

        //Leyendo destino
        getline(file,aux,'|');
        dest.setCountry(aux);

        getline(file,aux,'|');
        dest.setState(aux);

        getline(file,aux,'*');
        dest.setCity(aux);

        if(file.eof()) break;


        insertEdge(ori,dest,weight);

    }

    file.close(); //Cerramos el archivo
    remove("file01.txt"); //Eliminamos el txt que tenia solo aristas

    file.open("file01.txt",ios::app | ios::out); //Creamos de nuevo el archivo y en modo escritura

    file << vertices << "\n" << aristas; //Escribimos en el txt los vertices, despues un salto de linea y al final las aristas para diferenciarlas
    //Para dejarlo como era originalmente

    file.close(); //Lo cerramos

}
/*

METODO ANTERIOR

void Graph::readData(void)
{
    ifstream file;

    fstream tempFile("temp.txt",ios::app); //Con esta instruccion creamos un archivo temporal
    tempFile.close(); //Lo cerramos inmediatamente

    string vertices;
    string aristas;

    file.open("file01.txt",ios::in); //Abrimos el archivo principal (file01)

    if(file.fail())
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        //LEYENDO VERTICES-------------------------------

        getline(file,vertices,'\n'); //Del archivo file01, leemos solo la primera linea (la que trae los vertices)

        cout << "vertices: " << vertices << endl; //esto solo era para comprobar que si se leyo bien toda la linea

        file.close();

        tempFile.open("temp.txt",ios::out); //Abrimos el archivo temporal en modo escritura

        tempFile << vertices; //Guardamos en el archivo temporal las vertices del grafo

        tempFile.close(); //Cerramos el archivo temporal

        tempFile.open("temp.txt",ios::in); //Lo volvemos a abrir, pero esta vez en modo lectura

        while(!tempFile.eof()) //Lectura hasta el final
        {
            Place p;
            string aux;

            getline(tempFile,aux,'|');
            p.setCountry(aux);

            getline(tempFile,aux,'|');
            p.setState(aux);

            getline(tempFile,aux,'*');
            p.setCity(aux);

            if(tempFile.eof())
            {
                break;
            }

            insertVertex(p); //Insertamos vertice
        }

        tempFile.close(); //Cerramos el archivo temporal de vertices
        remove("temp.txt"); //Eliminamos ese temporal para no dejar rastro vaya

        //LEYENDO ARISTAS -----------------------------------

        fstream tempFile("temp.txt",ios::app); //Volvemos a crear el temporal
        tempFile.close(); //Lo cerramos

        file.open("file01.txt",ios::in); //Volvemos a abrir el archivo original en modo lectura (file01)

        getline(file,vertices,'\n'); //leemos vertices pero aqui ya no usaremos esa variable
        getline(file,aristas,'\n'); //Leemos el siguiente renglon que es donde estan las aristas

        cout << "aristas: " << aristas << endl; //Para comprobar que si se leyo bien

        file.close(); //Cerramos el archivo principal

        tempFile.open("temp.txt",ios::out); //abrilos el temporal en modo escritura

        tempFile << aristas; //Escribimos todas las aristas dentro de ese temporal

        tempFile.close(); //Cerramos dicho archivo

        tempFile.open("temp.txt",ios::in); //Abrimos temporal ahora en modo lectura

        while(!tempFile.eof())
        {
            Place ori,dest;
            string aux;
            string weight;

            //Leyendo origen
            getline(tempFile,aux,'|');
            ori.setCountry(aux);

            getline(tempFile,aux,'|');
            ori.setState(aux);

            getline(tempFile,aux,'*');
            ori.setCity(aux);

            //Leyendo peso
            getline(tempFile,weight,'-');

            //Leyendo destino
            getline(tempFile,aux,'|');
            dest.setCountry(aux);

            getline(tempFile,aux,'|');
            dest.setState(aux);

            getline(tempFile,aux,'*');
            dest.setCity(aux);

            if(tempFile.eof())
            {
                break;
            }

            insertEdge(ori,dest,weight);
        }

        tempFile.close(); //Cerramos temporal
        remove("temp.txt"); //Eliminamos el archivo

    }
}
*/


