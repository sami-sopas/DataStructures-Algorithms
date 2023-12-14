#include "seller.h"

using namespace std;

Seller::Seller():password("321"){}

Seller::Seller(const Seller&){}

string Seller::getPassword(){
    return password;
}

void Seller::registerSale(Product& pSold,const int& qSold){

    fstream myFile;
    string result;

    result="Vendido: ";
    result+= pSold.getName();
    result+="\t Cantidad vendida: ";
    result+=to_string(qSold);

    myFile.open("History.txt",ios::app);
    if(myFile.is_open()){
        myFile<<"\n"<<result;
        myFile.close();
    }

}

string Seller::getInventory()
{
    fstream file;
    string result=" ";
    string myString;
    file.open("Inventory.txt",ios::in);//lectura

    if(file.is_open()){
        while(!file.eof()){
            getline(file,myString);
            result+="\t";
            result+=myString;
            result+="\n";
        }
    }
    file.close();
    return result;
}
