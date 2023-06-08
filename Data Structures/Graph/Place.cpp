#include"Place.h"

using namespace std;

Place::Place() { }

Place::Place(const Place& p) : country(p.country), state(p.state), city(p.city) { }

void Place::setCountry(const std::string& c)
{
    country = c;
}

void Place::setState(const std::string& s)
{
    state = s;
}

void Place::setCity(const std::string& c)
{
    city = c;
}

string Place::getCountry(void) const
{
    return country;
}

string Place::getState(void) const
{
    return state;
}

string Place::getCity(void) const
{
    return city;
}

string Place::toString()
{
    string result;

    result = country;
    result+= "|";
    result+= state;
    result+= "|";
    result+= city;
    result+= "*";

    return result;

}

bool Place::operator!=(const Place& p){
    return country != p.country;
}

bool Place::operator==(const Place& p){
    return country == p.country;
}

