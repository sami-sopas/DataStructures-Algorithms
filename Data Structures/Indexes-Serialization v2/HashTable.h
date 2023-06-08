#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include<iostream>
#include"Index.h"
#include"Node.h"

class HashTable
{
    private:
        Index* anchorIndex;
    public:
        HashTable(void);

        bool isEmpty(void);

        int HashFunction(Student&);

        void insertData(Student&);

        Index* findIndex(const int&) const; //Recibe un indice y regresa el nodo que lo tenga

        Node* findData(Student&);

        Student retrieveData(Node*) const;

        void deleteAllCollisions(Index*);  //Trabaja en conjunto con delete data para dejar la tabla vacia

        void deleteData(Student&);

        std::string toString(void) const;

        std::string toStringIndexes(void) const;

        void deleteAll(void);

        ~HashTable(void);

};

#endif // HASHTABLE_H_INCLUDED
