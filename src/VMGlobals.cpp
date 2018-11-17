#pragma once
#include "VMGlobals.hpp"

std::stack<Frame_type> frame_stack;
std::stack<cat1> jvm_stack;
u1 * PC;

bool global_path_set = 0;
extern char * global_path;
ClassFile * method_area;

int class_counter = 0;
u4 pop_cat1() {
	u4 top = jvm_stack.top().val;
	jvm_stack.pop();
	return top;
}

u8 pop_cat2() {
	u4 first = jvm_stack.top().val; jvm_stack.pop();
	u4 second = jvm_stack.top().val; jvm_stack.pop();
	return (*(u8*)&first) << 32 | *(u8*)&second;
}

void * pop_address() {
	void * addr = jvm_stack.top().ref_val;	jvm_stack.pop();
	return addr;
}

template <typename T>
void jvm_push(T val) {
	cat1 top; top.val = *(u4*)&val;
	jvm_stack.push( top );
}

template <typename T>
void * jvm_push_reference(T * ref_val) {
	cat1 top; top.ref_val = ref_val;
	jvm_stack.push( top );
}