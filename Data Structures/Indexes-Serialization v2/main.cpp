#include <iostream>
#include"HashTable.h"

 /** La idea principal sobre la que se basa la inserción de elementos en esta estructura
    de datos y en consecuencia la operación de búsqueda en ella, consiste en
    transformar las claves (parte de los datos a almacenar) en direcciones dentro
    del arreglo o lista **/

using namespace std;

void displayMenu(void);

int main()
{
    system("Title Indices-Serializacion");
    displayMenu();

    return 0;
}

void displayMenu(void)
{
    HashTable h;
    Student student,studentAux;
    int opc,code;
    string aux;


    do{
        system("cls");
        cout << "Tabla de Hash \n"
             << "1) Insertar elemento \n"
             << "2) Eliminar elemento \n"
             << "3) Buscar elemento \n"
             << "4) Modificar elemento \n"
             << "5) Imprimir tabla \n"
             << "7) Imprimir indices \n"
             << "8) Vaciar tabla \n" << endl;

             cout << "Digite una opcion: "; cin >> opc;
             cout << endl;

             switch(opc)
             {
                 case 1: //Insertar
                     cout << "Escriba el codigo del alumno" << endl;
                     cin >> code;
                     student.setCode(code);

                     cout << "Escriba el nombre del alumno" << endl;
                     cin.sync();
                     getline(cin,aux);
                     student.setName(aux);

                     cout << "Escriba la carrera del alumno" << endl;
                     getline(cin,aux);
                     student.setCarrer(aux);

                     h.insertData(student);


                     break;

                 case 2: //Eliminar

                     cout << "Escriba el codigo del alumno a eliminar" << endl;
                     cin >> code;
                     student.setCode(code);

                     if(h.findData(student) == nullptr)
                     {
                         cout << "El dato a eliminar no existe" << endl;
                     }
                     else
                     {
                         cout << "Dato a eliminar !" << endl;
                         cout << h.retrieveData(h.findData(student)).toString() << endl;
                         h.deleteData(student);
                     }

                    break;

                 case 3: //Buscar

                     cout << "Escriba el codigo del alumno a buscar" << endl;
                     cin >> code;
                     student.setCode(code);

                     if(h.findData(student) == nullptr)
                     {
                         cout << "El alumno no existe" << endl;
                     }
                     else
                     {
                         cout << "Dato encontrado !" << endl;
                         cout << h.retrieveData(h.findData(student)).toString() << endl;
                     }

                    break;

                 case 4: //Modificar

                     cout << "Escriba el codigo del alumno que desee modificar" << endl;
                     cin >> code;
                     student.setCode(code);

                     if(h.findData(student) == nullptr)
                     {
                         cout << "El alumno no existe" << endl;
                     }
                     else
                     {
                         cout << "Dato encontrado !" << endl;
                         cout << h.retrieveData(h.findData(student)).toString() << endl;

                         student = h.retrieveData(h.findData(student));

                         cout << "\nDesea modificarlo? \n1)Si\n2)No" << endl;
                         cin >> opc;

                         if(opc == 1)
                         {
                             h.deleteData(student);

                             cout << "Escriba el nuevo nombre" << endl;
                             cin.sync();
                             getline(cin,aux);
                             student.setName(aux);

                             cout << "Escriba la nueva carrera" << endl;
                             getline(cin,aux);
                             student.setCarrer(aux);

                             h.insertData(student);
                         }


                     }
                    break;

                 case 5: //Imprimir

                     cout << h.toString();

                    break;

                 case 6: //Eliminar todo

                     cout << "Eliminando toda la tabla Hash...." << endl;
                     h.deleteAll();

                    break;

                 case 7: //Imprimir indices

                     cout << h.toStringIndexes() << endl;

                    break;
             }

    cout << endl;
    system("pause");
    }while(opc!=8);

}
