#include <iostream>
using namespace std;

#include "graph.h"

Graph::Graph(int n)
{
    adj = vector<vector<int>>(n + 1, vector<int>());
    pre = vector<int>(n, -1);    // Inicializa o vetor pre com -1 em todas as posições
    post = vector<int>(n, -1);   // Inicializa o vetor post com -1 em todas as posições
    dist = vector<int>(n, -1);   // Inicializa o vetor dist com -1 em todas as posições
    parent = vector<int>(n, -1); // Inicializa o vetor parent com -1 em todas as posições
}

void Graph::addEdge(int v, int w)
{
    cout << "Adicionando aresta " << v << " -> " << w << endl;
    adj[v].push_back(w);
    adj[w].push_back(v);
}