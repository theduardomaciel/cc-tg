# Makefile para Kruskal

# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Diretórios
PROJECT_ROOT = ../
UTILS_DIR = $(PROJECT_ROOT)utils

# Inclui os diretórios de cabeçalhos se necessário
INCLUDES = -I$(PROJECT_ROOT)

# Arquivos Fonte
SOURCES = kruskal.cpp $(wildcard $(UTILS_DIR)/*.cpp) ./source/union_find.cpp

# Arquivo Executável
EXEC = kruskal.bin

# Regras de Compilação
all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(EXEC) -g

# Limpeza
clean:
	rm -f $(EXEC)

# Execução
run: $(EXEC)
	./$(EXEC)

# Help
help:
	@echo "Uso:"
	@echo "  make        - Compila o programa"
	@echo "  make clean  - Remove arquivos objeto e o executável"
	@echo "  make run    - Compila e executa o programa"
