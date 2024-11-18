#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"


class LeitorComum : public Pessoa
{
    public:
        LeitorComum();
        LeitorComum(string nome, int idade ) : Pessoa(nome, idade) {};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Tipo de Leitor: Comum" << endl;
        }
        virtual ~LeitorComum();



    protected:

    private:
};

#endif // LEITORCOMUM_H
