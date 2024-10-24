#ifndef DFS_H
#define DFS_H

#include <vector>
#include "utils/graph.h"

/**
 * @brief Helper function for performing a depth-first search (DFS) on the given graph starting from the specified vertex.
 *
 * This function is called recursively to traverse the graph in a depth-first manner, visiting all vertices reachable from the starting vertex.
 *
 * @param g The graph to be traversed.
 * @param v The starting vertex for the DFS traversal.
 * @param visited A boolean array that keeps track of visited nodes.
 * @param adj The adjacency list to be used (either adj_out or adj_in).
 * @param Stack A stack to store vertices by their finishing order (for Kosaraju's algorithm).
 */
void dfs_general(Graph &g, int v, vector<bool> &visited, const vector<vector<int>> &adj, stack<int> *Stack = nullptr);

/**
 * @brief Performs a depth-first search (DFS) for Kosaraju's algorithm.
 *
 * This function initiates a DFS traversal on a graph using the provided adjacency list.
 *
 * @param g The graph object on which DFS is to be performed.
 * @param adj The adjacency list to use for traversal (either adj_out or adj_in).
 * @param visited A boolean array indicating whether a node has been visited.
 * @param Stack (Optional) Stack to store the order of completion of each vertex.
 */
void dfs(Graph &g, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> *Stack = nullptr);

#endif
