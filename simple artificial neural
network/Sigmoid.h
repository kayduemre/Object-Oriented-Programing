#ifndef SIGMOID_H
#define SIGMOID_H
#include "Neuron.h"
#include <math.h>

class Sigmoid:public Neuron
{
protected:
   
public:
    Sigmoid(float z, float a):Neuron(z,a){}
    float activate()const;
    
};
float Sigmoid::activate()const
{
    return 1/(1 + float(exp(_z)));
}

#endif