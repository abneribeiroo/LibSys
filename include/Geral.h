#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>
using namespace std;

class Geral : 
{
protected:
    string titulo;
    string autor;
    Data dataPublicacao;
    // Talvez adicionar mais atributos para as subclasses
public:
    Geral();
    Geral(string titulo, string autor, Data dataPublicacao) : titulo(titulo), autor(autor), Data(dataPublicacao) {}
    virtual void mostrarInfo() const
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Data de Publicacao: " << dataPublicacao.mostrarInfo() << endl;
    }

    virtual ~Geral();
    // virtual string QuemEs() = 0;
    // virtual void Show();
};

#endif // GERAL_H
