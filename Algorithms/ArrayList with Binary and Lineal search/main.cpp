#include <iostream>
#include <string>
#include <cstdlib>

#include "list.h"
#include "student.h"
#include "name.h"

using namespace std;

int main() {
    List<Student> myLista;
    Student myStudent;
    Name myName;

    int aux2;
    string myStr, aux;
    float myFloat;

    char op;

    do {
        cout << "Codigo: ";
        getline(cin, myStr);
        myStudent.setCode(myStr);

        cout << "Apellido: ";
        getline(cin, myStr);
        myName.setLastName(myStr);

        cout << "Nombre: ";
        getline(cin, myStr);
        myName.setFirstName(myStr);

        myStudent.setName(myName);

        cout << "Carrera: ";
        getline(cin, myStr);
        myStudent.setCareer(myStr);

        cout << "Promedio: ";
        cin >> myFloat;
        myStudent.setGrade(myFloat);

        try {
            myLista.insertData(myLista.getLastPos(), myStudent);
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
    cout << myLista.toString() << endl;


    cout << "Dame el codigo a buscar: ";
    getline(cin, aux);
    myStudent.setCode(aux);

    /*
    aux2 = myLista.linearFindData(myStudent);
    if(aux2 == -1){
        cout << "EL ALUMNO NO FUE ENCONTRADO" << endl;
    }else{
        cout << "El alumno fue encontrado en la posicion: " << aux2 + 1;
        cout << "Se encontro el registro: " << endl;
        cout << myLista.retrieveData(aux2).toString();
    }*/

    aux2 = myLista.binaryFindData(myStudent);
    if(aux2 == -1){
        cout << "EL ALUMNO NO FUE ENCONTRADO" << endl;
    }else{
        cout << "El alumno fue encontrado en la posicion: " << aux2 + 1;
        cout << "Se encontro el registro: " << endl;
        cout << myLista.retrieveData(aux2).toString();
    }

    ///delete myLista;

}
