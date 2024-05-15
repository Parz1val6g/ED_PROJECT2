#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "./list.h"
#include "./book.h"
#include "./requests.h"
#include "./hashing.h"
#include "./library.h"
#include "./useful.h"
#include "./geo_entities.h"
#include "./requester.h"

GEN_LIST_PTR _districts;
GEN_LIST_PTR _counties;
GEN_LIST_PTR _parishes;
GEN_LIST_PTR _requesters;
LIBRARY_PTR _library;

char *FILES[] = {"distritos", "concelhos", "freguesias", "requesters", "books"};