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
    calcularDataLimite();
    prorrogado = 0;
}

void Emprestimo::calcularDataLimite() {
    dataLimite = dataEmprestimo;
    dataLimite = dataLimite.adicionarDias(5);
}



void Emprestimo::realizarDevolucao() {
    devolvido = true;
    dataDevolucao = dataDevolucao.dataAtual();
    livro->setDisponibilidade(true);
    if(valorMulta.getValorFinal() > 0){
        cout << "Pagar multa de " << valorMulta.getValorFinal() << " EUR" << endl;
        cout << "Multa paga? (S/N): ";
        char opcao;
        cin >> opcao;
        if(opcao == 'S' || opcao == 's'){
            valorMulta.setPago(true);
        }else{
            valorMulta.setPago(false);
        }
    }
}

void Emprestimo::prorrogarEmprestimo() {
    if((leitor->getCategoria() == "Estudante" || leitor->getCategoria() == "Professor") && prorrogado < 2) {
        dataLimite = dataLimite.adicionarDias(5);
        prorrogado++;
    } else {
        if(prorrogado >= 2) {
            cout << "Limite de prorrogações atingido para este emprestimo." << endl;
        } 
    }
    if(prorrogado < 1 && !(leitor->getCategoria() == "Estudante" || leitor->getCategoria() == "Professor")) {
            dataLimite = dataLimite.adicionarDias(3);
            prorrogado++;
        }else{
            cout << "Limite de prorrogações atingido para este emprestimo." << endl;
        }
}
