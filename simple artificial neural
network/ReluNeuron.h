/*
    Emre KAYDU
    150160552

*/
#include "Neuron.h"
#include <iostream>
#include <math.h>
using namespace std;
class ReluNeuron: public Neuron
{
protected:
    //float z;
    //float a;
public:
    ReluNeuron(){this->z = 0.0;this->a=0.0;};
    ReluNeuron(float z_in, float a_in){this->a = a_in; this->z = z_in;};
    void print();
    float activate();
};

float ReluNeuron::activate()
{
    return max(float(0.0),this->z);
}

void ReluNeuron::print()
{
    std::cout<<this->a<<std::endl;
}