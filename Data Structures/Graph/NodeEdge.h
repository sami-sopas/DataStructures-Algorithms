#ifndef NODEEDGE_H_INCLUDED
#define NODEEDGE_H_INCLUDED
#include"NodeVertex.h"

class NodeVertex;

//NODO ARISTA-------------------------------
class NodeEdge
{
    private:
        std::string weight; //Peso de la arista
        NodeEdge* next; //Puntero a siguiente de arista
        NodeVertex* destiny; //Puntero a nodo vertice destino

    public:
        NodeEdge(); //ctr
        NodeEdge(const std::string&,NodeVertex*); //ctr copy

        void setWeight(const std::string&);
        void setNext(NodeEdge*);
        void setDestiny(NodeVertex*);


        std::string getWeight() const;
        NodeEdge* getNext() const;
        NodeVertex* getDestiny() const;

        friend class Graph;

};


#endif // NODEEDGE_H_INCLUDED
