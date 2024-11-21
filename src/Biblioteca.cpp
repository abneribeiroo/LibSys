#include "../include/Biblioteca.h"
#include <algorithm>
#include <limits>

Biblioteca::Biblioteca()
{
    // ctor
}

Biblioteca::~Biblioteca() {
    for (auto& par : Coleccao_LIVROS) {
        for (auto& livro : par.second) {
            delete livro;
        }
    }
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


bool Biblioteca::Add_Livros(Geral* L) {
    if (L == nullptr) {
        cout << "Erro: Tentativa de adicionar um livro nulo!" << endl;
        return false;
    };
    string categoria = L->getCategoria();
    Coleccao_LIVROS[categoria].push_back(L);
    return true;
}

void Biblioteca::getCommonBookInfo(string& titulo, string& autor, int& anoPublicacao) {
    cout << "Digite o título: ";
    getline(cin >> ws, titulo);
    cout << "Digite o autor: ";
    getline(cin >> ws, autor);
    cout << "Digite o ano de publicação: ";
    cin >> anoPublicacao;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Biblioteca::registrarNovoLivro(){
    int tipo;
    string titulo, autor, areaPesquisa, editor, grauEscolaridade;
    int anoPublicacao, numeroEdicao;

    cout << "Selecione o tipo de livro para adicionar:" << endl;
    cout << "1. Livro Científico" << endl;
    cout << "2. Livro de Ficção" << endl;
    cout << "3. Livro Educativo" << endl;
    cout << "4. Revista" << endl;
    cout << "5. Jornal" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getCommonBookInfo(titulo, autor, anoPublicacao);

    Geral* novoLivro = nullptr;

    switch (tipo) {
    case 1: // Livro Científico
        cout << "Digite a área de pesquisa: ";
        getline(cin >> ws, areaPesquisa);
        novoLivro = new LivroCientifico(titulo, autor, anoPublicacao, areaPesquisa);
        break;
    case 2: // Livro de Ficção
        cout << "Digite o gênero: ";
        getline(cin >> ws, areaPesquisa);
        novoLivro = new LivroFiccao(titulo, autor, anoPublicacao, areaPesquisa);
        break;
    case 3: // Livro Educativo
        cout << "Digite o grau de escolaridade: ";
        getline(cin >> ws, grauEscolaridade);
        novoLivro = new LivroEducativo(titulo, autor, anoPublicacao, grauEscolaridade);
        break;
    case 4: // Revista
        cout << "Digite o número da edição: ";
        cin >> numeroEdicao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        novoLivro = new Revista(titulo, autor, anoPublicacao, numeroEdicao);
        break;
    case 5: // Jornal
        cout << "Digite a data de publicação: ";
        getline(cin >> ws, areaPesquisa);
        cout << "Digite o editor: ";
        getline(cin >> ws, editor);
        novoLivro = new Jornal(titulo, autor, anoPublicacao, areaPesquisa, editor);
        break;
    default:
        cout << "Tipo inválido!" << endl;
        return;
    }

    if (novoLivro) {
        if (Add_Livros(novoLivro)) {
            cout << "Livro adicionado com sucesso!" << endl;
        } else {
            cout << "Erro ao adicionar o livro." << endl;
            delete novoLivro;
        }
    } else {
        cout << "Erro ao criar o livro!" << endl;
    }
}

bool Biblioteca::Remove_Livro(const string& isbn) {
    for (auto& par : Coleccao_LIVROS) {
        auto& lista = par.second;
        auto it = find_if(lista.begin(), lista.end(),
            [&isbn](const Geral* livro) { return livro->getTitulo() == isbn; });
        if (it != lista.end()) {
            delete *it;
            lista.erase(it);
            return true;
        }
    }
    return false;
}

Geral* Biblioteca::Buscar_Livro(const string& isbn) const {
    for (const auto& par : Coleccao_LIVROS) {
        for (const auto* livro : par.second) {
            if (livro->getTitulo() == isbn) {
                return const_cast<Geral*>(livro);
            }
        }
    }
    return nullptr;
}

void Biblioteca::Editar_Livro(const string& isbn) {
    Geral* livro = Buscar_Livro(isbn);
    if (livro) {
        string novoTitulo, novoAutor;
        int novoAno;

        cout << "Novo título (ou Enter para manter): ";
        getline(cin, novoTitulo);
        if (!novoTitulo.empty()) livro->setTitulo(novoTitulo);

        cout << "Novo autor (ou Enter para manter): ";
        getline(cin, novoAutor);
        if (!novoAutor.empty()) livro->setAutor(novoAutor);

        cout << "Novo ano de publicação (ou 0 para manter): ";
        cin >> novoAno;
        if (novoAno != 0) livro->setAnoPublicacao(novoAno);

        cout << "Livro editado com sucesso!" << endl;
    } else {
        cout << "Livro não encontrado." << endl;
    }
}


void Biblioteca::Listagem_Livros() const {
    for (const auto& par : Coleccao_LIVROS) {
        cout << "Categoria: " << par.first << endl;
        for (const auto* livro : par.second) {
            livro->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
}

void Biblioteca::Listagem_Livros_Por_Categoria(const string& categoria) const {
    auto it = Coleccao_LIVROS.find(categoria);
    if (it != Coleccao_LIVROS.end()) {
        cout << "Categoria: " << categoria << endl;
        for (const auto* livro : it->second) {
            livro->mostrarInfo();
            cout << "--------------------" << endl;
        }
    } else {
        cout << "Categoria não encontrada." << endl;
    }
}


vector<LivroCientifico*> Biblioteca::BuscarLivrosCientificos(const string& areaPesquisa) const {
    vector<LivroCientifico*> resultado;
    auto it = Coleccao_LIVROS.find("LivroCientifico");
    if (it != Coleccao_LIVROS.end()) {
        for (auto* livro : it->second) {
            LivroCientifico* livroCientifico = dynamic_cast<LivroCientifico*>(livro);
            if (livroCientifico && (areaPesquisa.empty() || livroCientifico->getAreaPesquisa() == areaPesquisa)) {
                resultado.push_back(livroCientifico);
            }
        }
    }
    return resultado;
}

vector<LivroFiccao*> Biblioteca::BuscarLivrosFiccao(const string& genero) const {
    vector<LivroFiccao*> resultado;
    auto it = Coleccao_LIVROS.find("LivroFiccao");
    if (it != Coleccao_LIVROS.end()) {
        for (auto* livro : it->second) {
            LivroFiccao* livroFiccao = dynamic_cast<LivroFiccao*>(livro);
            if (livroFiccao && (genero.empty() || livroFiccao->getGenero() == genero)) {
                resultado.push_back(livroFiccao);
            }
        }
    }
    return resultado;
}

vector<LivroEducativo*> Biblioteca::BuscarLivrosEducativos(const string& grauEscolaridade) const {
    vector<LivroEducativo*> resultado;
    auto it = Coleccao_LIVROS.find("LivroEducativo");
    if (it != Coleccao_LIVROS.end()) {
        for (auto* livro : it->second) {
            LivroEducativo* livroEducativo = dynamic_cast<LivroEducativo*>(livro);
            if (livroEducativo && (grauEscolaridade.empty() || livroEducativo->getGrauEscolaridade() == grauEscolaridade)) {
                resultado.push_back(livroEducativo);
            }
        }
    }
    return resultado;
}

vector<Revista*> Biblioteca::BuscarRevistas(int numeroEdicao) const {
    vector<Revista*> resultado;
    auto it = Coleccao_LIVROS.find("Revista");
    if (it != Coleccao_LIVROS.end()) {
        for (auto* livro : it->second) {
            Revista* revista = dynamic_cast<Revista*>(livro);
            if (revista && (numeroEdicao == -1 || revista->getNumeroEdicao() == numeroEdicao)) {
                resultado.push_back(revista);
            }
        }
    }
    return resultado;
}

vector<Jornal*> Biblioteca::BuscarJornais(const string& dataPublicacao) const {
    vector<Jornal*> resultado;
    auto it = Coleccao_LIVROS.find("Jornal");
    if (it != Coleccao_LIVROS.end()) {
        for (auto* livro : it->second) {
            Jornal* jornal = dynamic_cast<Jornal*>(livro);
            if (jornal && (dataPublicacao.empty() || jornal->getDataPublicacao() == dataPublicacao)) {
                resultado.push_back(jornal);
            }
        }
    }
    return resultado;
}




void Biblioteca::testarFuncoes() {
    // Adicionar livros de teste
    Add_Livros(new LivroCientifico("Física Quântica", "Albert Einstein", 1935, "Física"));
    Add_Livros(new LivroCientifico("Origem das Espécies", "Charles Darwin", 1859, "Biologia"));
    Add_Livros(new LivroFiccao("1984", "George Orwell", 1949, "Distopia"));
    Add_Livros(new LivroFiccao("Dom Quixote", "Miguel de Cervantes", 1605, "Aventura"));
    Add_Livros(new LivroEducativo("Matemática Básica", "John Smith", 2020, "Ensino Fundamental"));
    Add_Livros(new Revista("National Geographic", "Various", 2023, 1));
    Add_Livros(new Jornal("The New York Times", "NYT Editorial", 2023, "2023-05-15", "NYT"));

    cout << "Testando busca de livros científicos:" << endl;
    auto livrosCientificos = BuscarLivrosCientificos("Física");
    for (auto livro : livrosCientificos) {
        livro->mostrarInfo();
        cout << endl;
    }

    cout << "Testando busca de livros de ficção:" << endl;
    auto livrosFiccao = BuscarLivrosFiccao("Distopia");
    for (auto livro : livrosFiccao) {
        livro->mostrarInfo();
        cout << endl;
    }

    cout << "Testando busca de livros educativos:" << endl;
    auto livrosEducativos = BuscarLivrosEducativos("Ensino Fundamental");
    for (auto livro : livrosEducativos) {
        livro->mostrarInfo();
        cout << endl;
    }

    cout << "Testando busca de revistas:" << endl;
    auto revistas = BuscarRevistas(1);
    for (auto revista : revistas) {
        revista->mostrarInfo();
        cout << endl;
    }

    cout << "Testando busca de jornais:" << endl;
    auto jornais = BuscarJornais("2023-05-15");
    for (auto jornal : jornais) {
        jornal->mostrarInfo();
        cout << endl;
    }

    cout << "Testando listagem de todos os livros:" << endl;
    Listagem_Livros();
}
