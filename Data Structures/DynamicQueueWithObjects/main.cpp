#include <iostream>


#include "queue.h"
#include "student.h"
#include "name.h"

using namespace std;

int main() {
    Queue<Student> cola1;
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
            cola1.enqueue(estudiante);
        } catch(Queue<Student>::Exception ex) {
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
    cout << cola1.toString() << endl;

    cout << endl << endl;
    cout << "Copeando la cola..." << endl;
    Queue<Student> copia(cola1);

    cout << endl << endl;
    cout << "Desapilando la cola..." << endl;
    while(!cola1.isEmpty()){
        cout << cola1.dequeue() << endl;
    }

    cout << endl << endl;
    cout << "Cola copeada:" << endl;
    cout << copia.toString();
    return 0;
}
