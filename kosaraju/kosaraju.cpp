#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "traversal/dfs.h" // Inclui o algoritmo de DFS

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

// Realiza uma DFS normal no grafo e preenche a pilha com a ordem de término
void fill_order(Graph &g, int v, vector<bool> &visited, stack<int> &Stack)
{
    visited[v] = true; // Marca o vértice atual como visitado

    // Visita todos os vizinhos de saída (adj+)
    for (int w : g.get_adj_out(v))
    {
        if (!visited[w])
        {
            fill_order(g, w, visited, Stack);
        }
    }

    // Após visitar todos os vizinhos, empilha o vértice (pós-ordem)
    Stack.push(v);
}

// Realiza uma DFS na direção inversa (usando adj-)
void dfs_scc(Graph &g, int v, vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " "; // Exibe ou armazena os vértices da SCC

    // Visita todos os vizinhos de entrada (adj-)
    for (int w : g.get_adj_in(v))
    {
        if (!visited[w])
        {
            dfs_scc(g, w, visited);
        }
    }
}

void kosaraju(Graph &g)
{
    stack<int> Stack;
    int n = g.vertices_amount();
    vector<bool> visited(n, false);

    // Passo 1: Realiza uma DFS no grafo original (usando adj_out) e preenche a pilha com a ordem de finalização
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            fill_order(g, i, visited, Stack);
        }
    }

    // Reseta o vetor de visitados para a segunda DFS
    fill(visited.begin(), visited.end(), false);

    // Passo 2: Realiza uma DFS no grafo transposto (usando adj_in), na ordem inversa da pilha
    while (!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();

        // Se o vértice ainda não foi visitado, é uma nova SCC
        if (!visited[v])
        {
            cout << "SCC: ";
            dfs_scc(g, v, visited); // Chama a DFS no grafo transposto a partir do vértice v
            cout << endl;
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
