///Ramirez Cuenca Samuel Osvaldo_Entregable 8

///Librerias a incluir---
#include <iostream>
#include"Stack.h"
#include"album.h"

using namespace std;

Stack<Album> pila; ///Creacion del objeto pila que manejara datos de tipo Album
Album album; ///Creacion del objeto album

void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu(){
    string auxiliar;
    float precio=0;
    int op,opc=0;
    int aux;

    do{
    system("cls");
    cout<<"Pila de Albumes"<<endl;
    cout<<"---------------"<<endl;
    cout<<"1)Vacia"<<endl;
    cout<<"2)Push"<<endl;
    cout<<"3)Pop"<<endl;
    cout<<"4)Tope"<<endl;
    cout<<"5)Imprimir"<<endl;
    cout<<"6)Volcado"<<endl;

    cout << endl;
    cout <<"Ingrese una opcion"<<endl;
    cin>>opc;
    cin.ignore();

    switch(opc){
    case 1:{
        if(pila.isEmpty()){
            cout << endl;
            cout<<"La pila esta vacia"<<endl;
        }else{
        cout << endl;
        cout<<"La pila ya no esta vacia"<<endl;
        }
    break;
    }
    case 2:{
        cout<<"Ingrese el nombre del album: \n";
        getline(cin,auxiliar);
        album.setNombre(auxiliar);

        cout<<"Ingrese el anio: \n";
        cin >> aux;
        album.setAnio(aux);

        cout<<"Ingrese la cantidad disponible de albumes: \n";
        cin >> aux;
        album.setCantidad(aux);

        cout<<"Ingrese el precio: \n";
        cin>>precio;
        album.setPrecio(precio);

        pila.push(album); ///Aqui se inserta el dato o push. Este se inserta en la ultima posicio o tope

        cout<<"\nPusheando el elemento: "<<endl;
        cout<<album << endl; ///Aqui se imprime el ultimo elemento que se empujo a la pila
    break;
    }
    case 3:{
        if(pila.isEmpty()){
            cout<<"La pila esta vacia"<<endl;
        }else{
         ///Aqui se elimina el ultimo elemento que se inserto en la pila
        cout<<"\nPopeando el elemento: "<<endl;
        cout<< pila.pop() <<endl;
        }
    break;
    }
    case 4:{
        if(pila.isEmpty()){
            cout<<"No hay tope porque la pila esta vacia"<<endl;
        }else{
        cout<<"\nEl tope es: "<<endl;
        cout << pila.getTop();           ///Se imprime el dato que se encuentra inserto al ultimo (que esta en el tope)
        }
    break;
    }
    case 5:{
        cout<<"\nImprimiendo Pila..."<<endl;
        cout<<pila.toString()<<endl; ///Se imprimen todos los elementos de la pila

    break;
    }
    case 6:{
        if(pila.isEmpty()){
            cout<<"La pila esta vacia"<<endl;
        }else{
        cout<<"\nDesvocando Pila..."<<endl;
          while(!pila.isEmpty()){  /** Con un ciclo while. vamos haciendo pop en todos los elementos e imprimiendolos
                                          el ciclo termina hasta que la pila este vacia **/
         cout << pila.pop() << endl;
        }
        }
    break;
    }
}
       cout<<"\nQue desea hacer?"<<endl;
       cout<<"1)Regresar al menu\n2)Salir"<<endl;
       cin>>op;
    }while(op!=2);
}
