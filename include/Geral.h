#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;

class Geral
{
protected:
    int id;
    string titulo;
    string autor;

    bool disponivel;
    Data dataPublicacao;
    //  Talvez adicionar mais atributos para as subclasses
public:
    Geral();
    Geral(int id, string titulo, string autor, Data dataPublicacao);

    void setTitulo(const string &novoTitulo) { titulo = novoTitulo; }

    void setAutor(const string &novoAutor) { autor = novoAutor; }

    void setDataPublicacao(const Data& novaData) { dataPublicacao = novaData; }

    virtual void mostrarInfo() const;

    virtual ~Geral() = default;
    virtual string getCategoria() const = 0;
    int getId() const {return id;}
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    string getDataPublicacao() const { return dataPublicacao.paraString(); }
    bool estaDisponivel() const { return disponivel; }
    void setDisponibilidade(bool disp) { disponivel = disp; }
    // virtual string QuemEs() = 0;
};

class LivroEducativo : public Geral
{
private:
    string grauEscolaridade;

public:
    LivroEducativo() : Geral(0, "", "", Data()), grauEscolaridade("") {}
};

class LivroFiccao : public Geral
{
private:
    string genero;

public:
    LivroFiccao() : Geral(0, "", "", Data()), genero("") {}
};

#endif // GERAL_H
