/*
	Emre KAYDU
	150160552
*/
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>

#include "Pizza.h"
#include "Drink.h"


using namespace std;
class Order
{
private:
	string customer;
	Pizza* pizza;
	Drink* drink;
public:
    Order *next;
    Order();
	Order(string, Pizza *,Drink *);
	Order(string, const Pizza *);
    Pizza *getpizza()const {return this->pizza;};
    Drink &getdrink()const {return *drink;};
    string getcustomer()const {return customer;};
    int getPrice();
    void printOrder();
    void generalPrintOrder();

};
int Order::getPrice()
{
    float price = 0;
    string size = this->pizza[0].getsize();
    int number = this->pizza[0].number;
    float drink_price = 0;

    if (drink[0].type_num != 0)
    {
        for (int i = 0; i < drink->type_num; i++)
        {
           drink_price += (drink[i].number*drink[i].price);
        }
    }
    
    if (size == "small")
    {
        price = 15*number;
        price += drink_price;
    }
    else if (size == "medium")
    {
        price = 20*number;
        price += drink_price;
    }
    else if (size == "big")
    {
        price = 25*number;
        price += drink_price;
    }
    return price;
}
Order::Order()
{
    
    next = NULL;
    customer = " ";
}
void Order::generalPrintOrder()
{   
    cout <<"----------------"<<endl;
    cout <<"Name: "<< customer <<endl<<endl;
    
    for (int i = 0; i < pizza->number; i++)
    {
        cout<<pizza[i].getname();
        cout<<"(";
        this->pizza[i].pirintIngredient();
        cout<<")"<<endl;
        cout<<"size: "<< pizza[i].getsize()<<","<<"crus: "<<pizza[i].getcrust_type()<<endl<<endl;
    }
    if (drink[0].type_num != 0)
    {
        for (int i = 0; i < drink[0].type_num; i++)
        {
            cout<< drink[i].number << " " << drink[i].name<<", ";
        }
    }
    cout<<endl <<"----------------"<<endl;
}
void Order::printOrder()
{
    cout<<endl;
	cout<<"Your order is saved, it will be delivered when it is reaady..."<<endl;
	cout <<"----------------"<<endl;
	cout <<"Name: "<< customer <<endl<<endl;
    
    for (int i = 0; i < pizza->number; i++)
    {
        cout<<pizza[i].getname();
        cout<<"(";
        this->pizza[i].pirintIngredient();
        cout<<")"<<endl;
        cout<<"size: "<< pizza[i].getsize()<<","<<"crus: "<<pizza[i].getcrust_type()<<endl<<endl;
    }
    if (drink[0].type_num != 0)
    {
        for (int i = 0; i < drink[0].type_num; i++)
        {
            cout<< drink[i].number << " " << drink[i].name<<", ";
        }
    }
    cout<<endl <<"----------------"<<endl;
}
Order::Order(string name, Pizza *head_pizza, Drink *head_drink)
{
    this->next = NULL;
    customer = name;
    Drink *traverse;
    traverse = head_drink;
    
    pizza = new Pizza[head_pizza[0].number];
    for (int i = 0; i < head_pizza[0].number; i++)
    {
        pizza[i] = head_pizza[i];
    }
    
    int number = 0;
    while (traverse != NULL)
    {
        number++;
        traverse = traverse->next;
    }
    drink = new Drink[number + 1];
    int index = 0;
    traverse = head_drink;
    while (traverse != NULL)
    {
        
        this->drink[index].name = traverse->name;
        this->drink[index].number = traverse->number;
        this->drink[index].price = traverse->price;
        this->drink[index].type = traverse->type;
        this->drink[index].type_num = number;
       
        traverse = traverse->next;
        index++;
    }
    
    
}
Order::Order(string name, const Pizza *head_pizza)
{
    customer = name;
    pizza = new Pizza[head_pizza[0].number];
    cout << head_pizza[0].number;
    drink = new Drink[1];
    drink[0].type_num = 0;
    for (int i = 0; i < head_pizza[0].number; i++)
    {
        pizza[i] = head_pizza[i];
    }
    
}
#endif