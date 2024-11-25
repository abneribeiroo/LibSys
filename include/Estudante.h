#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "Pessoa.h"


class Estudante : public Pessoa
{
    public:
        Estudante();
        Estudante(string nome, int idade, int id) : Pessoa(nome, idade, id){};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Tipo de Leitor: Estudante" << endl;
        }
        virtual ~Estudante();
        string getCategoria() const override
        {
            return "Estudante";
        };
    protected:

    private:
};

#endif // Estudante_H
