#include <iostream>
#include "Neuron.h"
class LReluNeuron:public Neuron
{
protected:

public:
    LReluNeuron(float z, float a):Neuron(z,a){}
    float activate()const;
    ~LReluNeuron();
};

LReluNeuron::~LReluNeuron()
{
}
float LReluNeuron::activate()const
{
    return max(float(0.1*_z),_z);
}