#include <queue>
#include "graph.h"

using namespace std;

/*
    DFS (Depth-First Search)

    * Parâmetros:
        - g: grafo

    * Estrutura de dados: Utiliza recursão para percorrer o grafo a partir do vértice v0

    * Pseudocódigo:
        - Para cada vértice v do grafo:
            - Se v não foi visitado:
                - Chama a função dfs_recursive(g, v)

        - Função dfs_recursive(g, v):
            - Marca o vértice v como visitado
            - Para cada vértice w adjacente a v:
                - Se w não foi visitado:
                    - Chama a função dfs_recursive(g, w)

    * Complexidade: O(V + E), onde V é o número de vértices e E é o número de arestas
        1. Cada vértice é visitado apenas uma vez, pois só pode ser visitado uma vez — O(V)
        2. Cada vez que um vértice é visitado, todos os seus k vizinhos são explorados e, portanto, depois que todos os vértices são visitados, acabamos examinando todas as E arestas — (O(E) como o número total de vizinhos de cada vértice [E]).

    * Aplicações:
        - Detectar ciclos em grafos não direcionados,
        - Detectar ciclos em grafos direcionados,
        - Encontrar componentes fortemente conectados (SCCs) em grafos direcionados,
        - Encontrar pontes e pontos de articulação em grafos não direcionados,
*/

#ifndef DFS_H
#define DFS_H

void dfs_recursive(Graph &g, int v)
{
    g.pre[v] = g.counter++;

    // adj[v] = vetor de adjacência do vértice v
    for (int w : g.adj[v])
    {
        if (g.pre[w] == -1)
        {
            dfs_recursive(g, w);
        }
        else if (w != g.parent[v])
        {
            cout << "Ciclo encontrado -> " << "Aresta de retorno: " << v << " -> " << w << endl;
        }
    }
    // ou: for(int i = 0; i < adj[v].size(); i++) { int w = adj[v][i]; }
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

#endif