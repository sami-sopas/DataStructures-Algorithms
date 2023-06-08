#ifndef ALBUM_H_INCLUDED
#define ALBUM_H_INCLUDED
///DEFINICION DE CLASE
#include<string>
using namespace std;

class Album{
    private:
        string interprete;
        string nombre;
        string autor;
        string anio;
        string cantidad;
        float precio;
    public:
        void setInterprete(const string&); ///Recibe los valores de manera constante y por referencia
        void setNombre(const string&);
        void setAutor(const string&);
        void setAnio(const string&);
        void setCantidad(const string&);
        void setPrecio(const float&);

        string getInterprete();
        string getNombre();
        string getAutor();
        string getAnio();
        string getCantidad();
        float getPrecio();

        string toString(); ///Para imprimir todos los elementos del OBJETO

        Album& operator = (const Album&); ///sobrecarga de operadores
};

#endif // ALBUM_H_INCLUDED
