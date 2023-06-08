#ifndef ALBUM_H_INCLUDED
#define ALBUM_H_INCLUDED

#include<string>
#include<iostream>
class Album{
    private:
        std::string nombre;
        std::string autor;
        int anio;
        int cantidad;
        float precio;
    public:
        Album();
        Album(const Album&);

        void setNombre(const std::string&);
        void setAutor(const std::string&);
        void setAnio(const int&);
        void setCantidad(const int&);
        void setPrecio(const float&);

        std::string getNombre();
        std::string getAutor();
        int getAnio();
        int getCantidad();
        float getPrecio();

        std::string toString();

        ///Sobrecarga de operadores
        Album& operator = (const Album&);

        bool operator == (const Album&);
        bool operator != (const Album&);
        bool operator < (const Album&);
        bool operator <= (const Album&);
        bool operator > (const Album&);
        bool operator >= (const Album&);

        friend std::ostream& operator << (std::ostream& os, const Album& al) {
        char miPrecio[16];
        sprintf(miPrecio,"%0.2f", al.precio);

        os << al.nombre << " | " << al.autor << " | " << al.anio << " | " << al.cantidad << " | " << miPrecio;

        return os;
        }
};

#endif // ALBUM_H_INCLUDED
