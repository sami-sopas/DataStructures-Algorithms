#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <iostream>
#include <cstdlib>

class Date{
private:
    int year;
    int month;
    int day;

public:
		Date();
		Date(const Date&);

    int getYear();
    int getMonth();
    int getDay();

    std::string toString();

    void setYear(const int&);
    void setMonth(const int&);
    void setDay(const int&);

    Date& operator = (const Date&);

    friend std::ostream& operator << (std::ostream&, Date&);
    friend std::istream& operator >> (std::istream&, Date&);
};

#endif // DATE_H_INCLUDED










