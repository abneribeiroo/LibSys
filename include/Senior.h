#ifndef SENIOR_H
#define SENIOR_H
#include <iostream>
#include <string>
#include "Pessoa.h"
using namespace std;

class Senior : public Pessoa
{
private:
    int Desconto; // em percentagem ex:20 para 20%
public:

    Senior();
    Senior(string nome, Data nascData, int id, Data regData, int Desconto) : Pessoa(nome, nascData, id, regData), Desconto(Desconto) {};

    void mostrarInfo() const {
        Pessoa::mostrarInfo();
        cout << "Desconto: " << Desconto << "%" << endl;
        cout << "Tipo de Leitor: Senior" << endl;
    }
    virtual ~Senior();
    int getDesconto() const { return Desconto; }
    string getCategoria() const override
    {
        return "Senior";
    };
};




#endif // SENIOR_H
