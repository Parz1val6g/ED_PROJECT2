#include "./main.h"

void manageRequisitantsMenu()
{
    int option;

    printf("\n | ---------------------REQUISICOES-------------------------------|");
    printf("\n | (1) Incluir novos requisitantes                                |");
    printf("\n | (2) Verificar se um requisitante existe (dando o seu nome)     |");
    printf("\n | (3) Listar todos os clientes (ordenados a escolha do utilizdor)|");
    printf("\n | (4) Determinar a idade maxima dos requisitantes                |");
    printf("\n | (5) Determinar a media das idades dos requisitantes            |");
    printf("\n | (6) Contar o numero de pessoas com idade superior a um valor   |");
    printf("\n | (7) Determinar a idade com mais requisitantes                  |");
    printf("\n | (8) Mostrar as requisicoes de um dado requisitante             |");
    printf("\n | (9) Mostrar pessoas que nunca requisitaram nada                |");
    printf("\n | (10) Listar requisitantes com livros requisitados              |");
    printf("\n | (11) Determinar o sobrenome mais comum dos requisitantes       |");
    printf("\n | (12) Determinar o numero de pessoas de um dado distrito        |");
    printf("\n | (13) Salvar informacoes das requisicoes                        |");
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
        case 1: // ADICIONAR A LISTA DE REQUISITANTES
            addNodePos(_requesters, addRequester(), checkRequester);
            break;
        case 2:
            // searchRequisitant();
            break;
        case 3:
            // listRequisitants(); por ordem alfabetica do nome, por ordem do campo | id_freguesia, por ordem alfabetica do apelido (considera-se apelido a ultima palavra do nome completo)
            break;
        case 4:
            // maxAge();
            break;
        case 5:
            // averageAge();
            break;
        case 6:
            // countAge();  (introduzido pelo teclado)
            break;
        case 7:
            // mostAge();
            break;
        case 8:
            // showRequisitions();
            break;
        case 9:
            // neverRequested();
            break;
        case 10:
            // requisitantsWithBooks();
            break;
        case 11:
            // mostUsedSurname();
            break;
        case 12:
            // countPeopleFromDistrict();  Distrito (ou Concelho)
            break;
        case 13:
            // saveRequisitions();
            break;
        }
    } while (option != 0);
}
REQUESTER_PTR createRequester(char *id, char *name, char *birth_date, char *loc_cod)
{
    if (!id || !name || !birth_date || !loc_cod)
        return NULL;
    int count = 0;
    for (; *id; id++)
        count += *id;
    if (strlen(id) != 9 || count % 10 != 0 || !isDate(birth_date) || strlen(loc_cod) != 6)
        return NULL;
    REQUESTER_PTR requester = (REQUESTER_PTR)myMALLOC(sizeof(REQUESTER));
    if (requester)
    {
        requester->id = id;
        requester->name = name;
        requester->birth_date = birth_date;
        requester->this_parish = getParish(loc_cod);
    }
    return requester;
}
REQUESTER_PTR addRequester()
{
    char *id = (char *)myMALLOC(10);
    char *name = (char *)myMALLOC(100);
    char *birth_date = (char *)myMALLOC(11);
    char *loc_cod = (char *)myMALLOC(7);
    printf("Insira o id do requerente: ");
    scanf(" %s", id);
    printf("Insira o nome do requerente: ");
    scanf(" %s", name);
    printf("Insira a data de nascimento do requerente: ");
    scanf(" %s", birth_date);
    printf("Insira o codigo da freguesia do requerente: ");
    scanf(" %s", loc_cod);
    REQUESTER_PTR requester = createRequester(id, name, birth_date, loc_cod);

    if (requester)
        return requester;
    printf("Dados invalidos, tente novamente!\n");

    free(id);
    free(name);
    free(birth_date);
    free(loc_cod);
}
// Função para verificar se um solicitante existe na lista pelo nome
int checkRequesterByName(char *name)
{
    NODE_PTR node = requester_list->beginning;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        if (strcmp(requester->name, name) == 0)
        {
            return 1; // Encontrou um solicitante com o nome fornecido
        }
        node = node->next;
    }
    return 0; // Nenhum solicitante com o nome fornecido foi encontrado
}

int checkRequester(REQUESTER_PTR aux1, REQUESTER_PTR aux2)
{
    return (int)(aux1->id) >= (int)(aux2->id);
}

// Função para calcular a idade a partir da data de nascimento
int calculateAge(char *birth_date)
{
    struct tm tm = {0};
    time_t curr_time;
    double seconds;

    strptime(birth_date, "%Y-%m-%d", &tm);
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1;
    seconds = difftime(time(&curr_time), mktime(&tm));

    return (int)(seconds / (60 * 60 * 24 * 365.25));
}

// Função para determinar a idade máxima de todos os solicitantes
int maxRequesterAge()
{
    NODE_PTR node = _requesters->beginning;
    int max_age = 0;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        int age = calculateAge(requester->birth_date);
        if (age > max_age)
        {
            max_age = age; // Encontrou um solicitante com uma idade maior
        }
        node = node->next;
    }
    return max_age; // Retorna a idade máxima encontrada
}

// Função para determinar a idade média de todos os solicitantes
double averageRequesterAge()
{
    NODE_PTR node = _requesters->beginning;
    int total_age = 0;
    int count = 0;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        int age = calculateAge(requester->birth_date);
        total_age += age;
        count++;
        node = node->next;
    }
    return (double)total_age / count; // Retorna a idade média
}

// Função para determinar a idade com o maior número de solicitantes
int mostCommonRequesterAge()
{
    NODE_PTR node = _requesters->beginning;
    int *age_counts = calloc(150, sizeof(int)); // Assume que ninguém tem mais de 150 anos
    int max_age_count = 0;
    int max_age = 0;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        int age = calculateAge(requester->birth_date);
        age_counts[age]++;
        if (age_counts[age] > max_age_count)
        {
            max_age_count = age_counts[age];
            max_age = age;
        }
        node = node->next;
    }
    free(age_counts);
    return max_age; // Retorna a idade com mais solicitantes
}

// Função para imprimir as solicitações de um solicitante específico
void printRequestsOfRequester(char *requester_name)
{
    NODE_PTR node = _requesters->beginning;
    while (node != NULL)
    {
        REQUESTER_PTR request = (REQUESTER_PTR)node->data;
        if (strcmp(request->name, requester_name) == 0)
        {
            printf("Request ID: %s, Request Date: %s\n", request->id, request->name);
        }
        node = node->next;
    }
}

// Função para imprimir todos os solicitantes
void printAllRequester()
{
    NODE_PTR node = _requesters->beginning;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        printf("Requester ID: %s, Name: %s, Birth Date: %s\n", requester->id, requester->name, requester->birth_date);
        node = node->next;
    }
}

// Função para contar o número de pessoas cuja idade é maior que um valor dado
int countPeopleOlderThan()
{
    int age_limit;
    printf("Escreva a idade limite : ");
    scanf("%d", &age_limit);

    NODE_PTR node = _requesters->beginning;
    int count = 0;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        int age = calculateAge(requester->birth_date);
        if (age > age_limit)
        {
            count++;
        }
        node = node->next;
    }
    return count; // Retorna a contagem de pessoas mais velhas que a idade dada
}

// Função para obter uma lista de pessoas que nunca fizeram uma solicitação
GEN_LIST_PTR getPeopleWhoNeverRequested()
{
    GEN_LIST_PTR never_requested_list = createList(); // Cria uma nova lista

    NODE_PTR node = _requesters->beginning;
    while (node != NULL)
    {
        REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
        // Verifica se o solicitante nunca fez uma solicitação
        // Se o solicitante nunca fez uma solicitação, adiciona-o à lista

        node = node->next;
    }

    return never_requested_list; // Retorna a lista de pessoas que nunca fizeram uma solicitação
}

// Função fictícia para criar uma lista (substitua isso pela sua implementação)
GEN_LIST_PTR createList()
{
    GEN_LIST_PTR list = (GEN_LIST_PTR)malloc(sizeof(GEN_LIST));
    list->beginning = NULL;
    return list;
}
