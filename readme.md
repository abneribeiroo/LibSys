incluindo instruções sobre como instalar o `make` no Windows.

# Sistema de Gestão da Biblioteca

Este projeto é um sistema de gestão de biblioteca, escrito em C++. O `Makefile` fornecido facilita a compilação e execução do projeto.

## Requisitos

- `g++` (compilador C++)
- `make` (ferramenta de automação de compilação)

## Instruções de Uso

### Compilando o Projeto

Para compilar o projeto, você pode usar o seguinte comando no terminal:

```bash
make
```

Isso irá compilar todos os arquivos fonte e gerar o executável `main`.

### Executando o Programa

Após a compilação, você pode executar o programa com o comando:

```bash
make run
```

Isso irá rodar o executável `main` e você verá a saída do programa no terminal.

### Limpando os Arquivos Gerados

Para remover os arquivos objeto e o executável gerados durante o processo de compilação, utilize:

```bash
make clean
```

### Observações

- Certifique-se de que todos os arquivos fonte estão na estrutura de diretórios correta, especialmente os arquivos dentro da pasta `src`.
- O `Makefile` foi projetado para compilar e executar o programa sem mostrar os comandos de compilação no terminal, exibindo apenas a saída do programa.

## Instalando o `make` no Windows

Se você estiver usando Windows e não tiver o `make` instalado, siga as instruções abaixo:

### Opção 1: Instalar o `make` com o MSYS2

1. **Baixe o instalador do MSYS2**:

   - Acesse o [site oficial do MSYS2](https://www.msys2.org/) e siga as instruções para baixar e instalar.

2. **Abra o terminal MSYS2**:

   - Após a instalação, abra o terminal MSYS2.

3. **Atualize o sistema**:

   - Execute os seguintes comandos para atualizar os pacotes:
     ```bash
     pacman -Syu
     ```

4. **Instale o `make`**:

   - Depois de atualizar, instale o `make` com o seguinte comando:
     ```bash
     pacman -S make
     ```

5. **Instale o `g++`** (se ainda não estiver instalado):
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```

TODO

- [x] - Atribuir o ID a toos os tipos de Leitores
- [x] - Colocar o ID no ficheiro dos arquivos
- [ ] - Criar o arquivo para peessos e requisições
- [ ] - E fazer as funções para criar requisições e gerir requisições
- [ ] - Implementar um relatório que mostre os empréstimos categorizados por tipo de
    livro (livros ficcionais, científicos, etc.) e o tipo de leitor que mais os requisita.
- [ ] - Histórico de Empréstimos de Leitores: Cada tipo de leitor terá seu próprio histórico de empréstimos, e o sistema deve
    exibir o histórico de empréstimos de cada leitor, categorizando os livros por tipo.
- [ ] - Certificar que todas as funções e ficheiros estão libertanto a memória de forma correta

`c

// bool Biblioteca::realizarEmprestimo(Geral *livro, Pessoa *leitor)
// {
// if (!livro->estaDisponivel())
// {
// cout << "Livro não está disponível para empréstimo." << endl;
// return false;
// }

// // Verificar se o leitor já atingiu o limite de empréstimos
// int limiteEmprestimos = 3; // Padrão para LeitorComum
// if (dynamic_cast<Estudante _>(leitor) || dynamic_cast<Professor _>(leitor))
// {
// limiteEmprestimos = 5;
// }

// int emprestimosAtuais = count_if(emprestimos.begin(), emprestimos.end(),
// [leitor](const Emprestimo &e)
// { return e.getLeitor() == leitor && !e.estaDevolvido(); });

// if (emprestimosAtuais >= limiteEmprestimos)
// {
// cout << "Leitor já atingiu o limite de empréstimos." << endl;
// return false;
// }

// emprestimos.emplace_back(livro, leitor);
// livro->setDisponibilidade(false);
// cout << "Empréstimo realizado com sucesso." << endl;
// return true;
// }

// bool Biblioteca::realizarDevolucao(Geral *livro, Pessoa *leitor)
// {
// auto it = find_if(emprestimos.begin(), emprestimos.end(),
// [livro, leitor](const Emprestimo &e)
// {
// return e.getLivro() == livro && e.getLeitor() == leitor && !e.estaDevolvido();
// });

// if (it == emprestimos.end())
// {
// cout << "Empréstimo não encontrado." << endl;
// return false;
// }

// it->realizarDevolucao();
// double multa = it->getMulta();
// if (multa > 0)
// {
// cout << "Multa a pagar: R$ " << multa << endl;
// }

// cout << "Devolução realizada com sucesso." << endl;
// return true;
// }

// bool Biblioteca::fazerReserva(Geral *livro, Pessoa *leitor)
// {
// if (livro->estaDisponivel())
// {
// cout << "O livro está disponível para empréstimo. Não é necessário fazer reserva." << endl;
// return false;
// }

// auto &filaReserva = reservas[livro];

// // Check if the reader is already in the queue
// auto it = find_if(filaReserva.\_Get_container().begin(), filaReserva.\_Get_container().end(),
// [leitor](const Pessoa \*p)
// { return p->getId() == leitor->getId(); });

// if (it != filaReserva.\_Get_container().end())
// {
// cout << "Este leitor já tem uma reserva para este livro." << endl;
// return false;
// }

// filaReserva.push(leitor);
// cout << "Reserva realizada com sucesso para o livro: " << livro->getTitulo() << endl;
// return true;
// }

// void Biblioteca::gerarRelatorioMultasPendentes() const
// {
// map<string, double> multasPorTipo;

// for (const auto &emprestimo : emprestimos)
// {
// if (emprestimo.estahAtrasado() && !emprestimo.estaDevolvido())
// {
// Pessoa \*leitor = emprestimo.getLeitor();
// double multa = emprestimo.calcularMulta();
// string tipoLeitor = leitor->getCategoria();

// multasPorTipo[tipoLeitor] += multa;

// cout << "Leitor: " << leitor->getNome()
// << " (ID: " << leitor->getId() << ")"
// << ", Tipo: " << tipoLeitor
// << ", Livro: " << emprestimo.getLivro()->getTitulo()
// << ", Multa: R$ " << fixed << setprecision(2) << multa << endl;
// }
// }

// cout << "\nResumo de multas por tipo de leitor:" << endl;
// for (const auto &[tipo, total] : multasPorTipo)
// {
// cout << tipo << ": R$ " << fixed << setprecision(2) << total << endl;
// }
// }

// bool Biblioteca::salvarDados(const string &filename) const
// {
// // ... (previous code remains unchanged)

// // Save readers
// file << "LEITORES" << endl;
// for (const auto &[categoria, leitores] : Coleccao_LEITORES)
// {
// for (const auto \*leitor : leitores)
// {
// file << leitor->getId() << ";"
// << leitor->getCategoria() << ";"
// << leitor->getNome() << ";"
// << leitor->getIdade() << endl;
// }
// }

// // ... (rest of the function remains unchanged)
// }

// bool Biblioteca::carregarDados(const string &filename)
// {
// // ... (previous code remains unchanged)

// else if (currentSection == "EMPRESTIMOS")
// {
// // ... (previous code remains unchanged)

// if (livro && leitor)
// {
// Emprestimo emprestimo(livro, leitor);
// emprestimo.setDataEmprestimo(dataEmprestimo);
// emprestimo.setDataDevolucao(dataDevolucao);
// emprestimo.setDevolvido(devolvido);
// emprestimo.setMulta(multa);
// emprestimos.push_back(emprestimo);
// }
// }
// else if (currentSection == "RESERVAS")
// {
// vector<string> tokens;
// while (getline(iss, token, ';'))
// {
// tokens.push_back(token);
// }

// if (tokens.size() < 2)
// continue;

// int livroId = stoi(tokens[0]);
// Geral \*livro = Buscar_Livro(to_string(livroId));

// if (livro)
// {
// istringstream leitorIds(tokens[1]);
// string leitorIdStr;
// while (getline(leitorIds, leitorIdStr, ','))
// {
// int leitorId = stoi(leitorIdStr);
// Pessoa \*leitor = Buscar_Leitor(leitorId);
// if (leitor)
// {
// reservas[livro].push(leitor);
// }
// }
// }
// }
// }

// file.close();
// cout << "Dados carregados com sucesso do arquivo " << filename << endl;
// return true;
// }

`
