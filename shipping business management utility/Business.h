/*
    Emre KAYDU
    150160552

*/
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
#include <string>
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
    int calculate_shipment_capacity();
    
    void operator()()const;
    Courier operator[](int );

    string getName(){return _name;};
    string getAdress(){return _address;};
    int getNumberofowner(){return _number_of_owners;};
    Owner *getOwner(){return _owners;};



    ~Business();
};

int Business::calculate_shipment_capacity()
{
    Courier *traverse = _curiers;
    int capacity = 0;
    if (_curiers != NULL)
    {
        while (traverse != NULL)
        {
            capacity += traverse->getVehicle().getcapacity();
            traverse = traverse->next;
        }
        return capacity;
    }
   
}
Business::Business()
{
    _curiers = NULL;
}
Business::Business(string name, string address,const Owner *owner_array, int number_of_owners)
{
    _name.assign(name);
    _address.assign(address);
    _number_of_owners = number_of_owners;
    _owners = new Owner[_number_of_owners];

    for (int i = 0; i < _number_of_owners; i++)
    {
        _owners[i] = owner_array[i];
    }
    
}

void Business::operator()()const
{
    cout << _name <<","<<_address<<endl;
    list_owners();
    list_couriers();
}

Courier Business::operator[](int index)
{
    Courier *traverse, *tail;
    traverse = _curiers;
    if (traverse != NULL)
    {

        if (traverse->getOrder() == index)
        {
            return *traverse;
        }
        
       while (traverse != NULL && (traverse->getOrder() != index))
       {
            tail = traverse;
            traverse = traverse->next;
       }
       if (traverse == NULL)
       {
            
           cout <<"there is no curier"<<endl;
        
       }
       else if ((traverse->getOrder() == index))
       {
          
           return *traverse;
       }
       
    }
}

void Business::fire_courier(const Courier &courier)
{
    Courier *traverse, *tail;
    traverse = _curiers;
    if (traverse != NULL)
    {
        if (traverse->getOrder() == courier.getOrder())
        {
            _curiers = traverse->next;
            delete traverse;
            return;
        }
        
       while (traverse != NULL && (traverse->getOrder() != courier.getOrder()))
       {
            tail = traverse;
            traverse = traverse->next;
       }
       if (traverse == NULL)
       {
           cout <<"there is no curier"<<endl;
           return;
       }

       if ((traverse->getOrder() == courier.getOrder()))
       {
           tail->next = traverse->next;
           delete traverse;
           return;
       }
       
       
    }
}

void Business::hire_courier(const Courier &courier)
{
    Courier *traverse, *newcourier, *tail;
    traverse = _curiers;
    newcourier = new Courier();
    *newcourier = courier;
    newcourier->next = NULL;


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
            cout<< traverse->getName()<<" ";
            cout<< traverse->getSurname()<<" ";
            cout<< traverse->getVehicle().gettype()<<endl;
            traverse = traverse->next;
        }
        
    }
    
}

void Business::list_owners()const
{

    for (int i = 0; i < _number_of_owners; i++)
    {
        cout << _owners[i].getName() <<" "<< _owners[i].getSurname()<<" "<< _owners[i].getPercentage()<<endl;
    }
}

Business::~Business()
{
   Courier *traverse, *next;
   traverse = _curiers;

   while (traverse != NULL)
   {
       next = traverse->next;
       delete traverse;
       traverse = next;
   }
   delete [] _owners;
}
#endif