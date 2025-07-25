#ifndef DATA_OPERATIONS
#define DATA_OPERATIONS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "entities.h"

Table *create_table(const char *table_name, size_t field_count, FieldType *types);
void free_table(Table *table);
void insert_row(Table *table, Field *fields);
void print_row(Row *row,Table *table);
void print_table(Table *table);

#endif // DATA_OPERATIONS
