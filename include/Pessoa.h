#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;

class Pessoa
{
    protected:
    string nome;
    Data nascData;
    int id;
    Data regData;
    public:
        Pessoa();
        Pessoa(string nome, Data nascData, int id, Data regData) : nome(nome), nascData(nascData), id(id), regData(regData) {};

        virtual void mostrarInfo() const {
            cout << "Nome: " << nome << endl;
            cout << "Data de Nascimento: ";
            nascData.mostrarInfo();
            cout << "Id: " << id << endl;
            cout << "Data de Registro: ";
            regData.mostrarInfo();
        }
        virtual ~Pessoa();

        virtual string getCategoria() const = 0;
        string getNome() const { return nome; }
        int getId() const { return id; }
        Data getnascData() const { return nascData; }
        Data getregData() const { return regData; }
        void setNome(const string &novoNome) { nome = novoNome; }
        virtual int getDesconto() const{ return 0; }

        void setNasc(const Data& novaData) { nascData = novaData; }

    protected:

    private:
};

#endif // PESSOA_H
