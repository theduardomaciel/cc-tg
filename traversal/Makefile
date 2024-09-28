# Variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++20

# Criação do diretório bin e compilação
bfs: bfs.cpp graph.h | bin
	$(CXX) $(CXXFLAGS) -o ../bin/bfs.bin bfs.cpp graph.h && ../bin/bfs.bin < graph.dat

dfs: dfs.cpp graph.h | bin
	$(CXX) $(CXXFLAGS) -o ../bin/dfs.bin dfs.cpp graph.h && ../bin/dfs.bin < graph.dat

# Criação do diretório bin, se não existir
bin:
	mkdir -p ../bin

# Limpeza dos arquivos gerados
clean:
	rm -rf ../bin
