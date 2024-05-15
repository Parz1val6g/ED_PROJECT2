#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./main.c"

typedef struct
{
    char *title, *author, *ISBN;
    int year;
} *BOOK_PTR, BOOK;

int addBook(const char *isbn, const char *author, const char *area, int year);
BOOK_PTR createBook();
void showBOOK(BOOK_PTR P);
void destroyBOOK(BOOK_PTR P);
int checkISBN(BOOK_PTR book1, BOOK_PTR book2);

#endif // BOOK_H
