#include "../include/LivroEducativo.h"

// Construtor padrão
LivroEducativo::LivroEducativo() : Geral("", "", 0), grauEscolaridade("") {}

// Construtor parametrizado
LivroEducativo::LivroEducativo(string titulo, string autor, int anoPublicacao, string grauEscolaridade)
    : Geral(titulo, autor, anoPublicacao), grauEscolaridade(grauEscolaridade) {}

// Método para mostrar informações
void LivroEducativo::mostrarInfo() const {
    Geral::mostrarInfo();
    cout << "Grau de Escolaridade: " << grauEscolaridade << endl;
}

// Método virtual para retornar a categoria
string LivroEducativo::getCategoria() const {
    return "LivroEducativo";
}

// Destrutor
LivroEducativo::~LivroEducativo() {}