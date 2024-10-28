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

#include <queue>
#include "utils/graph.h"

/**
 * @brief Performs a breadth-first search (BFS) on the given graph starting from the specified vertex.
 *
 * This function traverses the graph using the BFS algorithm, starting from the vertex `v0`.
 * It explores all vertices at the present depth level before moving on to vertices at the next depth level.
 *
 * @param g Reference to the graph object on which BFS is to be performed.
 * @param v0 The starting vertex for the BFS traversal.
 */
void bfs(Graph &g, int v0);

#endif