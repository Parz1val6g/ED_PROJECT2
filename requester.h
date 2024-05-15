#ifndef REQUESTER_H
#define REQUESTER_H

#include "./geo_entities.h"
#include "./list.h"

typedef struct requester
{
    char *id, *name, *birth_date;
    NODE_PTR this_parish;
} *REQUESTER_PTR, REQUESTER;


REQUESTER_PTR createRequester(char *id, char *name, char *birth_date, char *loc_cod);
REQUESTER_PTR addRequester();
// void addNodeEndRequester(REQUESTER_PTR requester);
// int checkRequesterByName(char *name);
// int calculateAge(char *birth_date);
// int maxRequesterAge();
// double averageRequesterAge();
// int mostCommonRequesterAge();
// void printRequestsOfRequester(char *requester_name);
// int countPeopleOlderThan();
// void printAllRequester();
int checkRequester(REQUESTER_PTR aux1, REQUESTER_PTR aux2);

#endif // REQUESTER_H
