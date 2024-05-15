#include "./db_management.h"

char *filePath(char *file)
{
    char *file_path = (char *)myMALLOC(strlen("./database/") + strlen(file) + strlen(".txt") + 1);
    if (file_path)
        sprintf(file_path, "./database/%s.txt", file);
    return file_path;
}

GEN_LIST_PTR fetchData(const char *file_type)
{
    int type = 0;
    GEN_LIST_PTR list = NULL;
    char line[256], number[10];
    FILE *file = myFOPEN(filePath(file_type), "r+");
    if (file)
    {
        list = createList();
        while (fgets(line, sizeof(line), file) != NULL)
        {
            sscanf(line, "%s", number);
            type = strlen(number);
            switch (type)
            {
            case 2:
                addNodePos(list, getLineContent(line, type), checkDistrict);
                break;
            case 4:
                addNodePos(list, getLineContent(line, type), checkCounty);
                break;
            case 6:
                addNodePos(list, getLineContent(line, type), checkParish);
                break;
            case 9:
                addNodePos(list, getLineContent(line, type), checkRequester);
                break;
            default:
                return NULL;
            }
        }
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
    case 2: // DISTRITOS
        DISTRICT_PTR district = createDistrict();
        sscanf(line, "%2s %[^\n]", district->cod, district->name);
        return district;
    case 4: // CONCELHOS
        COUNTY_PTR county = createCounty();
        sscanf(line, "%4s %[^\n]", cod, county->name);
        strncpy(county->cod, cod + 2, 2);
        county->cod[2] = '\0';
        county->this_district = getDistrict(cod);
        return county;
    case 6: // FREGUESIAS
        PARISH_PTR parish = createParish();
        sscanf(line, "%6s %[^\n]", cod, parish->name);
        strncpy(parish->cod, cod + 4, 2);
        parish->cod[2] = '\0';
        parish->this_county = getCounty(cod);
        return parish;
    case 9: // REQUESITANTES
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
    default:
        error(("Error: Unknown data format in line '%s'\n", line));
        return NULL;
    }
}