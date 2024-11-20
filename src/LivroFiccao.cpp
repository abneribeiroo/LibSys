#include "../include/LivroFiccao.h"

LivroFiccao::LivroFiccao(string titulo, string autor, int anoPublicacao, string genero)
    : Geral(titulo, autor, anoPublicacao), genero(genero) {}


void LivroFiccao::mostrarInfo() const {
    Geral::mostrarInfo();
    cout << "Gênero: " << genero << endl;
}
LivroFiccao::~LivroFiccao()
{
    // dtor
}
