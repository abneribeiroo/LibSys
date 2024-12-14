#include "../include/Biblioteca.h"
#include "../include/Uteis.h"
#include "../include/Data.h"
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
//ola
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

bool Biblioteca::SaveToFile_Livros(const string &filename)
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
                 << livro->getDataPublicacao() << ";";

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
                file << j->getEditor();
            }

            file << endl;
        }
    }

    file.close();
    cout << "Dados salvos com sucesso no arquivo " << filename << endl;
    return true;
}

bool Biblioteca::LoadFile_Livros(const string &filename)
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

        string categoria, titulo, autor, dataStr, atributoEspecifico, editor;
        int id;
        Data dataPublicacao;

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
        getline(ss, dataStr, ';');
        getline(ss, atributoEspecifico, ';');

        dataPublicacao = dataPublicacao.lerString(dataStr);

        Geral *livro = nullptr;

        if (categoria == "LivroCientifico")
        {
            livro = new LivroCientifico(id, titulo, autor, dataPublicacao, atributoEspecifico);
        }
        else if (categoria == "LivroFiccao")
        {
            livro = new LivroFiccao(id, titulo, autor, dataPublicacao, atributoEspecifico);
        }
        else if (categoria == "LivroEducativo")
        {
            livro = new LivroEducativo(id, titulo, autor, dataPublicacao, atributoEspecifico);
        }
        else if (categoria == "Revista")
        {
            livro = new Revista(id, titulo, autor, dataPublicacao, stoi(atributoEspecifico));
        }
        else if (categoria == "Jornal")
        {

            livro = new Jornal(id, titulo, autor, dataPublicacao, atributoEspecifico);
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

void Biblioteca::getCommonBookInfo(string &titulo, string &autor, Data &dataPublicacao)
{
    cout << "Digite o título: ";
    getline(cin >> ws, titulo);
    cout << "Digite o autor: ";
    getline(cin >> ws, autor);
    while (!dataPublicacao.eValida())
    {
        cout << "Digite o data de publicação: ";
        dataPublicacao = dataPublicacao.lerData();
        if (!dataPublicacao.eValida())
        {
            cout << "Data Invalida!";
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Biblioteca::registrarNovoLivro()
{
    int tipo;
    string titulo, autor, areaPesquisa, editor, grauEscolaridade;
    int numeroEdicao;
    Data dataPublicacao;

    cout << "Selecione a categoria que deseja listar:" << endl;
    cout << "1. Livro Científico" << endl;
    cout << "2. Livro de Ficção" << endl;
    cout << "3. Livro Educativo" << endl;
    cout << "4. Revista" << endl;
    cout << "5. Jornal" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getCommonBookInfo(titulo, autor, dataPublicacao);

    int id = getNextId();
    cout << "ID do livro: " << id << endl;
    Geral *novoLivro = nullptr;

    switch (tipo)
    {
    case 1: // Livro Científico
        cout << "Digite a área de pesquisa: ";
        getline(cin >> ws, areaPesquisa);
        novoLivro = new LivroCientifico(id, titulo, autor, dataPublicacao, areaPesquisa);
        break;
    case 2: // Livro de Ficção
        cout << "Digite o gênero: ";
        getline(cin >> ws, areaPesquisa);
        novoLivro = new LivroFiccao(id, titulo, autor, dataPublicacao, areaPesquisa);
        break;
    case 3: // Livro Educativo
        cout << "Digite o grau de escolaridade: ";
        getline(cin >> ws, grauEscolaridade);
        novoLivro = new LivroEducativo(id, titulo, autor, dataPublicacao, grauEscolaridade);
        break;
    case 4: // Revista
        cout << "Digite o número da edição: ";
        cin >> numeroEdicao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        novoLivro = new Revista(id, titulo, autor, dataPublicacao, numeroEdicao);
        break;
    case 5: // Jornal
        cout << "Digite o editor: ";
        getline(cin >> ws, editor);
        novoLivro = new Jornal(id, titulo, autor, dataPublicacao, editor);
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
        Biblioteca::ListarLivros_Por_Categoria(categoriaLivro);
        break;
    case 2:
        categoria = new LivroFiccao();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::ListarLivros_Por_Categoria(categoriaLivro);
        break;
    case 3:
        categoria = new LivroEducativo();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::ListarLivros_Por_Categoria(categoriaLivro);
        break;
    case 4:
        categoria = new Revista();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::ListarLivros_Por_Categoria(categoriaLivro);
        break;
    case 5:
        categoria = new Jornal();
        categoriaLivro = categoria->getCategoria();
        Biblioteca::ListarLivros_Por_Categoria(categoriaLivro);
        break;
    }
}

void Biblioteca::Editar_Livro(const string &id)
{
    Geral *livro = Buscar_Livro(id);
    if (livro)
    {
        string novoTitulo, novoAutor;
        Data novaData;

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

        cout << livro->getDataPublicacao() << endl;
        cout << "Nova data de publicação (ou 0 para manter): ";
        novaData = novaData.lerData();
        if (novaData.eValida())
            livro->setDataPublicacao(novaData);

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

void Biblioteca::ListarLivros_Por_Categoria(const string &categoria) const
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

bool Biblioteca::Add_Leitor(Pessoa *P)
{
    if (P == nullptr)
    {
        cout << "Erro: Tentativa de adicionar uma Pessoa nula!" << endl;
        return false;
    };
    string categoria = P->getCategoria();
    Coleccao_LEITORES[categoria].push_back(P);
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
    while (!nascData.eValida())
    {
        cout << "Digite a sua data de nascimento: ";
        nascData = nascData.lerData();
        if (!nascData.eValida())
        {
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
        for (auto it = lista.begin(); it != lista.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                delete *it;
                lista.erase(it);
                return true;
            }
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

void Biblioteca::Editar_Leitor(int id) const
{
    Pessoa *pessoa = Buscar_Leitor(id);
    if (pessoa)
    {
        string novoNome, tmpData;
        Data novaData;

        cout << "Novo Nome (ou Enter para manter): ";
        cin.ignore();
        getline(cin, novoNome);
        if (!novoNome.empty())
            pessoa->setNome(novoNome);

        cout << "Nova Data (ou 0 para manter): ";

        novaData = novaData.lerData();

        if (novaData.eValida())
        {
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
    cout << "digite enter para continuar";
    cin.ignore();
}

void Biblioteca::Buscarleitor_por_categoria() const
{
    int tipo;
    cout << "Selecione o tipo de leitor que deseja listar:" << endl;
    cout << "1. Estudante" << endl;
    cout << "2. Leitor Comum" << endl;
    cout << "3. Professor" << endl;
    cout << "4. Senior" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string categoria;
    switch (tipo)
    {
    case 1:
        categoria = "Estudante";
        break;
    case 2:
        categoria = "LeitorComum";
        break;
    case 3:
        categoria = "Professor";
        break;
    case 4:
        categoria = "Senior";
        break;
    }
    auto it = Coleccao_LEITORES.find(categoria);
    if (it != Coleccao_LEITORES.end())
    {
        cout << "Categoria: " << categoria << endl;
        for (const auto *pessoa : it->second)
        {
            pessoa->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
    else
    {
        cout << "Categoria não encontrada." << endl;
    }
}

int Biblioteca::gerarID_leitor()
{
    int id = 0;
    for (auto &par : Coleccao_LEITORES)
    {
        for (auto &pessoa : par.second)
        {
            if (pessoa->getId() == id)
            {
                id++;
            }
        }
    }
    return id;
}

bool Biblioteca::SaveToFile_Livros_Leitores(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return false;
    }

    for (const auto &par : Coleccao_LEITORES)
    {
        for (const Pessoa *leitor : par.second)
        {
            file << leitor->getId() << ";"
                 << leitor->getCategoria() << ";"
                 << leitor->getNome() << ";"
                 << leitor->getnascData().paraString() << ";"
                 << leitor->getregData().paraString() << ";";

            if (leitor->getCategoria() == "Estudante")
            {
                const Estudante *estudante = dynamic_cast<const Estudante *>(leitor);
                file << estudante->getCurso();
            }
            else if (leitor->getCategoria() == "Professor")
            {
                const Professor *professor = dynamic_cast<const Professor *>(leitor);
                file << professor->getArea();
            }
            else if (leitor->getCategoria() == "Senior")
            {
                const Senior *senior = dynamic_cast<const Senior *>(leitor);
                file << senior->getDesconto();
            }

            file << endl;
        }
    }
    return true;
}

bool Biblioteca::LoadFile_Livros_Leitores(const string &filename)
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
        }
        else
        {
            cout << "Erro ao carregar leitor (erro de formato da data) " << nome << endl;
        }
    }
    cout << "Dados carregados com sucesso do arquivo " << filename << endl;
    return true;
}

bool Biblioteca::realizarEmprestimo(Geral *livro, Pessoa *leitor)
{
    if (!livro->estaDisponivel())
    {
        cout << "Livro não está disponível para empréstimo." << endl;
        return false;
    }

    // Verificar se o leitor já atingiu o limite de empréstimos
    int limiteEmprestimos = 3; // Padrão para LeitorComum
    if (leitor->getCategoria() == "Estudante" || leitor->getCategoria() == "Professor")
    {
        limiteEmprestimos = 5;
    }

    int emprestimosAtuais = 0;

    for (const auto &[_, emprestimosDoTipo] : Coleccao_Emprestimo)
    {
        for (const auto &e : emprestimosDoTipo)
        {
            if (e->getLeitor() == leitor && !e->estaDevolvido())
            {
                emprestimosAtuais++;
            }
        }
        if (emprestimosAtuais >= limiteEmprestimos)
        {
            cout << "Leitor já atingiu o limite de empréstimos." << endl;
            return false;
        }
    }
    int id = 0;

    // Criar novo empréstimo e adicioná-lo ao map
    Emprestimo *novoEmprestimo = new Emprestimo(id, livro, leitor);
    novoEmprestimo->setDevolvido(false);
    livro->setDisponibilidade(0);
    Data novaData;
    novaData = novaData.dataAtual();
    novoEmprestimo->setDataEmprestimo(novaData);
    novoEmprestimo->calcularDataLimite();

    string categoria = livro->getCategoria();
    Coleccao_Emprestimo[categoria].push_back(novoEmprestimo);

    livro->setDisponibilidade(false);
    cout << "Empréstimo realizado com sucesso." << endl;
    return true;
}

bool Biblioteca::LoadFile_Emprestimos(const string &filename)
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
        string categoria, livroIdStr, leitorIdStr, dataEmprestimoStr, dataDevolucaoStr, devolvidoStr, multaStr;
        int livroId, leitorId;
        bool devolvido;


        getline(ss, categoria, ';');
        getline(ss, livroIdStr, ';');
        getline(ss, leitorIdStr, ';');
        getline(ss, dataEmprestimoStr, ';');
        getline(ss, dataDevolucaoStr, ';');
        getline(ss, devolvidoStr, ';');
        getline(ss, multaStr, ';');

        livroId = stoi(livroIdStr);
        leitorId = stoi(leitorIdStr);
        devolvido = devolvidoStr == "1";


        Geral *livro = Buscar_Livro(to_string(livroId));
        Pessoa *leitor = Buscar_Leitor(leitorId);

        if (livro && leitor)
        {
            Emprestimo *emprestimo = new Emprestimo(getNextId(), livro, leitor);
            emprestimo->setDataEmprestimo(Data().lerString(dataEmprestimoStr));
            emprestimo->setDataDevolucao(Data().lerString(dataDevolucaoStr));
            emprestimo->setDevolvido(devolvido);
            emprestimo->calcularDataLimite();

            Coleccao_Emprestimo[categoria].push_back(emprestimo);
        }
        else
        {
            return false;
        }
    }
    cout << "Dados carregados com sucesso do arquivo " << filename << endl;

    return true;
}

void Biblioteca::ListarEmprestimos()
{
    for (const auto &par : Coleccao_Emprestimo)
    {
        cout << "Categoria: " << par.first << endl;
        for (const auto &emprestimo : par.second)
        {
            emprestimo->mostrarInfo();
            cout << "--------------------" << endl;
        }
    }
}


bool Biblioteca::salvarEmprestimos(const string &filename) const
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return false;
    }

    for (const auto &[categoria, emprestimos] : Coleccao_Emprestimo)
    {
        for (const auto &emprestimo : emprestimos)
        {

            file << emprestimo->getLivro()->getCategoria() << ";"
                 << emprestimo->getLivro()->getId() << ";"
                 << emprestimo->getLeitor()->getId() << ";"
                 << emprestimo->getDataEmprestimo() << ";"
                 << emprestimo->getDataDevolucao() << ";"
                 << emprestimo->estaDevolvido() << ";"
                 << emprestimo->getMulta().getValorFinal() << endl;
        }
    }

    file.close();
    cout << "Dados salvos com sucesso no arquivo " << filename << endl;
    return true;
}

int Biblioteca::subtrairData(Data d1, Data d2) {
    int dias = 0;

    int totalDiasD1 = d1.getAno() * 365 + d1.getMes() * 30 + d1.getDia();

    int totalDiasD2 = d2.getAno() * 365 + d2.getMes() * 30 + d2.getDia();

    dias = totalDiasD1 - totalDiasD2;

    return dias;
}

bool Biblioteca::compararDatas(const Data& data1, const Data& data2) {
    if (data1.getAno() > data2.getAno()) {
        return true;
    }
    else if (data1.getAno() == data2.getAno()) {
        if (data1.getMes() > data2.getMes()) {
            return true;
        }
        else if (data1.getMes() == data2.getMes()) {
            if (data1.getDia() > data2.getDia()) {
                return true;
            }
        }
    }
    return false;
}

bool Biblioteca::GerarMultas() {
    for (const auto &par : Coleccao_Emprestimo) {
        for (const auto &emprestimo : par.second) {
            if (!Data().lerString(emprestimo->getDataDevolucao()).eValida()) {
                int diasAtraso = subtrairData(Data().dataAtual(), Data().lerString(emprestimo->getDataLimite()));
                Multa multa;
                multa = multa.calcularMulta(diasAtraso, 0.5, (emprestimo->getLeitor()->getDesconto())*0.01);
                emprestimo->setMulta(multa);
                }else{
                int diasAtraso = subtrairData(Data().lerString(emprestimo->getDataDevolucao()), Data().lerString(emprestimo->getDataLimite()));
                Multa multa;
                multa = multa.calcularMulta(diasAtraso, 0.5, (emprestimo->getLeitor()->getDesconto())*0.01);
                emprestimo->setMulta(multa);
                }
        }
    }
    return true;
}

bool Biblioteca::DevolverLivro(int id) {
    for (auto &par : Coleccao_Emprestimo) {
        for (auto &emprestimo : par.second) {
            if (emprestimo->getId() == id) {
                emprestimo->realizarDevolucao();
                return true;
            }
        }
    }
    return false;
}

void Biblioteca::Listar_Leitores_Atraso(){
    for (const auto &par : Coleccao_Emprestimo) {
        for (const auto &emprestimo : par.second) {
            if (!Data().lerString(emprestimo->getDataDevolucao()).eValida()) {
                int diasAtraso = subtrairData(Data().dataAtual(), Data().lerString(emprestimo->getDataLimite()));
                if (diasAtraso > 0) {
                    emprestimo->getLeitor()->mostrarInfo();
                    cout << "Dias de atraso: " << diasAtraso << endl;
                }
            }
    }
}
}

void Biblioteca::Prorrogacao_Emprestimos(){
    int id;
    cout << "Digite o ID do empréstimo que deseja prorrogar: ";
    cin >> id;
    for (auto &par : Coleccao_Emprestimo) {
        for (auto &emprestimo : par.second) {
            if (emprestimo->getId() == id) {
                emprestimo->prorrogarEmprestimo();
                return;
            }
        }
    }
}

void Biblioteca::Listagem_Emprestimo_leitor(){
    int id;
    cout << "Digite o ID do leitor: ";
    cin >> id;

    for (const auto &par : Coleccao_Emprestimo) {
        for (const auto &emprestimo : par.second) {
            if (emprestimo->getLeitor()->getId() == id) {
                emprestimo->mostrarInfo();
                cout << "--------------------" << endl;
            }
        }
    }
}

void Biblioteca::Listagem_Multas_Pendentes(){
    for (const auto &par : Coleccao_Emprestimo) {
        for (const auto &emprestimo : par.second) {
            if (emprestimo->getMulta().getPago() == false) {
                emprestimo->mostrarInfo();
                cout << "--------------------" << endl;
            }
        }
    }
}

void Biblioteca::Pagar_Multa(){
    int id = 0;
    cout << "Digite o ID da Requisição que deseja pagar: ";
    cin >> id;
    for (auto &par : Coleccao_Emprestimo) {
        for (auto &emprestimo : par.second) {
            if (emprestimo->getId() == id && emprestimo->getDevolvido() == true) {
                emprestimo->getMulta().setPago(true);
                return;
            }
        }
    }
}
