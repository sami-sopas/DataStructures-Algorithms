#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include<regex>
#include<string>
#include<iostream>
#include<iomanip>

class Product{
    private:
        std::string name;
        std::string category;
        float price;
        int code;
        int amount;
        bool validate(std::string,std::regex);

    public:
        Product(); ///Constructor vacio
        Product(const Product&); ///Constructor copia

        ///Setters
        void setName(std::string&);
        void setCategory(std::string&);
        void setPrice(const float&);
        void setCode(const int&);
        void setAmount(const int&);

        ///Getters
        std::string getName();
        std::string getCategory();
        float getPrice();
        int getCode();
        int getAmount();

        std::string toString();

        ///Sobrecargas de operadores
        Product& operator = (const Product&);

        bool operator == (const Product&);
        bool operator != (const Product&);
        bool operator < (const Product&);
        bool operator <= (const Product&);
        bool operator > (const Product&);
        bool operator >= (const Product&);

        ///Para imprimir
        friend std::ostream& operator << (std::ostream& os, const Product& pt) {
        char myPrice[16];
        sprintf(myPrice,"%0.2f", pt.price);

        os << std::to_string(pt.code) << " | " << pt.name << " | " << pt.category << " | " << myPrice << " | " << std::to_string(pt.amount)<< " | ";

        return os;
        }

};

#endif // PRODUCT_H_INCLUDED
