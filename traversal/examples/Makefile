# Makefile para DFS e BFS

# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Diretórios
PROJECT_ROOT = ../../
UTILS_DIR = $(PROJECT_ROOT)utils

# Inclui os diretórios de cabeçalhos se necessário
INCLUDES = -I$(PROJECT_ROOT)

# Arquivos Fonte
DFS_SOURCES = dfs_example.cpp $(wildcard $(UTILS_DIR)/*.cpp) $(PROJECT_ROOT)traversal/dfs.cpp
BFS_SOURCES = bfs_example.cpp $(wildcard $(UTILS_DIR)/*.cpp) $(PROJECT_ROOT)traversal/bfs.cpp

# Arquivo Executável
DFS_EXEC = dfs.bin
BFS_EXEC = bfs.bin

# Regras de Compilação
all: dfs bfs

dfs: $(DFS_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(DFS_EXEC) $(DFS_SOURCES)

bfs: $(BFS_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BFS_EXEC) $(BFS_SOURCES)

# Limpeza
clean:
	rm -f $(DFS_EXEC) $(BFS_EXEC)

# Execução
run_dfs: dfs
	./$(DFS_EXEC)

run_bfs: bfs
	./$(BFS_EXEC)

# Help
help:
	@echo "Uso:"
	@echo "  make        - Compila o programa"
	@echo "  make clean  - Remove arquivos objeto e o executável"
	@echo "  make run    - Compila e executa o programa"
