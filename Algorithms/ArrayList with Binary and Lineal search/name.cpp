#include "name.h"

using namespace std;

Name::Name() {	}

Name::Name(const Name& n) : lastName(n.lastName), firstName(n.firstName) { }

string Name::getLastName() {
	return lastName;
	}

string Name::getFirstName() {
	return firstName;
	}

string Name::toString(){
	return lastName + ", " + firstName;
	}

void Name::setLastName(const string& l) {
	lastName = l;
	}

void Name::setFirstName(const string& n) {
	firstName = n;
	}

Name& Name::operator=(const Name& n) {
	lastName = n.lastName;
	firstName = n.firstName;

	return *this;
	}
