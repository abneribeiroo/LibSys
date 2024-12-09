#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <queue>
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
#include "Professor.h"
#include "LeitorComum.h"
#include "Estudante.h"
#include "Senior.h"
#include "Emprestimo.h"
using namespace std;

class Biblioteca
{
private:
    map<string, list<Geral *>> Coleccao_LIVROS;
    map<string, list<Pessoa *>> Coleccao_LEITORES;

    vector<Emprestimo> emprestimos;
    map<Geral *, std::queue<Pessoa *>> reservas;
    int highestId;
    int getNextId();

    void getCommonBookInfo(std::string &titulo, std::string &autor, int &anoPublicacao);

public:
    Biblioteca();
    ~Biblioteca();

    bool Add_Livros(Geral *L);
    void registrarNovoLivro();
    bool Remove_Livro(const string &id);
    Geral *Buscar_Livro(const string &id) const;
    void Editar_Livro(const std::string &id);
    void Listagem_Livros() const;
    void Listagem_Livros_Por_Categoria(const string &categoria) const;
    void ListarCategoria();
    void Relatorio_Livros_Por_Categoria() const;

    vector<LivroCientifico *> BuscarLivrosCientificos(const string &areaPesquisa = "") const;
    vector<LivroFiccao *> BuscarLivrosFiccao(const string &genero = "") const;
    vector<LivroEducativo *> BuscarLivrosEducativos(const string &grauEscolaridade = "") const;
    vector<Revista *> BuscarRevistas(int numeroEdicao = -1) const;
    vector<Jornal *> BuscarJornais(const string &dataPublicacao = "") const;

    bool SaveToFile(const string &filename);
    bool LoadFile(const string &filename);
    void RelatorioCategoria(string cat);
    void Prorrogacao_Emprestimos();
    void Sistema_Notificacoes_Atraso();
    bool Add_Leitores();
    bool Add_Leitor(Pessoa *P);
    bool Remove_Leitor(int id);
    Pessoa *Buscar_Leitor(int id) const;
    void Editar_Leitor(int id);
    void Listagem_Leitores() const;
    void registarLeitor();

    // bool realizarEmprestimo(Geral *livro, Pessoa *leitor);
    // bool realizarDevolucao(Geral *livro, Pessoa *leitor);
    // bool fazerReserva(Geral *livro, Pessoa *leitor);
    // void processarReservas();
    // void listarEmprestimosAtrasados() const;
    // void listarReservas() const;

    // void gerarRelatorioMultasPendentes() const;
    // bool salvarDados(const std::string &filename) const;
    // bool carregarDados(const std::string &filename);
};

#endif // BIBLIOTECA_H
