#include <queue>
#include <climits>

#include "utils/input.h"
#include "traversal/dfs.h"

using namespace std;

/*
    Em C++ a fila de prioridade é implementada como uma fila de prioridade máxima, ou seja, o maior elemento é sempre o primeiro a ser removido.
    Para tornar a fila de prioridade uma fila de prioridade mínima, utilizamos algo do seguinte tipo:
        priority_queue<int, vector<int>, greater<int>> pq;
            1. O primeiro argumento é o tipo de dado que a fila de prioridade armazenará.
            2. O segundo argumento é o tipo de contêiner que a fila de prioridade usará para armazenar os elementos.
            3. O terceiro argumento é o comparador que a fila de prioridade usará para ordenar os elementos.

    É meio bagunçado, mas é assim que funciona.
*/

void dijkstra(WeightedGraph &g, int source)
{
    // Inicializa as distâncias como infinito e o nó inicial com distância 0
    g.dist = vector<int>(g.size() + 1, INT_MAX);

    // Criamos uma fila de proridade mínima para armazenar os vértices
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;

    pq.push({0, source});
    g.dist[source] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Verifica cada vizinho de u para relaxamento
        for (auto x : g.adj[u])
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

    // Imprime o caminho mínimo para cada nó
    for (int i = 1; i < g.size(); i++)
    {
        cout << i << ": " << (g.dist[i] == INT_MAX ? "-1" : to_string(g.dist[i])) << endl;
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

    int source = stoi(argv[4]);

    // Executa o algoritmo de Dijkstra
    dijkstra(g, source);

    return 0;
}
