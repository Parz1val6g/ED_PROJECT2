#ifndef HASHING_H
#define HASHING_H

#include "./main.h"

typedef struct library_node
{
    char *key;
    GEN_LIST_PTR category;
    struct library_node *next;
} *LIBRARY_NODE_PTR, LIBRARY_NODE;

typedef struct groups
{
    int n_el;
    LIBRARY_NODE_PTR beginning;
} *GROUPS_PTR, GROUPS;

typedef struct library
{
    char *name;
    GROUPS_PTR _groups;
} *LIBRARY_PTR, LIBRARY;

LIBRARY_PTR createLibrary();
GROUPS_PTR createGroups();
GROUPS_PTR searchCategorie();
LIBRARY_NODE_PTR createLibraryNode();

void destroyHashing();

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
