# Variáveis
CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
SRC = src/Biblioteca.cpp src/Geral.cpp src/LeitorComum.cpp src/LivroCientifico.cpp src/LivroFiccao.cpp src/Pessoa.cpp src/Professor.cpp src/Revista.cpp src/Uteis.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

# Regra principal
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar cada arquivo .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para rodar o programa
run: all
	./$(TARGET)

# Limpar arquivos gerados
clean:
	rm -f $(TARGET) $(OBJ)
