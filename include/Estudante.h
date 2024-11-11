#ifndef ESTUDANTE_h
#define ESTUDANTE_h
#include "Pessoa.h"
#include <iostream>
#include <string>
using namespace std;

class Estudante : public Pessoa
{
    public:
        Estudante(string nome, int idade) : Pessoa(nome, idade) {};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Tipo de Leitor: Estudante" << endl;
        }
        virtual ~Estudante();

    protected:

    private:
};

#endif // !ESTUDANTE_h
