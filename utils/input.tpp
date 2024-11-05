#include "input.h"

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

template <typename GraphType>
unique_ptr<GraphType> read_graph(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    auto g = make_unique<GraphType>(n); // Inicializa o grafo com n vértices

    int u, v; // u = vértice de origem, v = vértice de destino
    for (int i = 0; i < m; i++)
    {
        file >> u >> v;
        g->add_edge(u, v); // Adiciona a aresta direcionada de u para v
    }

    file.close();
    return g;
}

template <typename GraphType>
unique_ptr<GraphType> read_weighted_graph(const string &filename)
{
    // cout << "Lendo grafo com pesos no arquivo " << filename << endl;
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int n, m; // n = número de vértices, m = número de arestas
    file >> n >> m;

    // cout << "O grafo tem " << n << " vértices e " << m << " arestas" << endl;

    auto g = make_unique<GraphType>(n); // Inicializa o grafo com n vértices

    int u, v, weight; // u = vértice de origem, v = vértice de destino, weight = peso da aresta
    for (int i = 0; i < m; i++)
    {
        // cout << "Lendo aresta " << i << endl;
        file >> u >> v >> weight;
        g->add_edge(u, v, weight); // Adiciona a aresta direcionada de u para v com peso weight
    }

    file.close();
    return g;
}