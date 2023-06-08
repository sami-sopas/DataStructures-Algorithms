#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include"Student.h"

class Node
{
    private:
        Student data;
        Node* next;
    public:
        Node();
        Node(const Student&);

        void setData(const Student&);
        void setNext(Node*);

        Student getData() const;
        Node* getNext() const;

};


#endif // NODE_H_INCLUDED
