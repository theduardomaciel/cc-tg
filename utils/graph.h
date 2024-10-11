#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
public:
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

    // Construtor
    Graph(int n);

    // Função para adicionar aresta
    void addEdge(int v, int w);
};

#endif