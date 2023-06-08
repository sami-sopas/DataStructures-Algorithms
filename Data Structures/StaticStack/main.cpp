///Ramirez Cuenca Samuel Osvaldo_Entregable 5
//Librerias a incluir-------
#include <iostream>
#include"album.h"
#include"Pila.h"
#include<string>
using namespace std;

int main()
{
    Album album; ///Creacion del objeto album
    Pila<Album,50>pila; ///Creacion del objeto pila

    string auxiliar;
    float precio=0;
    int op,opc=0;

    do{
    system("cls");
    cout<<"Pila de Albumes"<<endl;
    cout<<"---------------"<<endl;
    cout<<"1)Vacia"<<endl;
    cout<<"2)LLena"<<endl;
    cout<<"3)Push"<<endl;
    cout<<"4)Pop"<<endl;
    cout<<"5)Tope"<<endl;
    cout<<"6)Imprimir"<<endl;
    cout<<"7)Volcado"<<endl;

    cout << endl;
    cout <<"Ingrese una opcion"<<endl;
    cin>>opc;
    cin.ignore();

    switch(opc){
    case 1:{
        if(pila.estaVacia()){
            cout << endl;
            cout<<"La pila esta vacia"<<endl;
        }else{
        cout << endl;
        cout<<"La pila ya no esta vacia"<<endl;
        }
    break;
    }
    case 2:{
        if(pila.estaLLena()){
            cout << endl;
            cout<<"La pila esta llena"<<endl;
        }else{
        cout << endl;
        cout<<"La pila no esta llena"<<endl;
        }
    break;
    }
    case 3:{
        cout<<"Ingrese el nombre del album: \n";
        getline(cin,auxiliar);
        album.setNombre(auxiliar);

        cout<<"Ingrese el nombre del interprete: \n";
        getline(cin,auxiliar);
        album.setInterprete(auxiliar);

        cout<<"Ingrese el anio: \n";
        getline(cin, auxiliar);
        album.setAnio(auxiliar);

        cout<<"Ingrese la cantidad disponible de albumes: \n";
        getline(cin, auxiliar);
        album.setCantidad(auxiliar);

        cout<<"Ingrese el precio: \n";
        cin>>precio;
        album.setPrecio(precio);

        pila.pushPila(album); ///Aqui se inserta el dato o push. Este se inserta en la ultima posicio o tope

        cout<<"\nPusheando el elemento: "<<endl;
        cout<<album.toString()<<endl; ///Aqui se imprime el ultimo elemento que se empujo a la pila
    break;
    }
    case 4:{
        if(pila.estaVacia()){
            cout<<"La pila esta vacia"<<endl;
        }else{
        pila.popPila(); ///Aqui se elimina el ultimo elemento que se inserto en la pila
        cout<<"\nPopeando el elemento: "<<endl;
        cout<< album.toString()<<endl;
        }
    break;
    }
    case 5:{
        if(pila.estaVacia()){
            cout<<"No hay tope porque la pila esta vacia"<<endl;
        }else{
        cout<<"\nEl tope es: "<<endl;
        cout <<
        pila.getTope().toString()<<endl; ///Se imprime el dato que se encuentra inserto al ultimo (que esta en el tope)
        }
    break;
    }
    case 6:{
        cout<<"\nImprimiendo Pila..."<<endl;
        cout<<pila.toString()<<endl; ///Se imprimen todos los elementos de la pila

    break;
    }
    case 7:{
        if(pila.estaVacia()){
            cout<<"La pila esta vacia"<<endl;
        }else{
        cout<<"\nDesvocando Pila..."<<endl;
          while(!pila.estaVacia()){  /** Con un ciclo while. vamos haciendo pop en todos los elementos e imprimiendolos
                                          el ciclo termina hasta que la pila este vacia **/
         cout<<pila.popPila().toString()<<endl;
        }
        }
    break;
    }
}
       cout<<"\nQue desea hacer?"<<endl;
       cout<<"1)Regresar al menu\n2)Salir"<<endl;
       cin>>op;
    }while(op!=2);

    return 0;
}
