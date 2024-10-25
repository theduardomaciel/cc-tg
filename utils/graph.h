#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adj_out; // Lista de adjacência para vizinhos de saída
    vector<vector<int>> adj_in;  // Lista de adjacência para vizinhos de entrada
    vector<int> pre;             // Vetor de pré-ordem
    vector<int> post;            // Vetor de pós-ordem
    vector<int> dist;            // Vetor de distâncias
    vector<int> parent;          // Vetor de pais
    int counter = 0;             // Contador para numeração dos vértices

    // Construtor: inicializa o grafo com n vértices
    Graph(int n) : adj_out(n + 1), adj_in(n + 1), pre(n + 1, -1), post(n + 1, -1), dist(n + 1, -1), parent(n + 1, -1) {}

    // Adiciona aresta de v para w
    void add_edge(int v, int w);

    // Retorna a lista de adjacência de saída de um vértice (adj+)
    const vector<int> &get_adj_out(int v) const
    {
        return adj_out[v];
    }

    // Retorna a lista de adjacência de entrada de um vértice (adj-)
    const vector<int> &get_adj_in(int v) const
    {
        return adj_in[v];
    }

    // Retorna o número de vértices no grafo
    int get_vertices_amount() const
    {
        return adj_out.size();
    }
};

#endif
