#include "Courier.h"
#include "Owner.h"

using namespace std;

class Business
{
private:
    string _name;
    string _address;
    int _number_of_owners;

    Owner* _owners;
    Courier* _curiers;

public:
    Business();
    Business(string, string, const Owner *, int);
    void hire_courier(const Courier &);
    void fire_courier(const Courier &);
    void list_couriers()const;
    void list_owners()const;
    void calculate_shipment_capacity();
    void operator()()const;
    Courier operator[](int );
    ~Business();
};
Business::Business()
{
    _curiers = NULL;
}
Business::Business(string name, string address,const Owner *owner_array, int number_of_owners)
{
    _name = name;
    _address = address;
    _number_of_owners = number_of_owners;
    _owners = new Owner[number_of_owners];
    *_owners = *owner_array;

}

void Business::operator()()const
{
    cout << _name <<","<<_address;
    list_owners();
    list_couriers();

}

Courier Business::operator[](int index)
{
    Courier *traverse, *tail;
    traverse = _curiers;
    if (traverse != NULL)
    {
       while (traverse != NULL && (traverse->_index != index))
       {
            tail = traverse;
            traverse = traverse->next;
       }
       if (traverse == NULL)
       {
           cout <<"there is no curier"<<endl;
           return;
       }
       
       if ((traverse->_index == index))
       {
           return *traverse;
       }
       
       
    }
    return;
}

void Business::fire_courier(const Courier &courier)
{
    Courier *traverse, *tail;
    traverse = _curiers;
    if (traverse != NULL)
    {
       while (traverse != NULL && (traverse->_index != courier._index))
       {
            tail = traverse;
            traverse = traverse->next;
       }
       if (traverse == NULL)
       {
           cout <<"there is no curier"<<endl;
           return;
       }
       
       if ((traverse->_index == courier._index))
       {
           traverse = traverse->next;
           delete traverse;
       }
       
       
    }
}

void Business::hire_courier(const Courier &courier)
{
    Courier *traverse, *newcourier, *tail;
    traverse = _curiers;
    *newcourier = *newcourier;

    if (_curiers == NULL)
    {
        _curiers = newcourier;
        return;
    }

    while (traverse != NULL)
    {
        tail = traverse;
        traverse = traverse->next;
    }
    if (traverse == NULL)
    {
        tail->next = newcourier;
        return;
    }
    
}

void Business::list_couriers()const
{
    Courier *traverse;
    traverse = _curiers;
    if ( traverse != NULL)
    {
        while (traverse != NULL)
        {
            cout<< traverse->getName();
            traverse = traverse->next;
        }
        
    }
    
}

void Business::list_owners()const
{
    for (int i = 0; i < _number_of_owners; i++)
    {
        cout << _owners[i].getName() <<", "<< _owners[i].getSurname()<<endl;
    }
    
}

Business::~Business()
{
}
