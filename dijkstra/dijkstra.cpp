#include <queue>
#include <limits>
#include "utils/input.h"
#include "utils/graph.h"

using namespace std;

static constexpr int INF = numeric_limits<int>::max();

class DijkstraGraph : public WeightedGraph
{
public:
    vector<int> dist;

    // Construtor que herda de WeightedGraph
    DijkstraGraph(const WeightedGraph &wg) : WeightedGraph(wg) {}

    // O construtor poderia ser otimizado da seguinte forma:
    // DijkstraGraph(int n) : WeightedGraph(n), dist(n + 1, INF) {}

    void add_edge(int u, int v, int weight)
    {
        // Grafo não direcionado
        WeightedGraph::add_edge(u, v, weight);
        WeightedGraph::add_edge(v, u, weight); // Cuidamos de casos não-direcionados
    }
};

void dijkstra(DijkstraGraph &g, int start)
{
    // Criamos uma fila de prioridade mínima para armazenar os vértices
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;

    // Inicializa o custo como infinito e o vértice inicial com custo 0
    g.dist = vector<int>(g.size() + 1, INF);

    g.dist[start] = 0;

    // Adiciona o vértice inicial à fila de prioridade
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Verifica cada vizinho de u
        for (auto x : g.adj_out[u])
        {
            int v = x.first;
            int weight = x.second;

            if (g.dist[v] > g.dist[u] + weight)
            {
                g.dist[v] = g.dist[u] + weight;
                pq.push({g.dist[v], v}); // Sobe na heap a distância reduzida
            }
        }
    }

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
    const char *args_list[] = {"-i", NULL};
    InputData input = parse_input(argc, argv, args_list);

    // Lê o grafo de entrada
    auto dijkstra_graph = read_weighted_graph<DijkstraGraph>(input.in);

    // Executa o algoritmo de Dijkstra
    dijkstra(*dijkstra_graph, input.initial);

    return 0;
}
