#include <iostream>
#include <string>
using namespace std;

class Network
{
private:
    int _layer;
    int *_neuronNumber;
    int *_neuronType;
    int *_input;

    float **_w;
    float **_b;
   
public:
    Network(string, string, string, string);
    void setW(int, int);
    void setB(int, int);
    ~Network();
};

Network::Network(string layer, string neuronNumber, string neuronType, string input)
{
    _layer = stoi(layer);
    _neuronNumber = new int[_layer];
    _neuronType = new int[_layer];

    for (int i = 0; i < _layer; i++)
    {
        char *n = &neuronNumber[i];
        char *t = &neuronType[i];
        char *ı = &input[i];
        _neuronNumber[i] = atoi(n);
        _neuronType[i] = atoi(t);
        _input[i] = atoi(ı);
    }
}

void Network::setW(int row, int col)
{
    _w = new float*[row];
    for (int i = 0; i < row; i++)
        _w[i] = new float[col];
    
}

void Network::setB(int row, int col)
{
    _b = new float*[row];
    for (int i = 0; i < row; i++)
        _b[i] = new float[col];
}

Network::~Network()
{
}
