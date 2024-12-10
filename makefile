# Variáveis
CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
SRC = src/Biblioteca.cpp src/Geral.cpp src/LeitorComum.cpp src/Jornal.cpp src/Revista.cpp src/LivroCientifico.cpp src/LivroEducativo.cpp src/LivroFiccao.cpp src/Pessoa.cpp src/Estudante.cpp src/Senior.cpp src/menu.cpp src/Professor.cpp src/Uteis.cpp src/Data.cpp main.cpp
OBJ = $(SRC:.cpp=.o)  # Lista de arquivos objeto

# Regra principal
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar os objetos
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para rodar o programa
run: all
	@./$(TARGET)

# Limpar arquivos gerados
clean:
	@rm -f $(OBJ) $(TARGET)
