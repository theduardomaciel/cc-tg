#include <iostream>
using namespace std;

#include "graph.h"

void Graph::add_edge(int v, int w)
{
    cout << "Adicionando aresta " << v << " -> " << w << endl;
    adj_out[v].push_back(w); // Adiciona w à lista de saída de v (adj+)
    adj_in[w].push_back(v);  // Adiciona v à lista de entrada de w (adj-)
}

void WeightedGraph::add_edge(int v, int w, int p)
{
    cout << "Adicionando aresta " << v << " -> " << w << " com peso " << p << endl;
    Graph::add_edge(v, w); // Chama o método add_edge da classe base
    weights[v][w] = p;     // Armazena o peso da aresta de v para w
}