#include <iostream>

using namespace std;

// DisjointSet (ou Union-Find Algorithm) é uma estrutura de dados que mantém conjuntos disjuntos de elementos
class DisjointSet
{
    int *rank, *parent, n;

public:
    // Construtor para criar e iniciar um dado conjunto de n elementos
    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        make_set();
    }

    // Cria n conjuntos unitários
    void make_set()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Encontra (Find) o conjunto de um elemento x
    int find(int x)
    {
        // Encontra o representante do conjunto do qual x é um elemento
        if (parent[x] != x)
        {
            // Se x não é o próprio pai, então não é o representante de seu conjunto
            // então, recursivamente chamamos Find em seu pai
            // e movemos o nó i diretamente sob o representante deste conjunto
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    // Realiza a união de dois conjuntos representados por x e y
    void Union(int x, int y)
    {
        // Encontra os conjuntos atuais de x e y
        int xset = find(x);
        int yset = find(y);

        // Se eles já estão no mesmo conjunto, não há nada a fazer
        if (xset == yset)
            return;

        // Colocamos o item de rank menor sob o item de
        // rank maior se os ranks forem diferentes
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        // Se os ranks são iguais, então incrementamos a rank
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

/*
    Complexidade de tempo: O(n) para criar n conjuntos de itens únicos.
*/

/* int main()
{
    DisjointSet obj(5);

    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);

    // No fim, temos os seguintes conjuntos:
    // {0, 2, 4} e {1, 3}

    // Testando se 0 e 4 estão no mesmo conjunto
    if (obj.find(4) == obj.find(0))
        cout << "Sim" << endl;
    else
        cout << "Não" << endl;

    // Testando se 1 e 0 estão no mesmo conjunto
    if (obj.find(1) == obj.find(0))
        cout << "Sim" << endl;
    else
        cout << "Não" << endl;

    return 0;
} */
