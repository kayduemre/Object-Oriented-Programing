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
    int* _input;
    int neuronNumber;
public:
    Layer(){_index = 0;};
    Layer(int,int);

    void createNeuron(int ,int);
    float* calculateLayer_Z(int);
    void doMatrixMultipication(Layer &, Layer&, bool);

    void setInput(int *, int);
    void setNeuron(int value, int index){neurons[index].setZ(value);};

    Neuron& getNeuron(int index){return neurons[index];};
    int* getInput(){return _input;};
    int getNeuronNumber(){return neuronNumber;};

    void printInput();
    void printZ();
    ~Layer();
};

void Layer::printInput()
{
    for (int i = 0; i < 3; i++)
    {
        cout<<_input[i]<<endl;
    }
    
}

void Layer::printZ()
{
    for (int i = 0; i < neuronNumber; i++)
    {
       cout << neurons[i].getZ() << endl;
    }
    
}
Layer::Layer(int row, int col)
{
    _input = new int[row];
    
    
    neuronNumber = col;
}

void Layer::setInput(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        _input[i] = arr[i];
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

float* Layer::calculateLayer_Z(int nNumber)
{
    //calculate z values of next layer with a values
    float *z = new float[nNumber];
    float result;

    for (int i = 0; i < neuronNumber; i++)
    {
        result += this->neurons[i].getA() * this->neurons[i].getW();
    }
    result += this->neurons[0].getB();

    for (int i = 0; i < neuronNumber; i++)
    {
        z[i] = result;
    }
    return z;
}



Layer::~Layer()
{
}
#endif