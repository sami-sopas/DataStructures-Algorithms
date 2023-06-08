#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<string.h>
#include<iostream>

class Player{
    private:
        std::string name;
        std::string country;
        std::string years;

    public:
        Player(); //ctr por omision
        Player(const Player&);

        //Setters
        void setName(const std::string&);
        void setCountry(const std::string&);
        void setYears(const std::string&);

        //Getters
        std::string getName() const;
        std::string getCountry() const;
        std::string getYears() const;

        std::string toString();

        bool operator != (const Player&);
        bool operator < (const Player&);
        bool operator > (const Player&);


};

#endif // PLAYER_H_INCLUDED
