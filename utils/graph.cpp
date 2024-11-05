#include "utils/graph.h"

void Graph::add_edge(int u, int v)
{
    adj_out[u].push_back(v);
}

void WeightedGraph::add_edge(int u, int v, int weight)
{
    adj_out[u].push_back({v, weight});
}