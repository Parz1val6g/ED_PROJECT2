#ifndef REQUESTS_H
#define REQUESTS_H

#include "./main.h"

typedef struct Person
{
    char name[20], address[100], mail[50];
    int age, phone;
} *PERSON_PTR, PERSON;

#endif // PERSON_H
