#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
public:
    // Lista de adjacência para vizinhos de saída (adj+)
    vector<vector<int>> adj_out;

    // Lista de adjacência para vizinhos de entrada (adj-)
    vector<vector<int>> adj_in;

    // Vetore de numeração dos vértices (pré-ordem e pós-ordem)
    vector<int> pre;
    vector<int> post;

    // Vetor de distâncias (distância do vértice inicial a cada vértice)
    vector<int> dist;

    // Vetor de pais (vértice pai de cada vértice)
    vector<int> parent;

    int counter = 0; // Contador para numeração dos vértices

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
