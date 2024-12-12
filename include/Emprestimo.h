#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Geral.h"
#include "Pessoa.h"
#include "Data.h"
#include <string>

class Emprestimo {
private:
    int id;
    Geral* livro;
    Pessoa* leitor;
    Data dataEmprestimo;
    Data dataDevolucao;
    Data dataLimite;
    bool devolvido;
    double multa;

public:
    Emprestimo(int id, Geral* livro, Pessoa* leitor);
    Emprestimo();
    void calcularDataDevolucao();
    bool estahAtrasado() const;
    double calcularMulta() const;
    void realizarDevolucao();

    // Getters
    int getId() const { return id; }
    Geral* getLivro() const { return livro; }
    Pessoa* getLeitor() const { return leitor; }
    string getDataEmprestimo() const { return dataEmprestimo.paraString(); }
    string getDataDevolucao() const { return dataDevolucao.paraString(); }
    string getDataLimite() const { return dataLimite.paraString(); }
    bool estaDevolvido() const { return devolvido; }
    double getMulta() const { return multa; }

    // Setters for loading data
    void setId(int novoId) { id = novoId; }
    void setDataEmprestimo(Data data) { dataEmprestimo = data; }
    void setDataDevolucao(Data data) { dataDevolucao = data; }
    void setDataLimite(Data data) { dataLimite = data; }
    void setDevolvido(bool estado) { devolvido = estado; }

    void setMulta(double valor) { multa = valor; }

    void mostrarInfo() const {
        cout << "ID: " << id << endl;
        cout << "Livro: " << livro->getTitulo() << endl;
        cout << "Leitor: " << leitor->getNome() << endl;
        cout << "Data de Emprestimo: " << dataEmprestimo.paraString() << endl;
        cout << "Data de Devolucao: " << dataDevolucao.paraString() << endl;
        cout << "Data Limite: " << dataLimite.paraString() << endl;
        cout << "Devolvido: " << (devolvido ? "Sim" : "Não") << endl;
        cout << "Multa: " << multa << endl;
    }
};

#endif // EMPRESTIMO_H
