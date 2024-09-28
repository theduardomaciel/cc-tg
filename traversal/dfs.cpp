#include <vector>
#include <iostream>

using namespace std;

int counter = 0;

void dfsRecursive(vector<vector<int>> &adj, vector<int> &pre, int v)
{
    pre[v] = counter++;

    // adj = vetor de vetores | adj[v] = vetor de adjacência do vértice v
    for (int w : adj[v])
    {
        if (pre[w] == -1)
        {
            dfsRecursive(adj, pre, w);
        }
    }
    // ou for(int i = 0; i < adj[v].size(); i++) { int w = adj[v][i]; }
}

// O & é uma referência, ou seja, é um ponteiro que não precisa ser desreferenciado
// É um ponteiro mais elegante (não precisa passar o operador ->)
void dfs(vector<vector<int>> &adj, vector<int> &pre)
{
    int n = adj.size();
    for (int v = 0; v < n; v++)
    {
        if (pre[v] == -1)
            dfsRecursive(adj, pre, v);
    }
}

int main()
{
    // No Windows, é necessário definir a codificação para UTF-8
    setlocale(LC_ALL, ".utf8");

    int n, m;
    cin >> n >> m; // Na primeira linha, lê a quantidade de vértices e arestas
    cout << "Quantidade de vértices: " << n << endl;
    cout << "Quantidade de arestas: " << m << endl;

    // Cria um vetor de vetores de inteiros (int) com n posições (a matriz de adjacência)
    vector<vector<int>> adj(n, vector<int>());

    // Cria um vetor de inteiros com o valor −1 inicializado em todas as posições
    vector<int> pre(n, -1);

    int v, w;
    for (int c = 0; c < m; c++)
    {
        cin >> v >> w; // Lê as arestas dispostas nas linhas do arquivo de entrada no formato v w
        }

    dfs(adj, pre);

    for (int v = 0; v < n; v++)
    {
        cout << "pre[" << v << "] = " << pre[v] << " | ";
    }

    cout << endl;

    return 0;
}
