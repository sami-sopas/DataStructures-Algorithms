#include"album.h"

using namespace std;

///Constructores--------------------------------
Album::Album() { }

Album::Album(const Album& a) : nombre(a.nombre), autor(a.autor), anio(a.anio), cantidad(a.cantidad), precio(a.precio) { }

///Setters -------------------------------------
void Album::setNombre(const string& n)
{
    nombre = n;
}

void Album::setAutor(const string& a)
{
    autor = a;
}

void Album::setAnio(const int& an)
{
    anio = an;
}
void Album::setCantidad(const int& c)
{
    cantidad = c;
}

void Album::setPrecio(const float& p)
{
    precio = p;
}

///Getters-----------------------------------------

string Album::getNombre()
{
    return nombre;
}

string Album::getAutor()
{
    return autor;
}

int Album::getAnio()
{
    return anio;
}
int Album::getCantidad()
{
    return cantidad;
}

float Album::getPrecio()
{
    return precio;
}

string Album::toString() {

    string resultado; //Variable string
    char miPrecio[10];
    sprintf(miPrecio,"%0.2f",precio);

    resultado = "\nNombre: ";
    resultado+=  nombre;
    resultado+=  "\nAnio: ";
    resultado+= to_string(anio);
    resultado+= "\nCantidad: ";
    resultado+= to_string(cantidad);
    resultado+= "\nPrecio: ";
    resultado+= miPrecio;

    return resultado;
}

///Sobrecargas-----------------------------
Album& Album::operator=(const Album& a) {
    nombre = a.nombre;
    anio = a.anio;
    cantidad = a.cantidad;
    precio = a.precio;

    return *this;
}

bool Album::operator==(const Album& a)
{
    return nombre == a.nombre;
}

bool Album::operator!=(const Album& a)
{
    return nombre != a.nombre;
}

bool Album::operator<(const Album& a)
{
    return nombre < a.nombre;
}

bool Album::operator<=(const Album& a)
{
    return nombre <= a.nombre;
}

bool Album::operator>(const Album& a)
{
    return nombre > a.nombre;
}

bool Album::operator>=(const Album& a)
{
    return nombre >= a.nombre;
}



