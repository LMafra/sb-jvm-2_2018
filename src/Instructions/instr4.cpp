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
		case Type::BYTE: memcpy( &( (char*)(ref->data)) [index], &one_byte, sizeof(char));break;
		case Type::CHAR: memcpy( &( (char*)(ref->data)) [index], &one_byte, sizeof(char));break;
		case Type::SHORT: memcpy( &( (short*)(ref->data)) [index], &two_byte, sizeof(short));break;
		case Type::INT: memcpy( &( (int*)(ref->data)) [index], &value, sizeof(int));break;
		case Type::FLOAT: memcpy( &( (float*)(ref->data)) [index], &value, sizeof(float));break;
		default:
			throw "Shouldn't be here";

		case Type::LONG: ( (long*)(ref->data)) [index] = value;break;
		case Type::DOUBLE: ( (double*)(ref->data)) [index] = value;break;
	}
}

static void _astore64(Type t) {
	int value = pop_cat1();	int index = pop_cat1();
	Array_instance * ref = (Array_instance *)pop_reference();

	switch (t) {
		case Type::INT: ( (int*)(ref->data)) [index] = value;
		case Type::LONG: ( (long*)(ref->data)) [index] = value;
		case Type::FLOAT: ( (float*)(ref->data)) [index] = value;
		case Type::DOUBLE: ( (double*)(ref->data)) [index] = value;
		default:
			throw "Shouldn't be here";
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




void exec_jvm_aastore(){

}


void exec_jvm_bastore(){

}


void exec_jvm_castore(){

}


void exec_jvm_sastore(){

}


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

