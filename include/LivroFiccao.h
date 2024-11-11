#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Geral.h"


class LivroFiccao : public Geral
{
    string genero;
    public:
        LivroFiccao(string titulo, string autor, int anoPublicacao, string genero) : Geral(titulo, autor, anoPublicacao), genero(genero) {};
        virtual ~LivroFiccao();

        void mostrarInfo() const {
            Geral::mostrarInfo();
            cout << "Genero: " << genero << endl;
        }
    protected:

    private:
};

#endif // LIVROFICCAO_H
