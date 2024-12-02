#ifndef JORNAL_H
#define JORNAL_H

#include "Geral.h"
using namespace std;

class Jornal : public Geral
{
    string dataPublicacao;
    string editor;

public:
    Jornal();
    Jornal(int id, string titulo, string autor, int anoPublicacao, string dataPublicacao, string editor) : Geral(id, titulo, autor, anoPublicacao), dataPublicacao(dataPublicacao), editor(editor) {};

    void mostrarInfo() const
    {
        Geral::mostrarInfo();
        cout << "Data de Publicacao: " << dataPublicacao << endl;
        cout << "Editor: " << editor << endl;
    }
    string getCategoria() const override
    {
        return "Jornal";
    }
    string getDataPublicacao() const { return dataPublicacao; }
    string getEditor() const { return editor; }
    virtual ~Jornal();

protected:
private:
};

#endif
