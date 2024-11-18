#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    public:
        Professor();
        Professor(string nome, int idade) : Pessoa(nome, idade) {};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Tipo de Leitor: Professor" << endl;
        }
        virtual ~Professor();

    protected:

    private:
};

#endif // PROFESSOR_H
