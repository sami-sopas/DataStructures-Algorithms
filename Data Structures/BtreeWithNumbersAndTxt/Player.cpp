#include "Player.h"

using namespace std;

Player::Player() { }

Player::Player(const Player& p) : name(p.name), country(p.country), years(p.years) { }

void Player::setName(const std::string& n)
{
    name = n;
}

void Player::setCountry(const std::string& c)
{
    country = c;
}

void Player::setYears(const std::string& y)
{
    years = y;
}

string Player::getName() const
{
    return name;
}

string Player::getCountry() const
{
    return country;
}

string Player::getYears() const
{
    return years;
}

string Player::toString()
{
    string result="";

    result = name;
    result += "|";
    result += country;
    result += "|";
    result += years;
    result += "*";

    return result;

}

bool Player::operator!=(const Player& p){
    return name!=p.name;
}

bool Player::operator<(const Player& p)
{
    return name < p.name;
}

bool Player::operator>(const Player& p)
{
    return name > p.name;
}
