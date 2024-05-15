#include "./main.h"
GEN_LIST_PTR _districts;
GEN_LIST_PTR _counties;
GEN_LIST_PTR _parishes;
GEN_LIST_PTR _requesters;
LIBRARY_PTR _library;
int menu()
{

    int option;
    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Gerir os livros                                            |");
    printf("\n | (2) Gerir a lista de requisitantes                             |");
    printf("\n | (3) Gerir as requisicoes de livros                             |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 22); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!
    return option;
}

int main()
{
    int option, sub_option;

    _districts = fetchListsData(FILES[0]);
    _counties = fetchListsData(FILES[1]);
    _parishes = fetchListsData(FILES[2]);
    _requesters = fetchListsData(FILES[3]);
    _library = fetchHashingData(FILES[4]);

    do
    {
        option = menu();
        system("cls");
        switch (option)
        {
        case 1:
            manageBooksMenu();

            break;
        case 2:
            manageRequisitantsMenu();

            break;
        case 3:
            manageRequisitionsMenu();

            break;
        case 0: // sair
            // Salvar dados antes de terminar o programa
            printf("\n\n ***** Salvando os dados *****\n");
            printf(" ***** Saindo do programa *****\n");
            break;
        }
    } while (option != 0);

    return 0;
}
