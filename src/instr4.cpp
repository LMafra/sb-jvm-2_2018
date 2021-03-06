#include "instructions.hpp"
// #include "exec_instr.hpp"
#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include <string.h>

static void _astore32(Type t) {
	int32_t value = pop_cat1();	int32_t index = pop_cat1();
	Array_instance * ref = (Array_instance *)pop_reference();
  u1 one_byte = value; u2 two_byte = value;
	switch (t) {
		case Type::BYTE: memcpy( &( (char*)(ref->data)) [index], &one_byte, sizeof(u1));break;
		case Type::CHAR: memcpy( &( (char*)(ref->data)) [index], &one_byte, sizeof(u1));break;
		case Type::SHORT: memcpy( &( (short*)(ref->data)) [index], &two_byte, sizeof(u2));break;
		case Type::INT: memcpy( &( (int*)(ref->data)) [index], &value, sizeof(u4));break;
		case Type::FLOAT: memcpy( &( (float*)(ref->data)) [index], &value, sizeof(u4));break;
		default:
			throw "Shouldn't be here [_astore32]";
	}
}

static void _astore64(Type t) {
	u8 value = pop_cat2();	int32_t index = pop_cat1();
	Array_instance * ref = (Array_instance *)pop_reference();
	switch (t) {
		case Type::LONG: memcpy( &( (long*)(ref->data))[index], &value, sizeof(u8));break;
		case Type::DOUBLE: memcpy( &( (double*)(ref->data))[index], &value, sizeof(u8));break;
		default:
			throw "Shouldn't be here [_astore64]";
	}
}
static void _astore_ref() {
	void * value = pop_reference();	int32_t index = (int32_t)pop_cat1();
	Array_ref_instance * arrayref = (Array_ref_instance *)pop_reference();
	arrayref->data[index] = value;
}

static void _astore(Type t) {
  switch (t) {
  case Type::REFERENCE:
    _astore_ref();  break;
  case Type::DOUBLE:case Type::LONG:
    _astore64(t); break;
  default:
    _astore32(t); break;
  }
}

// maffei
void exec_jvm_iastore(){_astore(Type::INT);incpc(1);}  // ok
void exec_jvm_lastore(){_astore(Type::LONG);incpc(1);}
void exec_jvm_fastore(){_astore(Type::FLOAT);incpc(1);}
void exec_jvm_dastore(){_astore(Type::DOUBLE);incpc(1);}
void exec_jvm_aastore(){_astore(Type::REFERENCE);incpc(1);}
void exec_jvm_bastore(){_astore(Type::BYTE);incpc(1);}
void exec_jvm_castore(){_astore(Type::CHAR);incpc(1);}
void exec_jvm_sastore(){_astore(Type::SHORT);incpc(1);}

// maffei
void exec_jvm_pop(){jvm_stack.pop();incpc(1);}

// maffei
void exec_jvm_pop2(){jvm_stack.pop();jvm_stack.pop();incpc(1);}

// maffei
// Duplicate the top operand stack value
void exec_jvm_dup(){
	u4 value = pop_cat1();
	push_cat1(value);	push_cat1(value); incpc(1);
}

// Duplicate the top operand stack value and insert two values down
// Maffei
void exec_jvm_dup_x1(){
	u4 value1 = pop_cat1(); u4 value2 = pop_cat1();
	push_cat1(value1);
	push_cat1(value2);	push_cat1(value1);incpc(1);
}


// Maffei
void exec_jvm_dup_x2(){
	u4 value1 = pop_cat1(); u4 value2 = pop_cat1(); u4 value3 = pop_cat1();
	push_cat1(value1);
	push_cat1(value3);push_cat1(value2);push_cat1(value1);incpc(1);
}


// Maffei
void exec_jvm_dup2(){
	u4 value1 = pop_cat1(); u4 value2 = pop_cat1();
	push_cat1(value2);push_cat1(value1);
	push_cat1(value2);push_cat1(value1);incpc(1);
}


// Maffei
void exec_jvm_dup2_x1(){
	u4 value1 = pop_cat1(); u4 value2 = pop_cat1(); u4 value3 = pop_cat1();
	push_cat1(value2);push_cat1(value1);
	push_cat1(value3);push_cat1(value2);push_cat1(value1);incpc(1);
}


// Maffei
void exec_jvm_dup2_x2(){
	u4 value1 = pop_cat1(); u4 value2 = pop_cat1();
	u4 value3 = pop_cat1(); u4 value4 = pop_cat1();
	push_cat1(value2);push_cat1(value1);
	push_cat1(value4);push_cat1(value3);push_cat1(value2);push_cat1(value1);incpc(1);
}

// Maffei
void exec_jvm_swap(){
	u4 value1 = pop_cat1(); u4 value2 = pop_cat1();
	push_cat1(value1); push_cat1(value2);incpc(1);
}

