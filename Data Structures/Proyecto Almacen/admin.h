#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <fstream>
#include <string>
#include "seller.h"

class Admin{
private:
    std::string password;

public:
    Admin();
    Admin(const Admin&);

    void setPassword(const std::string&);
    void setInventory(std::string&);
    void setHistory(std::string&);
    std::string getPassword();
    std::string getHistory();
    std::string getInventory();


};

#endif // ADMIN_H_INCLUDED
