#include <vector>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
    Graph(int n)
    {
        adj = vector<vector<int>>(n, vector<int>());
        pre = vector<int>(n, -1);    // Inicializa o vetor pre com -1 em todas as posições
        post = vector<int>(n, -1);   // Inicializa o vetor post com -1 em todas as posições
        dist = vector<int>(n, -1);   // Inicializa o vetor dist com -1 em todas as posições
        parent = vector<int>(n, -1); // Inicializa o vetor parent com -1 em todas as posições
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Lista de adjacência (vértices vizinhos de cada vértice)
    vector<vector<int>> adj;

    // Vetor de pré-ordem (numeração dos vértices)
    vector<int> pre;

    // Vetor de pós-ordem (numeração dos vértices)
    vector<int> post;

    // Vetor de distâncias (distância do vértice inicial a cada vértice)
    vector<int> dist;

    // Vetor de pais (vértice pai de cada vértice)
    vector<int> parent;

    int counter = 0;
};

#endif