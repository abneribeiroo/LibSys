#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
using namespace std;

class Data {
public:
    Data();
    Data(int dia, int mes, int ano);
    virtual ~Data();
    virtual void mostrarInfo() const;
    int calcularIdade() const;
    bool eValida() const;
    Data lerData();
    Data dataAtual();
    Data lerString(const string& dataStr);
    string paraString() const;
private:
    int dia;
    int mes;
    int ano;
};

#endif

