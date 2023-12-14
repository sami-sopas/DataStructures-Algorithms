#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<string>
#include<iostream>
#include<ctime>


class Date{
    private:
        int year;
        std::string month;
        int day;
        int hour;
        int minute;

    public:
		Date();
		Date(const Date&);


    int getYear();
    std::string getMonth();
    std::string getDay();
    int getHour();
    int getMinute();

    std::string toString();

    void setYear(const int&);
    void setMonth(const int&);
    void setDay(const int&);


    Date& operator = (const Date&);

    ///Para imprimir
    friend std::ostream& operator << (std::ostream& os, const Date& dt) {

    os << dt.day << " | " << dt.month << " | " << std::to_string(dt.year);

    return os;
    }

};


#endif // DATE_H_INCLUDED
