#ifndef DFS_H
#define DFS_H

#include <vector>
#include <stack>
#include "utils/graph.h"

/**
 * @brief Helper function for performing a depth-first search (DFS) on the given graph starting from the specified vertex.
 *
 * This function is called recursively to traverse the graph in a depth-first manner, visiting all vertices reachable from the starting vertex.
 *
 * @param g The graph to be traversed.
 * @param v The starting vertex for the DFS traversal.
 * @param adj The adjacency list to be used (either adj_out or adj_in).
 */
void dfs(Graph &g, const vector<vector<int>> &adj, stack<int> *Stack = nullptr);

void dfs_recursion(Graph &g, int v, const vector<vector<int>> &adj, stack<int> *Stack = nullptr);

#endif
