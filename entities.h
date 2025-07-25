#ifndef ENTITIES
#define ENTITIES

#include <stddef.h>

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

#endif /* ENTITIES */
