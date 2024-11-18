#include "../include/Biblioteca.h"

Biblioteca::Biblioteca()
{
    // ctor
}

Biblioteca::~Biblioteca()
{
    // dtor
}

bool Biblioteca::SaveToFile(string nf)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
    return true;
}
void Biblioteca::RelatorioCategoria(string cat)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}
void Biblioteca::Prorrogacao_Emprestimos()
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}
void Biblioteca::Sistema_Notificacoes_Atraso()
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}

bool Biblioteca::Add_Leitores()
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
    return true;
}
bool Biblioteca::Add_Leitor(Pessoa *P)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
    return true;
}

bool Biblioteca::Add_Livros(Geral *L)
{
    if (L == nullptr)
    {
        cout << "Erro: Tentativa de adicionar um livro nulo!" << endl;
        return false;
    }
    string categoria = L->getCategoria();
    Coleccao_LIVROS[categoria].push_back(L);
    return true;
}

void Biblioteca::Listagem_Livros()
{
    for (const auto &pair : Coleccao_LIVROS)
    {
        cout << "Categoria: " << pair.first << endl;
        for (const auto *livro : pair.second)
        {
            livro->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
}
