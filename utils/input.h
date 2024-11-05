#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <memory>
#include <fstream>
#include <string>

#include <utils/graph.h>
#include "input.tpp" // Inclui a implementação

using namespace std;

struct InputData
{
    string in = "";
    string out = "";
    bool return_answer = false;
    int initial_vertex = 1;
};

// args_list: lista de argumentos que o algoritmo aceita
InputData parse_input(int argc, char *argv[], const char *args_list[])
{
    InputData data;

    for (int i = 1; i < argc; i++)
    {
        if (string(argv[i]).compare("-h") == 0)
        {
            cout << "Help:" << endl;
            cout << "-h: mostra o help" << endl;
            cout << "-o <arquivo>: redireciona a saida para o 'arquivo'" << endl;
            cout << "-f <arquivo>: indica o 'arquivo' que contém o grafo de entrada" << endl;
            for (int j = 0; args_list[j] != NULL; j++)
            {
                if (string(args_list[j]).compare("-s") == 0)
                {
                    cout << "-s: retorna a resposta do algoritmo" << endl;
                }
                else if (string(args_list[j]).compare("-i") == 0)
                {
                    cout << "-i <vértice>: indica o 'vértice' inicial" << endl;
                }
            }
            return data;
        }

        // Verificamos os argumentos padrão
        if (string(argv[i]) == "-f")
        {
            data.in = argv[i + 1];
        }
        else if (string(argv[i]) == "-o")
        {
            data.out = argv[i + 1];
        }

        // Verificamos os argumentos específicos por algoritmo
        for (int j = 0; args_list[j] != NULL; j++)
        {
            if (string(argv[i]) == args_list[j])
            {
                if (string(argv[i]) == "-s")
                {
                    data.return_answer = true;
                }
                else if (string(argv[i]) == "-i")
                {
                    data.initial_vertex = stoi(argv[i + 1]);
                }
            }
        }
    }

    if (data.in == "")
    {
        cerr << "Erro: nenhum arquivo de entrada foi especificado" << endl;
        exit(1);
    }

    return data;
}

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

#endif
