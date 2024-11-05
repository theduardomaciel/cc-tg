#include "union_find.h"

// Cria n conjuntos unitários
void DisjointSet::make_set()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Encontra (Find) o conjunto de um elemento x
// A "heurística da compressão de caminhos" está aplicada
int DisjointSet::find(int x)
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
// A "heurística dos tamanhos" está aplicada
void DisjointSet::Union(int x, int y)
{
    // Encontra os conjuntos atuais de x e y
    int xset = find(x);
    int yset = find(y);

    // Se eles já estão no mesmo conjunto, não há nada a fazer
    if (xset == yset)
        return;

    // Se os conjuntos são diferentes, então fazemos a união
    if (rank[xset] >= rank[yset])
    {
        parent[yset] = xset;

        // Se os ranks são iguais, então incrementamos a rank
        if (rank[xset] == rank[yset])
            rank[xset]++;
    }
    else
    {
        parent[xset] = yset;
    }
}