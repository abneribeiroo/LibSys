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
    int anoPublicacao;
    bool disponivel;
    // Data dataPublicacao;
    //  Talvez adicionar mais atributos para as subclasses
public:
    Geral();
    Geral(int id, string titulo, string autor, int anoPublicacao);

    void setTitulo(const string &novoTitulo) { titulo = novoTitulo; }

    void setAutor(const string &novoAutor) { autor = novoAutor; }

    void setAnoPublicacao(int novoAno) { anoPublicacao = novoAno; }

    virtual void mostrarInfo() const;

    virtual ~Geral() = default;
    virtual string getCategoria() const = 0;
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAnoPublicacao() const { return anoPublicacao; }
    int getId() const { return id; }
    bool estaDisponivel() const { return disponivel; }
    void setDisponibilidade(bool disp) { disponivel = disp; }
    // virtual string QuemEs() = 0;
};

#endif // GERAL_H
