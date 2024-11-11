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
    Senior(string nome, int idade) : Pessoa(nome, idade) {};

    void mostrarInfo() const {
        Pessoa::mostrarInfo();
        cout << "Tipo de Leitor: Senior" << endl;
    }
    virtual ~Senior();
};




#endif // SENIOR_H