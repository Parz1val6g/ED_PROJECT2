#include "./book.h"
#include "./list.h"


int book_exists(const char *isbn) {
    for (int i = 0; i < num_books; ++i) {
        if (strcmp(books[i]->ISBN, isbn) == 0) {
            return 1; 
        }
    }
    return 0; 
}


int addBook(const char *isbn, const char *author, const char *area, int year) {
    if (num_books >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return -1; 
    }

    // Validate input data
    if (isbn == NULL || author == NULL || area == NULL || year <= 0) {
        printf("Error: Invalid input data.\n");
        return -1; 
    }


    if (strlen(isbn) == 0) {
        printf("Error: ISBN cannot be empty.\n");
        return -1; 
    }

    
    if (book_exists(isbn)) {
        printf("Error: Book with ISBN %s already exists.\n", isbn);
        return -1; 
    }

    
    BOOK *new_book = create_book(isbn, author, area, year);
    if (new_book == NULL) {
        printf("Error: Failed to create book.\n");
        return -1; 
    }

    
    books[num_books++] = new_book;

    printf("Book added successfully.\n");

    return 0; /
}

BOOK *createBook(char *_isbn, char *_author, char *_area,int year)
{
    //acho q falta igualar o ultimo caracter a \0
    BOOK *P = (BOOK *)malloc(sizeof(BOOK));
    P->title = (char *)malloc((strlen(_isbn) + 1) * sizeof(char));
    strcpy(P->title, _isbn);
    P->author = (char *)malloc((strlen(_author) + 1) * sizeof(char));
    strcpy(P->author, _author);
    P->area = (char *)malloc((strlen(_area) + 1) * sizeof(char));
    strcpy(P->area, _area);
    P->year = year;
    return P;
}

void showBook(BOOK *P)
{
    printf("\tBOOK: ISBN: %s Author: [%s] Area: [%s]\n", P->ISBN, P->author, P->area);
}


void destroyBook(BOOK *P)
{
    free(P->title);
    free(P->author);
    free(P->area);
    free(P->ISBN);
    free(P);
}
