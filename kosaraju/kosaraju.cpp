#include <iostream>
#include <stack>
#include <vector>

#include "utils/input.h"
#include "./source/traversal/dfs.h"

using namespace std;

void kosaraju(KosarajuGraph &g, ostream &output = cout)
{
    stack<int> aux_stack;

    // Função "pos" para empilhar o vértice após a primeira DFS
    auto pos_fill_stack = [&aux_stack](int v)
    {
        aux_stack.push(v);
    };

    // Passo 1: Fazer DFS no grafo original para preencher a pilha
    dfs(g, g.adj_out, nullptr, pos_fill_stack);

    // output << "Ordem de visita dos vértices:" << endl;

    // Resetamos as marcações de pré-ordem (pre) para a segunda DFS
    fill(g.pre.begin(), g.pre.end(), -1);

    // Função "pre" para exibir componentes fortemente conectados
    auto pre_print_scc = [&output](int v)
    {
        output << v << " ";
    };

    // Passo 2: Fazer DFS no grafo reverso (usando adj_in) para encontrar as componentes fortemente conexas
    while (!aux_stack.empty())
    {
        int v = aux_stack.top();
        aux_stack.pop();

        if (g.pre[v] == -1)
        {
            dfs_recursion(g, v, g.adj_in, pre_print_scc, nullptr); // Executa DFS no grafo reverso
            output << endl;                                        // Finaliza o componente fortemente conectado
        }
    }
}

int main(int argc, char *argv[])
{
    InputData input = parse_input(argc, argv, NULL);

    // Lê o grafo do arquivo de entrada
    auto kosaraku_graph = read_graph<KosarajuGraph>(input.in);

    // Verifica se há redirecionamento de saída
    ostream *output_stream = &cout;
    ofstream out_file;
    if (!input.out.empty())
    {
        out_file.open(input.out);
        if (out_file.is_open())
        {
            output_stream = &out_file;
        }
        else
        {
            cerr << "Erro ao abrir o arquivo de saída: " << input.out << endl;
            exit(1);
        }
    }

    // Executa o algoritmo de Kosaraju
    kosaraju(*kosaraku_graph, *output_stream);

    return 0;
}
