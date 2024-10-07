# Makefile para Kosaraju

# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Diretórios
PROJECT_ROOT = ../
INCLUDES = -I$(PROJECT_ROOT)

# Arquivos Fonte
SOURCES = kosaraju.cpp

# Arquivos Objetos
OBJECTS = kosaraju.o

# Arquivo Executável
EXEC = kosaraju

# Regras de Compilação
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(EXEC) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJECTS) $(EXEC)

# Execução
run: $(EXEC)
	./$(EXEC)

# Help
help:
	@echo "Uso:"
	@echo "  make        - Compila o programa"
	@echo "  make clean  - Remove arquivos objeto e o executável"
	@echo "  make run    - Compila e executa o programa"
