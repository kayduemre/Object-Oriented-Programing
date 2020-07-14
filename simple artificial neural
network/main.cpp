/*
    Emre KAYDU
    150160552

*/
#include <iostream>
#include "Sigmoid.h"
#include "LReluNeuron.h"
#include "ReluNeuron.h"
#include "Network.h"
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    ifstream in(argv[1]);
    int layer;

    try
    {
       if (!in.is_open())throw "ERROR: File could not been open";
    }
    catch(const char* e)
    {
        cout<<e<<endl;
        return 0;
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

    int index = 0;
    while (!in.eof())
    {
        in>> input[index];
        index++;
    }
    in.close();

    try
    {
       if (index !=neuronNumber[0]) throw "Input shape does not match!";
    }
    catch(const char* e)
    {
        cout<<e<<index<<endl;
        return 0;
    }

    Network *network = new Network(input, neuronNumber[0], layer );
    Layer<Neuron> layer0(neurontype[0], neuronNumber[0]);
    float result = network->matrisMultipication();

    try{
    if (layer0.getType() == 0)
    {
        Sigmoid *sigmoid = new Sigmoid;
        layer0.neurons = sigmoid;
    }
    else if (layer0.getType() == 1)
    {
        LReluNeuron lReluNeuron;
        layer0.neurons = &lReluNeuron;
    }
    else if (layer0.getType() == 2)
    {
        ReluNeuron reluNeuron;
        layer0.neurons = &reluNeuron;
    }
    else
        throw "Unidentified activation function!";
    }
    catch(const char* e)
    {
        cout<<e<<endl;
    }
    network->setLayer(&layer0,0);
    float previousA = 0.0;

    for (int i = 1; i < layer; i++)
    {
        Layer<Neuron> temp(neurontype[i], neuronNumber[i]);

        try{
            if (temp.getType() == 0)
            {
                Sigmoid *sigmoid = new Sigmoid;
                temp.neurons = sigmoid;
            }
            else if (temp.getType() == 1)
            {
               LReluNeuron lReluNeuron;
                temp.neurons = &lReluNeuron;
            }
            else if (temp.getType() == 2)
            {
                ReluNeuron reluNeuron;
                temp.neurons = &reluNeuron;
            }
            else 
                throw "Unidentified activation function!";
        }
        catch(const char* e){
            cout << e << endl;
            return 0;
        }
        if (i == 1)
        {
            temp.neurons->setZ(result);
            const float a_in = temp.neurons->activate();
            previousA = a_in;
            temp.neurons->setA(a_in);
            network->setLayer(&temp, 1);
        }
        else
        {
            float a_in = previousA;
            float b_in = network->getB();
            float w_in = network->getW();
            temp.matrisMultipication(w_in, a_in, b_in);
            float a_out = temp.neurons->activate();
            previousA = a_out;
            temp.neurons->setA(a_out);
            network->setLayer(&temp, i);
        }
        
    }
    
    network->print();
    return 0;
}
