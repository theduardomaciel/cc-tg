#include <queue>
#include <limits>
#include "utils/input.h"
#include "utils/graph.h"

using namespace std;

static constexpr int INF = numeric_limits<int>::max();

class BellmanGraph : public WeightedGraph
{
public:
    vector<vector<pair<int, int>>> adj_in;
    vector<int> dist;

    // Construtor que herda de WeightedGraph
    BellmanGraph(int n) : WeightedGraph(n), adj_in(n + 1), dist(n + 1, INF) {}
};

void bellman(BellmanGraph &g, int start)
{
    // Passo 1: Inicialização
    g.dist[start] = 0;

    // Passo 2: Relaxação de arestas (n-1) vezes
    for (int l = 1; l < g.size(); ++l)
    {
        for (int k = 0; k < g.size(); ++k)
        {
            for (const auto &edge : g.adj_out[k])
            {
                int i = edge.first;       // Vértice de destino
                int weight = edge.second; // Peso da aresta
                if (g.dist[k] != INF && g.dist[k] + weight < g.dist[i])
                {
                    g.dist[i] = g.dist[k] + weight;
                }
            }
        }
    }

    // Passo 3: Verificação de ciclos negativos (opcional, mas importante)
    for (int k = 0; k < g.size(); ++k)
    {
        for (const auto &edge : g.adj_in[k])
        {
            int i = edge.first;       // Vértice de origem
            int weight = edge.second; // Peso da aresta
            if (g.dist[k] > g.dist[i] + weight)
            {
                cout << "O grafo contém um ciclo negativo!" << endl;
                return;
            }
        }
    }

    // Exibindo as distâncias mínimas
    for (int i = 1; i < g.size(); i++)
    {
        if (g.dist[i] == INF)
        {
            cout << "-1";
        }
        else
        {
            cout << i << ":" << g.dist[i];
        }
        cout << " ";
    }

    cout << endl;
}

int main(int argc, char *argv[])
{
    InputData input = parse_input(argc, argv, NULL);
    auto bellman_graph = read_weighted_graph<BellmanGraph>(input.in);

    // DEBUG: printar o grafo
    /* cout << "Grafo de entrada:" << endl;
    for (int i = 0; i < bellman_graph->size(); ++i)
    {
        cout << "Vértice " << i << ":" << endl;
        for (const auto &edge : bellman_graph->adj_out[i])
        {
            cout << "  -> " << edge.first << " (peso " << edge.second << ")" << endl;
        }
    } */

    // Executa o algoritmo de Bellman
    bellman(*bellman_graph, input.initial);

    return 0;
}
