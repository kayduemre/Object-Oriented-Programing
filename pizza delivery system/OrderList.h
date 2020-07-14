/*
	Emre KAYDU
	150160552
*/
#include <iostream>
#include<iomanip>
#include<stdio.h>
#include <string>
#include <sstream>
#include "Order.h"
#include "Pizza.h"
#include "Drink.h"


using namespace std;
class OrderList
{
private:

	static int order_number;
	Order* head;
    Pizza* pizzaHead;
    Drink* drinkHead;  
public:
	OrderList();

	void takeOrder();
	void listOrders();
	void deliveryOrders();

    //my functions
    void pizzaMenu();
    int getOerderNumber();
    void setOerderNumber(int);
    void addPizza(Pizza *);
    void addDrink(const Drink &);
    void addOrder(const Order *);
    bool takeDrink();
    void printPizza();
    void printDrink();
    bool promotionCode();
    void removeOrder(Order *);

    Order *searchOrder(string);

};
int OrderList::order_number =0 ;
void OrderList::removeOrder(Order *rm)
{
    Order *traverse, *tail;
    traverse = head;

    if (head->getcustomer().compare(rm->getcustomer()) == 0 )
    {
        head = head->next;
        return;
    }
    while ((traverse != NULL) && (traverse->getcustomer().compare(rm->getcustomer()) != 0) )
    {
        tail = traverse;
        traverse = traverse->next;
    }
    if (traverse == NULL)
    {
        cout<<"Could not find order to delete..."<<endl;
        
    }
    if ((traverse->getcustomer().compare(rm->getcustomer()) == 0))
    {
        tail->next = traverse->next;
        delete traverse;
        return;
    }
    
    
    
}
Order *OrderList::searchOrder(string search)
{
    Order *traverse;
    traverse = head;
    string name = search;
    string other = head->getcustomer();
    if (traverse != NULL)
    {
        
        

        while ((traverse != NULL) && (traverse->getcustomer().compare(search) != 0) )
        {
            traverse = traverse->next;
        }
        if ((traverse->getcustomer().compare(search) == 0))
        {
           return traverse;
        }
    }
    return NULL;
}
void OrderList::deliveryOrders()
{
    this->listOrders();
    string choose;
    cout<<"Please write the customer name in order to delivery his/her order: ";
    cin >> choose;
    cout<<"Following order will be delivered..."<<endl;
    cout <<"--------------------------"<<endl;
    Order *delivery_order = this->searchOrder(choose);
    if (delivery_order != NULL)
    {
       delivery_order->printOrder();
    }
    else
    {
        cout<<"Order not found...";
        takeOrder();
    }
    
    float total_price = delivery_order->getPrice();
    cout<<"Total price: "<< total_price<< endl;
   
    bool flag = true;
    
    

    while (flag)
    {
        string q;
        cout<<"Do you have a promotion code? (y/n)"<<endl;
        cin >> q;

         if ( q.compare("y") == 0)
        {
        
            char buf[16];
            char *code;
            string deneme;
            cout<<"Please enter your code: ";
            cin.ignore();
            cin.getline(buf, 15);

            code = new char[strlen(buf) + 1];

            strcpy(code,buf);

            if (strcmp(code,"I am a student") == 0)
            {
                total_price = total_price - (total_price/10);
                cout << "Discounted price: "<< total_price<<endl;
                flag = false;
            }
            else
            {
                cout << "Promotion code is not accepted: "<<endl;
            }

        }
        else if (q.compare("n") == 0)
        {
           flag = false;
        }
        
       
    }
    
   
          
    
    removeOrder(delivery_order);
    cout<<"The order is delivered successfully!"<<endl<<endl;
}

void OrderList::listOrders()
{
    Order *traverse;
    traverse = head;
    if (traverse != NULL)
    {
        int index = 1;
        while (traverse != NULL)
        {
            cout<<index<<endl;
            traverse->generalPrintOrder();
            index++;
            
            traverse = traverse->next;
            
        }   
    }
    else
    {
        cout<<endl<<"There is no order yet...."<<endl;
        takeOrder();
    }
    
}

int OrderList::getOerderNumber()
{
    return order_number;
}

void OrderList::setOerderNumber(int set)
{
    order_number = set;
}

void OrderList::addOrder(const Order *obj)
{
    Order *traverse, *tail;
    Order *newnode = new (std::nothrow) Order(obj->getcustomer(), obj->getpizza(), drinkHead);
    traverse = head;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    while (traverse != NULL)
    {
        tail = traverse;
        traverse = traverse->next;
    }
    if (traverse == NULL)
    {
        tail->next = newnode;
        return;
    }
            
}

void OrderList::printDrink()
{
    if (drinkHead != NULL)
    {
        while (drinkHead != NULL)
        {
            cout<<"number: "<< drinkHead->number<<"name:"<<drinkHead->name;
            drinkHead = drinkHead->next;
        }
    }
}

void OrderList::addDrink(const Drink &add)
{
    Drink *traverse, *tail;
    Drink *newdrink = new Drink(add.name, add.price, add.type);
    newdrink->next = NULL;

    traverse = drinkHead;

    if (drinkHead == NULL)
    {
        drinkHead = newdrink;
        return;
    }

    while ((traverse != NULL) && (traverse->type != newdrink->type))
    {
         tail = traverse;
         traverse = traverse->next;
    }
    if (traverse == NULL)
    {
        tail->next = newdrink;
        return;
    }
    if (traverse->type == newdrink->type)
    {
        traverse->number++;
        return;
    }
}

void OrderList::printPizza()
{
    if (pizzaHead != NULL)
    {
        while (pizzaHead != NULL)
        {
            pizzaHead->pirintIngredient();
            pizzaHead = pizzaHead->next;
        }
    }
    
    
    
}

void OrderList::addPizza(Pizza *add)
{
    Pizza *traverse, *tail;
    Pizza *newnode = new Pizza;
    *newnode = *add;
    traverse = pizzaHead;
    newnode->next = NULL;

    if (pizzaHead == NULL)
    {
        pizzaHead = newnode;
        return;
    }

    while (traverse != NULL)
    {
        tail = traverse;
        traverse = traverse->next;
    }
    if (traverse == NULL)
    {
        tail->next = newnode;
        return;
    }
}

OrderList::OrderList()
{
    head = NULL;
    pizzaHead = NULL;
    drinkHead = NULL;
    order_number = 0;

}

bool OrderList::takeDrink()
{
    cout<<"Please choose a drink: "<<endl;
    cout<<"0. no drink"<<endl;
    cout<<"1. cola 4 TL"<<endl;
    cout<<"2. soda 2 TL"<<endl;
    cout<<"3. ice tea 3 TL"<<endl;
    cout<<"4. fruit juice 3.5 TL"<<endl;
    cout<<"5. Press -1 for save your order"<<endl;
    int choose = -2;
    while (choose != -1)
    {
        cin >> choose;
        if (choose == 0)
            return false;
        else if (choose == 1)
        {
            Drink drink("cola", 4, choose);
            addDrink(drink);

        }
        else if (choose == 2)
        {
            Drink drink("soda", 2, choose);
            addDrink(drink);
        }
        else if (choose == 3)
        {
            Drink drink("ice tea", 3, choose);
            addDrink(drink);
        }
        else if (choose == 4)
        {
            Drink drink("fruit juice", 3.5, choose);
            addDrink(drink);
        }  
    }
    return true;
}

void OrderList::pizzaMenu()
{
    
    int choose, amount;
    string select_size, select_crust_type;
	cout << "Pizza Menu" << endl;
	cout << "1. Chicken Pizza: mozarella, chicken, mushroom, corn, onion, tomato" << endl;
	cout << "2. Broccoli Pizza: mozarella, broccoli, pepperoni, olive, corn, onion" << endl;
	cout << "3. Sausage Pizza: mozarella, sausage, tomato, olive, mushroom, corn" << endl;
	cout << "0. Back to main menu" << endl;
	cin >> choose;
	
	if (choose == 0)
	{
		takeOrder();
	}
    
    
    Pizza pizza();
    cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
	cin >> select_size;
	cout << "Select crust type: thin, normal, thick" << endl;
	cin >> select_crust_type;
    Pizza newpizza = Pizza(select_size, select_crust_type, choose);
    cout << "Enter the amount:";
	cin >> amount;
    pizzaHead = new Pizza[amount];
    //addPizza(&newpizza);
    pizzaHead[0] = newpizza;
    
    if (amount > 1)
    {
        for (int i = 1; i < amount; i++)
        {
            Pizza newtopizza = newpizza;
            //addPizza(&newtopizza);
            pizzaHead[i] = newtopizza;
        }
    }
    bool result = takeDrink();
    //head = new Order[10];
    pizzaHead[0].number = amount;
    if (result)
    {
        string name;
	    cout << "Please enter your name:" << endl;
	    cin >> name;

        Order order(name, pizzaHead,drinkHead);
        order.printOrder();
        addOrder(&order);
        //head[order_number] = order;
    }
    else
    {
       string name;
	    cout << "Please enter your name:" << endl;
	    cin >> name;

        Order order(name, pizzaHead);
        order.printOrder();
        addOrder(&order);
        //head[order_number] = order;
    }
    
    OrderList::order_number++;
    delete [] pizzaHead;
    drinkHead = NULL;

}

void OrderList::takeOrder()
{
    cout << "Welcom to Unicorn Pizza!" << std::endl;
	cout << "1. Add an order" << endl;
	cout << "2. List orders" << endl;
	cout << "3. Deliver order" << endl;
	cout << "4. Exit" << endl;
	int chooses;

	cout<< "Choose what to do: ";
	cin >> chooses;

    if (chooses == 1)
	{
		this->pizzaMenu();
		this->takeOrder();
	}
	else if (chooses == 2)
	{
		this->listOrders();
        this->takeOrder();
	}
	else if (chooses == 3)
	{
		this->deliveryOrders();
        takeOrder();
	}
	else if (chooses == 4)
	{
        cout <<"Good By..."<<endl;
		return;
	}
    

}

