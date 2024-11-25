#ifndef SENIOR_H
#define SENIOR_H
#include <iostream>
#include <string>
#include "Pessoa.h"
using namespace std;

class Senior : public Pessoa
{
private:
    /* data */
public:
    Senior();
    Senior(string nome, int idade, int id) : Pessoa(nome, idade, id) {};

    void mostrarInfo() const {
        Pessoa::mostrarInfo();
        cout << "Tipo de Leitor: Senior" << endl;
    }
    virtual ~Senior();
    string getCategoria() const override
    {
        return "Senior";
    };
};




#endif // SENIOR_H
