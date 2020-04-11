
#include <iostream>
#include <string>
#include "Person.h"
#include "OwnerShip.h"

using namespace std;
class Owner: public Person   //derived Class
{
private:
    OwnerShip OwnerShip;     //composition
public:
    Owner(/* args */);
    ~Owner();
};

Owner::Owner(/* args */)
{
}

Owner::~Owner()
{
}
