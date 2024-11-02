#include <iostream>
using namespace std;

#include "graph.h"

void Graph::add_edge(int u, int v)
{
    // cout << "Adicionando aresta " << u << " -> " << v << endl;
    adj_out[u].push_back(v); // Adiciona v à lista de saída de u (adj+)
    adj_in[v].push_back(u);  // Adiciona u à lista de entrada de v (adj-)
}

void WeightedGraph::add_edge(int u, int v, int weight)
{
    // cout << "Adicionando aresta " << u << " -> " << v << " com peso " << p << endl;
    adj[u].push_back({v, weight}); // Adiciona v à lista de saída de u (adj+)
    adj[v].push_back({u, weight}); // Adiciona u à lista de saída de v (adj+)
}