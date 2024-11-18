#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
using namespace std;

class Pessoa
{
    protected:
    string nome;
    int idade;
    public:
        Pessoa();
        Pessoa(string nome, int idade) : nome(nome), idade(idade) {};

        virtual void mostrarInfo() const {
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
        }
        virtual ~Pessoa();

    protected:

    private:
};

#endif // PESSOA_H
