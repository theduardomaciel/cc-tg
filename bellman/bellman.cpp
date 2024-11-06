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
    BellmanGraph(int n) : WeightedGraph(n), adj_in(n), dist(n, INF) {}
};

void bellman(BellmanGraph &g, int start)
{
}

int main(int argc, char *argv[])
{
    if (argc < 2 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo> -i <vértice inicial>" << endl;
        return 1;
    }

    string filename = argv[2];
    auto bellman_graph = read_weighted_graph<BellmanGraph>(filename);

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

    // Executa o algoritmo de Bellman
    bellman(*bellman_graph, start);

    return 0;
}
