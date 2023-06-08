#include <iostream>
#include <fstream>
using namespace std;

void encrypt();
void decrypt();

int main()
{
    int opc;

    do{
        system("cls");
        cout << "Que desea hacer? \n"
             << "1) Encriptar un mensaje \n"
             << "2) Desencriptar un mensaje \n"
             << "3) Salir \n" << endl;

             cout << "Seleccione una opcion: "; cin >> opc;

             switch(opc)
             {
                 case 1: encrypt(); break;

                 case 2: decrypt(); break;

                 case 3: break;

                 default: cout << "Opcion no valida !" << endl; break;
             }

     cout << endl;
     system("pause");
    }while(opc != 3);

   return 0;
}



void encrypt()
{
    fstream file;
    string message;

    cout << "\nEscriba el mensaje que desee cifrar " << endl;
    cin.ignore();
    getline(cin,message);

    // Metodo Cesar ----------------------------------------------------------
    /* recibe una cadena y la cantidad de
   posiciones que recorreremos la cadena, retorna el mensaje encriptado */


    //Recorremos la cadena hasta su final
    for(int i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] + 7; //Recorremos la cadena 7 pocisiones (key)
    }

    //En este punto ya tenemos la cadena encriptada con cesar, aplicaremos un segundo algoritmo

    //Metodo XOR -------------------------------------------------------------
    char key = 'N'; //Definimos una llave de tipo char, que sera la letra que queramos
    string result = message;

    for(unsigned int i = 0; i < message.size(); i++)
    {
        result[i] = message[i] ^ key; //A cada letra del mensaje le aplicamos la llave
    }

    cout << "\nMensaje encriptado: " << result;

    file.open("file01.txt",ios::app);

    file << result;

    file.close();

}

void decrypt()
{
    fstream file;
    string message;

    file.open("file01.txt",ios::in); //abrimos el archivo en modo lectura

    getline(file,message,'\0'); //Leemos hasta el final de la cadena para obtener el mensaje a decifrar

    file.close(); //Cerramos el archivo

    cout << "\nMensaje a decifrar: " << message;

    //Primero desencriptamos el XOR, realizando el mismo procedimiento con el que encriptamos

    char key = 'N';

    string result = message;

    for(unsigned int i = 0; i < message.size(); i++)
    {
        result[i] = message[i] ^ key;
    }

    //Aqui al mensaje ya le quitamos la encriptacion XOR, ahora falta la cesar

    //Recorremos la cadena hasta su final
    for(unsigned int i = 0; i < result.size(); i++)
    {
        result[i] = result[i] - 7; //Recorremos la cadena 7 pocisiones menos (key)
    }

    cout << "\n\nMensaje descifrado: " << result << endl;
}
