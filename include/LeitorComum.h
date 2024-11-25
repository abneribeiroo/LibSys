#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"


class LeitorComum : public Pessoa
{
    public:
        LeitorComum();
        LeitorComum(string nome, int idade, int id) : Pessoa(nome, idade, id) {};

        void mostrarInfo() const {
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
