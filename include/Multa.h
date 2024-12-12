#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
using namespace std;

class Multa
{
public:
    Multa();
    Multa(int dia, int mes, int ano);
    virtual ~Multa();
    virtual void mostrarInfo() const;
    int calcularIdade() const;
    bool eValida() const;
    Multa lerData();
    Multa dataAtual();
    Multa lerString(const string &dataStr);
    string paraString() const;

private:
    int dia;
    int mes;
    int ano;
};

#endif
