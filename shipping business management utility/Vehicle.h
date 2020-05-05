/*
    Emre KAYDU
    150160552

*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;
class Vehicle       //composition class
{
private:
    string _type;;
    int _capacity;
public:
    Vehicle();
    Vehicle(string);

    string gettype(){return _type;};
    int getcapacity(){return _capacity;};
    ~Vehicle();
};
Vehicle::Vehicle()
{
    _type = "";
    _capacity = 0;
}
Vehicle::Vehicle(string type)
{
    if (type.compare("car") == 0)
    {
        _type.assign("car");
        _capacity = 200;
        
    }else if (type.compare("motorcycle") == 0)
    {
        _type.assign("motorcycle");
        _capacity = 35;
    }
    else if (type.compare("bicycle") == 0)
    {
        _type.assign("bicycle");
        _capacity = 10;
    }
    else
    {
        cout<<"fail"<<endl;
    }
}

Vehicle::~Vehicle()
{
}
#endif
