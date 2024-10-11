#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

#include "traversal/dfs.h" // Inclui o algoritmo de DFS

Graph read_graph(string filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    Graph g(n); // Inicializa o grafo com n vértices

    int v, w; // v = vértice de origem, w = vértice de destino
    for (int i = 0; i < m; i++)
    {
        file >> v >> w;
        g.addEdge(v, w);
    }

    file.close();

    return g;
}

void kosaraju(Graph &g)
{
}

int main(int argc, char *argv[])
{
    if (argc < 3 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo>" << endl;
        return 1;
    }

    string filename = argv[2];
    Graph g = read_graph(filename);

    kosaraju(g);

    return 0;
}
