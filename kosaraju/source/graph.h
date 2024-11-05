#include <utils/graph.h>

class KosarajuGraph : public Graph
{
public:
    vector<vector<int>> adj_in; // Lista de adjacência para vizinhos de entrada
    vector<int> pre;            // Vetor de pré-ordem
    vector<int> post;           // Vetor de pós-ordem
    int counter = 0;            // Contador para numeração dos vértices

    // Construtor que herda de um WeightedGraph
    KosarajuGraph(const Graph &g) : Graph(g.size()), adj_in(g.size()), pre(g.size(), -1), post(g.size(), -1) {};

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

    void add_edge(int u, int v)
    {
        Graph::add_edge(u, v);
        adj_in[v].push_back(u);
    }
};