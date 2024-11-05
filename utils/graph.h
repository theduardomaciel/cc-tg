#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

class Graph
{
public:
    vector<vector<int>> adj_out; // Lista de adjacência para vizinhos de saída

    // Construtor padrão
    Graph(int n = 0) : adj_out(n + 1) {}

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
public:
    vector<vector<int_pair>> adj_out;

    // Construtor padrão
    WeightedGraph(int n = 0) : Graph(n), adj_out(n + 1) {}

    // Adiciona aresta de u para v com peso p
    void add_edge(int u, int v, int weight);
};

#endif