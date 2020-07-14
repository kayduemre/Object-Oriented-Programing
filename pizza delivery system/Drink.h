/*
	Emre KAYDU
	150160552
*/
#ifndef DRINK_H
#define DRINK_H
#include <iostream>

using namespace std;
class Drink
{
public:

    string name;
    Drink *next;
    int price;
    int type;
    int number;
    int type_num;
    Drink();
    Drink(string, int, int);
    
};
Drink::Drink()
{
    next = NULL;
    number = 1;
}
Drink::Drink(string getname, int getprice, int gettype)
{
    name = getname;
    price = getprice;
    next = NULL;
    type = gettype;
    number = 1;
}

#endif