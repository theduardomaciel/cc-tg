#include <vector>

using namespace std;

class Graph
{
public:
    Graph(int n)
    {
        adj = vector<vector<int>>(n, vector<int>());
        pre = vector<int>(n, -1); // Inicializa o vetor pre com -1 em todas as posições
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Cria um vetor de vetores de inteiros (int)
    vector<vector<int>> adj;

    // Cria um vetor de inteiros
    vector<int> pre;

    int counter = 0;
};