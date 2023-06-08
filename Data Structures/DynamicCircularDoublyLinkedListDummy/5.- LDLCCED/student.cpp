#include "student.h"

using namespace std;

Student::Student() { }

Student::Student(const Student& s) : 	code(s.code), name(s.name), career(s.career), grade(s.grade) { }

string Student::getCode() {
	return code;
	}

Name Student::getName() {
	return name;
	}

string Student::getCareer() {
	return career;
	}

float Student::getGrade() {
	return grade;
	}

string Student::toString() {
	string result;
	char myGrade[7];
	sprintf(myGrade, "%0.2f", grade);

	result = code;
	result+=  " | ";
	result+= name.toString();
	result+=  " | ";
	result+= career;
	result+=  " | ";
	result+= myGrade;

	return result;
	}

void Student::setCode(const string& c) {
	code = c;
	}

void Student::setName(const Name& n) {
	name = n;
	}

void Student::setCareer(const string& c) {
	career = c;
	}


void Student::setGrade(const float& g) {
	grade = g;
	}

Student& Student::operator=(const Student& s) {
	code = s.code;
	name = s.name;
	career = s.career;
	grade = s.grade;

	return *this;
	}

bool Student::operator==(const Student& s) {
	return code == s.code;
	}

bool Student::operator!=(const Student& s) {
	return code != s.code;
	}

bool Student::operator<(const Student& s) {
	return code < s.code;
	}

bool Student::operator<=(const Student& s) {
	return code <= s.code;
	}

bool Student::operator>(const Student& s) {
	return code > s.code;
	}

bool Student::operator>=(const Student& s) {
	return code >= s.code;
	}
