#ifndef LAYER_H
#define LAYER_H
#include "Neuron.h"
#include "Sigmoid.h"


class Layer
{
private:
    int _index;
    Neuron *neurons;
    int** _input;
public:
    Layer(){_index = 0;};
    Layer(int,int);
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

Layer::~Layer()
{
}
#endif