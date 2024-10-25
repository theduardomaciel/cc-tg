#ifndef DFS_H
#define DFS_H

#include <functional>
#include <vector>
#include <stack>
#include "utils/graph.h"

/**
 * @brief Helper function for performing a depth-first search (DFS) on the given graph starting from the specified vertex.
 *
 * This function is called recursively to traverse the graph in a depth-first manner, visiting all vertices reachable from the starting vertex.
 *
 * @param g The graph to be traversed.
 * @param adj The adjacency list of the graph.
 * @param pre The function to be executed before visiting a vertex.
 * @param pos The function to be executed after visiting a vertex.
 */
void dfs(Graph &g, const vector<vector<int>> &adj, const function<void(int)> &pre, const function<void(int)> &pos);

/**
 * @brief Helper function for performing a depth-first search (DFS) on the given graph starting from the specified vertex.
 *
 * This function is called recursively to traverse the graph in a depth-first manner, visiting all vertices reachable from the starting vertex.
 *
 * @param g The graph to be traversed.
 * @param v The vertex to start the DFS from.
 * @param adj The adjacency list of the graph.
 * @param pre The function to be executed before visiting a vertex.
 * @param pos The function to be executed after visiting a vertex.
 */
void dfs_recursion(Graph &g, int v, const vector<vector<int>> &adj, const function<void(int)> &pre, const function<void(int)> &pos);

#endif
