#include <iostream>

#include "Network.h"
#include "Neuron.h"
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

    //layer 0 input layer
    Layer layer0(neuronNumber[1], neuronNumber[0]);
    layer0.setInput(input, layer);
    layer0.createNeuron(neuronNumber[0], neurontype[0]);
    network.setLayer(layer0,0);

    for (int i = 1; i < layer; i++)
    {
        Layer newlayer(neuronNumber[i + 1], neuronNumber[i]);
        newlayer.createNeuron(neuronNumber[i], neurontype[i]);
        network.setLayer(newlayer, i);
    }
    

    return 0;
}
