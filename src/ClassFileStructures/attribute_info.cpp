#pragma once
#include <stdio.h>
#include "attribute_info.hpp"

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

