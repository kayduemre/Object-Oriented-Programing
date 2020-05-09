#include <iostream>
#include "Network.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("input1.txt");
    string number_of_level;
    string neurons_number_of_level;
    string neuron_type;
    string input;


    if (!in.is_open())
    {
        cout<<"ERROR: File could not been open"<<endl;
    }

    while (in.peek() !=EOF)
    {

        getline(in,number_of_level,'\n');
        
		getline(in,neurons_number_of_level,'\n');
        
		getline(in,neuron_type,'\n');
        
		getline(in,input,'\n');
        
    }
    in.close();

    Network *network = new Network(number_of_level, neurons_number_of_level, neuron_type, input);

    
    return 0;
}
