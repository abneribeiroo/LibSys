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
    Data(int ano, int mes, int dia) : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao) {}
    virtual void mostrarInfo() const
    {
        cout << "Ano: " << ano << endl;
        cout << "Mes: " << mes << endl;
        cout << "Dia: " << dia << endl;
    }

    virtual ~Data();
   
};

#endif 
