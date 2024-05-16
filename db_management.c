#include "./db_management.h"

char *filePath(char *file)
{
    char *file_path = (char *)myMALLOC(strlen("./database/") + strlen(file) + strlen(".txt") + 1);
    if (file_path)
        sprintf(file_path, "./database/%s.txt", file);
    return file_path;
}

GEN_LIST_PTR fetchListsData(const char *file_type)
{
    GEN_LIST_PTR list = NULL;
    char line[256];
    FILE *file = myFOPEN(filePath(file_type), "r+");
    if (file)
    {
        list = createList();
        while (fgets(line, sizeof(line), file) != NULL)
            if (strcmp(file_type, FILES[0]))
                addNodePos(list, getLineContent(line, 1), checkDistrict);
            else if (strcmp(file_type, FILES[1]))
                addNodePos(list, getLineContent(line, 2), checkCounty);
            else if (strcmp(file_type, FILES[2]))
                addNodePos(list, getLineContent(line, 3), checkParish);
            else if (strcmp(file_type, FILES[3]))
                addNodePos(list, getLineContent(line, 4), checkRequester);
            else if (strcmp(file_type, FILES[4]))
                addNodePos(list, getLineContent(line, 5), checkRequester);
            else
                return NULL;
    }
    fclose(file);
    return list;
}
void storeDataGen(GEN_LIST_PTR L, char *type)
{
    NODE_PTR aux_node = L->beginning;
    FILE *file = myFOPEN(filePath(type), 'w');
    if (file)
        while (aux_node)
        {
            if (strcmp(type, "requesters"))
                fprintf(file, "%s\t%s\t%s\t%s\n", ((REQUESTER_PTR)aux_node->data)->id, ((REQUESTER_PTR)aux_node->data)->name, ((REQUESTER_PTR)aux_node->data)->birth_date, strcat(strcat(((DISTRICT_PTR)((COUNTY_PTR)((PARISH_PTR)((REQUESTER_PTR)aux_node->data)->this_parish->data)->this_county->data)->this_district)->cod, ((COUNTY_PTR)((PARISH_PTR)((REQUESTER_PTR)aux_node->data)->this_parish->data)->this_county->data)->cod), ((PARISH_PTR)((REQUESTER_PTR)aux_node->data)->this_parish->data)->cod));
            else if (strcmp(type, "books")) // NÃO FEITO
                fprintf(file, "%s\t%s\n", ((BOOK_PTR)aux_node->data), ((BOOK_PTR)aux_node->data));
            else if (strcmp(type, "library")) // NÃO FEITO
                fprintf(file, "%s\t%s\n", ((LIBRARY_PTR)aux_node->data), ((LIBRARY_PTR)aux_node->data));
            aux_node = aux_node->next;
        }
    fclose(file);
}
void *getLineContent(char *line, int type)
{
    char cod[9] = NULL;
    switch (type)
    {
    case 1: // DISTRITOS
        DISTRICT_PTR district = createDistrict();
        sscanf(line, "%2s %[^\n]", district->cod, district->name);
        return district;
    case 2: // CONCELHOS
        COUNTY_PTR county = createCounty();
        sscanf(line, "%4s %[^\n]", cod, county->name);
        strncpy(county->cod, cod + 2, 2);
        county->cod[2] = '\0';
        county->this_district = getDistrict(cod);
        return county;
    case 3: // FREGUESIAS
        PARISH_PTR parish = createParish();
        sscanf(line, "%6s %[^\n]", cod, parish->name);
        strncpy(parish->cod, cod + 4, 2);
        parish->cod[2] = '\0';
        parish->this_county = getCounty(cod);
        return parish;
    case 4: // REQUESITANTES
        REQUESTER_PTR requester = NULL;
        char *id = (char *)myMALLOC(sizeof(10)), *name = (char *)myMALLOC(sizeof(50)), *birth_date = (char *)myMALLOC(sizeof(11)), *cod = (char *)myMALLOC(sizeof(7));
        if (id && name && birth_date && cod)
        {
            if (sscanf(line, "%s %99[^0-9] %s %s", id, name, birth_date, cod) == 4)
                requester = createRequester(id, name, birth_date, cod);
            free(id);
            free(name);
            free(birth_date);
            free(cod);
        }
        return requester;
    case 5:
        BOOK_PTR book = createBook();
        sscanf(line, "%s %s %s %s %d", book->author, book->ISBN, book->title, book->year);
        return book;
    default:
        error(("Error: Unknown data format in line '%s'\n", line));
        return NULL;
    }
}
/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
LIBRARY_PTR fetchHashingData(const char *file_type)
{
    char line[256];
    FILE *file = myFOPEN(filePath(file_type), "r+");
    if (file)
    {
        LIBRARY_PTR _lib = createLibrary();
        while (fgets(line, sizeof(line), file) != NULL)
            addNodeHash(_lib, line);
    }
}

void addNodeHash(LIBRARY_PTR _lib, char *line)
{
    BOOK_PTR book = createBook();
    if (book)
    {
        char *_category = (char *)myMALLOC(sizeof(char) * 50);
        sscanf(line, "%s %s %s %s %d %s", book->author, book->ISBN, book->title, book->year, _category);
        LIBRARY_NODE_PTR aux = searchCategorie(_category);
        if (aux)
            addNodePos(aux->books_list, book, checkISBN);
        else
        {
            aux = createLibraryNode();
            if (aux)
            {
                addNodePos(aux->books_list, book, checkISBN);
                aux->key = _category;
                aux->next = NULL;
            }
            addHashNodePos(_lib->_groups, aux, _category);
        }
    }
}
