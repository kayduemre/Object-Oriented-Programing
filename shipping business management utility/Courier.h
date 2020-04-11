

#include "Person.h"
#include "Vehicle.h"

using namespace std;

class Courier: public Person  // derived class
{
private:
    Vehicle vehicle;
public:
    Courier(/* args */);
    ~Courier();
};

Courier::Courier(/* args */)
{
}

Courier::~Courier()
{
}
