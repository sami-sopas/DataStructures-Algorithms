///Ramirez Cuenca Samuel Osvaldo_Entregable 4

///Librerias a incluir-------------
#include <iostream>
#include<windows.h>
#include"Lista.h"
#include"album.h"
#define color SetConsoleTextAttribute
using namespace std;

void menu(); ///Prototipo de la funcion menu
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); ///Para cambiar el color en la consola

Album album; ///Creacion del objeto
Lista<Album,50>lista; ///Lista que manejara dato de tipo album(50)

///Variables auxiliares para insertar la informacion
string auxiliar;
float precio;
int op,opc,pos;

int main()
{
    menu();
    return 0;
}

void menu(){

    do{
        system("cls");
        cout << "\t LISTA ESTATICA" << endl;
        cout << "\t-----------------" << endl;
        cout << "\t< Menu Principal >" << endl;
        cout << "\t[1] Insertar dato" << endl;
        cout << "\t[2] Insertar dato dada una posicion" << endl;
        cout << "\t[3] Eliminar " << endl;
        cout << "\t[4] Recuperar" << endl;
        cout << "\t[5] Anular lista" << endl;
        cout << "\t[6] Mas opciones... " << endl;
        cout << "\t[7] Salir" << endl;

        cout << endl;
        cout <<"\tIngrese una opcion" << endl;
        cout << "\t"; cin >> opc;
        cout << endl;

        switch(opc){
            case 1:{ ///INSERTAR DATOS -----------------------------------------

                cout << "\tIngrese el nombre del album: " << endl;
                cin.ignore(); ///Funcion para que el codigo de tiempo de escribir y no se pase a la siguiente linea
                cout << "\t"; getline(cin,auxiliar); ///Leemos el string con getline
                album.setNombre(auxiliar); ///Enviamos ese dato al campo nombre

                cout << "\tIngrese el interprete: " << endl;
                cout << "\t"; getline(cin,auxiliar);
                album.setInterprete(auxiliar);

                cout << "\tIngrese el anio: " << endl;
                cout << "\t"; getline(cin, auxiliar);
                album.setAnio(auxiliar);

                cout << "\tIngrese la cantidad disponible de albumes: " << endl;
                cout << "\t"; getline(cin, auxiliar);
                album.setCantidad(auxiliar);

                cout << "\tIngrese el precio: " << endl;
                cout << "\t"; cin >> precio;
                album.setPrecio(precio);

                /**Para este punto. El objeto album ya tiene la informacion dentro. Aqui se insertan en la lista
                    obteniendo la ultima posicion y enviando ahi el objeto**/
                lista.insertarDato(lista.getUltimaPos(),album);

                cout << endl;
                color(hConsole,10); /// Esto solo cambia el color en consola
                cout << "\tRegistro Exitoso! :p" << endl;

                cout << album.toString() << endl; ///Se imprime toda la informacion anterior para verificar que este bien

                color(hConsole,7); ///Se regresa al color original de la consola

            break;
            }

            case 2:{ ///INSERTAR DADA UNA POSICION --------------------------------------------

             ///Primero se pide la posicion en donde se quiera insertar
                cout << "\tIngrese la posicion en donde quiera insertar los datos " << endl;
                cout << "\t"; cin >> pos;

            ///Despues se piden los datos normalmente
                cout << "\tIngrese el nombre del album: " << endl;
                cin.ignore();
                cout << "\t"; getline(cin,auxiliar);
                album.setNombre(auxiliar);

                cout << "\tIngrese el interprete: " << endl;
                cout << "\t"; getline(cin,auxiliar);
                album.setInterprete(auxiliar);

                cout << "\tIngrese el anio: " << endl;
                cout << "\t"; getline(cin, auxiliar);
                album.setAnio(auxiliar);

                cout << "\tIngrese la cantidad disponible de albumes: " << endl;
                cout << "\t"; getline(cin, auxiliar);
                album.setCantidad(auxiliar);

                cout << "\tIngrese el precio: " << endl;
                cout << "\t"; cin >> precio;
                album.setPrecio(precio);

                /**Haciendo uso de la misma funcion de insertarDato, insertamos dada la posicion que nos dio
                   se le agrego el menos 1 para hacerlo mas facil para el usuario, vemos que tambien se le envia el objeto
                   con todos los datos que acabamos de ingresar anteriormente**/

                lista.insertarDato(pos-1,album);

                cout << endl;
                color(hConsole,10);
                cout << "\tRegistro Exitoso! :D" << endl;

                cout << album.toString() << endl;
                color(hConsole,7);

            break;
            }

            case 3:{ ///ELIMINAR DATOS DADA UNA POSICION-------------------------------------

            ///Pedimos la posicion
                cout << "\tIngrese la posicion de donde quiera eliminar los datos" << endl;
                cout << "\t"; cin >> pos;

                cout << endl;
                color(hConsole,12);

            ///Aqui primero recuperamos el dato de la posicion que nos dio, para que verifique el usuario que si esta bien
                cout << "\tEliminando los siguientes datos de la posicion " << pos << endl;

                cout << lista.recuperarDato(pos).toString() << endl;

                color(hConsole,7);

                lista.borrarDato(pos); ///Finalmente se le envia la posicion y se elimina

            break;
            }

            case 4:{ ///RECUPERAR DADA UNA POSICION--------------------------------------

            ///Ingresa la posicion del elemento a recuperar
                cout << "\tIngrese la posicion del elemento a recuperar" << endl;
                cout << "\t"; cin >> pos;

                cout << endl;
                color(hConsole,11);
            /** Se imprime la informacion de el dato de la posicion dada con toString,
                es importante recordar que este metodo va de la mano con el de localizar **/

                cout << "\tEl dato recuperado de la posicion " << pos << " es: " << endl;
                cout << lista.recuperarDato(pos).toString() << endl;
                color(hConsole,7);

            break;
            }

            case 5:{ ///VACIAR LISTA------------------------------------------------

                cout << "\tEsta seguro de querer borrar toda la lista? " << endl;
                cout << "\t(Este proceso es irreversible)" << endl;
                cout << endl;
                cout << "\t1)Si\n\t2)No" << endl;
                cout << "\t"; cin >> pos;

                if(pos == 2){
                    return menu(); //Si no decide borrar todo. lo regresamos al menu
                }else{
                    cout << endl;
                    color(hConsole,12);
                    cout << "\tLista anulada!" << endl;
                    lista.borrarTodo(); //esta funcion borra todo. mas detalles en Lista.H
                    color(hConsole,7);
                }

            break;
            }

            case 6:{ ///MENU SECUNDARIO (PARA EVITAR TENER MUCHAS OPCIONES EN EL MENU PRINCIPAL---

                int opc2;
                system("cls");

                do{
                    cout << "\t LISTA ESTATICA" << endl;
                    cout << "\t---------------" << endl;
                    cout << "\t< Menu Secundario >" << endl;
                    cout << "\t[1] Vacia " << endl;
                    cout << "\t[2] LLena " << endl;
                    cout << "\t[3] Primero " << endl;
                    cout << "\t[4] Ultimo " << endl;
                    cout << "\t[5] Anterior" << endl;
                    cout << "\t[6] Siguiente " << endl;
                    cout << "\t[7] Imprimir" << endl;
                    cout << "\t[8] Regresar al menu principal " << endl;

                    cout << endl;
                    cout << "\tIngresar opcion: " << endl;
                    cout << "\t"; cin >> opc2;
                    cout << endl;

                }while(opc2==9);

                switch(opc2){ ///COMPROBAR SI LA LISTA ESTA VACIA--------------------
                    case 1:{
                        if(lista.estaVacia()){
                            cout << "\tEfectivamente, la lista esta vacia" << endl;
                        }else{
                            cout << "\tEn efecto, la lista YA no esta vacia" << endl;
                        }
                    break;
                    }

                    case 2:{ ///COMPROBAR SI LA LISTA LLEGO A SU LIMITE (LLENA)--------------
                        if(lista.estaLLena()) {
                            cout << "\tLa lista esta llena, cuidado!" << endl;
                        }else{
                            cout << "\tLa lista aun no esta llena, puedes seguir metiendo datos :)" << endl;
                        }

                    break;
                    }

                    case 3:{ ///OBTENER LA PRIMERA POSICION DE LA LISTA------------------------------
                        if(lista.estaVacia()) {
                            cout << "\tLa lista esta vacia!" << endl;
                        }else{
                            cout << "\tLa primera posicion de la lista es " << lista.getPrimeraPos() << endl;
                        }

                    break;
                    }

                    case 4:{ ///OBTENER LA ULTIMA POSICION CON DATOS DE LA LISTA--------------------
                        if(lista.estaVacia()) {
                            cout << "\tLa lista esta vacia!" << endl;
                        }else{
                            cout << "\tLa ultima posicion de la lista es " << lista.getUltimaPos() << endl;
                        }

                    break;
                    }

                    case 5:{ ///DADA UNA POSICION. OBTENER SU POSICION PREVIA
                        cout << "\tEscriba la posicion del que quiera saber la posicion previa" << endl;
                        cout << "\t"; cin >> pos;

                        if(lista.getPreviaPos(pos) == -1) { //Si regresa un (-1) es porque dio una posicion invalida o que no existe
                            cout << "\tPosicion invalida" << endl;
                        }else{
                            cout << "\tLa posicion previa a " << pos << " es " << lista.getPreviaPos(pos) << endl;
                        }

                    break;
                    }

                    case 6:{ ///DADA UNA POSICION. CONOCER LA POSICION SIGUIENTE--------------------
                        cout << "\tEscriba la posicion del que quiera saber la posicion siguiente" << endl;
                        cout << "\t"; cin >> pos;

                        if(lista.getSiguientePos(pos) == -1 ) { //Se realiza la misma validacion anterior
                            cout << "\tPosicion invalida" << endl;
                        }else{
                            cout << "\tLa posicion siguiente a " << pos << " es " << lista.getSiguientePos(pos) << endl;
                        }



                    break;
                    }

                    case 7:{ ///IMPRIMIR TODOS LOS ELEMENTOS DE LA LISTA CON TOSTRING------------------
                        if(lista.estaVacia()) {
                            cout << "\tNo hay elementos para imprimir, lista vacia" << endl;
                        }else{
                            cout << "\tImpriminedo lista..." << endl;
                            color(hConsole,14);
                            cout << lista.toString();
                            color(hConsole,7);
                        }

                    break;
                    }

                    case 8:{ ///REGRESAR AL MENU GENERAL
                        return menu();
                    break;
                    }

                    default:{
                        cout << "\tIngrese una opcion valida" << endl;
                    break;
                    }
                }

            break;
            }

            case 7:{

            break;
            }

            default:{
                cout << "\tOpcion no valida" << endl;
            break;
            }
        }
    cout << endl;
    cout << "\tQue deseas hacer" << endl;
    cout << "\t1)Continuar" << endl;
    cout << "\t2)Salir" << endl;
    cout << "\t"; cin >> op;
    }while(op!=2);
    cout << endl;
    color(hConsole,6);
    cout << "\tGracias por usar esta lista. ten un bonito dia :)" << endl;

}

