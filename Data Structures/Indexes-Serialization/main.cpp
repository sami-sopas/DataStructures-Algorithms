#include <iostream>
#include"HashTable.h"
#include"Student.h"

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
    HashTable<Student> h;
    Student student,studentAux;
    unsigned int opc,code,pos;
    string aux;


    do{
        system("cls");
        cout << "\t Tabla de Hash \n"
             << "-----------------------------------\n"
             << "1) Insertar elemento \n"
             << "2) Eliminar elemento \n"
             << "3) Buscar elemento \n"
             << "4) Modificar elemento \n"
             << "5) Imprimir tabla \n"
             << "6) Imprimir indices \n"
             << "7) Vaciar tabla \n"
             << "8) Cargar a txt \n"
             << "9) Leer txt \n"
             << "10) Salir \n" << endl;

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

                     pos = h.HashFunction(student);

                     cout << "\nEl dato se guardo en la posicion " << pos << endl;

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
                         pos = h.HashFunction(student);

                         cout << "\nDato a eliminar encontrado en la posicion " << pos << endl;
                         cout << h.retrieveData(h.findData(student)).toString() << endl;

                        cout << "\nDesea eliminarlo? \n1)Si\n2)No" << endl;
                         cin >> opc;

                         if(opc == 1)
                         {
                             h.deleteData(student);

                             cout << "\n Dato eliminado correctamente !" << endl;
                         }
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
                         pos = h.HashFunction(student);
                         cout << "\nDato encontrado en la posicion " << pos << endl;
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
                         pos = h.HashFunction(student);
                         cout << "\nDato encontrado en la posicion " << pos << endl;
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

                             cout << "\n Dato modificado correctamente !" << endl;
                         }


                     }
                    break;

                 case 5: //Imprimir

                     cout << "Imprimiendo tabla Hash...\n" << endl;
                     cout << h.toString();

                    break;

                 case 6: //Imprimir indices

                     cout << "Imprimiendo indices de la tabla....\n" << endl;
                     cout << h.toStringIndexes() << endl;

                    break;

                 case 7: //Eliminar todo

                     cout << "Eliminando toda la tabla Hash....\n" << endl;
                     h.deleteAll();

                    break;

                 case 8: //Cargar a txt

                     cout << "Cargando datos al txt...\n" << endl;
                     h.writeFile();

                    break;

                 case 9: //Leer txt

                    cout << "Leyendo datos del txt...\n" << endl;
                    h.readFile();

                    break;

                 case 10:
                    break;

                 default :

                    cout << "Esa opcion no existe mano" << endl;

                    break;
             }

    cout << endl;
    system("pause");
    }while(opc!=10);
}
