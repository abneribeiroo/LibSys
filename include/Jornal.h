#ifndef JORNAL_H
#define JORNAL_H
#include "Geral.h"


class Jornal : public Geral
{
    string dataPublicacao;
    string editor;
    public:
        Jornal ( string titulo, string autor, int anoPublicacao, string dataPublicacao, string editor ) : Geral(titulo, autor, anoPublicacao), dataPublicacao(dataPublicacao), editor(editor) {};

        void mostrarInfo() const {
            Geral::mostrarInfo();
            cout << "Data de Publicacao: " << dataPublicacao << endl;
            cout << "Editor: " << editor << endl;
        }
        
        virtual ~Jornal();

    protected:

    private:
};
#endif 