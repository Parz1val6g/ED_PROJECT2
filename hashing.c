#include "./hashing.h"

HASH_NODE_PTR createHashNode()
{
    HASH_NODE_PTR hash_node = (HASH_NODE_PTR)myMALLOC(sizeof(HASH_NODE));
    if (hash_node)
    {
        hash_node->key = NULL;
        hash_node->list = createList();
        hash_node->next = NULL;
    }
    return hash_node;
}
GEN_GROUP_PTR createGroup()
{
    GEN_GROUP_PTR group = (GEN_GROUP_PTR)myMALLOC(sizeof(GEN_GROUP));
    if (group)
    {
        group->n_ele = 0;
        group->start = NULL;
    }
    return group;
}
GEN_HASH_PTR createHashing()
{
    GEN_HASH_PTR hash_table = (GEN_HASH_PTR)myMALLOC(sizeof(GEN_HASH));
    if (hash_table)
        hash_table->groups = createGroup();
    return hash_table;
}
GEN_GROUP_PTR searchGroup(char *key)
{
    HASH_NODE_PTR aux = books.groups.start;
    while (aux)
        if(strcmp(aux.key, key))
         aux = aux.next;
    return aux;
}