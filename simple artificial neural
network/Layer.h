#ifndef LAYER_H
#define LAYER_H
#include "Neuron.h"
#include "Sigmoid.h"
#include "ReluNeuron.h"
#include "LReluNeuron.h"

using namespace std; 
class Layer
{
private:
    int _index;
    Neuron *neurons;
    int** _input;
    int neuronNumber;
public:
    Layer(){_index = 0;};
    Layer(int,int);

    void createNeuron(int ,int);
    float* calculateLayerZero_Z(int);
    void setInput(int *, int);
    void setNeuron(int value, int index){neurons[index].setZ(value);};
    ~Layer();
};

Layer::Layer(int row, int col)
{
    _input = new int*[row];
    for(int i = 0; i < row; ++i)
        _input[i] = new int[0];
    
    neuronNumber = col;
}

void Layer::setInput(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        _input[i][0] = arr[i];
    }
    
}

void Layer::createNeuron(int type, int number)
{
    Neuron *traverse, *tail, *temp;
    if (type == 0)
    {
        Sigmoid sigmoid(0.0,0.0);
        temp = &sigmoid;
    }
    if (type == 1)
    {
        ReluNeuron reluNeuron(0.0,0.0);
        temp = &reluNeuron;
    }
    if (type == 2)
    {
        LReluNeuron lReluNeuron(0.0,0.0);
        temp = &lReluNeuron;
    }

    traverse = neurons;

    if (neurons == NULL)
    {
        neurons = temp;
        return;
    }
    
    for (int i = 0; i < number; i++)
    {
        traverse->next = temp;
        traverse = traverse->next;
    }
}

float* Layer::calculateLayerZero_Z(int oneLayer)
{
    float z[oneLayer];
    float result;
    for (int i = 0; i < neuronNumber; i++)
    {
        result += _input[i][0] * this->neurons[i].getW();
    }
    result += this->neurons[0].getB();

    for (int i = 0; i < oneLayer; i++)
    {
        z[i] = result;
    }
    return z;
}

Layer::~Layer()
{
}
#endif