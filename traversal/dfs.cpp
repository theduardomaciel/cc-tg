#include <stack>
#include "traversal/dfs.h"

void dfs_general(Graph &g, int v, vector<bool> &visited, const vector<vector<int>> &adj, stack<int> *Stack)
{
    // Marca o vértice atual como visitado
    visited[v] = true;

    // Percorre todos os vizinhos do vértice v na lista de adjacência fornecida
    for (int w : adj[v])
    {
        if (!visited[w])
        {
            dfs_general(g, w, visited, adj, Stack);
        }
    }

    // Se for passado um ponteiro para a Stack, empilhamos o vértice após finalizar a DFS
    if (Stack != nullptr)
    {
        Stack->push(v);
    }
}

void dfs(Graph &g, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> *Stack)
{
    int n = g.vertices_amount();

    // Realiza a DFS em todos os vértices não visitados
    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
        {
            dfs_general(g, v, visited, adj, Stack);
        }
    }
}
