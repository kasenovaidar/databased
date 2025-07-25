#ifndef DB_TYPES
#define DB_TYPES

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Возможные типы полей */
typedef enum {
	FIELD_TYPE_INT,
	FIELD_TYPE_STRING
} FieldType;

typedef struct {
	union {
		int int_val;
		char *str_val;
	};
} Field;

/* Описание строки */
typedef struct Row Row;

struct Row {
	Field *fields;
	Row *next_row;
};

/* Описание таблицы */
typedef struct {
	char *name;

	size_t field_count;
	size_t row_count;

	FieldType *field_types;
	Row *first_row;
	Row *last_row;
} Table;

Table *create_table(const char *table_name, size_t field_count, FieldType *types);
void free_table(Table *table);
void insert_row(Table *table, Field *fields);
void print_row(Row *row,Table *table);
void print_table(Table *table);

#endif // DB_TYPES
