#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_h

#include "Geral.h"

class LivroEducativo : public Geral {
    string grauEscolaridade;
    public :
        LivroEducativo(string titulo, string autor, int anoPublicacao, string grauEscolaridade) : Geral(titulo, autor, anoPublicacao), grauEscolaridade(grauEscolaridade) {};
        void mostrarInfo() const {
            Geral::mostrarInfo();
            cout << "Grau de Escolaridade: " << grauEscolaridade << endl;
        }

        virtual ~LivroEducativo();
    protected:
    
    private:
};


#endif // LIVROEDUCATIVO_H