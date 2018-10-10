#pragma once
#include <stdio.h>
#include "attribute_info.hpp"

void ConstantValue_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&constantvalue_index, sizeof(constantvalue_index), f);
}

void StackMapTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&number_of_entries, sizeof(number_of_entries), f);
	read_us(&entries, sizeof(entries), f);
	read_us(&verification_type_info, sizeof(verification_type_info), f);
}

void EnclosingMethod_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&class_index, sizeof(class_index), f);
	read_us(&method_index, sizeof(method_index), f);
}

void Signature_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&signature_index, sizeof(signature_index), f);
}

void SourceDebugExtension_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&debug_extension, sizeof(debug_extension), f);
}

void LocalVariableTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&local_variable_table_length, sizeof(local_variable_table_length), f);
	read_us(&local_variable_table, sizeof(local_variable_table), f);
}

void Deprecated_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
}

// void element_value  :: fill_from(FILE * f) {
	read_us(&tag, sizeof(tag), f);
	read_us(&value, sizeof(value), f);
	read_us(&}, sizeof(}), f);
}

void RuntimeVisibleParameterAnnotations_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&num_parameters, sizeof(num_parameters), f);
	read_us(&parameter_annotations, sizeof(parameter_annotations), f);
	read_us(&annotations, sizeof(annotations), f);
}

void AnnotationDefault_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&default_value, sizeof(default_value), f);
	read_us(&std, sizeof(std), f);
	read_us(&attribute_info, sizeof(attribute_info), f);
}

