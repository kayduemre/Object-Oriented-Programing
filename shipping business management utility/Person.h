#include <iostream>
#include <string>

using namespace std;

class Person // base Class
{
private:
    string _name;
    string _surname;
public:
    Person();
    Person(string, string);

    void setName(string name);
    string getName();
    string getSurname();
    ~Person();
};
string Person::getName()
{
    return _name;
}
string Person::getSurname()
{
    return _surname;
}
Person::Person(string name, string surname)
{
    _name = name;
    _surname = surname;
}

Person::~Person()
{
}
