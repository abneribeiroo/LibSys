#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Geral.h"
using namespace std;

class LivroFiccao : public Geral
{
    string genero;

public:
    LivroFiccao();
    LivroFiccao(int id, string titulo, string autor, Data dataPublicacao, string genero): Geral(id,titulo, autor, dataPublicacao), genero(genero) {};
    void mostrarInfo() const{
        Geral::mostrarInfo();
        cout << "Género: " << genero << endl;
    };
    string getCategoria() const override { return "LivroFiccao"; }
    string getGenero() const { return genero; }
    virtual ~LivroFiccao();

protected:
private:
};

#endif // LIVROFICCAO_H
