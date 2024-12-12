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

    // Livros
    bool Add_Livros(Geral *L);
    void registrarNovoLivro();
    bool Remove_Livro(const string &id);
    Geral *Buscar_Livro(const string &id) const;
    void Editar_Livro(const string &id);
    void Listagem_Livros() const;
    void ListarLivros_Por_Categoria(const string &categoria) const;
    void ListarCategoria();
    //void Relatorio_Livros_Por_Categoria() const;

    bool SaveToFile_Livros(const string &filename);
    bool LoadFile_Livros(const string &filename);

    void RelatorioCategoria(string cat); // TODO: Implementar
    void Prorrogacao_Emprestimos();      // TODO: Implementar
    void Sistema_Notificacoes_Atraso();  // TODO: Implementar


    // Leitores
    bool Add_Leitor(Pessoa *P);
    bool Remove_Leitor(int id);
    Pessoa *Buscar_Leitor(int id) const;
    void Editar_Leitor(int id);
    void Listagem_Leitores() const;
    void registarLeitor();
    int gerarID_leitor();
    bool SaveToFile_Livros_Leitores(const string &filename);
    bool LoadFile_Livros_Leitores(const string &filename);

    bool realizarEmprestimo(Geral *livro, Pessoa *leitor);
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
