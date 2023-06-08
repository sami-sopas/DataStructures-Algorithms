#include <iostream>

#include "Stack.h"

/// Para randoms en C++
#include <random>
#include <chrono>
#include <functional>


using namespace std;

int main()
{
    default_random_engine generador(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribucion(1, 999);
    auto randomNum = bind(distribucion, generador);

    cout << "Empujando elementos...." << endl;

    Stack<int, 50> pilaNumeros;
    Stack<int,50>pilaNumeros2;
    int auxNumero;
    int auxiliar =100;
    int auxiliar2 = 200;
    int auxiliar3 = 300;

    //for(int i = 0; i <= 49; i++){
    auxNumero = randomNum();
    pilaNumeros.pushStack(auxiliar);
        pilaNumeros.pushStack(auxiliar2);
            pilaNumeros.pushStack(auxiliar3);


    cout << "Elemento empujado: " << auxiliar << endl;
        cout << "Elemento empujado: " << auxiliar2 << endl;
            cout << "Elemento empujado: " << auxiliar3 << endl;

  //  }

    cout << endl << endl;
    cout << "Imprimiendo pila con toString()" << endl;
    cout << pilaNumeros.toStringNumbers()<<endl;
 //   cout << pilaNumeros.toString()<<endl;

    cout<<"Tope: "<<pilaNumeros.getTop()<<endl;

//    pilaNumeros.copyAll(pilaNumeros2);
   // cout<<pilaNumeros2.toStringNumbers();


    cout << "Desvocando la pila..." << endl;
    while(!pilaNumeros.isEmpty()){
        cout << "El numero desvocado: " << pilaNumeros.popStack() << endl;
    }


    return 0;
}
