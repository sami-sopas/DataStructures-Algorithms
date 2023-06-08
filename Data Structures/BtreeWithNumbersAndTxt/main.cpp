#include <iostream>
#include <string.h>
#include "Btree.h"
#include "Player.h"

using namespace std;

int main()
{
    Btree arbol;
    Player player;
    int opc;
    string aux;
    int num;

    do{
            system("cls");
        cout << "1 insertar" << endl;
        cout << "2 eliminar" << endl;
        cout << "3 escribir en txt" << endl;
        cout << "4 leer de txt" << endl;
        cout << "5 imprimir" << endl;
        cin >> opc;

        switch(opc)
        {
        case 1:
            cout << "numero: "; cin >> num;
            arbol.insertData(arbol.getRoot(),num);

            break;

        case 2:
            cout << "numero: "; cin >> num;
            arbol.deleteData(arbol.getRoot(),num);

            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            arbol.inOrder(arbol.getRoot());
            system("pause");
            break;
        }

    }while(opc!=6);



    /*cout << "Leyendo del txt" << endl;
  //  arbol.readFile();

    player.setName("Juanito");
    player.setCountry("Mexico");
    player.setYears("18");

    cout << "Insertando" << endl;
    arbol.insertData(arbol.getRoot(),player);

    arbol.writeFile(arbol.getRoot());

    arbol.inOrder(arbol.getRoot());*/




    return 0;
}
