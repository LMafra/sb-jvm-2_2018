#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.hpp"
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

u1 * PC;
std::stack<Frame_type> frame_stack;
std::stack<cat1> stack;
ClassFile * method_area;  // vetor de ClassFile

bool global_path_set = 0;  // indica que "global_path" foi ou nao inicializado
char * global_path;

int class_counter = 0;

u4 pop_cat1();
u8 pop_cat2();
void * pop_address();