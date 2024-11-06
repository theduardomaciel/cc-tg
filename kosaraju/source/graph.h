#include <utils/graph.h>

class KosarajuGraph : public Graph
{
public:
    int counter = 0;  // Contador para numeração dos vértices
    vector<int> pre;  // Vetor de pré-ordem
    vector<int> post; // Vetor de pós-ordem

    vector<vector<int>> adj_in; // Lista de adjacência para vizinhos de entrada (adj-)

    // Construtor que herda de um WeightedGraph
    KosarajuGraph(const Graph &g) : Graph(g.size()), pre(g.size(), -1), post(g.size(), -1), adj_in(g.size() + 1) {}

    void add_edge(int u, int v)
    {
        Graph::add_edge(u, v);
        adj_in[v].push_back(u);
    }
};