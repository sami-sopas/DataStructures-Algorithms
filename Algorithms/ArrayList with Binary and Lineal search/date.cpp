#include "date.h"

using namespace std;

Date::Date() { }

Date::Date(const Date& d) : year(d.year), month(d.month), day(d.day) { }

int Date::getYear() {
	return year;
	}

int Date::getMonth() {
	return month;
	}

int Date::getDay() {
	return day;
	}

string Date::toString(){
	char myDate[11];

	sprintf(myDate, "%04i/%02i/%02i", year, month, day);

	return myDate;
	}

void Date::setYear(const int& y) {
	year = y;
	}

void Date::setMonth(const int& m) {
	month = m;
	}

void Date::setDay(const int& d) {
	day = d;
	}

Date& Date::operator=(const Date& d) {
	year =  d.year;
	month = d.month;
	day = d.day;

	return *this;
	}

ostream& operator << (ostream& os, Date& d){
	os << d.toString();

	return os;
	}

istream& operator >> (istream& is, Date& d){
	string myStr;

	getline(is, myStr, '/');
	d.year = atoi(myStr.c_str());
	getline(is, myStr, '/');
	d.month = atoi(myStr.c_str());
	getline(is, myStr);
	d.day = atoi(myStr.c_str());

	return is;
	}













