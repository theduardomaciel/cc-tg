#include <iostream>
#include <stack>
#include <vector>

#include "utils/input.h"
#include "./traversal/dfs.h"

using namespace std;

void kosaraju(KosarajuGraph &g)
{
    stack<int> aux_stack;

    cout << "Componentes fortemente conectados:" << endl;

    // Função "pos" para empilhar o vértice após a primeira DFS
    auto pos_fill_stack = [&aux_stack](int v)
    {
        aux_stack.push(v);
    };

    // Passo 1: Fazer DFS no grafo original para preencher a pilha
    dfs(g, g.adj_out, nullptr, pos_fill_stack);

    cout << "Ordem de visita dos vértices:" << endl;

    // Resetamos as marcações de pré-ordem (pre) para a segunda DFS
    fill(g.pre.begin(), g.pre.end(), -1);

    // Função "pre" para exibir componentes fortemente conectados
    auto pre_print_scc = [](int v)
    {
        cout << v << " ";
    };

    // Passo 2: Fazer DFS no grafo reverso (usando adj_in) para encontrar as componentes fortemente conexas
    while (!aux_stack.empty())
    {
        int v = aux_stack.top();
        aux_stack.pop();

        if (g.pre[v] == -1)
        {
            dfs_recursion(g, v, g.adj_in, pre_print_scc, nullptr); // Executa DFS no grafo reverso
            cout << endl;                                          // Finaliza o componente fortemente conectado
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
    auto kosaraku_graph = read_graph<KosarajuGraph>(filename);

    // Executa o algoritmo de Kosaraju
    kosaraju(*kosaraku_graph);

    return 0;
}
