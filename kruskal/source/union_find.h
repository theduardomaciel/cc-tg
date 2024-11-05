#ifndef UNION_FIND_H
#define UNION_FIND_H

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
    void make_set();

    // Encontra (Find) o conjunto de um elemento x
    // A "heurística da compressão de caminhos" está aplicada
    int find(int x);

    // Realiza a união de dois conjuntos representados por x e y
    // A "heurística dos tamanhos" está aplicada
    void Union(int x, int y);
};

#endif