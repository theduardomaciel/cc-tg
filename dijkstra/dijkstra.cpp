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

void prim(PrimGraph &g, int start)
{
    // Criamos uma fila de prioridade mínima para armazenar os vértices
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;

    // Inicializa o custo como infinito e o vértice inicial com custo 0
    g.custo = vector<int>(g.size() + 1, INF);
    g.prev = vector<int>(g.size() + 1, -1);
    g.custo[start] = 0;

    // Adiciona o vértice inicial à fila de prioridade
    pq.push({0, start});

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        // Verifica cada vizinho u de v
        for (auto x : g.adj_out[v])
        {
            int u = x.first;
            int weight = x.second;

            // Se a aresta v-u tem peso menor que o custo atual de u
            if (g.custo[u] > weight)
            {
                g.custo[u] = weight;
                g.prev[u] = v;
                pq.push({g.custo[u], u}); // Sobe na heap o novo custo
            }
        }
    }

    // Imprime a Árvore Geradora Mínima
    for (int i = 1; i < g.size(); i++)
    {
        if (g.prev[i] != -1)
            cout << g.prev[i] << " - " << i << " : " << g.custo[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo> -i <vértice inicial>" << endl;
        return 1;
    }

    string filename = argv[2];
    auto prim_graph = read_weighted_graph<PrimGraph>(filename);

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

    // Executa o algoritmo de Prim
    prim(*prim_graph, start);

    return 0;
}
