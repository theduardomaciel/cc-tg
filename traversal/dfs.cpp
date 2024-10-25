#include <stack>
#include <iostream>

#include "traversal/dfs.h"

void dfs_recursion(Graph &g, int v, const vector<vector<int>> &adj, stack<int> *Stack)
{
    g.pre[v] = g.counter++;

    if (Stack == nullptr)
    {
        cout << v << " "; // Exibe o vértice sendo visitado (para depuração ou visualização)
    }

    for (int w : adj[v])
    {
        if (g.pre[w] == -1)
        {
            dfs_recursion(g, w, adj, Stack);
        }
    }

    g.post[v] = g.counter++;

    // Se estamos preenchendo a pilha, empilhamos após a finalização do vértice
    if (Stack != nullptr)
    {
        Stack->push(v);
    }
}

// Função DFS principal usando dfs_recursion
void dfs(Graph &g, const vector<vector<int>> &adj, stack<int> *Stack)
{
    for (int i = 1; i < g.get_vertices_amount(); i++)
    {
        if (g.pre[i] == -1)
        {
            dfs_recursion(g, i, adj, Stack);
        }
    }
}