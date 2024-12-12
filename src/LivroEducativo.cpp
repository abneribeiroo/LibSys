#include "../include/LivroEducativo.h"

// Construtor padrão
LivroEducativo::LivroEducativo() {}

// Construtor parametrizado
LivroEducativo::LivroEducativo(int id, string titulo, string autor, Data dataPublicacao, string grauEscolaridade)
    : Geral(id, titulo, autor, dataPublicacao), grauEscolaridade(grauEscolaridade) {}

// Método para mostrar informações


// Método virtual para retornar a categoria
string LivroEducativo::getCategoria() const
{
    return "LivroEducativo";
}

// Destrutor
LivroEducativo::~LivroEducativo() {}
