#include <iostream>
#include"Graph.h"

using namespace std;

void displayMenu();

int main()
{
    displayMenu();

    return 0;
}

void displayMenu()
{
    Graph graph;
    Place place,ori,dest;
    unsigned short int opc;
    string aux;
    string weight;

    do{
        system("cls");

        cout << "----- MENU DEL GRAFO ----- \n"
             << "1) Insertar Vertice \n"
             << "2) Insertar Arista \n"
             << "3) Eliminar Vertice \n"
             << "4) Eliminar Arista \n"
             << "5) Imprimir Grafo \n"
             << "6) Eliminar Grafo \n"
             << "7) Cargar a txt \n"
             << "8) Leer txt \n" << endl;

             cout << "Ingrese una opcion -> "; cin >> opc;
             cout << endl;

             switch(opc)
             {
                 case 1: //Insertar vertice ---------------------

                     cout << "Escriba el nombre del pais" << endl;
                     cin.sync();
                     getline(cin,aux);
                     place.setCountry(aux);

                     cout << "Escriba el nombre del estado" << endl;
                     getline(cin,aux);
                     place.setState(aux);

                     cout << "Escriba el nombre de la ciudad" << endl;
                     getline(cin,aux);
                     place.setCity(aux);

                     graph.insertVertex(place);

                     break;

                  case 2: //Insertar arista -----------------------

                      cout << "Vertices disponibles" << endl;
                      graph.displayVertexes();
                      cout << endl;

                      cout << "Escriba el vertice origen" << endl;
                      cin.sync();
                      getline(cin,aux);
                      ori.setCountry(aux);

                      cout << "Escriba el vertice destino" << endl;
                      getline(cin,aux);
                      dest.setCountry(aux);

                      cout << "Escriba el peso de la arista" << endl;
                      getline(cin,weight);

                      graph.insertEdge(ori,dest,weight);

                      break;

                  case 3: //Eliminar vertice -------------------------

                      cout << "Escriba el nombre del vertice a eliminar" << endl;
                      cin.sync();
                      getline(cin,aux);
                      place.setCountry(aux);

                      graph.deleteVertex(place);

                      break;

                  case 4: //Eliminar arista ---------------------------

                      cout << "Escriba el origen de la arista a eliminar" << endl;
                      cin.sync();
                      getline(cin,aux);
                      ori.setCountry(aux);

                      cout << "Escriba el destino de la arista a eliminar" << endl;
                      getline(cin,aux);
                      dest.setCountry(aux);

                      graph.deleteEdge(ori,dest);

                      break;

                   case 5: //Imprimir grafo -----------------------------

                       cout << "Imprimiendo grafo..." << endl;
                       cout << graph.toString();

                       break;

                   case 6: //Eliminar grafo -----------------------------

                       cout << "Eliminando grafo..." << endl;
                       graph.deleteAll();
                       cout << "Grafo vacio!" << endl;

                       break;

                   case 7: //Cargar a txt ------------------------------

                       cout << "Cargando datos a file01...." << endl;
                       graph.saveData();

                       break;

                   case 8: //Leer txt ------------------------------------

                       cout << "Leyendo datos de file01..." << endl;
                       graph.readData();

                       break;
             }


        system("pause");
    }while(opc != 9);
}
