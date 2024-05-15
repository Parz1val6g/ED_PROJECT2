#ifndef USEFUL_H
#define USEFUL_H

#include "./main.h"

#define myMALLOC(size) ({void *ptr = malloc(size);if (!ptr){perror("Error: Memory allocation failed");return NULL;}ptr; })

#define myFOPEN(filename, mode) ({FILE *file = fopen(filename, mode);if (!file){perror("Error: Failed to open file");return NULL;}file; })

typedef struct timestamp
{
    int day, month, year, hour, minute, seconds;
} *TIMESTAMP_PTR, TIMESTAMP;

int random(int min, int max);
int factorial(int N);
int readInteger(char *txt);
int isDate(char *date);
int compare(char *val1, char *val2, int op);
TIMESTAMP_PTR setTimestamp();
void error(const char *message, ...);

#endif // USEFUL_H
