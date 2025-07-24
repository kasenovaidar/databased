#ifndef ENTITIES
#define ENTITIES

#include <stdlib.h>

/* Возможные типы полей */
typedef enum {
	FIELD_TYPE_INT,
	FIELD_TYPE_STRING
} FieldType;

/* Описание поля */
typedef struct {
	FieldType type;
	char name[64];
	size_t max_length; /* ограничение для строк */
} FieldDef;

/* Описание строки */
typedef struct {
	void **values; /* указатель на массив с данными */
} Row;

/* Описание таблицы */
typedef struct {
	FieldDef *fields; /* Схема */
	size_t field_count;
	Row *rows;
	size_t row_count;
} Table;

#endif /* ENTITIES */
