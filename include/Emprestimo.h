#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Geral.h"
#include "Pessoa.h"
#include <chrono>

class Emprestimo {
private:
    Geral* livro;
    Pessoa* leitor;
    chrono::system_clock::time_point dataEmprestimo;
    chrono::system_clock::time_point dataDevolucao;
    bool devolvido;
    double multa;

public:
    Emprestimo(Geral* livro, Pessoa* leitor);
    void calcularDataDevolucao();
    bool estahAtrasado() const;
    double calcularMulta() const;
    void realizarDevolucao();

    // Getters
    Geral* getLivro() const { return livro; }
    Pessoa* getLeitor() const { return leitor; }
    chrono::system_clock::time_point getDataEmprestimo() const { return dataEmprestimo; }
    chrono::system_clock::time_point getDataDevolucao() const { return dataDevolucao; }
    bool estaDevolvido() const { return devolvido; }
    double getMulta() const { return multa; }

    // Setters for loading data
    void setDataEmprestimo(chrono::system_clock::time_point data) { dataEmprestimo = data; }
    void setDataDevolucao(chrono::system_clock::time_point data) { dataDevolucao = data; }
    void setDevolvido(bool estado) { devolvido = estado; }
    void setMulta(double valor) { multa = valor; }
};

#endif // EMPRESTIMO_H
