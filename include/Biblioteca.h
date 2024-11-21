#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <vector>
#include "Pessoa.h"
#include "Geral.h"
#include "Revista.h"
#include "Jornal.h"
#include "LivroCientifico.h"
#include "LivroFiccao.h"
#include "LivroEducativo.h"
using namespace std;

class Biblioteca
{
private:
    map<string, list<Geral *>> Coleccao_LIVROS;
    map<string, list<Pessoa *>> Coleccao_LEITORES;


    void getCommonBookInfo(std::string& titulo, std::string& autor, int& anoPublicacao);

public:
    Biblioteca();
    ~Biblioteca();

    bool Add_Livros(Geral *L);
    void registrarNovoLivro();
    bool Remove_Livro(const string &isbn);
    Geral *Buscar_Livro(const string &isbn) const;
    void Editar_Livro(const std::string &isbn);
    void Listagem_Livros() const;
    void Listagem_Livros_Por_Categoria(const string &categoria) const;
    void Relatorio_Livros_Por_Categoria() const;


    vector<LivroCientifico *> BuscarLivrosCientificos(const string &areaPesquisa = "") const;
    vector<LivroFiccao *> BuscarLivrosFiccao(const string &genero = "") const;
    vector<LivroEducativo *> BuscarLivrosEducativos(const string &grauEscolaridade = "") const;
    vector<Revista *> BuscarRevistas(int numeroEdicao = -1) const;
    vector<Jornal *> BuscarJornais(const string &dataPublicacao = "") const;
    bool SaveToFile(const string& filename);
    bool LoadFile(const string& filename);
    void RelatorioCategoria(string cat);
    void Prorrogacao_Emprestimos();
    void Sistema_Notificacoes_Atraso();
    bool Add_Leitores();
    bool Add_Leitor(Pessoa *P);

    void testarFuncoes();
};

#endif // BIBLIOTECA_H
