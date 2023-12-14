#ifndef ANIMACIONES_H_INCLUDED
#define ANIMACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include"windows.h"
#include <iostream>

/// Todos los colores que hay para cambiar un printf en especifico
#define NEGROBAJITO "\x1b[1;30m"
#define NEGROFUERTE "\x1b[0;30m"
#define NEGROFONDO "\x1b[1;30;40m"

#define ROJOBAJITO "\x1b[1;31m"
#define ROJOFUERTE "\x1b[0;31m"
#define ROJOFONDO "\x1b[1;31;41m"

#define VERDEBAJITO "\x1b[1;32m"
#define VERDEFUERTE "\x1b[0;32m"
#define VERDEFONDO "\x1b[1;32;42m"

#define AMARILLOBAJITO "\x1b[1;33m"
#define AMARILLOFUERTE "\x1b[0;33m"
#define AMARILLOFONDO "\x1b[1;33;43m"

#define AZULREYBAJITO "\x1b[1;34m"
#define AZULREYFUERTE "\x1b[0;34m"
#define AZULREYFONDO "\x1b[1;34;44m"

#define MORADOBAJITO "\x1b[1;35m"
#define MORADOFUERTE "\x1b[0;35m"
#define MORADOFONDO "\x1b[1;35;45m"

#define AQUABAJITO "\x1b[1;36m"
#define AQUAFUERTE "\x1b[0;36m"
#define AQUAFONDO "\x1b[1;36;46m"

#define GRISBAJITO "\x1b[1;37m"
#define GRISFUERTE "\x1b[0;37m"
#define GRISFONDE "\x1b[1;37;47m"


/// Para regresar al color origial
#define REGRESA "\x1b[0m"

void crearMarco();

void gotoxy(int,int);
void perfiles();
void loginAdmin();
void loginVendedor();
void interfazAdmin();
void interfazVendedor();
void iniciandoSesion();


#endif // ANIMACIONES_H_INCLUDED
