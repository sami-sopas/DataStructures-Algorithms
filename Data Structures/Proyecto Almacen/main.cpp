#include <iostream>
#include<iomanip>
///Librerias para numeros random-----
#include <random>
#include <chrono>
#include <functional>
///----------------------------------
#include"Product.h"
#include "admin.h"
#include "seller.h"
#include"LDLCCED.h"
#include"Animaciones.h"
#include"date.h"

/**
Querido viajero:

Si estas leyendo esto, eres de los afortunados en tener nuestro codigo.

Cuando escribimos este codigo, solo Dios y nosotros sabiamos como funcionaba.
Ahora, solo Dios lo sabe!!

Asi que si estas tratando de entender este codigo y fracasas (seguramente)
No te preocupes! Es normal, te deseo suerte en esta pequeña travesia :)

Con amor:
-Equipo 98
**/

using namespace std;

    default_random_engine generador(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribucion(100, 999);
    auto randomNum = bind(distribucion, generador);


///Funciones del admin-----
void registrarProducto();
void eliminarProducto();
void cambiarContrasenaA();
void modificarProducto();
void ordena();
///------------------------

///Funciones del vendedor---
void venderProducto();
///-------------------------

///Funciones de ambos------
void login();
void buscarProducto();
void modifyInventory();
///------------------------

void recoverPreviousInventory();

void temporizador(int,int); ///Para cuando falle mas de 3 veces con la contraseña

bool validacion(char*);

Product producto;
Admin admin;
Seller seller;
List<Product> lista;
fstream myFile;

int main()
{
    system("Title Sistema de gestion de productos electronicos");
    recoverPreviousInventory();
    login(); //Para seleccionar si es admin o vendedor, y la validacion de password
    return 0;
}

void login()
{
    system("cls");
    string pass;
    char myChar[64];
    int opc,attempts = 3;
    perfiles();
    gotoxy(45,22); cout << "Seleccione una opcion: "; cin >> myChar;

    if(validacion(myChar)){ //Validamos que si meta un numero
        opc = atoi(myChar);
    }


    if(opc == 1){ ///Opcion 1 Admins
        system("cls");
        loginAdmin();

        gotoxy(55,15); cout << "Escriba la contrasenia: "; cin.sync();
        getline(cin,pass);

        while(pass != admin.getPassword())
        {
            attempts--; //Desde que se equivoca, aumenta en uno los intentos
            system("cls");
            loginAdmin(); //animacion

            gotoxy(55,12); cout << "Le quedan " << attempts << " intentos";
            gotoxy(55,15); cout << "Intente de nuevo: "; getline(cin,pass);

            if (attempts == 0) temporizador(3,30); //SI se equivoca mas de 3 veces, se va a un ciclo del que no podra salir
        }

        if(pass == admin.getPassword()){
            system("cls");
            iniciandoSesion(); //Animacion antes de llevarte a la interfaz
            interfazAdmin();
        }

    }else{ ///Opcion 2 Vendedor
        system("cls");
        loginVendedor();


        gotoxy(20,15); cout << "Escriba la contrasenia: "; cin.sync();
        getline(cin,pass);

        while(pass != seller.getPassword())
        {
            attempts--; //Desde que se equivoca, amenta en uno los intentos
            system("cls");
            loginVendedor(); //animacion

            gotoxy(20,12); cout << "Le quedan " << attempts << " intentos";
            gotoxy(20,15); cout << "Intente de nuevo: "; getline(cin,pass);

            if (attempts == 0) temporizador(3,30); //SI se equivoca mas de 3 veces, se va a un ciclo del que no podra salir
        }

        if(pass == seller.getPassword()){
            system("cls");
            iniciandoSesion(); //Animacion antes de llevarte a la interfaz principal
            interfazVendedor();
        }
    }

}


void interfazAdmin(){
    int opc;
    char myChar[50];

    do{
    system("cls");
    crearMarco();
    cout << endl << endl;
    cout << "\t" << "Que desea hacer?" << "\n\t"
            "1) Registrar producto " << "\n\t"
            "2) Buscar un producto" << "\n\t"
            "3) Eliminar un producto" << "\n\t"
            "4) Modificar producto" << "\n\t"
            "5) Imprimir lista" << "\n\t"
            "6) Cambiar contrasena de administador" << "\n\t"
            "7) Salir"<< endl;

            cout << "\t" << "Opcion: "; cin >> myChar;

            if(!validacion(myChar)){
            }else{
            opc=atoi(myChar);

            switch(opc){
                case 1: registrarProducto(); ///Insertar en la lista
                    break;

                case 2: buscarProducto(); ///Busqueda
                    break;

                case 3: eliminarProducto();
                    break;

                case 4: modificarProducto();
                    break;

                case 5:
                    cout << "\t" << "EL CONTENIDO DE LA LISTA ES: " << endl;
                    cout << lista.toString();///Imprimir lista
                    break;

                case 6: cambiarContrasenaA();
                    break;

                case 7:
                    return login();
                    break;

            }
            }
        do
        {
        cout << "\n\n\tQue deseas hacer? \n\t1)Continuar \n\t2)Salir" << endl;
        cout << "\t"; cin >> myChar;}
        while(!validacion(myChar));

    }while(opc!=2);

}

void interfazVendedor(){
    int opc;
    char myChar[50];

    do{
    system("cls");
    crearMarco();
    cout << endl << endl;
    cout << "\t" << "Que desea hacer?" << "\n\t"
            "1) Vender producto " << "\n\t"
            "2) Consultar productos" << "\n\t"
            "3) Salir " << "\n\t";

            cout << "\t" << "Opcion: "; cin >> myChar;

            if(!validacion(myChar)){

            }else{
            opc=atoi(myChar);
            switch(opc){
                case 1: venderProducto();
                    break;

                case 2: cout << "\t" << "EL CONTENIDO DE LA LISTA ES: " << endl;
                    cout<<lista.toString();///Imprimir el inventario (Está en el TXT)
                    break;

                case 3:
                    return login();
                    break;


            }
            }
        do{
        cout << "\n\n\tQue deseas hacer? \n\t1)Continuar \n\t2)Salir" << endl;
        cout << "\t"; cin >> myChar;}
        while(!validacion(myChar));
        opc=atoi(myChar);

    }while(opc!=2);

}

void registrarProducto(){
    string auxiliar;
    float precio;
    int cantidad;

    producto.setCode(randomNum());

    cout << endl;

    cout << "\t" << "Ingrese nombre: "; cin.sync(); getline(cin,auxiliar);
    cout << endl;
    producto.setName(auxiliar);

    cout << "\t" << "Ingrese categoria: "; getline(cin,auxiliar);
    cout << endl;
    producto.setCategory(auxiliar);

    cout << "\t" << "Ingrese precio: "; cin >> precio;
    cout << endl;
    producto.setPrice(precio);

    cout << "\t" << "Ingrese cantidad: "; cin >> cantidad;
    cout << endl;
    producto.setAmount(cantidad);

    cout << "\t" << "Su producto quedo asi:" << endl;
    printf(VERDEBAJITO);
    cout << "\t" << producto;
    printf(REGRESA);

    lista.insertData(lista.getLastPos(),producto); ///Insertamos los datos a la lista

    string inventory=lista.toString();
    admin.setInventory(inventory);

    string result="Producto: ";
    result+=producto.getName();
    result+=" ingresado, cantidad: ";
    result+=to_string(cantidad);
    admin.setHistory(result);
}

void buscarProducto(){
    char myChar[50];
    int aux;

    do{
    cout << endl;
    cout << "\t" << "Ingrese el codigo del producto"; cin >> myChar;
    }while(!validacion(myChar));

    aux=atoi(myChar);

    producto.setCode(aux);

    producto = lista.retrieve(lista.findData(producto));

    cout << "\t" << producto;

}

void eliminarProducto(){
    char myChar[64];
    int aux;

    do{
    cout << endl;
    cout << "\t" << "Ingrese el codigo del producto: "; cin >> myChar;
    }while(!validacion(myChar));

    aux=atoi(myChar);

    producto.setCode(aux);

    producto = lista.retrieve(lista.findData(producto));

    cout << endl;

    cout << "\tEsta seguro de querer eliminar el siguiente producto?" << endl;
    printf(ROJOBAJITO);
    cout << "\t" << producto << endl;
    printf(REGRESA);

    cout << endl;

    cout << "\t1)Si\n\t2)No\n";
    cout << "\tOpcion: "; cin >> aux;


    if(aux == 1){
        lista.deleteData(lista.findData(producto));

        cout << "\n\t" << "Producto eliminado!" << endl;


    string inventory=lista.toString();
    admin.setInventory(inventory);

    string result="Producto: ";
    result+=producto.getName();
    result+=" eliminado";
    admin.setHistory(result);

    }else{
        return;
    }
}

void modificarProducto(){


    string auxiliar;
    float precio;
    int cantidad;
    Product productoaux;

    char myChar[64];
    int aux;

    do{
    cout << endl;
    cout << "\t" << "Ingrese el codigo del producto: "; cin >> myChar;
    }while(!validacion(myChar));

    aux=atoi(myChar);

    producto.setCode(aux);

    producto = lista.retrieve(lista.findData(producto));
    productoaux=producto;

    cout << endl;

    cout << "\tProducto a modificar (el producto conservara el codigo): " << endl;
    cout << "\t" << producto << endl;

    lista.deleteData(lista.findData(producto));

    cout << endl;

    cout << "\t" << "Ingrese nombre: "; cin.sync(); getline(cin,auxiliar);
    cout << endl;
    producto.setName(auxiliar);

    cout << "\t" << "Ingrese categoria: "; getline(cin,auxiliar);
    cout << endl;
    producto.setCategory(auxiliar);

    cout << "\t" << "Ingrese precio: "; cin >> precio;
    cout << endl;
    producto.setPrice(precio);

    cout << "\t" << "Ingrese cantidad: "; cin >> cantidad;
    cout << endl;
    producto.setAmount(cantidad);

    lista.insertData(lista.findData(producto),producto);

    cout << "\t" << "Ahora el producto conserva los siguientes datos:" << endl;
    cout << "\t" << producto;

    string inventory=lista.toString();
    admin.setInventory(inventory);

    string result="Producto: ";
    result+=productoaux.getName();
    result+=" modificado, ahora es: ";
    result+=producto.getName();
    result+=" cantidad: ";
    result+=producto.getAmount();
    admin.setHistory(result);

}


void cambiarContrasenaA(){

    string nuevaContrasena;
    int opc;

    system("cls");
    cout<<"Seguro que quieres cambiar la contrasena\n1)Cambiar contrasena. \n2)Volver al menu. ";
    cin>>opc;

    switch(opc){
        do{
            case 1:
                cout<<"La contrasena actual es: "<<admin.getPassword();
                cout<<"\nIntroduce la nueva contrasena: ";
                cin>>nuevaContrasena;
                admin.setPassword(nuevaContrasena);
                cout<<"\nContrasena cambiada exitosamente!";
            break;

            case 2:
            break;
        }while(opc!=2);
    }
}

void venderProducto(){
    char myChar[50];
    int aux,aux2;

    do{
    cout << "\t" << "Ingrese el codigo del producto: "; cin >> myChar;
    }while(!validacion(myChar));

    aux=atoi(myChar);
    producto.setCode(aux);

    producto = lista.retrieve(lista.findData(producto));

    cout << "\t" << "El producto es el siguiente " << endl;
    cout << "\t" << producto;

    do{
    cout << "\t" << "Ingrese la cantidad a vender: "; cin >> myChar;
    }while(!validacion(myChar));
    aux=atoi(myChar);

    if(producto.getAmount()<aux){
        cout << "\t" << "Imposible de realizar la venta, no hay producto suficiente";
    }else{

    aux2=producto.getAmount()-aux;
    producto.setAmount(aux2);
    lista.deleteData(lista.findData(producto));
    lista.insertData(lista.findData(producto),producto);
    modifyInventory();
    seller.registerSale(producto,aux);

    }
}

void modifyInventory(){
    string inventory=lista.toString();
    admin.setInventory(inventory);
}

void recoverPreviousInventory(){
    string name,category,price,code,amount;
    myFile.open("Inventory.txt",ios::in);

    if(myFile.is_open()){
        while(!myFile.eof()){
            getline(myFile,code,'|');
            getline(myFile,name,'|');
            getline(myFile,category,'|');           ///LEEMOS LOS DATOS DEL ARCHIVO
            getline(myFile,amount,'|');
            getline(myFile,price,'|');

            producto.setName(name);
            producto.setCategory(category);
            producto.setPrice(stof(price));     ///LOS DATOS DEL ARCHIVO LOS ASIGNAMOS AL OBJETO
            producto.setCode(stoi(code));           ///STOI PARA CONVERTIR STRING EN INT
            producto.setAmount(stoi(amount));       ///STOF PARA CONVERTIR STRING EN FLOAT


            lista.insertData(lista.getLastPos(),producto);


        getline(myFile,name);
        }
        myFile.close();
    }

}

void temporizador(int m,int s)
{

    while(true)
    {
        gotoxy(50,20); cout << "Espere a que acabe el tiempo para volver a intentarlo";
        gotoxy(50,22); printf("%.2d:%.2d",m,s); //Para el temporizador
        Sleep(1000);

        s--;

        if(m == 0 and s == 0){
            system("cls");
            return login();
        }

        if(s == 0){
            m--;
            s = 60;
        }
    }

}

bool validacion(char *abc){
   bool isValid=false;
    if(int(*abc)>=48 && int(*abc)<=57){
    isValid=true;
}
return isValid;
}
