
#include <iostream>
#include <string>
#include "Person.h"
#include "OwnerShip.h"

using namespace std;
class Owner: public Person   //derived Class
{
private:
    OwnerShip _ownership;     //composition
public:
    Owner();
    Owner(string, string);
    ~Owner();
};
Owner::Owner(string name, string surname):Person(name, surname){}
Owner::~Owner()
{
}
