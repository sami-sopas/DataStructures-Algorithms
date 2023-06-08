#include"NodeEdge.h"

using namespace std;

NodeEdge::NodeEdge() : weight(""),next(nullptr),destiny(nullptr) { } //Constructor

NodeEdge::NodeEdge(const std::string& n,NodeVertex* v) : weight(n), next(nullptr), destiny(v) { } //Constructor copia

void NodeEdge::setWeight(const string& w)
{
    weight = w;
}

void NodeEdge::setNext(NodeEdge* nodeEdge)
{
    next = nodeEdge;
}

void NodeEdge::setDestiny(NodeVertex* nodeDestiny)
{
    destiny = nodeDestiny;
}

string NodeEdge::getWeight() const
{
    return weight;
}

NodeEdge* NodeEdge::getNext() const
{
    return next;
}

NodeVertex* NodeEdge::getDestiny() const
{
    return destiny;
}

