#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

#include "traversal/dfs.h"

using namespace std;

// Função para ler o grafo a partir de um arquivo
Graph read_graph(string filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    Graph g(n); // Inicializa o grafo com n vértices

    int v, w; // v = vértice de origem, w = vértice de destino
    for (int i = 0; i < m; i++)
    {
        file >> v >> w;
        g.add_edge(v, w); // Adiciona a aresta direcionada de v para w
    }

    file.close();
    return g;
}

void kosaraju(Graph &g)
{
    stack<int> Stack;

    // Passo 1: Fazer DFS no grafo original para preencher a pilha
    dfs(g, g.adj_out, &Stack);

    // Resetar as marcações de pré-ordem (pre) para a segunda DFS
    fill(g.pre.begin(), g.pre.end(), -1);

    // Passo 2: Fazer DFS no grafo transposto (usando adj_in) para encontrar SCCs
    while (!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();

        if (g.pre[v] == -1)
        {
            dfs_recursion(g, v, g.adj_in, nullptr); // Executa DFS no grafo transposto
            cout << endl;                           // Finaliza o componente fortemente conectado
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo>" << endl;
        return 1;
    }

    string filename = argv[2];
    Graph g = read_graph(filename);

    // Executa o algoritmo de Kosaraju
    kosaraju(g);

    return 0;
}
