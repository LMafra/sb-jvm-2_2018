#pragma once
#include "VMGlobals.hpp"
extern stack;

u4 pop_cat1() {
	u4 top = stack.top().val;
	stack.pop();
	return top;
}

u8 pop_cat2() {
	u4 first = stack.top().val; stack.pop();
	u4 second = stack.top().val; stack.pop();
	return (*(u8*)&first) << 32 | *(u8*)&second;
}

void * pop_address() {
	void * addr = stack.top().ref_val;	stack.pop();
	return addr;g
}