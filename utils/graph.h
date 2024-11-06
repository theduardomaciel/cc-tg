#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

class Graph
{
private:
    bool is_directed;

public:
    vector<vector<int>> adj_out; // Lista de adjacência para vizinhos de saída (adj+)

    // Construtor padrão
    Graph(int n = 0, bool directed = true) : adj_out(n + 1)
    {
        is_directed = directed;
    }

    // Retorna o número de vértices no grafo
    int size() const
    {
        return adj_out.size();
    }

    // Adiciona aresta de u para v
    void add_edge(int u, int v);
};

typedef pair<int, int> int_pair;

class WeightedGraph : public Graph
{
private:
    bool is_directed;

public:
    vector<vector<int_pair>> adj_out;

    // Construtor padrão
    WeightedGraph(int n = 0, bool directed = false) : Graph(n), adj_out(n + 1)
    {
        is_directed = directed;
    }

    // Adiciona aresta de u para v com peso p
    void add_edge(int u, int v, int weight);
};

#endif