# Variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGETS = bin/bfs bin/dfs

# Regras principais
all: $(TARGETS)

# Criação do diretório bin e compilação
bfs: bfs.cpp | bin
	$(CXX) $(CXXFLAGS) -o ../bin/bfs.bin bfs.cpp && ../bin/bfs.bin < graph.dat

dfs: dfs.cpp | bin
	$(CXX) $(CXXFLAGS) -o ../bin/dfs.bin dfs.cpp && ../bin/dfs.bin < graph.dat

# Criação do diretório bin, se não existir
bin:
	mkdir -p ../bin

# Limpeza dos arquivos gerados
clean:
	rm -rf ../bin
