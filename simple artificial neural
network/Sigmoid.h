#ifndef SIGMOID_H
#define SIGMOID_H
#include "Neuron.h"

class Sigmoid:public Neuron
{
private:
   
public:
    Sigmoid(float z, float a):Neuron(z,a){}
    void activate()const;
    
};
void Sigmoid::activate()const
{
    std::cout<<"virtual function";
}

#endif