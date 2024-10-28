#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <limits> // Para definir valores máximos
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
    int size() const
    {
        return adj_out.size();
    }
};

class WeightedGraph : public Graph
{
public:
    vector<vector<int>> weights; // Matriz de pesos das arestas

    // Construtor: inicializa o grafo com n vértices
    WeightedGraph(int n)
        : Graph(n), weights(n + 1, vector<int>(n + 1, -1)) {}

    // Adiciona aresta de v para w com peso p
    void add_edge(int v, int w, int p);

    // Retorna o peso da aresta de v para w
    int get_weight(int v, int w) const
    {
        return weights[v][w];
    }
};

#endif