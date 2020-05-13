#include <iostream>
#include "Network.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("input1.txt");
    int layer;


    if (!in.is_open())
    {
        cout<<"ERROR: File could not been open"<<endl;
    }

    in >> layer;
    int neuronNumber[layer];
    int neurontype[layer];
    int input[layer];

    for (int i = 0; i < layer; i++)
    {
        in>> neuronNumber[i];
    }

    for (int i = 0; i < layer; i++)
    {
        in>> neurontype[i];
    }

    for (int i = 0; i < layer; i++)
    {
        in>> input[i];
    }
 
    in.close();

    Network network(neuronNumber[1], neuronNumber[0], layer);

    Layer layer0(neuronNumber[1], neuronNumber[0]);
    layer0.setInput(input, layer);

    return 0;
}
