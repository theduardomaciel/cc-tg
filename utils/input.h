#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <iostream>
#include <memory>
#include <fstream>
#include <string>

#include <utils/graph.h>

using namespace std;

/**
 * @struct InputData
 * @brief Structure to hold input data.
 *
 * This structure holds various input parameters such as input and output file names,
 * a flag to indicate whether to return an answer, and the initial vertex for graph operations.
 *
 * @var InputData::in
 * Input file name.
 *
 * @var InputData::out
 * Output file name.
 *
 * @var InputData::return_answer
 * Flag to indicate whether to return an answer.
 *
 * @var InputData::initial
 * Initial vertex for graph operations.
 */
struct InputData
{
    string in = "";
    string out = "";
    bool return_answer = false;
    int initial = 1;
};

/**
 * @brief Parses command-line arguments.
 *
 * This function parses the command-line arguments provided to the program and extracts
 * the input parameters based on the specified argument list.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @param args_list The list of expected argument names.
 * @return InputData The parsed input data.
 */
InputData parse_input(int argc, char *argv[], const char *args_list[]);

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

#include "input.tpp"

#endif
