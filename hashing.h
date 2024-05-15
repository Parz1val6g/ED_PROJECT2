#ifndef HASHING_H
#define HASHING_H

#include "./list.h"

#define MAX_FAIXAS_ETARIAS 10

typedef struct Grupo
{
    int ageRange;
    GEN_LIST_PTR peopleList;
} GROUP;

typedef struct Hashing
{
    GROUP ele[10];
} *HASHING_PTR, HASHING;

#endif // HASHING_H
