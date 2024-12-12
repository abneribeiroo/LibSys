
#include "Emprestimo.h"
#include "Jornal.h"
#include "Revista.h"
#include "LivroEducativo.h"
#include "LivroCientifico.h"
#include "LivroFiccao.h"
#include "Senior.h"
#include "Estudante.h"
#include "Professor.h"
#include "LeitorComum.h"

using namespace std;

Emprestimo::Emprestimo(Geral* livro, Pessoa* leitor)
    : livro(livro), leitor(leitor), dataEmprestimo(chrono::system_clock::now()), devolvido(false), multa(0.0) {
    calcularDataDevolucao();
}

void Emprestimo::calcularDataDevolucao() {
    int diasEmprestimo = 14; // Padrão para LeitorComum

    if (dynamic_cast<Estudante*>(leitor)) {
        if (dynamic_cast<LivroEducativo*>(livro)) {
            diasEmprestimo = 21; // Mais tempo para estudantes com livros educativos
        }
    } else if (dynamic_cast<Professor*>(leitor)) {
        if (dynamic_cast<LivroCientifico*>(livro)) {
            diasEmprestimo = 30; // Mais tempo para professores com livros científicos
        }
    }

    dataDevolucao = dataEmprestimo + chrono::hours(24 * diasEmprestimo);
}

bool Emprestimo::estahAtrasado() const {
    return chrono::system_clock::now() > dataDevolucao;
}

double Emprestimo::calcularMulta() const {
    if (!estahAtrasado()) return 0.0;

    const double MULTA_POR_DIA = 1.0; // 1 euro por dia de atraso
    auto diasAtraso = chrono::duration_cast<chrono::hours>(chrono::system_clock::now() - dataDevolucao).count() / 24;

    double multaTotal = diasAtraso * MULTA_POR_DIA;

    if (dynamic_cast<Estudante*>(leitor) || dynamic_cast<Professor*>(leitor)) {
        multaTotal *= 0.5; // 50% de desconto para estudantes e professores
    }

    return multaTotal;
}

void Emprestimo::realizarDevolucao() {
    devolvido = true;
    multa = calcularMulta();
    livro->setDisponibilidade(true);
}
