#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Geral.h"
using namespace std;


class LivroFiccao : public Geral
{
    string genero;
    public:
        LivroFiccao();
        LivroFiccao(string titulo, string autor, int anoPublicacao, string genero);
        void mostrarInfo() const override;
        string getCategoria() const override { return "LivroFiccao"; }
        string getGenero() const { return genero; }
        virtual ~LivroFiccao();

    protected:
    private:
};

#endif // LIVROFICCAO_H
