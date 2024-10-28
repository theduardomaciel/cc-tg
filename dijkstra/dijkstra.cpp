#include <queue>
#include <climits>

#include "utils/input.h"
#include "traversal/dfs.h"

using namespace std;

void dijkstra(WeightedGraph &g, int v0)
{
    // Inicializa as distâncias como infinito e o nó inicial com distância 0
    g.dist = vector<int>(g.size() + 1, INT_MAX);
    g.dist[v0] = 0;
    g.parent[v0] = -1;

    // Criamos uma fila de proridade mínima para armazenar os vértices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, v0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Verifica cada vizinho de u para relaxamento
        for (int v : g.adj_out[u])
        {
            int weight_uv = g.get_weight(u, v);
            if (weight_uv != -1 && g.dist[v] > g.dist[u] + weight_uv)
            {
                g.dist[v] = g.dist[u] + weight_uv;
                g.parent[v] = u;
                pq.push({g.dist[v], v});
            }
        }
    }

    // Imprime o caminho mínimo para cada nó
    for (int i = 1; i <= g.size(); i++)
    {
        cout << "Distância mínima de " << v0 << " a " << i << ": "
             << (g.dist[i] == INT_MAX ? -1 : g.dist[i]) << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo> -i <vértice inicial>" << endl;
        return 1;
    }

    string filename = argv[2];
    WeightedGraph g = read_weighted_graph(filename);

    int v0 = stoi(argv[4]);

    // Executa o algoritmo de Dijkstra
    dijkstra(g, v0);

    return 0;
}
