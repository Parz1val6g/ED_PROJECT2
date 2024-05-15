#include "./useful.h"

int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}
int factorial(int N)
{
    if (N == 0)
        return 1;
    return N * Factorial(N - 1);
}
int readInteger(char *txt)
{
    int x;
    printf("%s : ", txt);
    scanf("%d", &x);
    return x;
}
int isDate(char *date)
{
    return !strcmp(*(date + 2), '-') && !strcmp(*(date + 5), '-');
}
int compare(char *val1, char *val2, int op)
{
    switch (op)
    {
    case -1:
        return (int)(val1) <= (int)(val2);
    case 0:
        return (int)(val1) == (int)(val2);
    case 1:
        return (int)(val1) >= (int)(val2);
    default:
        break;
    }
}
TIMESTAMP_PTR setTimestamp()
{
    time_t now;
    time(&now);
    struct tm *tm1 = localtime(&now);

    TIMESTAMP_PTR var = (TIMESTAMP_PTR)myMALLOC(sizeof(TIMESTAMP));
    if (var)
    {
        var->day = tm1->tm_mday;
        var->month = tm1->tm_mon + 1;
        var->year = tm1->tm_year + 1900;
        var->hour = tm1->tm_hour;
        var->minute = tm1->tm_min;
        var->seconds = tm1->tm_sec;
    }

    return var;
}
void error(const char *message, ...)
{
    if (!message)
        return;
        
    TIMESTAMP_PTR actual_time = setTimestamp();

    FILE *file = myFOPEN("./logs.txt", "a");

    va_list args;
    va_start(args, message);
    int required_size = vsnprintf(NULL, 0, message, args);
    va_end(args);

    if (required_size >= 0)

        char *string = (char *)myMALLOC((required_size + 1) * sizeof(char));

    va_start(args, message);
    vsprintf(string, message, args);
    va_end(args);

    fwrite(string, sizeof(char), strlen(string), file);

    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);

    fclose(file);
    free(string);
    free(actual_time);
}