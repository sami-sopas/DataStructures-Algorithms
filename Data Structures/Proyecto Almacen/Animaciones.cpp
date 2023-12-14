#include"Animaciones.h"
#include"date.h"

using namespace std;

Date fecha;

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

void crearMarco(){
     gotoxy(100,1); cout << fecha.getDay() <<  "/" << fecha.getMonth() << "/" << fecha.getYear();
     gotoxy(3,1); cout << fecha.getHour() << ":" << fecha.getMinute();

    for(int i = 1; i < 119; i++){
        gotoxy(i,0); printf("%c",205); ///Barra superior
    }

    for(int i = 1; i < 119; i++){
        gotoxy(i,28); printf("%c",205); ///Barra inferior
    }

    for(int i = 1; i < 29; i++){
        gotoxy(1,i); printf("%c",186); ///Barra izquierda
    }

    for(int i = 1; i < 29; i++){
        gotoxy(118,i); printf("%c",186); ///Barra derecha
    }

    gotoxy(1,0); printf("%c",201); ///Esquina superior izquierda
    gotoxy(1,28); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(118,0); printf("%c",187); ///Esquina superior derecha
    gotoxy(118,28); printf("%c",188); ///Esquina inferior derecha

    gotoxy(0,0);
}

void perfiles(){
    crearMarco();

    gotoxy(50,3); cout << "SELECCIONA TU PEFIL";
    gotoxy(48,4); cout << "-----------------------";

    gotoxy(20,5); cout << "ADMINISTRADOR";
    gotoxy(91,5); cout << "VENDEDOR";

    gotoxy(21,22); cout << "OPCION 1";
    gotoxy(91,22); cout << "OPCION 2";

   /* gotoxy(50,7); cout << "SELECCIONA TU PEFIL" << endl;
    gotoxy(48,8); cout << "----------------------" << endl;*/

    ///MARCO IZQUIERDO
    for (int i = 80; i < 110; i++){
        gotoxy(i,6); printf("%c",205); //arriba
    }

    for (int i = 80; i < 110; i++){
        gotoxy(i,20); printf("%c",205); //abajo
    }

    for (int i = 7; i < 20; i++){
        gotoxy(79,i); printf("%c",186); //derecha
    }

    for (int i = 7; i < 20; i++){
        gotoxy(109,i); printf("%c",186); //izquierda
    }

    gotoxy(79,6); printf("%c",201); ///Esquina superior izquierda
    gotoxy(79,20); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(109,6); printf("%c",187); ///Esquina superior derecha
    gotoxy(109,20); printf("%c",188); ///Esquina inferior derecha


    ///MARCO DERECHO
    for (int i = 10; i < 40; i++){
        gotoxy(i,6); printf("%c",205); //arriba
    }

    for (int i = 10; i < 40; i++){
        gotoxy(i,20); printf("%c",205); //abajo
    }

    for (int i = 7; i < 20; i++){
        gotoxy(10,i); printf("%c",186); //derecha
    }

    for (int i = 7; i < 20; i++){
        gotoxy(40,i); printf("%c",186); //izquierda
    }

    gotoxy(10,6); printf("%c",201); ///Esquina superior izquierda
    gotoxy(10,20); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(40,6); printf("%c",187); ///Esquina superior derecha
    gotoxy(40,20); printf("%c",188); ///Esquina inferior derecha

gotoxy(18,10);cout <<"  A_A";
gotoxy(18,11);cout <<" (-.-)";
gotoxy(18,12);cout <<"  |-|";
gotoxy(18,13);cout <<" /   \\ ";
gotoxy(18,14);cout <<"|     |   __ ";
gotoxy(18,15);cout <<"|  || |  |  \\__ ";
gotoxy(18,16);cout <<" \\_||_/_/ ";

gotoxy(85,10);cout <<"      ____";
gotoxy(85,11);cout <<" ____|    \\" ;
gotoxy(85,12);cout <<"(____|     `._____";
gotoxy(85,13);cout <<" ____|       _|___";
gotoxy(85,14);cout <<"(____|     .'";
gotoxy(85,15);cout <<"     |____/";

gotoxy(0,0);


}

void loginAdmin(){
    crearMarco();

    gotoxy(55,10); cout << "ADMINISTRADOR";

    ///MARCO DERECHO
    for (int i = 10; i < 40; i++){
        gotoxy(i,6); printf("%c",205); //arriba
    }

    for (int i = 10; i < 40; i++){
        gotoxy(i,20); printf("%c",205); //abajo
    }

    for (int i = 7; i < 20; i++){
        gotoxy(10,i); printf("%c",186); //derecha
    }

    for (int i = 7; i < 20; i++){
        gotoxy(40,i); printf("%c",186); //izquierda
    }

    gotoxy(10,6); printf("%c",201); ///Esquina superior izquierda
    gotoxy(10,20); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(40,6); printf("%c",187); ///Esquina superior derecha
    gotoxy(40,20); printf("%c",188); ///Esquina inferior derecha


gotoxy(18,10);cout <<"  A_A";
gotoxy(18,11);cout <<" (-.-)";
gotoxy(18,12);cout <<"  |-|";
gotoxy(18,13);cout <<" /   \\ ";
gotoxy(18,14);cout <<"|     |   __ ";
gotoxy(18,15);cout <<"|  || |  |  \\__ ";
gotoxy(18,16);cout <<" \\_||_/_/ ";


}

void loginVendedor(){
    crearMarco();

    gotoxy(20,10); cout << "VENDEDOR";

    for (int i = 80; i < 110; i++){
        gotoxy(i,6); printf("%c",205); //arriba
    }

    for (int i = 80; i < 110; i++){
        gotoxy(i,20); printf("%c",205); //abajo
    }

    for (int i = 7; i < 20; i++){
        gotoxy(79,i); printf("%c",186); //derecha
    }

    for (int i = 7; i < 20; i++){
        gotoxy(109,i); printf("%c",186); //izquierda
    }

    gotoxy(79,6); printf("%c",201); ///Esquina superior izquierda
    gotoxy(79,20); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(109,6); printf("%c",187); ///Esquina superior derecha
    gotoxy(109,20); printf("%c",188); ///Esquina inferior derecha

gotoxy(85,10);cout <<"      ____";
gotoxy(85,11);cout <<" ____|    \\" ;
gotoxy(85,12);cout <<"(____|     `._____";
gotoxy(85,13);cout <<" ____|       _|___";
gotoxy(85,14);cout <<"(____|     .'";
gotoxy(85,15);cout <<"     |____/";


}

void iniciandoSesion()
{
    crearMarco();
    gotoxy(50,10); cout << "INICIANDO SESION" << endl;

    for (int i = 30; i < 90; i+=2){
            Sleep(30);
       gotoxy(i,12); printf("%c",254);
    }
}
