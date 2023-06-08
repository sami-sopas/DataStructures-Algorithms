#include"Student.h"

using namespace std;

Student::Student() { }

Student::Student(const Student& s) : code(s.code), name(s.name), carrer(s.carrer) { }

void Student::setCode(const int& c)
{
    code = c;
}

void Student::setName(const std::string& n)
{
    name = n;
}

void Student::setCarrer(const std::string& c)
{
    carrer = c;
}

int Student::getCode()
{
    return code;
}

string Student::getName()
{
    return name;
}

string Student::getCarrer()
{
    return carrer;
}

string Student::toString()
{
    string result;

    result+= to_string(code);
    result+= "|";
    result+= name;
    result+= "|";
    result+= carrer;
    result+= "*";

    return result;
}

bool Student::operator!=(Student& s)
{
    return code != s.code;
}

bool Student::operator==(Student& s)
{
    return code == s.code;
}

/** Sobrecarga del operador % para ser aplicado en la función Hash
    módulo o residuo. Recibe como parámetro el objeto, y
    regresa como resultado el residuo entre el codigo del alumno y 10 **/
int Student::operator%(const int& num)
{
    return code % num;
}
