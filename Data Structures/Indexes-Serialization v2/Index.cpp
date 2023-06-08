#include"Index.h"

Index::Index() : index(0), nextIndex(nullptr), anchor(nullptr) { }

Index::Index(const int& i) : index(i), nextIndex(nullptr), anchor(nullptr) { }

void Index::setIndex(const int& i)
{
    index = i;
}

void Index::setNextIndex(Index* i)
{
    nextIndex = i;
}

void Index::setAnchor(Node* a)
{
    anchor = a;
}

int Index::getIndex() const
{
    return index;
}

Index* Index::getNextIndex() const
{
    return nextIndex;
}

Node* Index::getAnchor() const
{
    return anchor;
}
