# Makefile para BFS e DFS

# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Diretórios
PROJECT_ROOT = ../
INCLUDES = -I$(PROJECT_ROOT)

# Arquivos Fonte
BFS_SRC = bfs.cpp
DFS_SRC = dfs.cpp

# Arquivo Executáveis
BFS_EXEC = bfs.out
DFS_EXEC = dfs.out

# Regras de Compilação
all: $(BFS_EXEC) $(DFS_EXEC)

$(BFS_EXEC): $(BFS_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(BFS_SRC) -o $(BFS_EXEC)

$(DFS_EXEC): $(DFS_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DFS_SRC) -o $(DFS_EXEC)

# Limpeza
clean:
	rm -f $(BFS_EXEC) $(DFS_EXEC)

# Execução
run_bfs: $(BFS_EXEC)
	./$(BFS_EXEC) < ../graph.dat

run_dfs: $(DFS_EXEC)
	./$(DFS_EXEC) < ../graph.dat

# Help
help:
	@echo "Uso:"
	@echo "  make        - Compila os programas BFS e DFS"
	@echo "  make clean  - Remove os executáveis"
	@echo "  make run_bfs - Compila e executa o programa BFS"
	@echo "  make run_dfs - Compila e executa o programa DFS"
