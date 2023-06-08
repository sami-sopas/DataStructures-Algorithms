#ifndef ALBUM_CPP_INCLUDED
#define ALBUM_CPP_INCLUDED
#include"album.h"

///SETTERS
void Album::setInterprete(const string& i)
{
    interprete = i;
}

void Album::setNombre(const string& n)
{
    nombre = n;
}

void Album::setAutor(const string& a)
{
    autor = a;
}

void Album::setAnio(const string& an)
{
    anio = an;
}

void Album::setCantidad(const string& c)
{
    cantidad = c;
}

void Album::setPrecio(const float& p)
{
    precio = p;
}

///GETTERS

string Album::getInterprete()
{
    return interprete;
}

string Album::getNombre()
{
    return nombre;
}

string Album::getAutor()
{
    return autor;
}

string Album::getAnio()
{
    return anio;
}

string Album::getCantidad()
{
    return cantidad;
}

float Album::getPrecio()
{
    return precio;
}

///Imprimir

/**Esta funcion lo que hace es convertir todos los datos en string, concatenarlos
   e imprimirlos**/
string Album::toString()
{
    string resultado; //Variable string
    char miPrecio[10];
    sprintf(miPrecio,"%0.2f",precio);

    resultado = "\n\t -----------------------";
    resultado+= "\n\t| Nombre: ";
    resultado+=  nombre;
    resultado+=  "\n\t| Interprete: ";
    resultado+=  interprete;
    resultado+=  "\n\t| Anio: ";
    resultado+= anio;
    resultado+= "\n\t| Cantidad: ";
    resultado+= cantidad;
    resultado+= "\n\t| Precio: ";
    resultado+= miPrecio;
    resultado+= "\n\t -----------------------";

    return resultado; //Aqui retorna esa cadena con todos los datos
}

/**Sobrecarga de operadores, para copiar los datos de un objeto a otro
    recordar que por ser TDAS, debemos programar su comportamiento**/

Album& Album::operator = (const Album& a)
{
    nombre = a.nombre;
    interprete = a.interprete;
    anio = a.anio;
    cantidad = a.cantidad;
    precio = a.precio;

    return *this;
}

#endif // ALBUM_CPP_INCLUDED
