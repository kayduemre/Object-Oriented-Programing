#include <iostream>
#include "Neuron.h"
using namespace std;
class ReluNeuron:public Neuron
{
protected:
   
public:
    ReluNeuron(float z, float a):Neuron(z, a){}
    ~ReluNeuron();
    void activate()const;
};
void ReluNeuron::activate()const
{
    cout<<"virtual function";
}

ReluNeuron::~ReluNeuron()
{
}
