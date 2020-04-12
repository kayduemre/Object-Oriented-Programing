

#include "Person.h"
#include "Vehicle.h"

using namespace std;

class Courier: public Person  // derived class
{
private:
    Vehicle vehicle;
public:
    Courier *next;
    static int _index;

    Courier(){ next = NULL;};
    Courier(string, string, string);
    ~Courier();
};
int Courier::_index = 0;
Courier::Courier(string name, string surname, string Vehicle_type):Person(name, surname)
{
    next = NULL;
    _index++;
}

Courier::~Courier()
{
}
