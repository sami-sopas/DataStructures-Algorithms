#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <string>

class Name{
private:
    std::string lastName;
    std::string firstName;

public:
		Name();
		Name(const Name&);

    std::string getLastName();
    std::string getFirstName();

    std::string toString();

    void setLastName(const std::string&);
    void setFirstName(const std::string&);

    Name& operator = (const Name&);

};

#endif // NAME_H_INCLUDED
