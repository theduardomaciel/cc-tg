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

    // Adiciona aresta de u para v
    void add_edge(int u, int v);

    // Retorna a lista de adjacência de saída de um vértice (adj+)
    const vector<int> &get_adj_out(int u) const
    {
        return adj_out[u];
    }

    // Retorna a lista de adjacência de entrada de um vértice (adj-)
    const vector<int> &get_adj_in(int u) const
    {
        return adj_in[u];
    }

    // Retorna o número de vértices no grafo
    int size() const
    {
        return adj_out.size();
    }
};

typedef pair<int, int> int_pair;

class WeightedGraph : public Graph
{
public:
    vector<vector<int_pair>> adj; // Lista de adjacência para vizinhos de saída

    // Construtor: inicializa o grafo com n vértices
    WeightedGraph(int n) : Graph(n), adj(n + 1) {} // Redimensiona `adj` para ter `n + 1` listas de adjacência

    // Adiciona aresta de u para v com peso p
    void add_edge(int u, int v, int weight);
};

#endif