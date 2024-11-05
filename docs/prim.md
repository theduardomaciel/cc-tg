# Particularidades do Prim

Diferente do algoritmo de Dijkstra, precisamos acompanhar um vetor de booleanos para saber se um vértice já foi visitado ou não.  
Isso é necessário pois o algoritmo de Prim não garante que o menor caminho entre dois vértices seja o caminho mais curto. Assim, precisamos garantir que um vértice já visitado não seja visitado novamente.

Para resolver esse problema, precisamos garantir que um vértice já visitado não seja visitado novamente.

# Exemplo de implementação

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> int_pair;
typedef vector<int_pair> int_pair_vector;
typedef vector<int> int_vector;

int prim(vector<int_pair_vector> &graph, int start) {
    int n = graph.size();

    int_vector dist(n, INF);
    int_vector visited(n, false);

    priority_queue<int_pair, int_pair_vector, greater<int_pair>> pq;

    dist[start] = 0;
    pq.push({0, start});

    int mst = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        mst += dist[u];

        for (auto &[v, w] : graph[u]) {
            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    return mst;
}