#include <iostream>
#include "Neuron.h"
#include "math.h"
using namespace std;
class ReluNeuron:public Neuron
{
protected:
   
public:
    ReluNeuron(float z, float a):Neuron(z, a){}
    ~ReluNeuron();
    float activate()const;
};
float ReluNeuron::activate()const
{
    return max(float(0.0),_z);
}

ReluNeuron::~ReluNeuron()
{
}
