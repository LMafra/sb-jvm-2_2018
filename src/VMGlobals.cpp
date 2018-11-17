#pragma once
#ifndef VMGLOBALS_CPP
#define VMGLOBALS_CPP
// extern stack;
#include "VMGlobals.hpp"
#include "UsingUs.hpp"
u1 * PC;
std::stack<cat1> jvm_stack;
ClassFile * method_area;

bool global_path_set = 0;  // indica que "global_path" foi ou nao inicializado
char * global_path;

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

#endif