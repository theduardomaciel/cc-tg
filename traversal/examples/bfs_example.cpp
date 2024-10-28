#include "traversal/bfs.h"
#include "utils/input.h"

void print_path(Graph &g, int v)
{
    if (g.parent[v] == -1)
    {
        cout << v;
    }
    else
    {
        print_path(g, g.parent[v]);
        cout << " -> " << v;
    }
}

int main()
{
    // No Windows, é necessário definir a codificação para UTF-8
    setlocale(LC_ALL, ".utf8");

    Graph g = read_graph("graph.dat");

    bfs(g, 0);

    // Padrão: imprime a numeração dos vértices
    cout << "Numeração dos vértices:" << endl;
    for (int v = 0; v < g.size(); v++)
    {
        cout << "pre[" << v << "] = " << g.pre[v] << " | ";
    }

    cout << endl
         << endl;

    // Problema 1: Calcule a distância do vértice v0 para todos os outros vértices do grafo
    cout << "Distância do vértice 0 para todos os outros vértices:" << endl;
    for (int v = 0; v < g.size(); v++)
    {
        cout << "   dist[" << v << "] = " << g.dist[v] << endl;
    }

    cout << endl;

    // Problema 2: Obtenha o caminho mínimo de v0 para todos os outros vértices do grafo
    cout << "Caminho mínimo do vértice 0 para todos os outros vértices:" << endl;
    for (int v = 0; v < g.size(); v++)
    {
        cout << "   path[" << v << "] = ";
        print_path(g, v); // Imprime o caminho de v0 a v de forma reversa
        cout << endl;
    }

    return 0;
}