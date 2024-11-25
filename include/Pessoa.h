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
    int id;
    public:
        Pessoa();
        Pessoa(string nome, int idade, int id) : nome(nome), idade(idade), id(id) {};

        virtual void mostrarInfo() const {
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
            cout << "Id: " << id << endl;
        }
        virtual ~Pessoa();
        virtual string getCategoria() const = 0;
        string getNome() const { return nome; }
        int getId() const { return id; }
        void setNome(const string &novoNome) { nome = novoNome; }

        void setIdade(const int &novaIdade) { idade = novaIdade; }

    protected:

    private:
};

#endif // PESSOA_H
