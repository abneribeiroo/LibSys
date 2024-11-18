#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Geral.h"
using namespace std;


class LivroFiccao : public Geral
{
    string genero;
    public:
        LivroFiccao();

        LivroFiccao(string titulo, string autor, int anoPublicacao, string genero) : Geral(titulo, autor, anoPublicacao), genero(genero) {};

        void mostrarInfo() const {
            Geral::mostrarInfo();
            cout << "Genero: " << genero << endl;
        }
        string getCategoria() const override {
            return "LivroFiccao";
        }

        virtual ~LivroFiccao();

    protected:
    private:
};

#endif // LIVROFICCAO_H
