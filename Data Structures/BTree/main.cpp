#include <iostream>
#include <random>
#include <chrono>
#include "btree.h"
#include "contact.h"

using namespace std;

bool validacion(char*abc){
bool isValid=false;
if(int(*abc)>=48 && int(*abc)<=57){
    isValid = true;
}
return isValid;
}

void insertContact();
void searchNode(); //Buscar por id
void searchNode2(); //Buscar por nombre
void showLowest();
void showHighest();
void getPre();
void getPost();
void modify();
void deleteNode();
void inOrder();
void preOrder();
void postOrder();


BTree<Contact> myTree;
int id;

int main() {
    int opc;
    Contact contacto;

    do {
        system("cls");
        cout<<"1) Insertar Datos \n"
            <<"2) Buscar Nodo \n"
            <<"3) Mostrar Mínimo ID (Nodo)\n"
            <<"4) Mostrar Máximo ID (Nodo)\n"
            <<"5) Mostrar Nodo Antecesor\n"
            <<"6) Mostrar Nodo Sucesor\n"
            <<"7) Editar Nodo (por ID)\n"
            <<"8) Eliminar Nodo(Por ID)\n"
            <<"9) Mostrar Datos en InOrder\n"
            <<"10) Mostrar Datos en PreOrder\n"
            <<"11) Mostrar Datos en PostOrder\n"
            <<"12) Salir\n"
            <<"Selecciona una opcion: ";
        cin>>opc;

        switch(opc) {
            case 1:
                insertContact();
                break;
            case 2:
                cout << "COMO DESEA BUSCAR PROFE" << endl;
                cout << "1) POR ID" << endl;
                cout << "2) POR NOMBRE" << endl;
                cin >> opc;

                switch(opc){
                    case 1: searchNode();
                    break;
                    case 2: searchNode2();
                    break;
                }
                break;
            case 3:
                showLowest();
                break;
            case 4:
                showHighest();
                break;
            case 5:
                getPre();
                break;
            case 6:
                getPost();
                break;
            case 7:
                modify();
                break;
            case 8:
                deleteNode();
                break;
            case 9:
                inOrder();
                break;
            case 10:
                preOrder();
                break;
            case 11:
                postOrder();
                break;

            }
        system("pause");
        }
    while(opc!=12);

    return 0;

    }

void insertContact() {
    Contact contacto;
    int id;
    char aux[100];
    string name,address,email;

    cout<<"Ingresa el id del contacto: "<<endl;
    cin>>aux;

    if(validacion(aux)){
        id = atoi(aux);
    }else{ cout << "INGRESE ID VALIDO" << endl;

    return;
    }

    contacto.setId(id);
    cout<<"Ingrese el nombre del contacto: "<<endl;
    cin.sync();
    getline(cin,name);
    contacto.setName(name);
    cout<<"Ingresa la direccion del contacto: "<<endl;
    getline(cin,address);
    contacto.setAddress(address);
    cout<<"Ingresa el email del contacto: "<<endl;
    getline(cin,email);
    contacto.setEmail(email);

    myTree.insertData(contacto);
    }

void searchNode() {
    cout<<"Ingresa el id :";
                cin>>id;

                if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {

                    if(myTree.getPredecessorNode(id) == nullptr)
                        cout<<"No tiene padre"<<endl;
                    else
                        cout<<"predesecor: " <<myTree.retrieve(myTree.getPredecessorNode(id))<<endl;

                    if(myTree.searchById(id)==nullptr)
                        cout<<"El elemento no se encuentra en el arbol"<<endl;
                    else
                        cout<<"El id "<<id<< " si se encuentra en el arbol"<<endl;

                    if(myTree.getSuccessorNode(id) == nullptr)
                        cout<<"El elemento no tiene sucesor"<<endl;
                    else
                        cout<<"sucesor: "<<myTree.retrieve(myTree.getSuccessorNode(id))<<endl;
                    }
    }

void searchNode2() {
    string name;

    cout<<"Ingresa el nombre :";
    cin.sync();
                getline(cin,name);

                if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {

                    if(myTree.getPredecessorNode(id) == nullptr)
                        cout<<"No tiene padre"<<endl;
                    else
                        cout<<"predesecor: " <<myTree.retrieve(myTree.getPredecessorNode(id))<<endl;

                    if(myTree.searchByName(name)==nullptr)
                        cout<<"El elemento no se encuentra en el arbol"<<endl;
                    else
                        cout<<"El nombre " << name << " si se encuentra en el arbol"<<endl;

                    if(myTree.getSuccessorNode(id) == nullptr)
                        cout<<"El elemento no tiene sucesor"<<endl;
                    else
                        cout<<"sucesor: "<<myTree.retrieve(myTree.getSuccessorNode(id))<<endl;
                    }
    }

void showLowest() {
    if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<"Elemento menor: "<<myTree.retrieve(myTree.getLowest())<<endl;
                    cout<<endl;
                    }
    }

void showHighest() {
    if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<"Elemento mayor: "<<myTree.retrieve(myTree.getHighest())<<endl;
                    cout<<endl;
                    }
    }

void getPre() {
    if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<"Ingresa el id para saber su nodo antecesor: ";
                    cin>>id;
                    if(myTree.getPredecessorNode(id) == nullptr)
                        cout<<"No tiene padre"<<endl;
                    else
                        cout<<"antecesor: " <<myTree.retrieve(myTree.getPredecessorNode(id))<<endl;
                    }
    }

void getPost() {
if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<"Ingresa el id para saber su nodo sucesor: ";
                    cin>>id;

                    if(myTree.getSuccessorNode(id) == nullptr)
                        cout<<"El elemento no tiene sucesor"<<endl;
                    else
                        cout<<"sucesor: "<<myTree.retrieve(myTree.getSuccessorNode(id))<<endl;
                    }
    }

void modify() {
    Contact contacto;
    int id;

    string name,address,email;

    cout<<"Ingresa el id del contacto: "<<endl;
    cin>>id;
    contacto.setId(id);
    cout<<"Ingrese el nombre del contacto: "<<endl;
    cin.sync();
    getline(cin,name);
    contacto.setName(name);
    cout<<"Ingresa la direccion del contacto: "<<endl;
    getline(cin,address);
    contacto.setAddress(address);
    cout<<"Ingresa el email del contacto: "<<endl;
    getline(cin,email);
    contacto.setEmail(email);

    myTree.modify(id,contacto);
    }

void deleteNode() {
    Contact contacto;
    if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<"Ingresa el id del elemento a eliminar: ";
                    cin>>id;

                    if(myTree.searchById(id)==nullptr){
                        cout << "NO EXISTE" << endl;
                    }else{
                    contacto = myTree.retrieve(myTree.searchById(id));
                     myTree.deleteData(contacto) ;
                    }
                    }
    }

void inOrder() {
    if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<endl;
                    cout<<"Recorrido inOrder: "<<endl;
                    myTree.parseInOrder();
                    cout<<endl;
                    }
    }

void preOrder() {
     if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<endl;
                    cout<<"Recorrido preOrder: "<<endl;
                    myTree.parsePreOrder();
                    cout<<endl;
                    }
    }

void postOrder() {
    if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                    cout<<endl;
                    cout<<"Recorrido postOrder: "<<endl;
                    myTree.parsePostOrder();
                    cout<<endl;
                    }
    }
