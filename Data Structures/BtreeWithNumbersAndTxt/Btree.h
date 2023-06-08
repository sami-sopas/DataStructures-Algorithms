#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include<iostream>
#include<exception>
#include<string.h>
#include<fstream>
#include "Player.h"

class Btree{
    private:
        class Node{
            private:
                int data;
                Node* left;
                Node* right;
            public:
                Node();
                int getData();

                friend class Btree;
        };

        Node* root;

    public:
         Btree();
         Btree(const Btree&);
         Node* getRoot();
         void printLeft(Node*);
         void insertData(Node*,const int&);
         void deleteData(Node*,const int&);
         void inOrder(Node*);
         void readFile();
         void writeFile(Node*);





};

#endif // BTREE_H_INCLUDED
