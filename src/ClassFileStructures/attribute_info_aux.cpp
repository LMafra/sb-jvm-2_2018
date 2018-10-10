#pragma once
#include <stdio.h>
#include "attribute_info_aux.hpp"

void Local_variable_type_table :: fill_from(FILE * f) {
	read_us(&start_pc, sizeof(start_pc), f);
	read_us(&length, sizeof(length), f);
	read_us(&name_index, sizeof(name_index), f);
	read_us(&signature_index, sizeof(signature_index), f);
	read_us(&index, sizeof(index), f);
}

void annotation  :: fill_from(FILE * f) {
	// read_us(&type_index, sizeof(type_index), f);
	// read_us(&num_element_value_pairs, sizeof(num_element_value_pairs), f);
	// auto t = num_element_value_pairs;
	// element_value_pairs = (Element_value_pairs*)malloc(sizeof(Element_value_pairs));
	// for(auto i = 0; i < t; i++)
	// 	element_value_pairs[i].fill_from(f);

}

void ExceptionTable  :: fill_from(FILE * f) {
	read_us(&start_pc, sizeof(start_pc), f);
	read_us(&end_pc, sizeof(end_pc), f);
	read_us(&handler_pc, sizeof(handler_pc), f);
	read_us(&catch_type, sizeof(catch_type), f);
}

void Object_variable_info :: fill_from(FILE * f) {
	read_us(&tag, sizeof(tag), f);
	read_us(&cpool_index, sizeof(cpool_index), f);
}

void Uninitialized_variable_info :: fill_from(FILE * f) {
	read_us(&tag, sizeof(tag), f);
	read_us(&offset, sizeof(offset), f);
}

void same_locals_1_stack_item_frame  :: fill_from(FILE * f) {
	read_us(&frame_type, sizeof(frame_type), f);
	read_us(&stack[1], sizeof(stack[1]), f);
}

void same_locals_1_stack_item_frame_extended  :: fill_from(FILE * f) {
	read_us(&frame_type, sizeof(frame_type), f);
	read_us(&offset_delta, sizeof(offset_delta), f);
	read_us(&stack[1], sizeof(stack[1]), f);
}

void chop_frame  :: fill_from(FILE * f) {
	read_us(&frame_type, sizeof(frame_type), f);
	read_us(&offset_delta, sizeof(offset_delta), f);
}

void same_frame_extended  :: fill_from(FILE * f) {
	read_us(&frame_type, sizeof(frame_type), f);
	read_us(&offset_delta, sizeof(offset_delta), f);
}

void append_frame  :: fill_from(FILE * f) {
	read_us(&frame_type, sizeof(frame_type), f);
	read_us(&offset_delta, sizeof(offset_delta), f);
	read_us(&], sizeof(]), f);
	read_us(&locals, sizeof(locals), f);
}

void full_frame  :: fill_from(FILE * f) {
	read_us(&frame_type, sizeof(frame_type), f);
	read_us(&offset_delta, sizeof(offset_delta), f);
	read_us(&number_of_locals, sizeof(number_of_locals), f);
	read_us(&locals, sizeof(locals), f);
	read_us(&number_of_stack_items, sizeof(number_of_stack_items), f);
	read_us(&stack, sizeof(stack), f);
}

void Classes  :: fill_from(FILE * f) {
	read_us(&inner_class_info_index, sizeof(inner_class_info_index), f);
	read_us(&outer_class_info_index, sizeof(outer_class_info_index), f);
	read_us(&inner_name_index, sizeof(inner_name_index), f);
	read_us(&inner_class_access_flags, sizeof(inner_class_access_flags), f);
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

void Enum_const_value :: fill_from(FILE * f) {
	read_us(&type_name_index, sizeof(type_name_index), f);
	read_us(&const_name_index, sizeof(const_name_index), f);
}

void Array_value :: fill_from(FILE * f) {
	read_us(&num_values, sizeof(num_values), f);
	read_us(&value[num_values], sizeof(value[num_values]), f);
}

void element_value  :: fill_from(FILE * f) {
	read_us(&tag, sizeof(tag), f);
	read_us(&value, sizeof(value), f);
}

void Element_value_pairs   :: fill_from(FILE * f) {
	read_us(&element_name_index, sizeof(element_name_index), f);
	value.fill_from(f);
}

void Parameter_annotations  :: fill_from(FILE * f) {
	read_us(&num_annotations, sizeof(num_annotations), f);
	read_us(&annotations, sizeof(annotations), f);
}

void attribute_info  :: fill_from(FILE * f) {
	read_us(&attribute_name_index, sizeof(attribute_name_index), f);
	read_us(&attribute_length, sizeof(attribute_length), f);
	info = (u1*)malloc(sizeof(u1) * attribute_length);	
	for(auto i = 0; i < attribute_length; i++)	
		read_us(&info[i], sizeof(info[i]), f);
}

