#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <string>
#include <iostream>

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

    friend std::ostream& operator<<(std::ostream& os, const Name& nm) {

        os << nm.lastName << ", " << nm.firstName;
        return os;
    }

};

#endif // NAME_H_INCLUDED
