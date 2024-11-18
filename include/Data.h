#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
using namespace std;

class Data
{
protected:
    int ano;
    int mes;
    int dia;
public:
    Data();
    Data(int ano, int mes, int dia) : ano(ano), mes(mes), dia(dia) {}
    virtual void mostrarInfo() const
    {
        cout << "Ano: " << ano << endl;
        cout << "Mes: " << mes << endl;
        cout << "Dia: " << dia << endl;
    }

    virtual ~Data();
   
};

#endif 
