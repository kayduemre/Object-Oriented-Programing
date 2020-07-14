/*
    Emre KAYDU
    150160552

*/
#ifndef SIGMOID_H
#define SIGMOID_H
#include "Neuron.h"
#include <math.h>
class Sigmoid: public Neuron
{
protected:

    //float z;
    //float a;
    
public:
    Sigmoid(){this->a = this->z = 0.0;};
    Sigmoid(float z_in, float a_in){this->a = a_in; this->z = z_in;};
    void print();
    float activate();
};

float Sigmoid::activate()
{
    return 1/(1 + exp(this->z*-1));
}

void Sigmoid::print()
{
    std::cout<<this->a<<std::endl;
}
#endif