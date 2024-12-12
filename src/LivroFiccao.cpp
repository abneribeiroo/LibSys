#include "../include/LivroFiccao.h"

// Construtor padrão
LivroFiccao::LivroFiccao() {}

// Construtor parametrizado
LivroFiccao::LivroFiccao(int id, string titulo, string autor, Data dataPublicacao, string genero)
    : Geral(id, titulo, autor, dataPublicacao), genero(genero) {}




LivroFiccao::~LivroFiccao()
{
    // dtor
}
