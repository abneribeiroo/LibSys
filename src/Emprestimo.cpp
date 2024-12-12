#include "../include/Emprestimo.h"
#include "../include/Jornal.h"
#include "../include/Revista.h"
#include "../include/LivroEducativo.h"
#include "../include/LivroCientifico.h"
#include "../include/LivroFiccao.h"
#include "../include/Senior.h"
#include "../include/Estudante.h"
#include "../include/Professor.h"
#include "../include/LeitorComum.h"
#include <sstream>
#include <iomanip>

Emprestimo::Emprestimo(int id, Geral* livro, Pessoa* leitor)
    : id(id), livro(livro), leitor(leitor) {
    calcularDataDevolucao();
}

void Emprestimo::calcularDataDevolucao() {

}

// void Emprestimo::realizarDevolucao() {
//     devolvido = true;
//     multa = calcularMulta();
//     livro->setDisponibilidade(true);
// }
