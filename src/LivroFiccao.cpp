#include "../include/LivroFiccao.h"

// Construtor padrão
LivroFiccao::LivroFiccao(): Geral(0,"","", 0), genero(""){}

// Construtor parametrizado
LivroFiccao::LivroFiccao(int id, string titulo, string autor, int anoPublicacao, string genero)
    : Geral(id, titulo, autor, anoPublicacao), genero(genero) {}


void LivroFiccao::mostrarInfo() const
{
    Geral::mostrarInfo();
    cout << "Gênero: " << genero << endl;
}

LivroFiccao::~LivroFiccao()
{
    // dtor
}
