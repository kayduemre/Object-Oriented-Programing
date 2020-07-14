/*
	Emre KAYDU
	150160552
*/
#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string.h>

using namespace std;
class Pizza
{
private:
	string name;
	string size;
	string *ingredients;
	string crust_type;
    

public:
    int number;
    Pizza *next;
	Pizza();
	Pizza(string, string, int);
	Pizza(const Pizza &);

    void pirintIngredient();
    string getname(){return name;};
    string getsize(){return size;};
    string getcrust_type(){return crust_type;};
	
};
void Pizza::pirintIngredient()
{
    cout<<ingredients[0];
}
Pizza::Pizza()
{
    size = "medium";
    crust_type = "normal";
    ingredients = new string[6];
    ingredients[0] = "mozarella";
    next = NULL;
}
Pizza::Pizza(string getsize, string getcrust_type, int getpizza_type)
{
    ingredients = new string[6];
    size = getsize;
    crust_type = getcrust_type;
    next = NULL;

    if (getpizza_type == 1)
    {
        name = "Chicken Pizza:";
        ingredients->append("mozarella,");
        ingredients->append("chicken,");
        ingredients->append("mushroom,");
        ingredients->append("corn,");
        ingredients->append("onion,");
        ingredients->append("tomato");
    }
    else if (getpizza_type == 2)
    {
        name = "Broccoli Pizza:";
        ingredients->append("mozarella,");
        ingredients->append("broccoli,");
        ingredients->append("pepperoni,");
        ingredients->append("olive,");
        ingredients->append("corn,");
        ingredients->append("onion");
    }
    else if (getpizza_type == 3)
    {
        name = "Sausage Pizza:";
        ingredients->append("mozarella,");
        ingredients->append("sausage,");
        ingredients->append("tomato,");
        ingredients->append("olive,");
        ingredients->append("mushroom,");
        ingredients->append("corn");
    }   
}

Pizza::Pizza(const Pizza &pizza)
{
    name = pizza.name;
    size = pizza.crust_type;
    crust_type = pizza.crust_type;
    ingredients = new string[sizeof(pizza.ingredients)];
    *ingredients = *pizza.ingredients;
    next = NULL;
    
    cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
	cout << "1. mozarella" << endl;
	cout << "2. Broccoli" << endl;
	cout << "3. pepperoni" << endl;
	cout << "4. onion" << endl;
	cout << "5. olive" << endl;
	cout << "6. corn" << endl;
	cout << "Press 0 to seve it." << endl;
	int rmv = -1;

    while (rmv != 0)
    {
        cin >> rmv;
        if (rmv == 1)
        {
            
            string::size_type found = ingredients[0].find("mozarella");
            if (found!=std::string::npos)
              ingredients[0].erase(found, 10);
        }
        else if (rmv == 2)
        {
            string::size_type found = ingredients[0].find("Broccoli");
            if (found!=std::string::npos)
              ingredients[0].erase(found, 9);
        }
        else if (rmv == 3)
        {
            string::size_type found = ingredients[0].find("pepperoni");
            if (found!=std::string::npos)
              ingredients[0].erase(found, 10);
        }
        else if (rmv == 4)
        {
            string::size_type found = ingredients[0].find("onion");
            if (found!=std::string::npos)
              ingredients[0].erase(found, 6);
        }
        else if (rmv == 5)
        {
            string::size_type found = ingredients[0].find("olive");
            if (found!=std::string::npos)
              ingredients[0].erase(found, 6);
        }
        else if (rmv == 6)
        {
            string::size_type found = ingredients[0].find("corn");
            if (found!=std::string::npos)
              ingredients[0].erase(found, 5);
        }
    }

}
#endif