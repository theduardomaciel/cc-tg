#include <queue>
#include <limits>
#include <algorithm>

#include "utils/input.h"
#include "utils/graph.h"
#include "./source/union_find.h"

using namespace std;

void kruskal(WeightedGraph &g, bool print_tree)
{
    DisjointSet ds(g.size());
    ds.make_set();

    // Vetor de arestas (peso, u, v)
    vector<tuple<int, int, int>> edges;

    // Coletamos todas as arestas do grafo
    for (int u = 0; u < g.size(); ++u)
    {
        for (auto &v : g.adj_out[u])
        {
            edges.emplace_back(v.second, u, v.first); // (peso, u, v)
        }
    }

    // Ordenamos as arestas pelo peso (é a parte mais custosa do algoritmo)
    sort(edges.begin(), edges.end());

    int cost = 0;

    // Iteramos sobre as arestas em ordem crescente de peso
    for (auto &[weight, u, v] : edges)
    {
        int x = ds.find(u);
        int y = ds.find(v);

        // Adicionamos a aresta caso haja conexão entre dois componentes distintos
        if (x != y)
        {
            // cout << u << " - " << v << " : " << weight << endl;
            if (print_tree)
            {
                cout << "(" << u << "," << v << ")" << " ";
            }

            cost += weight;
            ds.Union(x, y);
        }
    }

    if (print_tree)
    {
        cout << endl;
    }
    else
    {
        cout << cost << endl;
    }

    // cout << "Custo total da MST: " << cost << endl;
}

int main(int argc, char *argv[])
{
    const char *args_list[] = {"-s", NULL};
    InputData input = parse_input(argc, argv, args_list);

    // Lê o grafo ponderado do arquivo de entrada
    auto kruskal_graph = read_weighted_graph<WeightedGraph>(input.in);

    kruskal(*kruskal_graph, input.return_answer);

    return 0;
}
