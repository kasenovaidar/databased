#include "db_types.h"

int main() {
	printf("It's main function of a database\n");

	FieldType types[3] = { FIELD_TYPE_INT, FIELD_TYPE_STRING, FIELD_TYPE_STRING };
	Table *table = create_table("Just table", 3, types);

	Field fields[3];
	fields[0].int_val = 34;
	fields[1].str_val = "Thulu";
	fields[2].str_val = "Bunk";
	insert_row(table, fields);
	
	fields[0].int_val = 54;
	insert_row(table, fields);

	fields[0].int_val = 1;
	fields[1].str_val = "CPD";
	fields[2].str_val = "FGHH";
	insert_row(table, fields);

	print_table(table);

	free_table(table);

	return 0;
}
	
