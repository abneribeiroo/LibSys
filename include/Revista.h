#ifndef REVISTA_H
#define REVISTA_H

#include "Geral.h"


class Revista : public Geral
{
    int numeroEdicao;
    public:
        Revista( string titulo, string autor, int anoPublicacao, int numeroEdicao ) : Geral(titulo, autor, anoPublicacao), numeroEdicao(numeroEdicao) {};
        void mostrarInfo() const override {
            Geral::mostrarInfo();
            cout << "Numero de Edicao: " << numeroEdicao << endl;
        }
        virtual ~Revista();

    protected:

    private:
};

#endif // REVISTA_H
