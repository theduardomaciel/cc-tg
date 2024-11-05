#include "input.h"

template <typename GraphType>
unique_ptr<GraphType> read_graph(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    auto g = make_unique<GraphType>(n); // Inicializa o grafo com n vértices

    int u, v; // u = vértice de origem, v = vértice de destino
    for (int i = 0; i < m; i++)
    {
        file >> u >> v;
        g->add_edge(u, v); // Adiciona a aresta direcionada de u para v
    }

    file.close();
    return g;
}

template <typename GraphType>
unique_ptr<GraphType> read_weighted_graph(const string &filename)
{
    // cout << "Lendo grafo com pesos no arquivo " << filename << endl;
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    // cout << "O grafo tem " << n << " vértices e " << m << " arestas" << endl;

    auto g = make_unique<GraphType>(n); // Inicializa o grafo com n vértices

    int u, v, weight; // u = vértice de origem, v = vértice de destino, weight = peso da aresta
    for (int i = 0; i < m; i++)
    {
        // cout << "Lendo aresta " << i << endl;
        file >> u >> v >> weight;
        g->add_edge(u, v, weight); // Adiciona a aresta direcionada de u para v com peso weight
    }

    file.close();
    return g;
}

/* template <typename GraphType>
GraphType read_generic_graph(string filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    GraphType g(n); // Inicializa o grafo com n vértices

    int u, v; // u = vértice de origem, v = vértice de destino
    for (int i = 0; i < m; i++)
    {
        if constexpr (std::is_same_v<GraphType, WeightedGraph>)
        {
            int weight;
            file >> u >> v >> weight;
            g.add_edge(u, v, weight); // Adiciona a aresta direcionada de u para v com peso weight
        }
        else
        {
            file >> u >> v;
            g.add_edge(u, v); // Adiciona a aresta direcionada de u para v
        }
    }

    file.close();
    return g;
} */