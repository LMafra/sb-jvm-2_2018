#include "instructions.hpp"
#include "exec_instr.hpp"
#include "../UsingUs.hpp"
#include "../VMGlobals.hpp"
#include <string.h>

enum Type {
	BYTE=0, CHAR, SHORT, INT,	FLOAT,	DOUBLE, LONG, REFERENCE
};



static void _astore32(Type t) {
	int value = pop_cat1();	int index = pop_cat1();
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
	u8 value = pop_cat2();	int index = pop_cat1();
	Array_instance * ref = (Array_instance *)pop_reference();
	switch (t) {
		case Type::LONG: memcpy( &( (long*)(ref->data))[index], &value, sizeof(u8));break;
		case Type::DOUBLE: memcpy( &( (double*)(ref->data))[index], &value, sizeof(u8));break;
		default:
			throw "Shouldn't be here [_astore64]";
	}
}
static void _astore_ref() {
	void * value = pop_reference();	int index = pop_cat1();
	Array_instance * ref = (Array_instance *)pop_reference();

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
void exec_jvm_iastore(){_astore(Type::INT);}  // ok
void exec_jvm_lastore(){_astore(Type::LONG);}
void exec_jvm_fastore(){_astore(Type::FLOAT);}
void exec_jvm_dastore(){_astore(Type::DOUBLE);}
void exec_jvm_aastore(){_astore(Type::DOUBLE);}
void exec_jvm_bastore(){_astore(Type::BYTE);}
void exec_jvm_castore(){_astore(Type::CHAR);}
void exec_jvm_sastore(){_astore(Type::SHORT);}


void exec_jvm_pop(){

}


void exec_jvm_pop2(){

}


void exec_jvm_dup(){

}


void exec_jvm_dup_x1(){

}


void exec_jvm_dup_x2(){

}


void exec_jvm_dup2(){

}


void exec_jvm_dup2_x1(){

}


void exec_jvm_dup2_x2(){

}


void exec_jvm_swap(){

}

