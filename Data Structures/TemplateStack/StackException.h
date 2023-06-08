#ifndef STACKEXCEPTION_H_INCLUDED
#define STACKEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

class StackException : public std::exception {
  private:
    std::string msg;
  public:
    explicit StackException(const char* message) : msg(message) {}

    explicit StackException(const std::string& message) : msg(message) { }

    virtual ~StackException() throw () { }

    virtual const char* what() const throw () {
        return msg.c_str();
    }


};

#endif // STACKEXCEPTION_H_INCLUDED
