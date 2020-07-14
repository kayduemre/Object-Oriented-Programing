/*
    Emre KAYDU
    150160552

*/
#ifndef LRELUNEURON_H
#define LRELUNEURON_H
#include "Neuron.h"
#include <math.h>
using namespace std;
class LReluNeuron: public Neuron
{
protected:
    //float z;
    //float a;
public:
    LReluNeuron(){this->z=this->a= 0.0;};
    LReluNeuron(float z, float a){this->a = a; this->z = z;};
    void print();
    float activate();
};

float LReluNeuron::activate()
{
    float z_in = this->z * 0.1;
    float r;

    if (z_in < this->z)
        r = this->z;
    else
        r = z_in;
    
    return r;
}
void LReluNeuron::print()
{
    std::cout<<this->a<<std::endl;
}
#endif
