#include <queue>
#include <limits>
#include "utils/input.h"
#include "utils/graph.h"

using namespace std;

static constexpr int INF = numeric_limits<int>::max();

class BellmanGraph
{
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> dist;

    // Construtor que herda de WeightedGraph
    BellmanGraph(int n) : adj(n + 1), dist(n + 1, INF) {}

    // Inicialmente, a distância da origem para todos os outros vértices
    // é desconhecida, portanto, é definida como infinito (INF).
    int size() const { return adj.size(); }

    void add_edge(int u, int v, int weight)
    {
        // Grafo não direcionado
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
};

/*
    Princípio do relaxamento de arestas:
        Consiste na atualização da menor distância de um vértice u até um vértice v,
        se um caminho menor for encontrado por outro vértice k.

        Seja u->v uma aresta do grafo, com peso w.
        Se ir a partir de u nos dá um caminho menor até v a partir do vértice inicial
        (por exemplo, dist[v] > dist[u] + w), então atualizamos dist[v] = dist[u] + w.
*/

void bellman(BellmanGraph &g, int start)
{
    g.dist[start] = 0;

    // "Relaxamos" todas as arestas n vezes
    // Rodamos um loop adicional (n ao invés de n - 1) para detectar ciclos negativos
    for (int l = 1; l < g.size(); l++)
    {
        for (int k = 1; k < g.size(); k++)
        {
            // $$d(l, k) = min_{v_i \in N^-(V_k)} \{d(l-1, v_i) + w(v_i, v_k)\}$$
            for (const auto &edge : g.adj[k])
            {
                int i = edge.first;       // Vértice de origem
                int weight = edge.second; // Peso da aresta

                // Calculamos o mínimo entre a distância atual e a distância do vértice de origem
                if (g.dist[i] != INF && g.dist[i] + weight < g.dist[k])
                {
                    // Se essa for a n-ésima iteração, então há um ciclo negativo
                    if (l == g.size() - 1)
                    {
                        cout << "Ciclo negativo detectado!" << endl;
                        g.dist[k] = -1;
                        return;
                    }

                    // Atualizamos a distância mínima até o vértice k
                    g.dist[k] = g.dist[i] + weight;
                }
            }
        }
    }

    // Exibindo as distâncias mínimas
    for (int i = 1; i < g.size(); i++)
    {
        if (g.dist[i] == INF)
        {
            cout << i << ":-1";
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
        for (const auto &edge : bellman_graph->adj[i])
        {
            cout << "  -> " << edge.first << " (peso " << edge.second << ")" << endl;
        }
    } */

    // Executa o algoritmo de Bellman
    bellman(*bellman_graph, input.initial);

    return 0;
}
