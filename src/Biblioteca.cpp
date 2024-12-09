#include "../include/Biblioteca.h"
#include "../include/Uteis.h"
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

bool Biblioteca::Add_Leitores()
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
    return true;
}

void Biblioteca::registarLeitor()
{
    int tipo;
    string nome;
    int id, idade;

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
    cout << "Digite a Idade: ";
    cin >> idade;
    cin.ignore(); // Limpa o buffer

    id = 10;

    Pessoa *novaPessoa = nullptr;

    switch (tipo)
    {
    case 1:
        novaPessoa = new Estudante(nome, idade, id);
        break;
    case 2:
        novaPessoa = new LeitorComum(nome, idade, id);
        break;
    case 3:
        novaPessoa = new Professor(nome, idade, id);
        break;
    case 4:
        novaPessoa = new Senior(nome, idade, id);
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
        int novaIdade;

        cout << "Novo Nome (ou Enter para manter): ";
        getline(cin, novoNome);
        if (!novoNome.empty())
            pessoa->setNome(novoNome);

        cout << "Nova Idade (ou 0 para manter): ";
        cin >> novaIdade;
        if (novaIdade != 0)
            pessoa->setIdade(novaIdade);

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
    Uteis::Pausar();
}

// bool Biblioteca::realizarEmprestimo(Geral *livro, Pessoa *leitor)
// {
//     if (!livro->estaDisponivel())
//     {
//         cout << "Livro não está disponível para empréstimo." << endl;
//         return false;
//     }

//     // Verificar se o leitor já atingiu o limite de empréstimos
//     int limiteEmprestimos = 3; // Padrão para LeitorComum
//     if (dynamic_cast<Estudante *>(leitor) || dynamic_cast<Professor *>(leitor))
//     {
//         limiteEmprestimos = 5;
//     }

//     int emprestimosAtuais = count_if(emprestimos.begin(), emprestimos.end(),
//                                      [leitor](const Emprestimo &e)
//                                      { return e.getLeitor() == leitor && !e.estaDevolvido(); });

//     if (emprestimosAtuais >= limiteEmprestimos)
//     {
//         cout << "Leitor já atingiu o limite de empréstimos." << endl;
//         return false;
//     }

//     emprestimos.emplace_back(livro, leitor);
//     livro->setDisponibilidade(false);
//     cout << "Empréstimo realizado com sucesso." << endl;
//     return true;
// }

// bool Biblioteca::realizarDevolucao(Geral *livro, Pessoa *leitor)
// {
//     auto it = find_if(emprestimos.begin(), emprestimos.end(),
//                       [livro, leitor](const Emprestimo &e)
//                       {
//                           return e.getLivro() == livro && e.getLeitor() == leitor && !e.estaDevolvido();
//                       });

//     if (it == emprestimos.end())
//     {
//         cout << "Empréstimo não encontrado." << endl;
//         return false;
//     }

//     it->realizarDevolucao();
//     double multa = it->getMulta();
//     if (multa > 0)
//     {
//         cout << "Multa a pagar: R$ " << multa << endl;
//     }

//     cout << "Devolução realizada com sucesso." << endl;
//     return true;
// }

// bool Biblioteca::fazerReserva(Geral *livro, Pessoa *leitor)
// {
//     if (livro->estaDisponivel())
//     {
//         cout << "O livro está disponível para empréstimo. Não é necessário fazer reserva." << endl;
//         return false;
//     }

//     auto &filaReserva = reservas[livro];

//     // Check if the reader is already in the queue
//     auto it = find_if(filaReserva._Get_container().begin(), filaReserva._Get_container().end(),
//                            [leitor](const Pessoa *p)
//                            { return p->getId() == leitor->getId(); });

//     if (it != filaReserva._Get_container().end())
//     {
//         cout << "Este leitor já tem uma reserva para este livro." << endl;
//         return false;
//     }

//     filaReserva.push(leitor);
//     cout << "Reserva realizada com sucesso para o livro: " << livro->getTitulo() << endl;
//     return true;
// }

// void Biblioteca::gerarRelatorioMultasPendentes() const
// {
//     map<string, double> multasPorTipo;

//     for (const auto &emprestimo : emprestimos)
//     {
//         if (emprestimo.estahAtrasado() && !emprestimo.estaDevolvido())
//         {
//             Pessoa *leitor = emprestimo.getLeitor();
//             double multa = emprestimo.calcularMulta();
//             string tipoLeitor = leitor->getCategoria();

//             multasPorTipo[tipoLeitor] += multa;

//             cout << "Leitor: " << leitor->getNome()
//                       << " (ID: " << leitor->getId() << ")"
//                       << ", Tipo: " << tipoLeitor
//                       << ", Livro: " << emprestimo.getLivro()->getTitulo()
//                       << ", Multa: R$ " << fixed << setprecision(2) << multa << endl;
//         }
//     }

//     cout << "\nResumo de multas por tipo de leitor:" << endl;
//     for (const auto &[tipo, total] : multasPorTipo)
//     {
//         cout << tipo << ": R$ " << fixed << setprecision(2) << total << endl;
//     }
// }

// bool Biblioteca::salvarDados(const string &filename) const
// {
//     // ... (previous code remains unchanged)

//     // Save readers
//     file << "LEITORES" << endl;
//     for (const auto &[categoria, leitores] : Coleccao_LEITORES)
//     {
//         for (const auto *leitor : leitores)
//         {
//             file << leitor->getId() << ";"
//                  << leitor->getCategoria() << ";"
//                  << leitor->getNome() << ";"
//                  << leitor->getIdade() << endl;
//         }
//     }

//     // ... (rest of the function remains unchanged)
// }

// bool Biblioteca::carregarDados(const string &filename)
// {
//     // ... (previous code remains unchanged)

//     else if (currentSection == "EMPRESTIMOS")
//     {
//         // ... (previous code remains unchanged)

//         if (livro && leitor)
//         {
//             Emprestimo emprestimo(livro, leitor);
//             emprestimo.setDataEmprestimo(dataEmprestimo);
//             emprestimo.setDataDevolucao(dataDevolucao);
//             emprestimo.setDevolvido(devolvido);
//             emprestimo.setMulta(multa);
//             emprestimos.push_back(emprestimo);
//         }
//     }
//     else if (currentSection == "RESERVAS")
//     {
//         vector<string> tokens;
//         while (getline(iss, token, ';'))
//         {
//             tokens.push_back(token);
//         }

//         if (tokens.size() < 2)
//             continue;

//         int livroId = stoi(tokens[0]);
//         Geral *livro = Buscar_Livro(to_string(livroId));

//         if (livro)
//         {
//             istringstream leitorIds(tokens[1]);
//             string leitorIdStr;
//             while (getline(leitorIds, leitorIdStr, ','))
//             {
//                 int leitorId = stoi(leitorIdStr);
//                 Pessoa *leitor = Buscar_Leitor(leitorId);
//                 if (leitor)
//                 {
//                     reservas[livro].push(leitor);
//                 }
//             }
//         }
//     }
// }

// file.close();
// cout << "Dados carregados com sucesso do arquivo " << filename << endl;
// return true;
// }
