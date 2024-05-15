#ifndef DB_MANAGEMENT_H
#define DB_MANAGEMENT_H

#include "./main.h"

GEN_LIST_PTR fetchData(const char *file_name);
void *getLineContent(char *line, int type);
void storeDataGen(GEN_LIST_PTR L, char *type);

#endif // DB_MANAGEMENT_H
