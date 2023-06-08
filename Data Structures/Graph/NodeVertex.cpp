#include"NodeVertex.h"

using namespace std;

NodeVertex::NodeVertex() : next(nullptr),anchor(nullptr) { } //Constructor

NodeVertex::NodeVertex(const Place& p) : data(p), next(nullptr), anchor(nullptr) { } //Constructor copia


void NodeVertex::setData(const Place& p)
{
  data = p;
}

void NodeVertex::setNext(NodeVertex* nodeVertex)
{
    next = nodeVertex;
}

void NodeVertex::setAnchor(NodeEdge* nodeEdge)
{
    anchor = nodeEdge;
}

Place NodeVertex::getData() const
{
    return data;
}

NodeVertex* NodeVertex::getNext() const
{
    return next;
}

NodeEdge* NodeVertex::getAnchor() const
{
    return anchor;
}


