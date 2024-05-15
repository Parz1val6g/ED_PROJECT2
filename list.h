#ifndef LIST_H
#define LIST_H
#include "./main.h"

typedef struct node
{
    struct node *previous, *next;
    void *data;
} *NODE_PTR, NODE;
typedef struct gen_list
{
    int n_el;
    NODE_PTR beginning;
} *GEN_LIST_PTR, GEN_LIST;

GEN_LIST_PTR createList();

NODE_PTR searchNode(GEN_LIST_PTR L, void *data, NODE_PTR(checkNodeValue)(void *, void *));

void addNodeStart(GEN_LIST_PTR L, void *data);
void addNodePos(GEN_LIST_PTR L, void *data, int (*checkNodeValue)(void *, void *));
void addNodeEnd(GEN_LIST_PTR L, void *data);

void destroyNode(GEN_LIST_PTR L, NODE_PTR node, void (*destroyData)(void *));
void destroyList(GEN_LIST_PTR L, void (*destroyData)(void *));
#endif /* LIST_H */