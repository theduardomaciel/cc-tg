#include "input.h"

Graph read_graph(string filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    Graph g(n); // Inicializa o grafo com n vértices

    int v, w; // v = vértice de origem, w = vértice de destino
    for (int i = 0; i < m; i++)
    {
        file >> v >> w;
        g.add_edge(v, w); // Adiciona a aresta direcionada de v para w
    }

    file.close();
    return g;
}

WeightedGraph read_weighted_graph(string filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    WeightedGraph g(n); // Inicializa o grafo com n vértices

    int v, w, weight; // v = vértice de origem, w = vértice de destino, weight = peso da aresta
    for (int i = 0; i < m; i++)
    {
        file >> v >> w >> weight;
        g.add_edge(v, w, weight); // Adiciona a aresta direcionada de v para w com peso weight
    }

    file.close();
    return g;
}