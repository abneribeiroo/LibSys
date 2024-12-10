#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "Pessoa.h"


class Estudante : public Pessoa
{


    string curso;

    public:

        Estudante();
        Estudante(string nome, Data nascData, int id, Data regData, string curso) : Pessoa(nome, nascData, id, regData), curso(curso){};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Curso: " << curso << endl;
            cout << "Tipo de Leitor: Estudante" << endl;
        }
        virtual ~Estudante();
        string getCurso() const { return curso; }
        string getCategoria() const override
        {
            return "Estudante";
        };


    protected:
    private:
};

#endif // Estudante_H
