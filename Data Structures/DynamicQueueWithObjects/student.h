#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <iostream>

#include "name.h"
#include "date.h"

class Student{
private:
    std::string code;
    Name name;
    std::string career;
    Date dateOfStart;
    float grade;
public:
		Student();
		Student(const Student&);

    std::string getCode();
    Name getName();
    std::string getCareer();
    float getGrade();

    std::string toString();

    void setCode(const std::string&);
    void setName(const Name&);
    void setCareer(const std::string&);
    void setGrade(const float&);

    Student& operator = (const Student&);

    bool operator == (const Student&);
    bool operator != (const Student&);
    bool operator < (const Student&);
    bool operator <= (const Student&);
    bool operator > (const Student&);
    bool operator >= (const Student&);

    friend std::ostream& operator<<(std::ostream& os, const Student& dt) {
        char myGrade[7];
        sprintf(myGrade, "%0.2f", dt.grade);

        os << dt.code << " | " << dt.name << " | " << dt.career << " | " << myGrade;
        return os;
    }
};

#endif // STUDENT_H_INCLUDED















