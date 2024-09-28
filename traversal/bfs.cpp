#include <vector>
#include <queue>
#include <iostream>

#include "graph.h"

using namespace std;

int counter = 0;

void bfs(Graph &g, int v0)
{
    queue<int> q;
    q.push(v0);

    g.pre[v0] = counter++;

    while (!q.empty())
    {
        int v = q.front(); // v é o vértice que está na frente da fila
        q.pop();           // Remove o vértice da frente da fila

        for (size_t i = 0; i < g.adj[v].size(); i++)
        {
            int w = g.adj[v][i]; // w é o vértice adjacente a v
            if (g.pre[w] == -1)
            { // Verifica se o vértice w já foi visitado
                g.pre[w] = counter++;
                q.push(w);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "Quantidade de vértices: " << n << endl;
    cout << "Quantidade de arestas: " << m << endl;

    Graph g(n);

    int v, w;
    for (int c = 0; c < m; c++)
    {
        cin >> v >> w; // Lê as arestas no formato v w pelo teclado
        g.addEdge(v, w);
    }

    bfs(g, 0);

    for (int v = 0; v < n; v++)
    {
        cout << "pre[" << v << "] = " << g.pre[v] << " | ";
    }

    cout << endl;

    return 0;
}