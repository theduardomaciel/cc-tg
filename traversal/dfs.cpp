#include "dfs.h"

void dfs_recursive(Graph &g, int v)
{
    g.pre[v] = g.counter++; // Marca o vértice v como visitado e atribui a pré-ordem

    for (int w : g.adj[v]) // Para cada vértice w vizinho a v
    {
        if (g.pre[w] == -1)
        {
            g.parent[w] = v;
            dfs_recursive(g, w);
        }
        /* else if (w != g.parent[v])
        {
            cout << "Ciclo encontrado -> " << "Aresta de retorno: " << v << " -> " << w << endl;
        } */
    }

    g.post[v] = g.counter++; // Atribui a pós-ordem
}

// O & é uma referência, ou seja, é um ponteiro que não precisa ser desreferenciado
// É um ponteiro mais elegante (não precisa passar o operador ->)
int dfs(Graph &g)
{
    int connected_components = 0; // Armazena a quantidade de componentes conexas
    int n = g.adj.size();

    for (int v = 0; v < n; v++)
    {
        if (g.pre[v] == -1)
        {
            connected_components++;
            dfs_recursive(g, v);
        }
    }

    return connected_components;
}