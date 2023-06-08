///Ramirez Cuenca Samuel Osvaldo_Entregable 6

///Librerias a incluir------
#include <iostream>
#include"Cola.h"
#include"Album.h"
using namespace std;
void menu(); ///Prototipo funcion menu


int main()
{
    menu();
    return 0;
}

void menu()
{
    Album album;///Instancia de objeto Album
    Cola<Album,50>cola; ///Instancia de objeto TDA cola

    string auxiliar;
    float precio=0;
    int op,opc=0;

    do{
    system("cls");
    cout<<"-------------------"<<endl;
    cout<<"| Cola de Albumes |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"1)Vacia"<<endl;
    cout<<"2)LLena"<<endl;
    cout<<"3)Encolar"<<endl;
    cout<<"4)Desencolar"<<endl;
    cout<<"5)Frente"<<endl;
    cout<<"6)Imprimir"<<endl;
    cin>>opc;
    cin.ignore();

    switch(opc){
    case 1:{ ///VERIFICAR SI LA COLA ESTA VACIA
        if(cola.estaVacia()){
            cout<<"\nLa cola esta vacia"<<endl;
        }else{
        cout<<"\nLa cola no esta vacia"<<endl;
        }
    break;
    }
    case 2:{ ///VERIFICAR SI LA COLA ESTA LLENA
        if(cola.estaLLena()){
            cout<<"\nLa cola esta llena"<<endl;
        }else{
        cout<<"\nLa cola no esta llena"<<endl;
        }
    break;
    }
    case 3:{ ///ENCOLAR ELEMENTO
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

        cola.encolar(album); ///Aqui se encola el elemento

        cout<<"\nEncolando el elemento..."<<endl;
        cout<<"------------------";
        cout<<album.toString()<<endl; ///Aqui se imprime el elemento que se acaba de encolar
        cout<<"------------------"<<endl;
    break;
    }
    case 4:{ ///DESENCOLAR ELEMENTO
        cout<<"\nDesencolando el elemento: "<<endl;
        cout<<"------------------";
        cout<<cola.desencolar().toString()<<endl; ///Aqui se desencola. y se imprime lo que se desencola
        cout<<"------------------"<<endl;
    break;
    }
    case 5:{ ///VER ELEMENTO EN EL FRENTE
        cout<<"\nEl frente es:\n------------------"<<cola.getFrente().toString()<<endl;
        cout<<"------------------"<<endl;
    break;
    }
    case 6:{ ///IMPRIMIR LA COLA
        if(cola.estaVacia()){
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

