#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#include <exception>
#include <string>

class QueueException : public std::exception {
  private:
    std::string msg;
  public:
    explicit QueueException(const char* message) : msg(message) {}

    explicit QueueException(const std::string& message) : msg(message) { }

    virtual ~QueueException() throw () { }

    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T, int ARRAYSIZE = 1024>
class Queues {
  private:
    T data[ARRAYSIZE];
    int posFront;
    int posFinal;

    void copyAll(const Queues&);
  public:
    Queues();
    Queues(const Queues&);

    bool isEmpty();
    bool isFull();


    void enqueue(const T&);
    T dequeue();
    T getFront();

    std::string toString();
    std::string toStringNumbers();

    Queues& operator = (const Queues&);
};

using namespace std;

template <class T, int ARRAYSIZE>
void Queues<T, ARRAYSIZE>::copyAll(const Queues<T, ARRAYSIZE>&cola1) {
    int aux(cola1.posFront);

    posFinal=cola1.posFinal;
    posFront=cola1.posFront;
    while(aux != cola1.posFinal + 1) {
        data[aux]=cola1.data[aux];
        aux++;
        if(aux==ARRAYSIZE) {
            aux= 0;
        }
    }

}

template <class T, int ARRAYSIZE>
Queues<T, ARRAYSIZE>::Queues() : posFront(0), posFinal(ARRAYSIZE - 1) {}

template <class T, int ARRAYSIZE>
Queues<T, ARRAYSIZE>::Queues(const Queues<T, ARRAYSIZE>& cola1) {
    copyAll(cola1);
}

template <class T, int ARRAYSIZE>
bool Queues<T, ARRAYSIZE>::isEmpty() {
    return posFront == posFinal+1
           or (posFront == 0 and posFinal == ARRAYSIZE - 1);
}

template <class T, int ARRAYSIZE>
bool Queues<T, ARRAYSIZE>::isFull() {
    return posFront == posFinal + 2
           or (posFront == 0 and posFinal == ARRAYSIZE - 2)
           or (posFront == 1 and posFinal == ARRAYSIZE - 1);
}

template <class T, int ARRAYSIZE>
void Queues<T, ARRAYSIZE>::enqueue(const T& elemento) {
    if(isFull()) {
        throw QueueException("Desbordamiento de datos, enqueue()");
    }

    if(++posFinal == ARRAYSIZE) {
        posFinal = 0;
    }

    data[posFinal] = elemento;
}

template <class T, int ARRAYSIZE>
T Queues<T, ARRAYSIZE>::dequeue() {
    if(isEmpty()) {
        throw QueueException("Insuficiencia de datos, dequeue()");
    }
    T desencolado(data[posFront]);

    if(++posFront == ARRAYSIZE) {
        posFront = 0;
    }

    return desencolado;
}

template <class T, int ARRAYSIZE>
T Queues<T, ARRAYSIZE>::getFront() {
    if(isEmpty()) {
        throw QueueException("Insuficiencia de datos, getFront()");
    }
    return data[posFront];
}

template <class T, int ARRAYSIZE>
string Queues<T, ARRAYSIZE>::toString() {
    string hoal;

    return hoal;
}

template <class T, int ARRAYSIZE>
string Queues<T, ARRAYSIZE>::toStringNumbers() {
    string impresion;

    int aux(posFront);
    int limite = posFinal + 1;
    if(posFinal == ARRAYSIZE - 1) {
        limite = 0;
    }
    while(!isEmpty() && (aux != limite)) {
        impresion+= to_string(data[aux]) + " , ";

        aux++;
        if(aux == ARRAYSIZE) {
            aux = 0;
        }
    }

    return impresion;
}

template <class T, int ARRAYSIZE>
Queues<T, ARRAYSIZE>& Queues<T, ARRAYSIZE>::operator=(const Queues<T, ARRAYSIZE>& cola1) {
    copyAll(cola1);
}

#endif // QUEUE_H_INCLUDED
