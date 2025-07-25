#include "db_types.h"

/*
 * Создаёт новую таблицу без строк.
 */
Table *create_table(const char *table_name, size_t field_count, FieldType *types) {
	Table *new_table = malloc(sizeof(Table));
	new_table->name = strdup(table_name);
	new_table->field_count = field_count;
	new_table->row_count = 0;
	new_table->first_row = NULL;
	new_table->last_row = NULL;
	FieldType *types_cpd  = malloc(sizeof(FieldType) * field_count);
	memcpy(types_cpd, types, sizeof(FieldType) * field_count);
	new_table->field_types = types_cpd;
	return new_table;
}

/*
 * Освобождает таблицу
 */
void free_table(Table *table) {
	Row *current_row = table->first_row;
	while (current_row) {
		free(current_row->fields);
		Row* temp = current_row;
		current_row = current_row->next_row;
		free(temp);
	}
	free(table->name);
	free(table->field_types);
	free(table);
}

void insert_row(Table *table, Field *fields) {
	Row *r = malloc(sizeof(Row));
	r->fields = malloc(sizeof(Field) * table->field_count);
	r->next_row = NULL;
	for (size_t i = 0; i < table->field_count; ++i) {
		if (table->field_types[i] == FIELD_TYPE_STRING) {
			r->fields[i].str_val = strdup(fields[i].str_val);
		}
		else if (table->field_types[i] == FIELD_TYPE_INT) {
			r->fields[i].int_val = fields[i].int_val;
		}
	}
	if (!table->first_row)
		table->first_row = r;
	if (!table->last_row) {
		table->last_row = r;
	}
	else {
		table->last_row->next_row = r;
		table->last_row = r;
	}
	table->row_count++;
}

void print_row(Row *row, Table *table) {
	Field *fields = row->fields;
	for (size_t i = 0; i < table->field_count; i++) {
		if (table->field_types[i] == FIELD_TYPE_STRING) {
			printf("%s\t", fields[i].str_val);
		}
		else {
			printf("%d\t", fields[i].int_val);
		}
	}
	printf("\n");
}

void print_table(Table *table) {
	Row *current_row = table->first_row;
	while (current_row) {
		print_row(current_row, table);
		current_row = current_row->next_row;
	}
}

