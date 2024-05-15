#include "./main.h"

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
    while (1)
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
}


// Function to check if a requester exists in the list by name
// int checkRequesterByName(char *name) {
//     NODE_PTR node = requester_list->beginning;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//         if (strcmp(requester->name, name) == 0) {
//             return 1; // Found a requester with the given name
//         }
//         node = node->next;
//     }
//     return 0; // No requester with the given name was found
// }

int checkRequester(REQUESTER_PTR aux1, REQUESTER_PTR aux2)
{
    return (int)(aux1->id) >= (int)(aux2->id);
}

// Function to calculate the age from a birth date
// int calculateAge(char *birth_date) {
//     struct tm tm;
//     time_t curr_time;
//     double seconds;

//     strptime(birth_date, "%Y-%m-%d", &tm);
//     tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0; tm.tm_isdst = -1;
//     seconds = difftime(time(&curr_time), mktime(&tm));

//     return (int)seconds / (60 * 60 * 24 * 365.25);
// }

// // Function to determine the maximum age of all requesters
// int maxRequesterAge() {
//     NODE_PTR node = requester_list->beginning;
//     int max_age = 0;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//         int age = calculateAge(requester->birth_date);
//         if (age > max_age) {
//             max_age = age; // Found a requester with a higher age
//         }
//         node = node->next;
//     }
//     return max_age; // Return the maximum age found
// }

// // Function to determine the average age of all requesters
// double averageRequesterAge() {
//     NODE_PTR node = requester_list->beginning;
//     int total_age = 0;
//     int count = 0;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//         int age = calculateAge(requester->birth_date);
//         total_age += age;
//         count++;
//         node = node->next;
//     }
//     return (double)total_age / count; // Return the average age
// }

// // Function to determine the age with the most requesters
// int mostCommonRequesterAge() {
//     NODE_PTR node = requester_list->beginning;
//     int *age_counts = calloc(150, sizeof(int)); // Assume no one is older than 150
//     int max_age_count = 0;
//     int max_age = 0;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//         int age = calculateAge(requester->birth_date);
//         age_counts[age]++;
//         if (age_counts[age] > max_age_count) {
//             max_age_count = age_counts[age];
//             max_age = age;
//         }
//         node = node->next;
//     }
//     free(age_counts);
//     return max_age; // Return the age with the most requesters
// }

// // Function to print the requests of a given requester
// void printRequestsOfRequester(char *requester_name) {
//     NODE_PTR node = requester_list->beginning;
//     while (node != NULL) {
//         REQUESTER_PTR request = (REQUESTER_PTR)node->data;
//         if (strcmp(request->name, requester_name) == 0) {
//             printf("Request ID: %s, Request Date: %s\n", request->id, request->name);
//         }
//         node = node->next;
//     }
// }

// void printAllRequester() {
//     NODE_PTR node = requester_list->beginning;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//         printf("Requester ID: %s, Name: %s, Birth Date: %s\n", requester->id, requester->name, requester->birth_date);
//         node = node->next;
//     }
// }

// // Function to count the number of people whose age is greater than a given value
// int countPeopleOlderThan() {
//     int age_limit;
//     printf("Escreva a idade limite : ");
//     scanf("%d", &age_limit);

//     NODE_PTR node = requester_list->beginning;
//     int count = 0;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//         int age = calculateAge(requester->birth_date);
//         if (age > age_limit) {
//             count++;
//         }
//         node = node->next;
//     }
//     return count; // Return the count of people older than the given age
// }

// // Function to get a list of people who have never made a request
// GEN_LIST_PTR getPeopleWhoNeverRequested() {
//     GEN_LIST_PTR never_requested_list = createList(); // Create a new list

//     NODE_PTR node = requester_list->beginning;
//     while (node != NULL) {
//         REQUESTER_PTR requester = (REQUESTER_PTR)node->data;
//             // Check if the requester has never made a request
//             // If the requester has never made a request, add them to the list

//         node = node->next;
//     }

//     //return never_requested_list; // Return the list of people who have never made a request
//     return NULL;
// }-