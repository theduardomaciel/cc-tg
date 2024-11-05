#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <memory>
#include <fstream>
#include <string>

#include <utils/graph.h>

using namespace std;

/**
 * @brief Reads a graph from a file.
 *
 * This function reads a graph from the specified file and returns it as a Graph object.
 * The file should be formatted in a way that the function can parse and construct the graph.
 *
 * @param filename The path to the file containing the graph data.
 * @return Graph The graph object constructed from the file data.
 */
template <typename GraphType>
unique_ptr<GraphType> read_graph(const string &filename);

/**
 * @brief Reads a weighted graph from a file.
 *
 * This function reads a weighted graph from the specified file and returns it as a Graph object.
 * The file should contain the graph data in a specific format that this function can parse.
 *
 * @param filename The path to the file containing the graph data.
 * @return Graph The graph object constructed from the file data.
 */
template <typename GraphType>
unique_ptr<GraphType> read_weighted_graph(const string &filename);

/**
 * @brief Reads a generic graph from a file.
 *
 * This function reads a generic graph from the specified file and returns it as a Graph object.
 * The file should contain the graph data in a specific format that this function can parse.
 *
 * @param filename The path to the file containing the graph data.
 * @return Graph The graph object constructed from the file data.
 */
/* template <typename GraphType>
GraphType read_generic_graph(string filename); */

#include "input.tpp" // Inclua a implementação aqui

#endif
