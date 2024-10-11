#include "bfs.h"

void bfs(Graph &g, int v0)
{
    queue<int> q;
    q.push(v0);

    g.dist[v0] = 0;
    g.pre[v0] = g.counter++;

    while (!q.empty())
    {
        int v = q.front(); // 1o vértice da fila
        q.pop();           // Remove o vértice da fila

        for (size_t i = 0; i < g.adj[v].size(); i++) // Percorre os vizinhos ()vértices adjacentes) a v
        {
            int w = g.adj[v][i];
            if (g.pre[w] == -1)
            {
                g.pre[w] = g.counter++; // Numera o vértice w
                q.push(w);              // Adiciona w à fila

                g.dist[w] = g.dist[v] + 1; // Distância de w ao vértice inicial
                g.parent[w] = v;           // Vértice pai de w
            }
        }
    }
}