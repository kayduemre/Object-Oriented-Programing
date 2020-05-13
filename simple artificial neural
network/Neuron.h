#ifndef NEURON_H
#define NEURON_H
class Neuron
{
protected:
    float w, b;
    float _z, _a;
public:
    Neuron(float, float);

    virtual void activate() const = 0;
};

Neuron::Neuron(float z, float a)
{
    w = 0.1;
    b = 0.1;
    _z = z;
    _a = a;   
}
#endif
