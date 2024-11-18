#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Geral.h"
#include <string>
#include <iostream>

using namespace std;

class LivroEducativo : public Geral {
    string grauEscolaridade;

public:
    LivroEducativo();
    LivroEducativo(string titulo, string autor, int anoPublicacao, string grauEscolaridade);

    void mostrarInfo() const override;

    string getCategoria() const override;

    virtual ~LivroEducativo();

protected:
private:
};

#endif // LIVROEDUCATIVO_H
