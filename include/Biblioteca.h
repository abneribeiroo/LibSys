#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include "Pessoa.h"
#include "Geral.h"
using namespace std;

class Biblioteca
{
    map<string, Geral*> Coleccao_LIVROS;
   // list, vector, map Coleccao_LIVROS;
   // list, vector, map Coleccao_REQ;
    public:
        Biblioteca();
        virtual ~Biblioteca();
        bool SaveToFile(string nf);
        bool LoadFile(string nf);
        void RelatorioCategoria(string cat);
        void Prorrogacao_Emprestimos();
        void Sistema_Notificacoes_Atraso();
        void Listagem_Livros();
        bool Add_Leitores();
        bool Add_Leitor(Pessoa *P);
        bool Add_Livros(Geral *L);

};

#endif // BIBLIOTECA_H
