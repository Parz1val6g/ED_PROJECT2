#ifndef HASHING_H
#define HASHING_H

#include "./main.h"

typedef struct Hash_list
{
    char *key;
    GEN_LIST_PTR list;
    struct Hash_node *next;
} *HASH_NODE_PTR, HASH_NODE;

typedef struct Group
{
    int n_ele;
    NODE_PTR first_group;
} *GEN_GROUP_PTR, GEN_GROUP;

typedef struct Hashing
{
    GEN_GROUP_PTR groups;
} *GEN_HASH_PTR, GEN_HASH;

GEN_HASH_PTR createHashing();
void destroyHashing();

GEN_GROUP_PTR createGroup();
GEN_GROUP_PTR addGroup();

GEN_GROUP_PTR searchGroup();

/*

HASHING *CriarHashing();
//--------------------------------------------------------
void DestruirHashing(HASHING *H);
//--------------------------------------------------------
void AddHashing(HASHING *H, PESSOA *P);
//--------------------------------------------------------
void ShowHashing(HASHING *H);
//--------------------------------------------------------
NO_CHAVE *FuncaoHashing(HASHING *H, PESSOA *X);

*/

void destroyGroup();

#endif // HASHING_H
