#include "../include/Geral.h"

using namespace std;

Geral::Geral() :id(0), titulo(""), autor(""), dataPublicacao(), disponivel(true) {}

Geral::Geral(int id, string titulo, string autor, Data dataPublicacao)
    : id(id), titulo(titulo), autor(autor), dataPublicacao(dataPublicacao), disponivel(true) {}

void Geral::mostrarInfo() const
{
    cout << "ID: " << id << endl;
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Data de Publicação: ";
    dataPublicacao.mostrarInfo();
    cout << endl;
    cout << "Disponível: " << (disponivel ? "Sim" : "Não") << endl;
}
