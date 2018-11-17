#pragma once
#ifndef ATTRIBUTE_INFO_CPP
#define ATTRIBUTE_INFO_CPP

#include <stdio.h>
#include "ClassFileStructures§attribute_info.hpp"
#include "ReaderFiles§read_us.hpp"

void ConstantValue_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&constantvalue_index, sizeof(constantvalue_index), f);
}

void Deprecated_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
}

void SourceFile_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&sourcefile_index, sizeof(sourcefile_index), f);
}

void LineNumberTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&line_number_table_length, sizeof(line_number_table_length), f);
	line_number_table = (Line_number_table *)malloc( line_number_table_length * sizeof( Line_number_table ) );
	for(int i=0;i<line_number_table_length;i++){
		line_number_table[i].fill_from(f);
	}
}

void LocalVariableTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&local_variable_table_length, sizeof(local_variable_table_length), f);
	local_variable_table = (Local_variable_table *)malloc( local_variable_table_length * sizeof( Local_variable_table ) );
	for(int i=0;i<local_variable_table_length;i++){
		local_variable_table[i].fill_from(f);
	}
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

void Exception_Table  :: fill_from(FILE * f){
	read_us(&start_pc, sizeof(start_pc), f);
  	read_us(&end_pc, sizeof(end_pc), f);
  	read_us(&handler_pc, sizeof(handler_pc), f);
  	read_us(&catch_type, sizeof(catch_type), f);
}

void Code_attribute :: fill_from(FILE*f){
  	read_us(&attribute_length, sizeof(attribute_length), f);
  	read_us(&max_stack, sizeof(max_stack), f);
  	read_us(&max_locals, sizeof(max_locals), f);
  	read_us(&code_length, sizeof(code_length), f);
  	code = (u1*)malloc(sizeof(u1) * code_length);
  	read_usstring(code, code_length, f);
	read_us(&exception_table_length, sizeof(exception_table_length), f);
	exception_table = (Exception_Table *)malloc( exception_table_length * sizeof( Exception_Table ) );
	for(int i=0;i<exception_table_length;i++){
		exception_table[i].fill_from(f);
	}
  	read_us(&attributes_count, sizeof(attributes_count), f);
}


void Exceptions_attribute :: fill_from(FILE * f){
  	read_us(&attribute_length, sizeof(attribute_length), f);
  	read_us(&number_of_exceptions, sizeof(number_of_exceptions), f);
	exception_index_table = (u2 *)malloc( number_of_exceptions * sizeof( u2 ) );
	for(int i=0;i<number_of_exceptions;i++){
		read_us(&exception_index_table[i], sizeof(exception_index_table[i]), f);
	}
}


void Classes :: fill_from(FILE * f){
  	read_us(&inner_class_info_index, sizeof(inner_class_info_index), f);
  	read_us(&outer_class_info_index, sizeof(outer_class_info_index), f);
  	read_us(&inner_name_index, sizeof(inner_name_index), f);
  	read_us(&inner_class_access_flags, sizeof(inner_class_access_flags), f);
};

void InnerClasses_attribute :: fill_from(FILE * f){
  	read_us(&attribute_length, sizeof(attribute_length), f);
  	read_us(&number_of_classes, sizeof(number_of_classes), f);
	classes = (Classes *)malloc( number_of_classes * sizeof( Classes ) );
	for(int i=0;i<number_of_classes;i++){
		classes[i].fill_from(f);
	}
}





#endif