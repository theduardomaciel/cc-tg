#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int counter = 0;

void bfs(vector<vector<int>> &adj, vector<int> &pre, int v0)
{
    queue<int> q;
    q.push(v0);

    pre[v0] = counter++;

    while (!q.empty())
    {
        int v = q.front(); // v é o vértice que está na frente da fila
        q.pop();           // Remove o vértice da frente da fila

        for (size_t i = 0; i < adj[v].size(); i++)
        {
            int w = adj[v][i]; // w é o vértice adjacente a v
            if (pre[w] == -1)
            { // Verifica se o vértice w já foi visitado
                pre[w] = counter++;
                q.push(w);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "Quantidade de vértices: " << n << endl;
    cout << "Quantidade de arestas: " << m << endl;

    // Cria um vetor de vetores de inteiros (int) com n posições (a matriz de adjacência)
    vector<vector<int>> adj(n, vector<int>());

    // Cria um vetor de inteiros com o valor −1 inicializado em todas as posições
    vector<int> pre(n, -1);

    int v, w;
    for (int c = 0; c < m; c++)
    {
        cin >> v >> w; // Lê as arestas no formato v w pelo teclado
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bfs(adj, pre, 0);

    for (int v = 0; v < n; v++)
    {
        cout << "pre[" << v << "] = " << pre[v] << " | ";
    }

    cout << endl;

    return 0;
}