# Variáveis
CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
SRC = main.cpp  src/Aquario.cpp src/Peixe.cpp

# Regra principal
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regra para rodar o programa
run: all
	./$(TARGET)

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)