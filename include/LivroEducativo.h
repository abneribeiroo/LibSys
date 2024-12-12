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
    LivroEducativo(int id, string titulo, string autor, Data dataPublicacao, string grauEscolaridade): Geral(id,titulo, autor, dataPublicacao), grauEscolaridade(grauEscolaridade) {};

    void mostrarInfo() const{
        Geral::mostrarInfo();
        cout << "Grau de Escolaridade: " << grauEscolaridade << endl;
    };
    string getCategoria() const override { return "LivroEducativo"; };
    string getGrauEscolaridade() const { return grauEscolaridade; }
    virtual ~LivroEducativo();

protected:
private:
};

#endif // LIVROEDUCATIVO_H
