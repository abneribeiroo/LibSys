

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
[] - Atribuir o ID a toos os tipos de Leitores
[] - Colocar o ID no ficheiro dos arquivos
[] - Criar o arquivo para peessos e requisições
[] - E fazer as funções para criar requisições e gerir requisições
