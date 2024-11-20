#include "../include/Geral.h"

using namespace std;

Geral::Geral() : titulo(""), autor(""), anoPublicacao(0), disponivel(true) {}

Geral::Geral(string titulo, string autor, int anoPublicacao)
    : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao), disponivel(true) {}

void Geral::mostrarInfo() const
{
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Ano de Publicação: " << anoPublicacao << endl;
    cout << "Disponível: " << (disponivel ? "Sim" : "Não") << endl;
}
