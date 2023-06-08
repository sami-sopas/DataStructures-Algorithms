#ifndef PILAEXCEPCION_H_INCLUDED
#define PILAEXCEPCION_H_INCLUDED
#include <exception>
#include <string>
class PilaExcepcion : public std::exception {
  private:
    std::string msg;
  public:
    explicit PilaExcepcion(const char* message) : msg(message) {}

    explicit PilaExcepcion(const std::string& message) : msg(message) { }

    virtual ~PilaExcepcion() throw () { }

    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

#endif // PILAEXCEPCION_H_INCLUDED
