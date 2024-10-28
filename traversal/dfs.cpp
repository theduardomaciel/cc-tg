#include "traversal/dfs.h"

void dfs_recursion(Graph &g, int v, const vector<vector<int>> &adj, const function<void(int)> &pre, const function<void(int)> &pos)
{
    // Executa a função pre, se definida
    if (pre)
        pre(v);

    g.pre[v] = g.counter++;

    for (int w : adj[v])
    {
        if (g.pre[w] == -1)
        {
            dfs_recursion(g, w, adj, pre, pos);
        }
    }

    g.post[v] = g.counter++;

    // Executa a função pos, se definida
    if (pos)
        pos(v);
}

// Função DFS principal usando dfs_recursion
void dfs(Graph &g, const vector<vector<int>> &adj, const function<void(int)> &pre, const function<void(int)> &pos)
{
    for (int i = 1; i < g.size(); i++)
    {
        if (g.pre[i] == -1)
        {
            dfs_recursion(g, i, adj, pre, pos);
        }
    }
}