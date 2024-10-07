#include <iostream>
#include <fstream>

#include "utils/graph.h"
#include "traversal/dfs.h"

using namespace std;

/*
    Problema das Componentes Fortemente Conexas
        1. Realizar uma DFS no grafo original e calcular o vetor de pós-ordem
        2. Inverter as arestas do grafo
        3. Realizar uma DFS no grafo invertido, considerando os vértices em ordem decrescente de pós-ordem

    Para o problema de componentes fortemente conexos o algoritmo de kosaraju deve possuir os seguintes parâmetros:
        -h : mostra o help
        -o <arquivo> : redireciona a saída para o ‘‘arquivo’’
        -f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada
*/

Graph read_graph(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    Graph g(n);

    int v, w; // v = vértice de origem, w = vértice de destino
    for (int i = 0; i < m; i++)
    {
        file >> v >> w;
        g.addEdge(v, w);
    }

    file.close();

    return g;
}

void print_path(Graph &g, int v)
{
    if (g.parent[v] == -1)
    {
        cout << v;
    }
    else
    {
        print_path(g, g.parent[v]);
        cout << " -> " << v;
    }
}

void kosaraju(Graph &g)
{
    // 1a DFS: Calcula o vetor de pós-ordem
    for (size_t v = 0; v < g.adj.size(); v++)
    {
        if (g.pre[v] == -1)
            dfs_recursive(g, v);
    }

    // Inicializa o vetor de pais
    for (size_t v = 0; v < g.adj.size(); v++)
    {
        g.parent[v] = -1;
    }

    // Inverte as arestas do grafo
    Graph gt(g.adj.size());
    for (size_t v = 0; v < g.adj.size(); v++)
    {
        for (int w : g.adj[v])
        {
            gt.addEdge(w, v);
        }
    }

    // Obtemos as componentes fortemente conexas
    int connected_components = dfs(gt);

    cout << "Componentes fortemente conexas:" << endl;

    for (size_t v = 0; v < gt.adj.size(); v++)
    {
        cout << "Componente " << v << ": ";
        print_path(gt, v);
        cout << endl;
    }

    cout << "Quantidade de componentes fortemente conexas: " << connected_components << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    // No Windows, é necessário definir a codificação para UTF-8
    setlocale(LC_ALL, ".utf8");

    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " -f <arquivo>" << endl;
        return 1;
    }

    if (string(argv[1]) == "-h")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo>" << endl;
        cout << "Opções:" << endl;
        cout << "    -h : mostra o help" << endl;
        cout << "    -o <arquivo> : redireciona a saída para o ‘‘arquivo’’" << endl;
        cout << "    -f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada" << endl;
        return 0;
    }

    string filename = argv[2];

    Graph g = read_graph(filename);

    kosaraju(g);

    return 0;
}