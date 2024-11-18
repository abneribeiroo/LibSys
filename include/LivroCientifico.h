#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"


class LivroCientifico : public Geral
{
    string areaPesquisa;
    public:
        LivroCientifico();
        LivroCientifico(string titulo, string autor, int anoPublicacao, string areaPesquisa) : Geral(titulo, autor, anoPublicacao), areaPesquisa(areaPesquisa) {};
        void mostrarInfo() const {
            Geral::mostrarInfo();
            cout << "Area de Pesquisa: " << areaPesquisa << endl;
        }
        virtual ~LivroCientifico();

    protected:

    private:
};

#endif // LIVROCIENTIFICO_H
