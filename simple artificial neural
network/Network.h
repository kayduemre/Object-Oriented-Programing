#include <iostream>
#include <string>

#include "Layer.h"
using namespace std;

class Network
{
private:

    Layer *_layer;
    int *_input;
   
public:
    Network(int);

    void print();
    void setLayer(const Layer &, int);
    void setW(int, int);
    void setB(int, int);
    ~Network();
};

void Network::print()
{
    for (int i = 0; i < 3; i++)
    {
       cout<< _layer[i].getIndex();
    }
    
}

Network::Network(int layerNumber)
{
   _layer = new Layer[layerNumber];
}

void Network::setLayer(const Layer &layer, int index)
{
   _layer[index] = layer;

}
Network::~Network()
{
}
