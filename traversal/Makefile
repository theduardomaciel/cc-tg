# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Nomes dos executáveis
BFS_EXEC = bfs.out
DFS_EXEC = dfs.out

# Arquivos fonte
BFS_SRC = bfs.cpp
DFS_SRC = dfs.cpp

# Arquivos de cabeçalho
HEADERS = bfs.h dfs.h graph.h

# Regra padrão para compilar todos os executáveis
all: $(BFS_EXEC) $(DFS_EXEC)

# Regra pra compilar o BFS
$(BFS_EXEC): $(BFS_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(BFS_SRC) -o $(BFS_EXEC)

# Regra pra compilar o DFS
$(DFS_EXEC): $(DFS_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(DFS_SRC) -o $(DFS_EXEC)

# Regra pra rodar o BFS
run_bfs: $(BFS_EXEC)
	./$(BFS_EXEC) < ../graph.dat
#	$(MAKE) clean

# Regra pra rodar o DFS
run_dfs: $(DFS_EXEC)
	./$(DFS_EXEC) < ../graph.dat

# Regra de limpeza para remover os executáveis
clean:
	rm -f $(BFS_EXEC) $(DFS_EXEC)
