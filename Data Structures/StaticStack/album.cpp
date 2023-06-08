#include"album.h"

using namespace std;

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
string Album::toString()
{
    string resultado; //Variable string
    char miPrecio[10];
    sprintf(miPrecio,"%0.2f",precio);

    resultado = "\nNombre: ";
    resultado+=  nombre;
    resultado+=  "\nInterprete: ";
    resultado+=  interprete;
    resultado+=  "\nAnio: ";
    resultado+= anio;
    resultado+= "\nCantidad: ";
    resultado+= cantidad;
    resultado+= "\nPrecio: ";
    resultado+= miPrecio;

    return resultado;
}

Album& Album::operator=(const Album& a)
{
    nombre = a.nombre;
    interprete = a.interprete;
    anio = a.anio;
    cantidad = a.cantidad;
    precio = a.precio;

    return *this;
}

