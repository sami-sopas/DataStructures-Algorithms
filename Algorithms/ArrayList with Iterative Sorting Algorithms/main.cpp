#include <iostream>
#include <string>
#include <cstdlib>

#include "list.h"
#include "student.h"
#include "name.h"

using namespace std;

int main() {
    List<Student> lista1;
    Student estudiante;
    Name auxName;

    /// int aux2;
    string rep, aux;
    float cali;

    char op;

    do {
        cout << "Codigo: ";
        getline(cin, rep);
        estudiante.setCode(rep);

        cout << "Apellido: ";
        getline(cin, rep);
        auxName.setLastName(rep);

        cout << "Nombre: ";
        getline(cin, rep);
        auxName.setFirstName(rep);

        estudiante.setName(auxName);

        cout << "Carrera: ";
        getline(cin, rep);
        estudiante.setCareer(rep);

        cout << "Promedio: ";
        cin >> cali;
        estudiante.setGrade(cali);

        try {
            lista1.insertData(lista1.getLastPos(), estudiante);
        } catch(ListException ex) {
            cout << "Hubo algun problema..." << endl;
            cout << ex.what() << endl;
        }

        cout << "Estudiante insertado exitosamente" << endl << endl;

        do {
            cout << "Insertar otro? (S/N): ";
            cin >> op;
            cin.ignore();

            op = toupper(op);
        } while(op != 'S' and op != 'N');

    } while(op == 'S');


    cout << endl << endl;

    cout << "Contenido de la lista: " << endl;
    cout << lista1.toString() << endl;


    cout << "Ordenando lista..." << endl;
    lista1.superShellSort();
    cout << "Contenido de la lista ordenada: " << endl;
    cout << lista1.toString() << endl;

    /*
     cout << "Dame el codigo a buscar: ";
     getline(cin, aux);
     estudiante.setCode(aux);


     aux2 = lista1.linearFindData(estudiante);
     if(aux2 == -1){
         cout << "EL ALUMNO NO FUE ENCONTRADO" << endl;
     }else{
         cout << "El alumno fue encontrado en la posicion: " << aux2 + 1;
         cout << "Se encontro el registro: " << endl;
         cout << lista1.retrieveData(aux2).toString();
     }

     aux2 = lista1.binaryFindData(estudiante);
     if(aux2 == -1){
         cout << "EL ALUMNO NO FUE ENCONTRADO" << endl;
     }else{
         cout << "El alumno fue encontrado en la posicion: " << aux2 + 1;
         cout << "Se encontro el registro: " << endl;
         cout << lista1.retrieveData(aux2).toString();
     }

     delete lista1;*/

}
