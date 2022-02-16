#ifndef SYSCTRL_H
#define SYSCTRL_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct HashNode
{
    char value[50];
    struct HashNode  *Save_address;
    _Bool IsFull;
}Hash_map;


#define Hashmap_length   100

unsigned long time33(const char * key);
Hash_map *Hash_mapping(Hash_map *Hash_TABLE, char **DataBase, int DataBase_length);

#endif


