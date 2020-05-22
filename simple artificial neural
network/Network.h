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
    Layer *getLayer(int index){return &_layer[index];};
    void doMatrixMultipication(Layer *, Layer* , bool );
    void updateLayer(int, int, int);
    
    ~Network();
};

void Network::print()
{
        cout<<"LAyer0"<<endl;
        _layer[0].printInput();
       cout<<"LAyer1"<<endl;
        _layer[1].printZ();
        //_layer[2].printZ();
    
}


void Network::doMatrixMultipication(Layer *tail, Layer *current, bool inf)
{
    Layer _tail = *tail;
    Layer _current = *current;

    
    float result = 0.0;
    //for zero layer and first layer
    if (inf == false)
    {
        //layer1
        for (int i = 0; i < current->getNeuronNumber(); i++)
        {
            //layer 0
            for (int j = 0; j < tail->getNeuronNumber(); j++)
            {
                result += _layer[0].getInput()[j]*_current.getNeuron(i).getW();
            }
            
            
            result += _current.getNeuron(i).getB();
            cout<<"result"<<_current.getNeuron(i).getB();
            _current.getNeuron(i).setZ(result);
            /*result = _current.getNeuron(i).activate();
            _current.getNeuron(i).setA(result);
            result = 0.0;
            */
        }
    }
    /*else
    {
        for (int i = 0; i < _current.getNeuronNumber(); i++)
        {
            for (int j = 0; j < _tail.getNeuronNumber(); j++)
            {
                result += _tail.getNeuron(j).getA()*_current.getNeuron(i).getW();
            }
            
            result += _current.getNeuron(i).getB();
            _current.getNeuron(i).setZ(result);
            result = _current.getNeuron(i).activate();
            _current.getNeuron(i).setZ(result);
            result = 0.0; 
        }
        
    }   */ 
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

void Network::updateLayer(int value, int lIndex, int nIndex)
{
    float activation_number;
    this->_layer[lIndex].setNeuron(value, nIndex);
    activation_number = this->_layer[lIndex].getNeuron(nIndex).activate();
    this->_layer[lIndex].getNeuron(nIndex).setA(activation_number);
}

void Network::setLayer(const Layer &layer, int index)
{
   _layer[index] = layer;

}
Network::~Network()
{
}
#endif