#include <iostream>

/// Para randoms en C++
#include <random>
#include <chrono>
#include <functional>

#include "queue.h"
#include <stdlib.h>

using namespace std;

int main() {
    system("Title La Cola");
    Queues<int, 30> colaEnteros;

    int aux=1;
    int aux2=2;
    int aux3=3;
        colaEnteros.enqueue(aux);
        colaEnteros.enqueue(aux2);
        colaEnteros.enqueue(aux3);
        cout << "Encolando: " << aux << endl;
        cout << "Encolando: " << aux2 << endl;
        cout << "Encolando: " << aux3 << endl;

         cout <<"Impresion: "<<endl;
         cout<<colaEnteros.toStringNumbers()<<endl;

         cout<<"Frente: "<<endl;
         cout<<colaEnteros.getFront();



        cout << endl << endl;
        cout << "Desencolando" << endl;
        //while(!colaEnteros.isEmpty()) {
            cout << colaEnteros.dequeue() << endl;
      //  }
      cout<<"Impresion: "<<endl;
      cout<<colaEnteros.toStringNumbers()<<endl;


    /*
        aux = randomNum();
        colaEnteros.enqueue(aux);
        cout << colaEnteros.toStringNumbers();*/

  /* Queues<int, 30> nueva(colaEnteros);

   cout << "Elementos de la nueva cola: " << endl << endl;
    cout << nueva.toStringNumbers();*/
    return 0;
}
