#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include"Node.h"

class Index
{
    private:
        int index;
        Index* nextIndex;
        Node* anchor;

    public:
        Index();
        Index(const int&);

        void setIndex(const int&);
        void setNextIndex(Index*);
        void setAnchor(Node*);

        int getIndex() const;
        Index* getNextIndex() const;
        Node* getAnchor() const;

};

#endif // INDEX_H_INCLUDED
