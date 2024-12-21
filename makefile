# Variáveis
CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
SRC = src/Library.cpp src/General.cpp src/CommonReader.cpp src/Newspaper.cpp src/Magazine.cpp src/ScientificBook.cpp src/EducationalBook.cpp src/FictionBook.cpp src/Person.cpp src/Student.cpp src/Senior.cpp src/menu.cpp src/Teacher.cpp src/Utils.cpp src/Date.cpp src/Loan.cpp src/Fine.cpp main.cpp
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
