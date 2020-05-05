/*
    Emre KAYDU
    150160552

*/

#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Owner: public Person   //derived Class
{
private:
    
    static int _percentage;
public:
    static int _ownership_number;
    Owner();
    Owner(string, string);
    int getNumber(){return _ownership_number;};
    int getPercentage(){return _percentage;};
    ~Owner();
};
int Owner::_ownership_number = 0;
int Owner::_percentage = 0;
Owner::Owner(){ _ownership_number = 0;}

Owner::Owner(string name, string surname):Person(name, surname)
{
    _ownership_number +=1;
    _percentage = 100/_ownership_number;
}



Owner::~Owner()
{
    
}
#endif