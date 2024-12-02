#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Geral.h"
#include <string>
#include <iostream>

using namespace std;

class LivroEducativo : public Geral
{
    string grauEscolaridade;

public:
    LivroEducativo();
    LivroEducativo(int id, string titulo, string autor, int anoPublicacao, string grauEscolaridade);

    void mostrarInfo() const override;
    string getCategoria() const override;
    string getGrauEscolaridade() const { return grauEscolaridade; }
    virtual ~LivroEducativo();

protected:
private:
};

#endif // LIVROEDUCATIVO_H
