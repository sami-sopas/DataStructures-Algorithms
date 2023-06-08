#include <iostream>
#include"Queue.h"
#include"Album.h"

using namespace std;

Album album;
Queue<Album> cola;

void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu()
{
    string auxiliar;
    float precio=0;
    int op,aux,opc=0;

    do{
    system("cls");
    cout<<"-------------------"<<endl;
    cout<<"| Cola de Albumes |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"1)Vacia"<<endl;
    cout<<"2)Encolar"<<endl;
    cout<<"3)Desencolar"<<endl;
    cout<<"4)Frente"<<endl;
    cout<<"5)Imprimir"<<endl;
    cin>>opc;
    cin.ignore();

    switch(opc){
    case 1:{ ///VERIFICAR SI LA COLA ESTA VACIA
        if(cola.isEmpty()){
            cout<<"\nLa cola esta vacia"<<endl;
        }else{
        cout<<"\nLa cola no esta vacia"<<endl;
        }
    break;
    }
    case 2:{ ///ENCOLAR ELEMENTO
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

        cola.enqueue(album); ///Aqui se encola el elemento

        cout<<"\nEncolando el elemento..."<<endl;
        cout<<"------------------" << endl;
        cout<<album<<endl; ///Aqui se imprime el elemento que se acaba de encolar
        cout<<"------------------"<<endl;
    break;
    }
    case 3:{ ///DESENCOLAR ELEMENTO
        cout<<"\nDesencolando el elemento: "<<endl;
        cout<<"------------------" << endl;
        cout<<cola.dequeue()<<endl; ///Aqui se desencola. y se imprime lo que se desencola
        cout<<"------------------"<<endl;
    break;
    }
    case 4:{ ///VER ELEMENTO EN EL FRENTE
        cout<<"\nEl frente es:\n------------------" << endl;
        cout << cola.getFront() <<endl;
        cout<<"------------------"<<endl;
    break;
    }
    case 5:{ ///IMPRIMIR LA COLA
        if(cola.isEmpty()){
            cout<<"La cola esta vacia"<<endl;
        }else{
        cout<<"\nImprimiendo cola..."<<endl;
        cout<<"------------------";

        cout<<cola.toString()<<endl;
        }
    break;
    }
}
       cout<<"\nQue desea hacer?"<<endl;
       cout<<"1)Regresar al menu\n2)Salir"<<endl;
       cin>>op;
    }while(op!=2);

}
