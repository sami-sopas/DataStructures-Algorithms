#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>

template <class T>
class BTree {
    private:
        class Node {
            public:
                Node();
                Node(const T&);
                ~Node();

                Node* left;
                Node* right;
                Node* ancestor;
                T* dataPtr;

                T getData();

                void setData(T& e);

                class Exception : public std::exception {
                    private:
                        std::string msg;
                    public:
                        explicit Exception (const char* message) : msg(message) { }
                        explicit Exception (const std::string& message) : msg(message) { }
                        virtual ~Exception () throw () { }
                        virtual const char* what () const throw() {
                            return msg.c_str();
                            }
                    };


            };


    public:
        typedef Node* Position;
    private:
        Position root;

        void copyAll(Position& r, Position& cr);
        void deleteAll();

        void insertData(Position&,const T&);
        void deleteData(Position&, T& e);

        Position& findData(Position&, const T&);

        Position& getLowest(Position&);
        Position& getHighest(Position&);

        void parsePreOrder(Position&);
        void parseInOrder(Position&);
        void parsePostOrder(Position&);

        Position& getPredecessorNode(int,Position&);
        Position& getSuccessorNode(int,Position&);

        Position& findPos(Position&, const T&);

         Position& searchById(int,Position&);
        Position& searchByName(std::string,Position&);

    public:
        class Exception : public std::exception {
            private:
                std::string msg;
            public:
                explicit Exception (const char* message) : msg(message) { }
                explicit Exception (const std::string& message) : msg(message) { }
                virtual ~Exception () throw () { }
                virtual const char* what () const throw() {
                    return msg.c_str();
                    }
            };

        BTree();
        BTree(const BTree&);

        ~BTree();

        bool isEmpty();

        void insertData( T&);
        void deleteData(T& e);
        T retrieve(Position&);

        int getHeight(Position&);

        Position& findData(T&);

        Position& getLowest();
        Position& getHighest();

        bool isLeaf(Position&);

        int getHeight();

        void parsePreOrder();
        void parseInOrder();
        void parsePostOrder();

        int getHeightLeft();
        int getHeightRight();

        Position& getPredecessorNode(int);
        Position& getSuccessorNode(int);

        Position& findPredecessor(int );
        Position& findPredecessor(Position&, Position&, int );

        Position& findSuccessor(T );
        //Position& findSuccessor(Position& , Position& , int );

        Position& findPos(const T& e);

        void modify(int);

        void deleteAll(Position&);

        BTree& operator = (const BTree&);
        bool printAncestors( int target);

        Position& searchById(int);
        Position& searchByName(std::string);

        void modify(int, T&);


    };

///Implementacion
using namespace std;
///Nodo
template <class T>
BTree<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) {
    }

template <class T>
BTree<T>::Node::Node(const T& e) : dataPtr(new T(e)), left(nullptr), right(nullptr) {
    if(dataPtr == nullptr)
        throw Exception("Memoria no disponible, inicializar Nodo");
    }

template <class T>
BTree<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T BTree<T>::Node::getData() {
    if(dataPtr == nullptr)
        throw Exception("Dato inexistente, getData");

    return *dataPtr;
    }

template <class T>
void BTree<T>::Node::setData(T& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr)
            throw Exception("Dato inexistente, getData");
        }
    else
        *dataPtr=e;
    }



///Arból
template <class T>
BTree<T>::BTree() : root(nullptr) {}

template <class T>
BTree<T>::BTree(const BTree& t) : root(nullptr) {
    copyAll(t);
    }
template <class T>
BTree<T>::~BTree() {
    deleteAll(root);
    }


template <class T>
void BTree<T>::deleteAll(Position& r) {
    if(r==nullptr)
        return;
    deleteAll(r->left);
    deleteAll(r->right);
    delete r;
    }

template <class T>
void BTree<T>::copyAll(Position& r, Position& cr) {
    if(cr != nullptr) {
        r= new Node(cr->getData());
        copyAll(r->left,cr->left);
        copyAll(r->right,cr->right);
        }
    }

template <class T>
bool BTree<T>::isEmpty() {
    return root == nullptr;
    }

template <class T>
void BTree<T>::insertData(T& e) {
    insertData(root,e);
    }

template <class T>
void BTree<T>::insertData(Position& r, const T& e) {
    if(r==nullptr) {
        try {
            if((r=new Node(e))==nullptr)
                throw Exception("Memoria no disponilbe, insertData");
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    else {
        if(e==r->getData()){
        cout<<"Elemento repetido"<<endl;
            return;
        }

        if(e < r->getData())
            insertData(r->left,e);
        else
            insertData(r->right,e);
        }

    }
template <class T>
void BTree<T>::deleteData(T& e) {
    deleteData(root,e);
    }


template <class T>
void BTree<T>::deleteData(Position& r, T& e) {
    if(r== nullptr)
        return;

    if(r->getData() == e) { ///hoja
        if(isLeaf(r)) {
            delete r;
            r=nullptr;
            return;
            }
        if(r->left == nullptr or r->right == nullptr) { ///1 hijo
            Position aux(r);

            if(r->left == nullptr)
                r=r->right;

            r=r->left;

            delete aux;
            return;
            }///2 hijos

        T sustitution(getHighest(r->left)->getData());

        r->setData(sustitution);

        deleteData(r->left,sustitution);

        }
    else {
        if(e < r->getData())
            deleteData(r->left,e);
        else
            deleteData(r->right,e);
        }

    }

template <class T>
typename BTree<T>::Position& BTree<T>::findData(T& e) {
    return findData(root,e);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::findData(Position& r, const T& e) {
    if(r==nullptr or r->getData() == e)
        return r;

    if(e < r->getData())
        return findData(r->left,e);

    return findData(r->right,e);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getLowest() {
    return getLowest(root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getLowest(Position& r) {
    if(r==nullptr or r->left==nullptr)
        return r;

    return getLowest(r->left);
    }
template <class T>

typename BTree<T>::Position& BTree<T>::getHighest() {
    return getHighest(root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getHighest(Position& r) {
    if(r==nullptr or r->right==nullptr)
        return r;

    return getHighest(r->right);

    }

template <class T>
bool BTree<T>::isLeaf(Position& r) {
    return r != nullptr and r->left == r->right;
    }

template <class T>
int BTree<T>::getHeight() {
    return getHeight(root);
    }

template <class T>
int BTree<T>::getHeight(Position& r) {
    if(r==nullptr)
        return 0;

    int lH(getHeight(r->left));
    int rH(getHeight(r->right));

    return(lH > rH ? lH : rH)+1;
    }
/// pre-order
template <class T>
void BTree<T>::parsePreOrder() {
    parsePreOrder(root);
    }

template <class T>
void BTree<T>::parsePreOrder(Position& r) {
    if(r==nullptr)
        return;

    std::cout<<r->getData() << ", ";
    parsePreOrder(r->left);
    parsePreOrder(r->right);
    }
///in-order
template <class T>
void BTree<T>::parseInOrder() {
    parseInOrder(root);
    }

template <class T>
void BTree<T>::parseInOrder(Position& r) {
    if(r==nullptr)
        return;

    parseInOrder(r->left);
    std::cout << r->getData() << ", ";
    parseInOrder(r->right);
    }
/// post-order
template <class T>
void BTree<T>::parsePostOrder() {
    parsePostOrder(root);
    }

template <class T>
void BTree<T>::parsePostOrder(Position& r) {
    if(r==nullptr)
        return;
    parsePostOrder(r->left);
    parsePostOrder(r->right);
    std::cout<<r->getData()<<", ";

    }

template <class T>
T BTree<T>::retrieve(Position& r) {
    return r->getData();
    }

template <class T>
int BTree<T>::getHeightLeft() {
    return getHeight(root->left);
    }

template <class T>
int BTree<T>::getHeightRight() {
    return getHeight(root->right);
    }


template <class T>
BTree<T>& BTree<T>::operator=(const BTree& t) {
    deleteAll(root);
    copyAll(t);

    return *this;
    }
///Antecesor
template <class T>
typename BTree<T>::Position& BTree<T>::getPredecessorNode(int id) {
    return getPredecessorNode(id,root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getPredecessorNode(int id,Position& p) {
    Position aux(nullptr);
    if(searchById(id) == nullptr)
        return getHighest()->right;

    if(root->getData().getId() == id )
        return getHighest()->right;
    else if(id == (p->left == nullptr ? -1 : p->left->getData().getId()) )
        return p;
    else if(id == (p->right == nullptr ? -1 : p->right->getData().getId()))
        return p;

    if(id < p->getData().getId())
        getPredecessorNode(id,p->left);
    else if(id >= p->left->getData().getId())
        getPredecessorNode(id,p->right);


    }

///Sucesor

template <class T>
typename BTree<T>::Position& BTree<T>::getSuccessorNode(int id) {

    Position aux(searchById(id));
    if(searchById(id) == nullptr)
        return getHighest()->right;

    //if(aux==nullptr)
        //return aux;

    if(!isLeaf(aux)) {
        if(aux->left != nullptr )
            return aux->left;
        else if(aux->right != nullptr )
            return aux->right;
        }

        return aux->left;

    }
///------------------------------------
template <class T>
typename BTree<T>::Position& BTree<T>::searchById(int id) {
    searchById(id,root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::searchById(int id,Position& r) {
    if(r==nullptr)
        return r;

    if(r->getData().getId()== id){
        return r;
    }
    searchById(id,r->left);
    searchById(id,r->right);
    }
///---------------------
template <class T>
typename BTree<T>::Position& BTree<T>::searchByName(string n) {
    searchByName(n,root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::searchByName(string n,Position& r) {
    if(r==nullptr)
        return r;

    if(r->getData().getName()== n){
        return r;
    }
    searchByName(n,r->left);
    searchByName(n,r->right);
    }

template <class T>
 void BTree<T>::modify(int id, T& e){
    Position aux(searchById(id));

    if(aux==nullptr)
        cout<<"El elemento no se encuentra en el arbol";
    else
        aux->setData(e);


 }
#endif // BTREE_H_INCLUDED
