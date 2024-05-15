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

void booksMenu()
{
    int option;

    printf("\n #-------------------------------------------------------------#");
    printf("\n | (1) Adicionar livros a biblioteca                           |");
    printf("\n | (2) Listar todos os livros por area                         |");
    printf("\n | (3) Verificar a area com mais livros                        |");
    printf("\n | (4) Verificar se um livro existe pelo ISBN                  |");
    printf("\n | (5) Encontrar os livros mais recentes                       |");
    printf("\n | (6) Encontrar o livro mais requisitado                      |");
    printf("\n | (7) Determinar a area mais requisitada                      |");
    printf("\n | (8) Salvar informacoes do livro                             |");
    printf("\n | (0) SAIR                                                    |");
    printf("\n #-------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 7); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

    do
    {
        switch (option)
        {
        case 1:
            // addBook();
            break;
        case 2:
            // listBooks();
            break;
        case 3:
            // areaWithMostBooks();
            break;
        case 4:
            // searchBook(); se existir deve mostrar os seus dados
            break;
        case 5:
            // mostRecentBooks(); o que tiver o ano mais recente!
            break;
        case 6:
            // mostRequestedBook(); Se existir mais  do que um, deve devolver o primeiro encontrado)
            break;
        case 7:
            // mostRequestedArea(); Se existir mais    tdo que uma, deve devolver a primeira encontrada)
            break;
        case 8:
            // saveBooks();
            break;
        }
    } while (option != 0);
}

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
