#include <vector>
#include <iostream>

#include "graph.h"

using namespace std;

void dfsRecursive(Graph &g, int v)
{
    g.pre[v] = g.counter++;

    // adj = vetor de vetores | adj[v] = vetor de adjacência do vértice v
    for (int w : g.adj[v])
    {
        if (g.pre[w] == -1)
        {
            dfsRecursive(g, w);
        }
    }
    // ou for(int i = 0; i < adj[v].size(); i++) { int w = adj[v][i]; }
}

// O & é uma referência, ou seja, é um ponteiro que não precisa ser desreferenciado
// É um ponteiro mais elegante (não precisa passar o operador ->)
void dfs(Graph &g)
{
    int n = g.adj.size();
    for (int v = 0; v < n; v++)
    {
        if (g.pre[v] == -1)
            dfsRecursive(g, v);
    }
}

int main()
{
    // No Windows, é necessário definir a codificação para UTF-8
    setlocale(LC_ALL, ".utf8");

    int n, m;
    cin >> n >> m; // Na primeira linha, lê a quantidade de vértices e arestas
    cout << "Quantidade de vértices: " << n << endl;
    cout << "Quantidade de arestas: " << m << endl;

    Graph g(n);

    int v, w;
    for (int c = 0; c < m; c++)
    {
        cin >> v >> w; // Lê as arestas dispostas nas linhas do arquivo de entrada no formato v w
        g.addEdge(v, w);
    }

    dfs(g);

    for (int v = 0; v < n; v++)
    {
        cout << "pre[" << v << "] = " << g.pre[v] << " | ";
    }

    cout << endl;

    return 0;
}
