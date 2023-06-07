#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <cstdio>
#include <string>

#include "listexception.h"

template <class T, int ARRAYSIZE = 100>
class List {
  private:
    T data[ARRAYSIZE];
    int last;

    void copyAll(const List&);

  public:
    List();
    List(const List&);

    bool isEmpty();
    bool isFull();

    void insertData(const int&, const T&);
    void deleteData(const int&);

    int getFirstPos();
    int getLastPos();
    int getPrevPos(const int&);
    int getNextPos(const int&);

    int linearFindData(const T&);
    int binaryFindData(const T&);

    T retrieveData(const int&);

    std::string toString();

    void deleteAll();

    List& operator = (const List&);
};

using namespace std;

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE>& l) {
    for(int i(0); i <= l.last; i++) {
        data[i] = l.data[i];
    }

    last = l.last;
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List() : last(-1) { }

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>& l) {
    copyAll(l);
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() {
    return last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() {
    return last == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertData(const int& p, const T& e) {
    if(isFull()) {
        throw  ListException("Desbordamiento de datos, insertData");
    }

    if(p < -1 or p > last) {
        throw ListException("Posicion invalida, insertData");
    }

    int i(last +1);
    while(i > p) {
        data[i] = data[i - 1];

        i--;
    }

    data[p + 1] = e;

    last++;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteData(const int& p) {
    if(isEmpty()) {
        /// Error, insuficiencia de datos
        throw ListException("insuficiencia de datos, deleteData");
    }

    if(p < 0 or p > last) {
        /// Error, posicion invalida
        throw ListException("posicion invalida, deleteData");
    }

    int i(p);
    while(i < last) {
        data[i] = data[i + 1];

        i++;
    }

    last--;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos() {
    if(isEmpty()) {
        return -1;
    }

    return 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos() {
    return last;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevPos(const int& p) {
    if(isEmpty() or p < 1 or p > last) {
        return -1;
    }

    return p - 1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int& p) {
    if(isEmpty() or p < 0 or p > last -1) {
        return -1;
    }

    return p + 1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::linearFindData(const T& e) {
    int i(0);
    while(i <= last) {
        if(data[i] == e) {
            return i;
        }

        i++;
    }

    return -1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::binaryFindData(const T& e) {
    int i(0), j(last), m;
    while(i <= j) {
        m = (i + j) / 2;
        if(data[m] == e) {
            return m;
        }

        if(data[m] > e) {
            j = m - 1;
        } else {
            i =  m + 1;
        }
    }

    return -1;
}

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieveData(const int& p) {
    if(isEmpty() or p < 0 or p > last) {
        /// Error
        throw ListException("Insuficiencia de datos, o posicion invalida, retrieveData");
    }

    return data[p];
}


template <class T, int ARRAYSIZE>
string List<T, ARRAYSIZE>::toString() {
    string result;

    int i(0);
    while(i <= last) {
        result+= data[i].toString() + "\n";
        /*
        		char myVal[10];
        		sprintf(myVal, "%i", data[i]);
        		result+= myVal;
        		result+= "\n";
        */
        i++;
    }

    return result;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAll() {
    last = -1;
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator = (const List<T, ARRAYSIZE>& l) {
    copyAll(l);

    return *this;
}

#endif // LIST_H_INCLUDED
