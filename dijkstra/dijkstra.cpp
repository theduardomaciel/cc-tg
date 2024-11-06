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
    // Poderíamos otimizar da seguinte forma:
    // DijkstraGraph(int n) : WeightedGraph(n), dist(n + 1, INF), prev(n + 1, -1) {}

    void add_edge(int u, int v, int weight)
    {
        adj_out[u].push_back({v, weight});
        adj_out[v].push_back({u, weight});
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
    if (argc < 2 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo> -i <vértice inicial>" << endl;
        return 1;
    }

    string filename = argv[2];
    auto dijkstra_graph = read_weighted_graph<DijkstraGraph>(filename);

    int start;
    try
    {
        start = stoi(argv[4]);
    }
    catch (const invalid_argument &e)
    {
        /* cout << "Erro: vértice inicial inválido." << endl;
        return 1; */
        start = 1;
    }

    // Executa o algoritmo de Dijkstra
    dijkstra(*dijkstra_graph, start);

    return 0;
}
