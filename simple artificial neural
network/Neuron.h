#ifndef NEURON_H
#define NEURON_H
class Neuron
{
protected:
    float w, b;
    float _z;
    
public:
float _a;
    Neuron* next;

    Neuron(float, float);
    void setZ(int z){_z = z; };
    float getW(){return w;};
    float getB(){return b;};
    virtual float activate() const = 0;
};

Neuron::Neuron(float z, float a)
{
    next = NULL;

    w = 0.1;
    b = 0.1;
    _z = z;
    _a = a;   
}
#endif
