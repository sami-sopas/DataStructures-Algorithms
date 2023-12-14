#include "admin.h"

using namespace std;

Admin::Admin(): password("123") {}

Admin::Admin(const Admin& a):password(a.password){}

void Admin::setPassword(const string& p){
    this->password=p;
}

void Admin::setInventory(string& newInventory){
    fstream myFile;

    myFile.open("Inventory.txt",ios::out);
    if(myFile.is_open()){
        myFile <<newInventory;
        myFile.close();
    }
}

void Admin::setHistory(string& newLine)
{
    fstream myFile;

    myFile.open("History.txt",ios::app);
    if(myFile.is_open()){
        myFile<<"\n"<<newLine;
        myFile.close();
    }

}


string Admin::getPassword(){
    return this->password;
}

string Admin::getHistory()
{
    fstream myFile;
    string result=" ";
    string myString;
    myFile.open("History.txt",ios::in);//lectura

    if(myFile.is_open()){
        while(!myFile.eof()){
            getline(myFile,myString);
            result+="\t";
            result+=myString;
            result+="\n";
        }
        myFile.close();
    }
    return result;
}

string Admin::getInventory(){
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
