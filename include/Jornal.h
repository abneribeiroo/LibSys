#ifndef JORNAL_H
#define JORNAL_H

#include "Geral.h"
using namespace std;

class Jornal : public Geral
{
    string editor;

public:
    Jornal( );
    Jornal(int id, string titulo, string autor, Data dataPublicacao, string editor): Geral(id,titulo, autor, dataPublicacao), editor(editor) {};
 

    void mostrarInfo() const
    {
        Geral::mostrarInfo();
        cout << "Editor: " << editor << endl;
    }
    string getCategoria() const override
    {
        return "Jornal";
    }
    string getDataPublicacao() const { return dataPublicacao.paraString(); }
    string getEditor() const { return editor; }
    virtual ~Jornal();

protected:
private:
};

#endif
