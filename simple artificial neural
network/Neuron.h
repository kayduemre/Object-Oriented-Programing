/*
    Emre KAYDU
    150160552

*/
#ifndef NEURON_H
#define NEURON_H
#include <iostream>
class Neuron
{
public:
    float z;
    float a;

    void print(){std::cout<<z<<std::endl;};
    void printA(){std::cout<<a<<std::endl;};
    void setZ(float z_in){this->z = z_in; };
    void setA(float a_in){this->a = a_in;};
    virtual float activate()=0;
};

#endif