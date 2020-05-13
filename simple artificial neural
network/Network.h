#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <string>

#include "Layer.h"
using namespace std;

class Network
{
private:

    Layer* _layer;

    
    float** _W;
    float** _B;
   
public:
    Network(int, int, int);

    void print();
    void setLayer(const Layer &, int);
    ~Network();
};

void Network::print()
{
    for (int i = 0; i < 3; i++)
    {
       //cout<< _layer[i].getIndex();
    }
    
}

Network::Network(int row, int col, int layerNumber)
{
    _layer = new Layer[layerNumber];

    _W = new float*[row];
    for(int i = 0; i < row; ++i)
        _W[i] = new float[col];

    _B = new float*[row];
    for(int i = 0; i < row; ++i)
        _B[i] = new float[0];
    
    

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            _W[i][j] = 0.1;
        }
        
    }

    for (int i = 0; i < row; i++)
    {
        _B[i][0] = 0.1;
    }
}



void Network::setLayer(const Layer &layer, int index)
{
   _layer[index] = layer;

}
Network::~Network()
{
}
#endif