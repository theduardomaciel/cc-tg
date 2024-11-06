#include "utils/graph.h"

// Para um melhor panorama geral, segue a relação de uso da estrutura de grafos pelos algoritmos:
/*
    | Algoritmo      | Tipo de Grafo    | Ponderado |
    |----------------|------------------|------|
    | Kosaraju       | Direcionado      | Não  |
    | Dijkstra       | Ambos            | Sim  |
    | Bellman-Ford   | Ambos            | Sim  |
    | Prim           | Não Direcionado  | Sim  |
    | Kruskal        | Não Direcionado  | Sim  |

    Como um não direcionado é basicamente um direcionado com arestas de volta,
    algoritmos que suportam grafos direcionados também suportam grafos não direcionados.
    Mas cuidado, o mesmo não se aplica ao contrário. (ex.: Prim e Kruskal)

    Tendo em vista que todos os algoritmos de grafos ponderados suportam grafos não direcionados,
    a variável "is_directed" foi definida como "false" por padrão em grafos ponderados.

    Seguindo a mesma lógica, como o algoritmo de Kosaraju é o único não ponderado,
    a variável "is_directed" foi definida como "true" por padrão em grafos não ponderados.
*/

void Graph::add_edge(int u, int v)
{
    adj_out[u].push_back(v);
    if (!is_directed)
        adj_out[v].push_back(u);
}

void WeightedGraph::add_edge(int u, int v, int weight)
{
    adj_out[u].push_back({v, weight});
    if (!is_directed)
        adj_out[v].push_back({u, weight});
}

/*
    Exemplo de uma abordagem mais genérica para adicionar arestas diretas e não-direcionadas

    // Função para adicionar arestas direcionadas
    void add_directed_edge(int u, int v) {
        adj_out[u].push_back(v); // Adiciona v na lista de saída de u
        adj_in[v].push_back(u);   // Adiciona u na lista de entrada de v
    }

    // Função para adicionar arestas não-direcionadas
    void add_undirected_edge(int u, int v) {
        add_directed_edge(u, v);
        add_directed_edge(v, u);
    }
*/