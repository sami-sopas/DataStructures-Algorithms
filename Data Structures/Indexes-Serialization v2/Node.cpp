#include"Node.h"

Node::Node() : next(nullptr) { }

Node::Node(const Student& s) : data(s), next(nullptr) { }

void Node::setData(const Student& s)
{
    data = s;
}

void Node::setNext(Node* n)
{
    next = n;
}

Student Node::getData() const
{
    return data;
}

Node* Node::getNext() const
{
    return next;
}
