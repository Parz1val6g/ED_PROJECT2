#include "./book.h"

/*int checkBook(const char *isbn)
{
    for (int i = 0; i < num_books; ++i)
    {
        if (strcmp(books[i]->ISBN, isbn) == 0)
        {
            return 1;
        }
    }
    return 0;
}*/

int checkBook(BOOK_PTR book1, BOOK_PTR book2)
{
    return !strcmp(book1->ISBN, book2->ISBN);
}

int addBook(const char *isbn, const char *author, const char *area, int year)
{
    if (num_books >= MAX_BOOKS)
    {
        printf("Error: Maximum number of books reached.\n");
        return -1;
    }

    // Validate input data
    if (isbn == NULL || author == NULL || area == NULL || year <= 0)
    {
        printf("Error: Invalid input data.\n");
        return -1;
    }

    if (strlen(isbn) == 0)
    {
        printf("Error: ISBN cannot be empty.\n");
        return -1;
    }

    if (book_exists(isbn))
    {
        printf("Error: Book with ISBN %s already exists.\n", isbn);
        return -1;
    }

    BOOK *new_book = create_book(isbn, author, area, year);
    if (new_book == NULL)
    {
        printf("Error: Failed to create book.\n");
        return -1;
    }

    books[num_books++] = new_book;

    printf("Book added successfully.\n");

    return 0;
    /
}

BOOK_PTR createBook()
{
    BOOK_PTR book = (BOOK_PTR)myMALLOC(sizeof(BOOK));
    if (book)
    {
        book->author = NULL;
        book->ISBN = NULL;
        book->title = NULL;
        book->year = 0;
    }
    return book;
}

void showBook(BOOK *P)
{
    printf("\tBOOK: ISBN: %s Author: [%s] Area: [%s]\n", P->ISBN, P->author, P->area);
}

void destroyBook(BOOK *P)
{
    free(P->title);
    free(P->author);
    free(P->ISBN);
    free(P);
}
