#ifndef NODEVERTEX_H_INCLUDED
#define NODEVERTEX_H_INCLUDED
#include <string>
#include"NodeEdge.h"
#include"Place.h"

class NodeEdge;

//NODO VERTICE--------------------------------------------------------
class NodeVertex
{
    private:
        Place data; //dato que va tener el vertice (identificador)
        NodeVertex* next; //Puntero a siguiente de la lista de vertices
        NodeEdge* anchor; //Header de la lista de aristas
    public:
        NodeVertex();
        NodeVertex(const Place&);

        void setData(const Place&);
        void setNext(NodeVertex*);
        void setAnchor(NodeEdge*);

        Place getData() const;
        NodeVertex* getNext() const;
        NodeEdge* getAnchor() const;

        friend class Graph;
};

#endif // NODEVERTEX_H_INCLUDED
