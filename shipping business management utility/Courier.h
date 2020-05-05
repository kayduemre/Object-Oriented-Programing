/*
    Emre KAYDU
    150160552

*/
#include <iostream>
#include <string>
#include "Person.h"
#include "Vehicle.h"

using namespace std;

class Courier: public Person  // derived class
{
private:
    Vehicle *vehicle;
    int _order;
public:
    Courier *next;
    static int _index;

    Courier(){ next = NULL;};
    Courier(string, string, string);

    Vehicle getVehicle(){return *vehicle;};
    int getOrder()const{return _order;};
    ~Courier();
};
int Courier::_index = 0;
Courier::Courier(string name, string surname, string Vehicle_type):Person(name, surname)
{
    next = NULL;
    _index++;
    _order = _index;
    vehicle = new Vehicle(Vehicle_type);
}

Courier::~Courier()
{
}
