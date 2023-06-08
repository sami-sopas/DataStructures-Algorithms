#ifndef LISTAEXCEPCION_H_INCLUDED
#define LISTAEXCEPCION_H_INCLUDED
#include <exception>
#include <string>
///PARA ERRORES FATALES, ESTO EVITA ESE TIPO DE ERRORES Y NOS DICE EN DONDE FALLO
class ListaExcepcion : public std::exception {
  private:
    std::string msg;
  public:
    explicit ListaExcepcion(const char* message) : msg(message) {}

    explicit ListaExcepcion(const std::string& message) : msg(message) { }

    virtual ~ListaExcepcion() throw () { }

    virtual const char* what() const throw () {
        return msg.c_str();
    }
};


#endif // LISTAEXCEPCION_H_INCLUDED
