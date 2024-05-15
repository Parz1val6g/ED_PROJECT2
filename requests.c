#include "./person.h"

void manageRequisitionsMenu()
{
    int option;

    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Listar requisitantes nascidos em Domingo                   |");
    printf("\n |     (ou cujo aniversario em um ano especifico eh um Domingo)   |");
    printf("\n | (2) Devolver um livro requisitado anteriormente                |");
    printf("\n | (3) Listar livros atualmente requisitados                      |");
    printf("\n |     (organizados por area)                                     |");
    printf("\n | (4) Salvar informacoes dos requisitantes                       |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 22); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

    do
    {
        switch (option)
        {
        case 1:
            // bornOnSunday();
            break;
        case 2:
            // returnBook();
            break;
        case 3:
            // listRequisitions();
            break;
        case 4:
            // saveRequisitions();
            break;
        }
    } while (option != 0);
}