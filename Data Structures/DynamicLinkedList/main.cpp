///Ramirez Cuenca Samuel Osvaldo_Entregable 7

#include <iostream>
#include"List.h"
#include"album.h"

using namespace std;

Album album;
List<Album> lista;

void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu(){

    string auxiliar;
    int opc,aux;
    float precio;

    do{
            system("cls");
        cout << "LISTA DINAMICA !!! \n";
        cout << "----------------------" << endl;

        cout << "[1] Insertar elementos" << endl;
        cout << "[2] Imprimir lista" << endl;
        cout << "[3] Eliminar elementos" << endl;
        cout << "[4] Ordenar" << endl;
        cout << "[5] Recuperar" << endl;
        cout << "[6] Anular lista" << endl;
        cout << "[7] Copiar lista" << endl;
        cout << "[8] Insertar despues de un elemento" << endl;
        cout << "[9] Primero" << endl;
        cout << "[10] Ultimo" << endl;
        cout << "[11] Anterior" << endl;
        cout << "[12] Siguiente " << endl;

        cin >> opc;

        switch(opc){
            case 1: ///INSERCION DE DATOS NORMAL
                cout << "Ingrese el nombre" << endl;
                cin.sync();
                getline(cin,auxiliar);
                album.setNombre(auxiliar);

                cout << "Ingrese el autor" << endl;
                getline(cin,auxiliar);
                album.setAutor(auxiliar);

                cout << "Ingrese el anio" << endl;
                cin >> aux;
                album.setAnio(aux);

                cout << "Ingrese la cantidad" << endl;
                cin >> aux;
                album.setCantidad(aux);

                cout << "Ingrese precio" << endl;
                cin >> precio;
                album.setPrecio(precio);

                cout << endl;

                cout << "Dato ingresado" << endl;
                cout << album << endl;

                lista.insertData(lista.getLastPos(),album); //Insercion

                cout << "Datos ingresador correctamente" << endl;

                cout << endl;

                cout << "Contenido de la lista" << endl;
                cout << lista.toString();
                system("pause");

                break;

            case 2: /// IMPRIMIR

                if(lista.isEmpty()){
                        cout << "LISTA VACIA" << endl;
                }else{
                cout << "LISTA COMPLETA" << endl;
                cout << lista.toString();
                }
                system("pause");

                break;

            case 3: /// ELIMINAR
                cout << "Escribe el nombre del album a eliminar" << endl;
                cin.sync();
                getline(cin,auxiliar);
                album.setNombre(auxiliar);

                if(lista.findData(album) == nullptr){
                    cout << "El dato no existe" << endl;
                    system("pause");
                    return displayMenu();
                }

                lista.deleteData(lista.findData(album));

                cout << "Dato eliminado !!" << endl;

                system("pause");

                break;

            case 4:
                lista.bubbleSort();

                cout << "Lista ordenada" << endl;
                cout << lista.toString();
                system("pause");

                break;

            case 5:
                cout << "Dame el nombre del album a recuperar" << endl;
                cin.sync();
                getline(cin,auxiliar);
                album.setNombre(auxiliar);

                cout << "Elemento recuperado!" << endl;
                cout << lista.retrieve(lista.findData(album)) << endl;
                system("pause");

                break;

            case 6:
                cout << "Anular lista" << endl;
                lista.deleteAll();
                cout << "Lista eliminada!" << endl;
                system("pause");

                break;

            case 7:{
                cout << "Copiando la lista" << endl;
                List<Album> copia(lista);

                cout << "LISTA ORIGINAL" << endl;
                cout << lista.toString() << endl;

                cout << "LISTA COPIA" << endl;
                cout << copia.toString() << endl;

                system("pause");
                }

                break;

            case 8:{
                Album albumAux;

                cout << "Ingrese el nombre de un elemento existente" << endl;
                cin.sync();
                getline(cin,auxiliar);
                albumAux.setNombre(auxiliar);

                cout << "Ingrese nombre del elemento a insertar" << endl;
                cin.sync();
                getline(cin,auxiliar);
                album.setNombre(auxiliar);

                cout << "Ingrese el autor" << endl;
                getline(cin,auxiliar);
                album.setAutor(auxiliar);

                cout << "Ingrese el anio" << endl;
                cin >> aux;
                album.setAnio(aux);

                cout << "Ingrese la cantidad" << endl;
                cin >> aux;
                album.setCantidad(aux);

                cout << "Ingrese precio" << endl;
                cin >> precio;
                album.setPrecio(precio);

                cout << endl;

                cout << "Dato ingresado" << endl;
                cout << album << endl;

                lista.insertData(lista.findData(albumAux),album); //Insercion

                cout << "Datos ingresador correctamente" << endl;

                system("pause");
                }

                break;

            case 9:
                cout << "Primer elemento de la lista" << endl;
                cout << lista.retrieve(lista.getFirstPos()) << endl;
                system("pause");

                break;

            case 10:
                cout << "Ultimo elemento de la lista" << endl;
                cout << lista.retrieve(lista.getLastPos()) << endl;
                system("pause");

                break;

            case 11:
                cout << "Ingrese el nombre de un elemento para saber su anterior" << endl;
                cin.sync();
                getline(cin,auxiliar);
                album.setNombre(auxiliar);

                cout << lista.retrieve(lista.getPrevPos(lista.findData(album))) << endl;
                system("pause");

                break;

            case 12:
                cout << "Ingrese el nombre de un elemento para saber su siguiente" << endl;
                cin.sync();
                getline(cin,auxiliar);
                album.setNombre(auxiliar);

                cout << lista.retrieve(lista.getNextPos(lista.findData(album))) << endl;
                system("pause");

                break;

        }


    }while(opc!=10);

}
