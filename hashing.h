#ifndef HASHING_H
#define HASHING_H

#include "./main.h"

typedef struct library_node
{
    char *key;
    GEN_LIST_PTR books_list;
    struct library_node *previous, *next;
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
LIBRARY_NODE_PTR createLibraryNode();

LIBRARY_NODE_PTR searchCategorie(char *key);

void addHashNodePos(GROUPS_PTR group, LIBRARY_NODE_PTR lib, char *category);

void destroyLibrary();

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
