#include "./geo_entities.h"

DISTRICT_PTR createDistrict()
{
    DISTRICT_PTR district = (DISTRICT_PTR)myMALLOC(sizeof(DISTRICT));
    if (district)
    {
        district->cod = (char *)myMALLOC(sizeof(char) * 3);
        district->name = NULL;
    }
    return district;
}
COUNTY_PTR createCounty()
{
    COUNTY_PTR county = (COUNTY_PTR)myMALLOC(sizeof(COUNTY));
    if (county)
    {
        county->this_district = NULL;
        county->cod = (char *)myMALLOC(sizeof(char) * 3);
        if (!(county->cod))
            return NULL;
        county->name = NULL;
    }
    return county;
}
PARISH_PTR createParish()
{
    PARISH_PTR parish = (PARISH_PTR)myMALLOC(sizeof(PARISH));
    if (parish)
    {
        parish->this_county = NULL;
        parish->cod = (char *)myMALLOC(sizeof(char) * 3);
        if (!(parish->cod))
            return NULL;
        parish->name = NULL;
    }
    return parish;
}

NODE_PTR getDistrict(char *code)
{
    NODE_PTR aux = districts->beginning;
    while (aux != NULL)
    {
        if (!strncmp(((DISTRICT_PTR)(aux->data))->cod, code, 2))
            return aux;
        aux = aux->next;
    }
    return NULL;
}
NODE_PTR getCounty(char *code)
{
    NODE_PTR aux = counties->beginning;
    while (aux)
    {
        char county_full_code[5];
        strncpy(county_full_code, ((DISTRICT_PTR)(((COUNTY_PTR)(aux->data))->this_district->data))->cod, 2);
        strncpy(county_full_code + 2, ((COUNTY_PTR)(aux->data))->cod, 2);
        county_full_code[4] = '\0';
        if (!strncmp(county_full_code, code, 4))
            return aux;
        aux = aux->next;
    }
    return NULL;
}
NODE_PTR getParish(char *code)
{
    NODE_PTR aux = parishes->beginning;
    while (aux)
    {
        char parish_full_code[7];
        strncpy(parish_full_code, ((DISTRICT_PTR)((COUNTY_PTR)(((PARISH_PTR)(aux->data))->this_county->data))->this_district->data)->cod, 2);
        strncpy(parish_full_code + 2, ((COUNTY_PTR)(((PARISH_PTR)(aux->data))->this_county->data))->cod, 2);
        strncpy(parish_full_code + 4, ((PARISH_PTR)(aux->data))->cod, 2);
        parish_full_code[6] = '\0';
        if (!strncmp(parish_full_code, code, 6))
            return aux;
        aux = aux->next;
    }
    return NULL;
}

int checkDistrict(DISTRICT_PTR aux1, DISTRICT_PTR aux2)
{
    return (int)(aux1->cod) >= (int)(aux1->cod);
}
int checkCounty(COUNTY_PTR aux1, COUNTY_PTR aux2)
{
    return (int)(aux1->cod) >= (int)(aux1->cod);
}
int checkParish(PARISH_PTR aux1, PARISH_PTR aux2)
{
    return (int)(aux1->cod) >= (int)(aux1->cod);
}
