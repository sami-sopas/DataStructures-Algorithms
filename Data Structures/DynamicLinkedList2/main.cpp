#include <iostream>


#include "List.h"
#include "student.h"
#include "name.h"

using namespace std;

int main() {
    List<Student> lista1;
    Student estudiante;
    Name auxName;

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
        } catch(List<Student>::Exception ex) {
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
    /*
        cout << "Anulando lista..." << endl;
        lista1.deleteAll();

        cout << "Contenido de la lista: " << endl;
        cout << lista1.toString() << endl;
        */
    cout << "Dame el codigo del alumno a eliminar: ";
    getline(cin, aux);
    estudiante.setCode(aux);

    cout << "Dios no me mates" << endl;
    lista1.deleteData(lista1.findData(estudiante));
    cout << "Creo que se elimino bien?" << endl << endl;

    cout << "Contenido de la lista: " << endl;
    cout << lista1.toString() << endl;

    return 0;
}
