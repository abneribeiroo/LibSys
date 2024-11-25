#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    public:
        Professor();
        Professor(string nome, int idade, int id) : Pessoa(nome, idade, id){};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Tipo de Leitor: Professor" << endl;
        }
        virtual ~Professor();
        string getCategoria() const override
        {
            return "Professor";
        };
    protected:

    private:
};

#endif // PROFESSOR_H
