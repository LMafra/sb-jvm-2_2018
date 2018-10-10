#include <stdio.h>
#include "attribute_info.hpp"
#include "read_us.hpp"

void ConstantValue_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&constantvalue_index, sizeof(constantvalue_index), f);
}

void Deprecated_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
}

void SourceFile_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&sourcefile_index, sizeof(sourcefile_index), f);
}

void LineNumberTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&line_number_table_length, sizeof(line_number_table_length), f);
	read_us(&line_number_table, sizeof(line_number_table), f);
}

void Line_number_table  :: fill_from(FILE * f) {
	read_us(&start_pc, sizeof(start_pc), f);
	read_us(&line_number, sizeof(line_number), f);
}

void Local_variable_table  :: fill_from(FILE * f) {
	read_us(&start_pc, sizeof(start_pc), f);
	read_us(&length, sizeof(length), f);
	read_us(&name_index, sizeof(name_index), f);
	read_us(&descriptor_index, sizeof(descriptor_index), f);
	read_us(&index, sizeof(index), f);
}

void attribute_info  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	info = (u1*)malloc(sizeof(u1) * attribute_length);	
	for(auto i = 0; i < attribute_length; i++)	
		read_us(&info[i], sizeof(info[i]), f);
}



