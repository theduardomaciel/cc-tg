#include "traversal/dfs.h"
#include "utils/input.h"

int main()
{
    // No Windows, é necessário definir a codificação para UTF-8
    setlocale(LC_ALL, ".utf8");

    Graph g = read_graph("graph.dat");

    dfs(g, g.adj_out, nullptr, nullptr);

    for (int v = 1; v < g.size(); v++)
    {
        cout << "pre[" << v << "] = " << g.pre[v] << endl;
    }

    cout << endl;
    // cout << "Quantidade de componentes conexas: " << connected_components << endl;

    return 0;
}
