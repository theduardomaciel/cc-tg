# Makefile para Kosaraju

# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Diretórios
PROJECT_ROOT = ../
INCLUDES = -I$(PROJECT_ROOT)

# Arquivos Fonte
SOURCES = kosaraju.cpp

# Arquivo Executável
EXEC = kosaraju.out

# Regras de Compilação
all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(EXEC)

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
