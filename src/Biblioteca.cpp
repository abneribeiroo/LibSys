#include "../include/Biblioteca.h"
#include "../include/Uteis.h"
#include "../include/Data.h"
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>

Biblioteca::Biblioteca() : highestId(0)
{
    // ctor
}

Biblioteca::~Biblioteca()
{
    for (auto &par : Coleccao_LIVROS)
    {
        for (auto &livro : par.second)
        {
            delete livro;
        }
    }
}

int Biblioteca::getNextId()
{
    return ++highestId;
}

bool Biblioteca::SaveToFile(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return false;
    }

    for (const auto &pair : Coleccao_LIVROS)
    {
        for (const Geral *livro : pair.second)
        {
            file << livro->getId() << ";"
                 << livro->getCategoria() << ";"
                 << livro->getTitulo() << ";"
                 << livro->getAutor() << ";"
                 << livro->getAnoPublicacao() << ";";

            if (livro->getCategoria() == "LivroCientifico")
            {
                const LivroCientifico *lc = dynamic_cast<const LivroCientifico *>(livro);
                file << lc->getAreaPesquisa();
            }
            else if (livro->getCategoria() == "LivroFiccao")
            {
                const LivroFiccao *lf = dynamic_cast<const LivroFiccao *>(livro);
                file << lf->getGenero();
            }
            else if (livro->getCategoria() == "LivroEducativo")
            {
                const LivroEducativo *le = dynamic_cast<const LivroEducativo *>(livro);
                file << le->getGrauEscolaridade();
            }
            else if (livro->getCategoria() == "Revista")
            {
                const Revista *r = dynamic_cast<const Revista *>(livro);
                file << r->getNumeroEdicao();
            }
            else if (livro->getCategoria() == "Jornal")
            {
                const Jornal *j = dynamic_cast<const Jornal *>(livro);
                file << j->getDataPublicacao() << ";" << j->getEditor();
            }

            file << endl;
        }
    }

    file.close();
    cout << "Dados salvos com sucesso no arquivo " << filename << endl;
    return true;
}

bool Biblioteca::LoadFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);

        string categoria, titulo, autor, anoPublicacaoStr, atributoEspecifico, editor;
        int id;

        string idStr;
        if (!getline(ss, idStr, ';'))
        {
            cout << "Erro: Formato de linha inválido." << endl;
            continue;
        }
        try
        {
            id = stoi(idStr);
            highestId = max(highestId, id);
        }
        catch (const invalid_argument &e)
        {
            cout << "Erro: ID inválido - " << idStr << endl;
            continue;
        }

        getline(ss, categoria, ';');
        getline(ss, titulo, ';');
        getline(ss, autor, ';');
        getline(ss, anoPublicacaoStr, ';');
        getline(ss, atributoEspecifico, ';');

        int anoPublicacao = stoi(anoPublicacaoStr);

        Geral *livro = nullptr;

        if (categoria == "LivroCientifico")
        {
            livro = new LivroCientifico(id, titulo, autor, anoPublicacao, atributoEspecifico);
        }
        else if (categoria == "LivroFiccao")
        {
            livro = new LivroFiccao(id, titulo, autor, anoPublicacao, atributoEspecifico);
        }
        else if (categoria == "LivroEducativo")
        {
            livro = new LivroEducativo(id, titulo, autor, anoPublicacao, atributoEspecifico);
        }
        else if (categoria == "Revista")
        {
            livro = new Revista(id, titulo, autor, anoPublicacao, stoi(atributoEspecifico));
        }
        else if (categoria == "Jornal")
        {
            getline(ss, editor, ';');
            livro = new Jornal(id, titulo, autor, anoPublicacao, atributoEspecifico, editor);
        }

        if (livro)
        {
            Add_Livros(livro);
        }
    }

    file.close();
    cout << "Dados carregados com sucesso do arquivo " << filename << endl;
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


bool Biblioteca::Add_Livros(Geral *L)
{
    if (L == nullptr)
    {
        cout << "Erro: Tentativa de adicionar um livro nulo!" << endl;
        return false;
    };
    string categoria = L->getCategoria();
    Coleccao_LIVROS[categoria].push_back(L);
    return true;
}

void Biblioteca::getCommonBookInfo(string &titulo, string &autor, int &anoPublicacao)
{
    cout << "Digite o título: ";
    getline(cin >> ws, titulo);
    cout << "Digite o autor: ";
    getline(cin >> ws, autor);
    cout << "Digite o ano de publicação: ";
    cin >> anoPublicacao;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Biblioteca::registrarNovoLivro()
{
    int tipo;
    string titulo, autor, areaPesquisa, editor, grauEscolaridade;
    int anoPublicacao, numeroEdicao;

    cout << "Selecione a categoria que deseja listar:" << endl;
    cout << "1. Livro Científico" << endl;
    cout << "2. Livro de Ficção" << endl;
    cout << "3. Livro Educativo" << endl;
    cout << "4. Revista" << endl;
    cout << "5. Jornal" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getCommonBookInfo(titulo, autor, anoPublicacao);

    int id = getNextId();
    cout << "ID do livro: " << id << endl;
    Geral *novoLivro = nullptr;

    switch (tipo)
    {
    case 1: // Livro Científico
        cout << "Digite a área de pesquisa: ";
        getline(cin >> ws, areaPesquisa);
        novoLivro = new LivroCientifico(id, titulo, autor, anoPublicacao, areaPesquisa);
        break;
    case 2: // Livro de Ficção
        cout << "Digite o gênero: ";
        getline(cin >> ws, areaPesquisa);
        novoLivro = new LivroFiccao(id, titulo, autor, anoPublicacao, areaPesquisa);
        break;
    case 3: // Livro Educativo
        cout << "Digite o grau de escolaridade: ";
        getline(cin >> ws, grauEscolaridade);
        novoLivro = new LivroEducativo(id, titulo, autor, anoPublicacao, grauEscolaridade);
        break;
    case 4: // Revista
        cout << "Digite o número da edição: ";
        cin >> numeroEdicao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        novoLivro = new Revista(id, titulo, autor, anoPublicacao, numeroEdicao);
        break;
    case 5: // Jornal
        cout << "Digite a data de publicação: ";
        getline(cin >> ws, areaPesquisa);
        cout << "Digite o editor: ";
        getline(cin >> ws, editor);
        novoLivro = new Jornal(id, titulo, autor, anoPublicacao, areaPesquisa, editor);
        break;
    default:
        cout << "Tipo inválido!" << endl;
        return;
    }

    if (novoLivro)
    {
        if (Add_Livros(novoLivro))
        {
            cout << "Livro adicionado com sucesso!" << endl;
        }
        else
        {
            cout << "Erro ao adicionar o livro." << endl;
            delete novoLivro;
        }
    }
    else
    {
        cout << "Erro ao criar o livro!" << endl;
    }
}

bool Biblioteca::Remove_Livro(const string &id)
{
    for (auto &par : Coleccao_LIVROS)
    {
        auto &lista = par.second;
        for (auto it = lista.begin(); it != lista.end(); ++it)
        {
            if (to_string((*it)->getId()) == id)
            {
                delete *it;
                lista.erase(it);
                return true;
            }
        }
    }
    return false;
}

Geral *Biblioteca::Buscar_Livro(const string &id) const
{
    for (const auto &par : Coleccao_LIVROS)
    {
        for (const auto *livro : par.second)
        {
            if (to_string(livro->getId()) == id)
            {
                return const_cast<Geral *>(livro);
            }
        }
    }
    return nullptr;
}

void Biblioteca::ListarCategoria()
{
    int tipo;
    Geral *categoria = nullptr;
    string categoriaLivro;
    cout << "Selecione o tipo de livro que deseja listar:" << endl;
    cout << "1. Livro Científico" << endl;
    cout << "2. Livro de Ficção" << endl;
    cout << "3. Livro Educativo" << endl;
    cout << "4. Revista" << endl;
    cout << "5. Jornal" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (tipo)
    {
    case 1:
        categoria = new LivroCientifico();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::Listagem_Livros_Por_Categoria(categoriaLivro);
        break;
    case 2:
        categoria = new LivroFiccao();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::Listagem_Livros_Por_Categoria(categoriaLivro);
        break;
    case 3:
        categoria = new LivroEducativo();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::Listagem_Livros_Por_Categoria(categoriaLivro);
        break;
    case 4:
        categoria = new Revista();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::Listagem_Livros_Por_Categoria(categoriaLivro);
        break;
    case 5:
        categoria = new Jornal();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::Listagem_Livros_Por_Categoria(categoriaLivro);
        break;
    }
}

void Biblioteca::Editar_Livro(const string &id)
{
    Geral *livro = Buscar_Livro(id);
    if (livro)
    {
        string novoTitulo, novoAutor;
        int novoAno;

        cout << livro->getTitulo() << endl;
        cout << "Novo título (ou Enter para manter): ";
        cin.ignore();
        getline(cin, novoTitulo);
        if (!novoTitulo.empty())
            livro->setTitulo(novoTitulo);

        cout << livro->getAutor() << endl;
        cout << "Novo autor (ou Enter para manter): ";
        getline(cin, novoAutor);
        if (!novoAutor.empty())
            livro->setAutor(novoAutor);

        cout << livro->getAnoPublicacao() << endl;
        cout << "Novo ano de publicação (ou 0 para manter): ";
        cin >> novoAno;
        if (novoAno != 0)
            livro->setAnoPublicacao(novoAno);

        cout << "Livro editado com sucesso!" << endl;
        livro->mostrarInfo();
    }
    else
    {
        cout << "Livro não encontrado." << endl;
    }
}

void Biblioteca::Listagem_Livros() const
{
    for (const auto &par : Coleccao_LIVROS)
    {
        cout << "Categoria: " << par.first << endl;
        for (const auto *livro : par.second)
        {
            livro->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
}

void Biblioteca::Listagem_Livros_Por_Categoria(const string &categoria) const
{
    auto it = Coleccao_LIVROS.find(categoria);
    if (it != Coleccao_LIVROS.end())
    {
        cout << "Categoria: " << categoria << endl;
        for (const auto *livro : it->second)
        {
            livro->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
    else
    {
        cout << "Categoria não encontrada." << endl;
    }
}

vector<LivroCientifico *> Biblioteca::BuscarLivrosCientificos(const string &areaPesquisa) const
{
    vector<LivroCientifico *> resultado;
    auto it = Coleccao_LIVROS.find("LivroCientifico");
    if (it != Coleccao_LIVROS.end())
    {
        for (auto *livro : it->second)
        {
            LivroCientifico *livroCientifico = dynamic_cast<LivroCientifico *>(livro);
            if (livroCientifico && (areaPesquisa.empty() || livroCientifico->getAreaPesquisa() == areaPesquisa))
            {
                resultado.push_back(livroCientifico);
            }
        }
    }
    return resultado;
}

vector<LivroFiccao *> Biblioteca::BuscarLivrosFiccao(const string &genero) const
{
    vector<LivroFiccao *> resultado;
    auto it = Coleccao_LIVROS.find("LivroFiccao");
    if (it != Coleccao_LIVROS.end())
    {
        for (auto *livro : it->second)
        {
            LivroFiccao *livroFiccao = dynamic_cast<LivroFiccao *>(livro);
            if (livroFiccao && (genero.empty() || livroFiccao->getGenero() == genero))
            {
                resultado.push_back(livroFiccao);
            }
        }
    }
    return resultado;
}

vector<LivroEducativo *> Biblioteca::BuscarLivrosEducativos(const string &grauEscolaridade) const
{
    vector<LivroEducativo *> resultado;
    auto it = Coleccao_LIVROS.find("LivroEducativo");
    if (it != Coleccao_LIVROS.end())
    {
        for (auto *livro : it->second)
        {
            LivroEducativo *livroEducativo = dynamic_cast<LivroEducativo *>(livro);
            if (livroEducativo && (grauEscolaridade.empty() || livroEducativo->getGrauEscolaridade() == grauEscolaridade))
            {
                resultado.push_back(livroEducativo);
            }
        }
    }
    return resultado;
}

vector<Revista *> Biblioteca::BuscarRevistas(int numeroEdicao) const
{
    vector<Revista *> resultado;
    auto it = Coleccao_LIVROS.find("Revista");
    if (it != Coleccao_LIVROS.end())
    {
        for (auto *livro : it->second)
        {
            Revista *revista = dynamic_cast<Revista *>(livro);
            if (revista && (numeroEdicao == -1 || revista->getNumeroEdicao() == numeroEdicao))
            {
                resultado.push_back(revista);
            }
        }
    }
    return resultado;
}

vector<Jornal *> Biblioteca::BuscarJornais(const string &dataPublicacao) const
{
    vector<Jornal *> resultado;
    auto it = Coleccao_LIVROS.find("Jornal");
    if (it != Coleccao_LIVROS.end())
    {
        for (auto *livro : it->second)
        {
            Jornal *jornal = dynamic_cast<Jornal *>(livro);
            if (jornal && (dataPublicacao.empty() || jornal->getDataPublicacao() == dataPublicacao))
            {
                resultado.push_back(jornal);
            }
        }
    }
    return resultado;
}

bool Biblioteca::Add_Leitor(Pessoa *P)
{
    if (P == nullptr)
    {
        cout << "Erro: Tentativa de adicionar uma Pessoa nula!" << endl;
        return false;
    };
    string categoria = P->getCategoria();
    Coleccao_LEITORES[categoria].push_back(P);
    cout << P->getNome() << " adicionado com sucesso!" << endl;
    return true;
}

void Biblioteca::registarLeitor()
{
    int tipo, id, temp2;
    string nome, temp;
    Data nascData;
    Data regData;

    // Apresenta as opções de tipo de livro
    cout << "Selecione o tipo de livro para adicionar:" << endl;
    cout << "1. Estudante" << endl;
    cout << "2. Leitor Comum" << endl;
    cout << "3. Professor" << endl;
    cout << "4. Senior" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(); // Limpa o buffer do teclado

    // Coleta informações comuns a todos os livros
    cout << "Digite o Nome: ";
    getline(cin, nome);
    while(!nascData.eValida()){
        cout << "Digite a sua data de nascimento: ";
        nascData = nascData.lerData();
        if(!nascData.eValida()){
            cout << "Data inválida!" << endl;
        }
    }


    cin.ignore(); // Limpa o buffer

    id = gerarID_leitor();

    regData = regData.dataAtual();

    Pessoa *novaPessoa = nullptr;

    switch (tipo)
    {
    case 1:
        cout << "Digite o curso: ";
        getline(cin, temp);
        novaPessoa = new Estudante(nome, nascData, id, regData, temp);
        break;
    case 2:
        novaPessoa = new LeitorComum(nome, nascData, id, regData);
        break;
    case 3:
        cout << "Digite a área: ";
        getline(cin, temp);
        novaPessoa = new Professor(nome, nascData, id, regData, temp);
        break;
    case 4:
        cout << "Digite o desconto em percentagem: ";
        cin >> temp2;
        novaPessoa = new Senior(nome, nascData, id, regData, temp2);
        break;
    default:
        cout << "Opção inválida!" << endl;
        return;
    }
    if (novaPessoa != nullptr)
    {
        Add_Leitor(novaPessoa);
        cout << "Leitor registrado com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao registrar leitor!" << endl;
    }
}

bool Biblioteca::Remove_Leitor(int id)
{
    for (auto &par : Coleccao_LEITORES)
    {
        auto &lista = par.second;
        auto it = find_if(lista.begin(), lista.end(), [id](const Pessoa *pessoa)
                          { return pessoa->getId() == id; });
        if (it != lista.end())
        {
            delete *it;
            lista.erase(it);
            return true;
        }
    }
    return false;
}

Pessoa *Biblioteca::Buscar_Leitor(int id) const
{
    for (const auto &par : Coleccao_LEITORES)
    {
        for (const auto *pessoa : par.second)
        {
            if (pessoa->getId() == id)
            {
                return const_cast<Pessoa *>(pessoa);
            }
        }
    }
    return nullptr;
}

void Biblioteca::Editar_Leitor(int id)
{
    Pessoa *pessoa = Buscar_Leitor(id);
    if (pessoa)
    {
        string novoNome;
        Data novaData;

        cout << "Novo Nome (ou Enter para manter): ";
        getline(cin, novoNome);
        if (!novoNome.empty())
            pessoa->setNome(novoNome);

        cout << "Nova Data (ou 0 para manter): ";
        novaData.lerData();
        if (novaData.eValida()) {
        pessoa->setNasc(novaData);
        }

        cout << "Pessoa editada com sucesso!" << endl;
    }
    else
    {
        cout << "Pessoa não encontrada." << endl;
    }
}

void Biblioteca::Listagem_Leitores() const
{
    for (const auto &par : Coleccao_LEITORES)
    {
        cout << "Categoria: " << par.first << endl;
        for (const auto *pessoa : par.second)
        {
            pessoa->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
    cout<< "digite enter para continuar";
    cin.ignore();

}

int Biblioteca::gerarID_leitor()
{
    int id = 0;
    for(auto &par : Coleccao_LEITORES){
        for(auto &pessoa : par.second){
            if(pessoa->getId() == id){
                id++;
            }
        }
    }
    return id;

}

bool Biblioteca::SaveToFile_Leitores(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return false;
    }

    for(const auto &par : Coleccao_LEITORES){
        for(const Pessoa *leitor : par.second){
            file << leitor->getId() << ";"
                 << leitor->getCategoria() << ";"
                 << leitor->getNome() << ";"
                 << leitor->getnascData().paraString() << ";"
                 << leitor->getregData().paraString() << ";";

            if(leitor->getCategoria() == "Estudante"){
                const Estudante *estudante = dynamic_cast<const Estudante *>(leitor);
                file << estudante->getCurso();
            } else if(leitor->getCategoria() == "Professor"){
                const Professor *professor = dynamic_cast<const Professor *>(leitor);
                file << professor->getArea();
            } else if(leitor->getCategoria() == "Senior"){
                const Senior *senior = dynamic_cast<const Senior *>(leitor);
                file << senior->getDesconto();
            }

            file << endl;
        }
    }
    return true;
}

bool Biblioteca::LoadFile_Leitores(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return false;
    }

    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string categoria, nome, nascDataStr, idStr, regDataStr, atributoEspecifico;
        int id;
        getline(ss, idStr, ';');
        id = stoi(idStr);
        getline(ss, categoria, ';');
        getline(ss, nome, ';');
        getline(ss, nascDataStr, ';');
        getline(ss, regDataStr, ';');
        getline(ss, atributoEspecifico, ';');

        Data nascData = nascData.lerString(nascDataStr);
        Data regData = regData.lerString(regDataStr);

        Pessoa *leitor = nullptr;

        if (categoria == "LeitorComum")
        {
            leitor = new LeitorComum(nome, nascData, id, regData);
        }
        else if (categoria == "Estudante")
        {
            leitor = new Estudante(nome, nascData, id, regData, atributoEspecifico);
        }
        else if (categoria == "Professor")
        {
            leitor = new Professor(nome, nascData, id, regData, atributoEspecifico);
        }
        else if (categoria == "Senior")
        {
            leitor = new Senior(nome, nascData, id, regData, stoi(atributoEspecifico));
        }

        if (leitor && nascData.eValida() && regData.eValida())
        {
            Add_Leitor(leitor);
        } else {
            cout << "Erro ao carregar leitor (erro de formato da data) " << nome << endl;
        }
    }
    return true;
}
