#ifndef GEO_ENTITIES_H
#define GEO_ENTITIES_H

#include "./main.h"

typedef struct district
{
    char *cod, *name;
} *DISTRICT_PTR, DISTRICT;
typedef struct county
{
    NODE_PTR this_district;
    char *cod, *name;
} *COUNTY_PTR, COUNTY;
typedef struct parish
{
    NODE_PTR this_county;
    char *cod, *name;
} *PARISH_PTR, PARISH;

DISTRICT_PTR createDistrict();
COUNTY_PTR createCounty();
PARISH_PTR createParish();

NODE_PTR getDistrict(char *code);
NODE_PTR getCounty(char *code);
NODE_PTR getParish(char *code);

int checkDistrict(DISTRICT_PTR aux1, DISTRICT_PTR aux2);
int checkCounty(COUNTY_PTR aux1, COUNTY_PTR aux2);
int checkParish(PARISH_PTR aux1, PARISH_PTR aux2);

#endif // GEO_ENTITIES_H
