#ifndef REVISTA_H
#define REVISTA_H

#include "Geral.h"
using namespace std;


class Revista : public Geral
{
    int numeroEdicao;
    public:
        Revista();
        Revista(int id, string titulo, string autor, Data dataPublicacao, int numeroEdicao) : Geral(id,titulo, autor, dataPublicacao), numeroEdicao(numeroEdicao) {};
        void mostrarInfo() const override {
            Geral::mostrarInfo();
            cout << "Numero de Edicao: " << numeroEdicao << endl;
        }
        string getCategoria() const override {
            return "Revista";
        }
        int getNumeroEdicao() const { return numeroEdicao; }
        virtual ~Revista();

    protected:

    private:
};

#endif // REVISTA_H
