#include "../include/Geral.h"

using namespace std;

Geral::Geral() :id(0), titulo(""), autor(""), anoPublicacao(0), disponivel(true) {}

Geral::Geral(int id, string titulo, string autor, int anoPublicacao)
    : id(id), titulo(titulo), autor(autor), anoPublicacao(anoPublicacao), disponivel(true) {}

void Geral::mostrarInfo() const
{
    cout << "ID: " << id << endl;
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Ano de Publicação: " << anoPublicacao << endl;
    cout << "Disponível: " << (disponivel ? "Sim" : "Não") << endl;
}
