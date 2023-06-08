#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include<string>

class Student
{
    private:
        int code;
        std::string name;
        std::string carrer;

    public:
        Student();
        Student(const Student&);

        void setCode(const int&);
        void setName(const std::string&);
        void setCarrer(const std::string&);

        int getCode();
        std::string getName();
        std::string getCarrer();

        std::string toString();

        bool operator != (Student& );
        bool operator == (Student& );
        int operator % (const int& );

};

#endif // STUDENT_H_INCLUDED
