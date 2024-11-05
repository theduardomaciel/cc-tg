#include <queue>
#include <limits>
#include "utils/input.h"
#include "utils/graph.h"

#include <union_find.cpp>

using namespace std;

void kruskal(WeightedGraph &g)
{
}

int main(int argc, char *argv[])
{
    if (argc < 2 || string(argv[1]) != "-f")
    {
        cout << "Uso: " << argv[0] << " -f <arquivo>" << endl;
        return 1;
    }

    string filename = argv[2];
    auto kruskal_graph = read_weighted_graph<WeightedGraph>(filename);

    kruskal(*kruskal_graph);

    return 0;
}
