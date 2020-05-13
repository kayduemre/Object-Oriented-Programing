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
public:
    Layer(){_index = 0;};
    Layer(int,int);

    void createNeuron(int ,int);
    void setInput(int *, int);
    ~Layer();
};

Layer::Layer(int row, int col)
{
    _input = new int*[row];
    for(int i = 0; i < row; ++i)
        _input[i] = new int[0];
    
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

Layer::~Layer()
{
}
#endif