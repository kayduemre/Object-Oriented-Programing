#ifndef NEURON_H
#define NEURON_H
class Neuron
{
protected:
    float w, b;
    float _z;
    float _a;
    
public:
    Neuron* next;

    Neuron(float, float);
    void setZ(float z){_z = z; };
    void setA(float a){_a = a;};
    float getW(){return w;};
    float getB(){return b;};
    float getA(){return _a;};
    float getZ(){return _z;};
    virtual float activate() const = 0;
};

Neuron::Neuron(float z, float a)
{
    next = NULL;

    w = 0.1;
    b = float(0.1);
    _z = z;
    _a = a;   
}
#endif
