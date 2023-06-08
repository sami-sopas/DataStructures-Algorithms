#ifndef PLACE_H_INCLUDED
#define PLACE_H_INCLUDED

#include<string>
#include<iostream>

class Place{

    private: //Atributos
        std::string country;
        std::string state;
        std::string city;

    public: //Métodos
        Place();
        Place(const Place&);

        void setCountry(const std::string&);
        void setState(const std::string&);
        void setCity(const std::string&);

        std::string getCountry(void) const;
        std::string getState(void) const;
        std::string getCity(void) const;

        std::string toString();

        bool operator != (const Place& p);
        bool operator == (const Place& p);

};


#endif // PLACE_H_INCLUDED
