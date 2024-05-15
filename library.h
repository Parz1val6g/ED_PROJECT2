#ifndef LIBRARY_H
#define LIBRARY_H

#include "./main.h"

typedef struct Library
{
    char *name;
    GEN_HASH_PTR library;
} *LIBRARY_PTR, LIBRARY;

LIBRARY_PTR createLibrary(char *_name, char *_logs);
void showLibrary(LIBRARY_PTR L);
void destroyLibrary(LIBRARY_PTR L);
int loadFileLibrary(LIBRARY_PTR L);
int addBookLibrary(LIBRARY_PTR L, BOOK_PTR B);
int removeBookLibrary(LIBRARY_PTR L, int isbn);
BOOK_PTR mostRequestedBookLibrary(LIBRARY_PTR L);
char *mostCommonNickname(LIBRARY_PTR L);
char *mostCommonArea(LIBRARY_PTR L);
int addBorrower(LIBRARY_PTR L, PERSON_PTR X);
PERSON_PTR searchBorrower(LIBRARY_PTR L, int code);

#endif // LIBRARY_H
