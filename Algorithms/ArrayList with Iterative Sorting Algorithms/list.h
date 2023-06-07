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
    void swapData(T&, T&);

  public:
    List();
    List(const List&);

    bool isEmpty();
    bool isFull();

    void insertData(const int&, const T&);
    void deleteData(const int&);

    void bubbleSort();
    void insertSort();
    void selectSort();
    void shellSort();

    void superShellSort();

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
void List<T, ARRAYSIZE>::swapData( T& a, T& b) {
T aux(a);

a = b;
b = aux;

}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::bubbleSort() {
    bool flag;
    int i(last);

    do {
        flag = false;
        int j = 0;
        while(j < i) {
            if(data[j] > data[j + 1]) {
                swapData(data[j], data[j + 1]);
                flag = true;
            }
            j++;

        }
        i--;

    } while(flag);

}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertSort() {
    int i = 1, j;
    while(i <= last) {
        T aux(data[i]);
        j = i;
        while(j > 0 and aux < data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        if(i != j) {
            data[j] = aux;
        }
        i++;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::selectSort() {
    int i(0), menor, j;
    while(i < last) {
        menor = i;
        j = i + 1;
        while(j <= last) {
            if(data[j] < data[menor]) {
                menor = j;
            }
            j++;
        }
        if(menor != i) {
            swap(data[i], data[menor]);
        }
        i++;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::shellSort() {
    /// Factor de .5
    float factor = 1.0 / 2.0;
    /// Diferencial
    int dif = (last + 1) * factor;
    int i, j;
    while(dif > 0) {
        i = dif;
        while(i <= last) {
            j = i;
            while(j >= dif and data[j - dif] > data[j]) {
                swapData(data[j - dif], data[j]);
                j--;
            }
            i++;
        }
        dif *= factor;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::superShellSort() {
    /// Factor de 1 / 3
    /// unsigned gapSeries[] = {531441, 177147, 59049, 19683, 6561, 2187, 729, 243, 81, 27, 9, 3, 1, 0};

    /// Factor de 1 / 2
    /// unsigned gapSeries[] = {524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1, 0};

    /// Tokuda Sequence --> Created By: Norio Tokuda
    /// unsigned gapSeries[] = {776591, 392451, 153401, 68178, 30301, 13467, 5985, 2660, 1182, 525, 233, 103, 46, 20, 9, 4, 1, 0};

    /// Ciura Sequence --> Created By: Marcin Ciura
    ///unsigned gapSeries[] = {510774, 227011, 100984, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1, 0};
    unsigned gapPos(0), gap(gapSeries[gapPos]), i, j;

    while(gap > 0) {
        i = gap;
        while(i <= last) {
            j = i;
            while(j >= gap and data[j - gap] > data[j]) {
                swapData(data[j - gap], data[j]);

                j -= gap;
            }

            i++;
        }
        gap = gapSeries[++gapPos];
    }
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
