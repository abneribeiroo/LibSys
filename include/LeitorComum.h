#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"

class LeitorComum : public Pessoa
{
public:
    LeitorComum();
    LeitorComum(string nome, Data nascData, int id, Data regData) : Pessoa(nome, nascData, id, regData) {};

    void mostrarInfo() const
    {
        Pessoa::mostrarInfo();
        cout << "Tipo de Leitor: Comum" << endl;
    }
    virtual ~LeitorComum();
    string getCategoria() const override
    {
        return "Leitor Comum";
    };

protected:
private:
};

#endif // LEITORCOMUM_H
