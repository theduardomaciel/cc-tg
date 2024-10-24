#include <iostream>
using namespace std;

#include "graph.h"

void Graph::add_edge(int v, int w)
{
    cout << "Adicionando aresta " << v << " -> " << w << endl;
    adj_out[v].push_back(w); // Adiciona w à lista de saída de v (adj+)
    adj_in[w].push_back(v);  // Adiciona v à lista de entrada de w (adj-)
}