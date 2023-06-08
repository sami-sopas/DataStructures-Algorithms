#ifndef COLAEXCEPCION_H_INCLUDED
#define COLAEXCEPCION_H_INCLUDED

#include<exception>
#include<string>

class ColaExcepcion : public std::exception {
  private:
    std::string msg;
  public:
    explicit ColaExcepcion(const char* message) : msg(message) {}

    explicit ColaExcepcion(const std::string& message) : msg(message) { }

    virtual ~ColaExcepcion() throw () { }

    virtual const char* what() const throw () {
        return msg.c_str();
    }

};

#endif // COLAEXCEPCION_H_INCLUDED
