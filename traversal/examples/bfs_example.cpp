#include <iostream>
#include "bfs.h"

using namespace std;

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

    int n, m;
    cin >> n >> m;
    cout << "Quantidade de vértices: " << n << endl;
    cout << "Quantidade de arestas: " << m << endl
         << endl;

    Graph g(n);

    int v, w;
    for (int c = 0; c < m; c++)
    {
        cin >> v >> w; // Lê as arestas no formato v w
        g.add_edge(v, w);
    }

    bfs(g, 0);

    // Padrão: imprime a numeração dos vértices
    cout << "Numeração dos vértices:" << endl;
    for (int v = 0; v < n; v++)
    {
        cout << "pre[" << v << "] = " << g.pre[v] << " | ";
    }

    cout << endl
         << endl;

    // Problema 1: Calcule a distância do vértice v0 para todos os outros vértices do grafo
    cout << "Distância do vértice 0 para todos os outros vértices:" << endl;
    for (int v = 0; v < n; v++)
    {
        cout << "   dist[" << v << "] = " << g.dist[v] << endl;
    }

    cout << endl;

    // Problema 2: Obtenha o caminho mínimo de v0 para todos os outros vértices do grafo
    cout << "Caminho mínimo do vértice 0 para todos os outros vértices:" << endl;
    for (int v = 0; v < n; v++)
    {
        cout << "   path[" << v << "] = ";
        print_path(g, v); // Imprime o caminho de v0 a v de forma reversa
        cout << endl;
    }

    return 0;
}