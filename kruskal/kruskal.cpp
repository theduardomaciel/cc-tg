#include <queue>
#include <limits>
#include <algorithm>

#include "utils/input.h"
#include "utils/graph.h"
#include "./source/union_find.h"

using namespace std;

void kruskal(WeightedGraph &g, bool print_tree, ostream &output = cout)
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
            // output << u << " - " << v << " : " << weight << endl;
            if (print_tree)
            {
                output << "(" << u << "," << v << ")" << " ";
            }

            cost += weight;
            ds.Union(x, y);
        }
    }

    if (print_tree)
    {
        output << endl;
    }
    else
    {
        output << cost << endl;
    }

    // output << "Custo total da MST: " << cost << endl;
}

int main(int argc, char *argv[])
{
    const char *args_list[] = {"-s", NULL};
    InputData input = parse_input(argc, argv, args_list);

    // Lê o grafo ponderado do arquivo de entrada
    auto kruskal_graph = read_weighted_graph<WeightedGraph>(input.in);

    // Verifica se há redirecionamento de saída
    ostream *output_stream = &cout;
    ofstream out_file;
    if (!input.out.empty())
    {
        out_file.open(input.out);
        if (out_file.is_open())
        {
            output_stream = &out_file;
        }
        else
        {
            cerr << "Erro ao abrir o arquivo de saída: " << input.out << endl;
            exit(1);
        }
    }

    kruskal(*kruskal_graph, input.return_answer, *output_stream);

    return 0;
}
