#include <iostream>
#include "Neuron.h"
class LReluNeuron:public Neuron
{
protected:
    
public:
    LReluNeuron(float z, float a):Neuron(z,a){}
    void activate()const;
    ~LReluNeuron();
};

LReluNeuron::~LReluNeuron()
{
}
void LReluNeuron::activate()const
{
    std::cout<<"virtual function";
}