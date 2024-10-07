#include <queue>
#include "utils/graph.h"

using namespace std;

/*
    BFS (Breadth-First Search)

    * Parâmetros:
        - g: grafo
        - v0: vértice inicial

    * Estrutura de dados: Utiliza uma fila (FIFO) para percorrer o grafo a partir do vértice v0

    * Pseudocódigo:
        - Inicializa a fila com o vértice inicial v0
        - Marca o vértice v0 como visitado
        - Enquanto a fila não estiver vazia:
            - Remove o 1o vértice da fila
            - Para cada vértice w adjacente a v:
                - Se w não foi visitado:
                    - Marca w como visitado
                    - Adiciona w à fila

    * Complexidade: O(V + E), onde V é o número de vértices e E é o número de arestas
        1. Cada vértice é visitado apenas uma vez, pois só pode entrar na fila uma vez — O(V)
        2. Cada vez que um vértice é removido da fila, todos os seus k vizinhos são explorados e, portanto, depois que todos os vértices são visitados, acabamos examinando todas as E arestas — (O(E) como o número total de vizinhos de cada vértice [E]).

    * Aplicações:
        - Impressão do caminho do vértice inicial a todos os outros vértices,
        - Teste de alcance (verificar se um vértice é alcançável a partir de outro),
        - Identificar/Contar/Rotular Componentes Conectados (CCs) de grafos não direcionados,
        - Detectar se um grafo é cíclico,
        - Ordenação Topológica (apenas em DAGs),
        - Encontrar o menor caminho em grafos não ponderados,
        - Encontrar o menor caminho em grafos ponderados (Dijkstra),
        - Encontrar o menor caminho em grafos ponderados com arestas negativas e ciclos (Bellman-Ford),
*/

#ifndef BFS_H
#define BFS_H

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

#endif