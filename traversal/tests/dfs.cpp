#include <iostream>
#include "dfs.h"

using namespace std;

int main()
{
    // No Windows, é necessário definir a codificação para UTF-8
    setlocale(LC_ALL, ".utf8");

    int n, m;
    cin >> n >> m; // Na primeira linha, lê a quantidade de vértices e arestas
    cout << "Quantidade de vértices: " << n << endl;
    cout << "Quantidade de arestas: " << m << endl
         << endl;

    Graph g(n);

    int v, w;
    for (int c = 0; c < m; c++)
    {
        cin >> v >> w; // Lê as arestas dispostas nas linhas do arquivo de entrada no formato v w
        g.addEdge(v, w);
    }

    int connected_components = dfs(g);

    for (int v = 0; v < n; v++)
    {
        cout << "pre[" << v << "] = " << g.pre[v] << endl;
    }

    cout << endl;
    cout << "Quantidade de componentes conexas: " << connected_components << endl;

    return 0;
}
