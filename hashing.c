#include "./hashing.h"

GEN_LIST_PTR createList()
{
    GEN_LIST_PTR list = (GEN_LIST_PTR)myMALLOC(sizeof(GEN_LIST));
    if (list)
    {
        list->beginning = NULL;
        list->n_el = 0;
    }
    return list;
}

void addNodeStart(GEN_LIST_PTR L, void *data) // adicionar nó no inicio
{
    if (!L || !data)
        return;
    NODE_PTR node = (NODE_PTR)myMALLOC(sizeof(NODE));
    node->data = data;
    node->previous = NULL;
    node->next = L->beginning;
    L->beginning = node;
    L->n_el++;
}
void addNodePos(GEN_LIST_PTR L, void *data, int (*checkNodeValue)(void *, void *)) // adicionar no numa determinada posição
{
    NODE_PTR node = (NODE_PTR)myMALLOC(sizeof(struct node));
    node->data = data;
    NODE_PTR aux1;
    aux1 = L->beginning;
    while (checkNodeValue(aux1->data, data))
        aux1 = aux1->next;
    L->n_el++;
}
void addNodeEnd(GEN_LIST_PTR L, void *data) // adicionar nó no fim
{
    NODE_PTR node = (NODE_PTR)myMALLOC(sizeof(NODE));
    node->next = NULL;
    node->data = data;

    NODE_PTR aux1 = L->beginning, aux2 = NULL;
    if (!aux1)
        L->beginning = node;
    else
    {
        while (aux1->next)
            aux1 = aux1->next;
        aux1->next = node;
        node->previous = aux1;
    }
    L->n_el++;
}
