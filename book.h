#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[40], author[30], area[20];
    char *ISBN;
    int year;
} *BOOK_PTR, BOOK;

int addBook(const char *isbn, const char *author, const char *area, int year);
BOOK_PTR createBook(char *_isbn, char *_author, char *_area, int year);
void showBOOK(BOOK_PTR P);
void destroyBOOK(BOOK_PTR P);

#endif // BOOK_H
