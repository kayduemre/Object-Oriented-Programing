/*
    Emre KAYDU
    150160552

*/
#include "Neuron.h"
template<class T>
class Layer
{
private:
    
    int _type;
    int _neronNumber;
public:
    T* neurons;
    Layer(){this->neurons = NULL;};
    Layer(int, int);
    void print();
    Neuron& getNeuron(){return *neurons;};
    int getType(){return _type;};
    int getNeuronNumber(){return _neronNumber;};
    void matrisMultipication(float, float, float);
};

template<class T>
void Layer<T>::matrisMultipication(float w_in,float a_in, float b_in)
{
    float result = 0.0;
    for (int i = 0; i < _neronNumber; i++)
    {
       result += w_in*a_in;
    }
    result += b_in;
    this->neurons->setZ(result);
    
}

template<class T>
Layer<T>::Layer(int type, int nNumber)
{
    this->_type = type;
    this->_neronNumber = nNumber;

}
template<class T>
void Layer<T>::print()
{
    for (int i = 0; i < _neronNumber; i++)
    {
        this->neurons->printA();
    }
    
}

