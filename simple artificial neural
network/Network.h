/*
    Emre KAYDU
    150160552

*/
#include "Layer.h"

class Network
{
private:
enum {MAX = 100};
    Layer<Neuron> *layers;
    int* input;
    int inputNumbers;
    int layerNumber;
    float w;
    float b;
public:
    Network(int *, int, int);
    void setLayer(const Layer<Neuron> *,int);
    float getW(){return w;};
    float getB(){return b;};
    void print();
    void printInput();
    float matrisMultipication();
    ~Network();
};

float Network::matrisMultipication()
{
    float result = 0.0;
    for (int i = 0; i < inputNumbers; i++)
    {
       result += input[i]*w;
    }
    result +=b;
    return result;
}
void Network::printInput()
{
    for (int i = 0; i < inputNumbers ; i++)
    {
        cout<<input[i]<<endl;
    }
    
}
void Network::print()
{
    cout<<"Layer 0:"<<endl;
    this->printInput();
    for (int i = 1; i < layerNumber; i++)
    {
        cout<<"Layer "<<i<<":"<<endl;
        layers[i].print();
    }
}

Network::Network(int *in, int nNumber, int nLayer)
{

    this->w = 0.1;
    this->b = 0.1;
    this->layerNumber = nLayer;
    this->input = new int[nNumber];
    this->inputNumbers = nNumber;
    this->layers = new Layer<Neuron>[nNumber];
    for (int i = 0; i < nNumber; i++)
    {
        this->input[i] = in[i];
    }
    
}

void Network::setLayer(const Layer<Neuron> *l, int index)
{
    layers[index] = *l;
}
Network::~Network()
{
    delete layers;
}