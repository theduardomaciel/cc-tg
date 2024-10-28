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

#include <functional>
#include <vector>
#include <stack>
#include "utils/graph.h"

/**
 * @brief Helper function for performing a depth-first search (DFS) on the given graph starting from the specified vertex.
 *
 * This function is called recursively to traverse the graph in a depth-first manner, visiting all vertices reachable from the starting vertex.
 *
 * @param g The graph to be traversed.
 * @param adj The adjacency list of the graph.
 * @param pre The function to be executed before visiting a vertex.
 * @param pos The function to be executed after visiting a vertex.
 */
void dfs(Graph &g, const vector<vector<int>> &adj, const function<void(int)> &pre, const function<void(int)> &pos);

/**
 * @brief Helper function for performing a depth-first search (DFS) on the given graph starting from the specified vertex.
 *
 * This function is called recursively to traverse the graph in a depth-first manner, visiting all vertices reachable from the starting vertex.
 *
 * @param g The graph to be traversed.
 * @param v The vertex to start the DFS from.
 * @param adj The adjacency list of the graph.
 * @param pre The function to be executed before visiting a vertex.
 * @param pos The function to be executed after visiting a vertex.
 */
void dfs_recursion(Graph &g, int v, const vector<vector<int>> &adj, const function<void(int)> &pre, const function<void(int)> &pos);

#endif
