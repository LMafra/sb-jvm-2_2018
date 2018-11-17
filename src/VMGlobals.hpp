#pragma once
#ifndef VMGLOBALS_HPP
#define VMGLOBALS_HPP

#include <cstdint>
#include <vector>
#include <stack>
#include "UsingUs.hpp"
#include "ClassFileStructures§ClassFile.hpp"
#define popcat1 pop_cat1
#define popcat2 pop_cat2

class Instancia{
	ClassFile * classe;
	void * atributos;
};

class Frame_type{
	Instancia * inst;
	u1 * PC_retorno;
	u4 * variaveis_locais;
};

union cat1 {
	u4 val;
	void * ref_val;
};

extern u1 * PC;
extern std::stack<Frame_type> frame_stack;
extern std::stack<cat1> jvm_stack;
extern ClassFile * method_area;  // vetor de ClassFile

extern bool global_path_set;  // indica que "global_path" foi ou nao inicializado
extern char * global_path;

extern int class_counter;

u4 pop_cat1();
u8 pop_cat2();
void * pop_address();

#endif