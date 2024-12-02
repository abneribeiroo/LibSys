#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"

class LivroCientifico : public Geral
{
    string areaPesquisa;

public:
    LivroCientifico();
    LivroCientifico(int id, string titulo, string autor, int anoPublicacao, string areaPesquisa);
    void mostrarInfo() const override;
    string getCategoria() const override
    {
        return "LivroCientifico";
    };
    string getAreaPesquisa() const { return areaPesquisa; }
    virtual ~LivroCientifico();

protected:
private:
};

#endif // LIVROCIENTIFICO_H
