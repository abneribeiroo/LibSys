#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>
using namespace std;

class Geral
{
protected:
    string titulo;
    string autor;
    int anoPublicacao;
    // Talvez adicionar mais atributos para as subclasses
public:
    Geral();
    Geral(string titulo, string autor, int anoPublicacao) : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao) {}
    virtual void mostrarInfo() const
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Ano de Publicacao: " << anoPublicacao << endl;
    }

    virtual ~Geral();
    // virtual string QuemEs() = 0;
    // virtual void Show();
};

#endif // GERAL_H
