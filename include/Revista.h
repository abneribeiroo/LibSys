#ifndef REVISTA_H
#define REVISTA_H

#include "Geral.h"
using namespace std;


class Revista : public Geral
{
    int numeroEdicao;
    public:
        Revista();
        Revista( string titulo, string autor, int anoPublicacao, int numeroEdicao ) : Geral(titulo, autor, anoPublicacao), numeroEdicao(numeroEdicao) {};
        void mostrarInfo() const override {
            Geral::mostrarInfo();
            cout << "Numero de Edicao: " << numeroEdicao << endl;
        }
        string getCategoria() const override {
            return "Revista";
        }
        virtual ~Revista();

    protected:

    private:
};

#endif // REVISTA_H
