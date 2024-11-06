#include <queue>
#include <limits>

#include "utils/input.h"
#include "utils/graph.h"

using namespace std;

static constexpr int INF = numeric_limits<int>::max();

class PrimGraph : public WeightedGraph
{
public:
    vector<int> custo;
    vector<int> prev;

    // Construtor que herda de WeightedGraph
    PrimGraph(const WeightedGraph &wg) : WeightedGraph(wg) {}

    void add_edge(int u, int v, int weight)
    {
        adj_out[u].push_back({v, weight});
        adj_out[v].push_back({u, weight});
    }
};

// DAG = MST = Minimum Spanning Tree (árvore geradora mínima)
void prim(PrimGraph &g, int start, bool print_tree = false)
{
    // Criamos uma fila de prioridade mínima para armazenar os vértices
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;

    g.custo = vector<int>(g.size() + 1, INF);
    g.prev = vector<int>(g.size() + 1, -1);
    g.custo[start] = 0;

    // Adiciona o vértice inicial à fila de prioridade
    pq.push({0, start});

    vector<bool> visited(g.size() + 1, false); // Para rastrear os nós incluídos na MST

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        // Verifica a presença de um ciclo
        if (visited[v]) // o mesmo que: if (visited.at(v))
            continue;

        visited[v] = true;

        for (auto x : g.adj_out[v])
        {
            int u = x.first;
            int weight = x.second;
            // o equivalente a fazer: auto &[u, weight] : g.adj_out[u]

            if (!visited[u] && g.custo[u] > weight)
            {
                g.custo[u] = weight;
                pq.push({g.custo[u], u});
                g.prev[u] = v;
            }
        }
    }

    int total_cost = 0;

    for (int i = 1; i < g.size(); i++)
    {
        if (g.prev[i] != -1)
        {
            total_cost += g.custo[i];

            if (print_tree)
                cout << "(" << g.prev[i] << "," << i << ")" << " ";
        }
    }

    if (print_tree)
    {
        cout << endl;
    }
    else
    {
        cout << total_cost << endl;
    }

    // cout << "Custo total: " << total_cost << endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " -f <arquivo> -i <vértice inicial> -s <mostrar solução?>" << endl;
        return 1;
    }

    const char *args_list[] = {"-s", "-i", NULL};
    InputData data = parse_input(argc, argv, args_list);

    auto prim_graph = read_weighted_graph<PrimGraph>(data.in);

    prim(*prim_graph, data.initial_vertex, data.return_answer);

    return 0;
}
