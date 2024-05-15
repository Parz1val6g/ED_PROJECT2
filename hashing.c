#include "./hashing.h"

LIBRARY_PTR createLibrary()
{
    LIBRARY_PTR library = (LIBRARY_PTR)myMALLOC(sizeof(LIBRARY));
    if (library)
    {
        library->name = NULL;
        library->_groups = NULL;
    }
    return library;
}
GROUPS_PTR createGroups()
{
    GROUPS_PTR groups = (GROUPS_PTR)myMALLOC(sizeof(GROUPS));
    if (groups)
    {
        groups->n_el = 0;
        groups->beginning = NULL;
    }
    return groups;
}
LIBRARY_NODE_PTR createLibraryNode(char *category, BOOK_PTR book)
{
    LIBRARY_NODE_PTR lib_node = (LIBRARY_NODE_PTR)myMALLOC(sizeof(LIBRARY_NODE));
    if (lib_node)
    {
        lib_node->key = NULL;
        lib_node->category = createList();
        lib_node->next = NULL;
    }
    return lib_node;
}
void addLibraryNodeEnd(GROUPS_PTR L, LIBRARY_NODE_PTR *category) // adicionar nó no fim
{
    LIBRARY_NODE_PTR node = (LIBRARY_NODE_PTR)myMALLOC(sizeof(LIBRARY_NODE));
    

    LIBRARY_NODE_PTR aux1 = L->beginning, aux2 = NULL;
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
LIBRARY_NODE_PTR searchCategorie(char *key)
{
    LIBRARY_NODE_PTR aux = _library->_groups->beginning;
    while (aux)
        if (strcmp(aux.key, key))
            aux = aux.next;
    return aux;
}