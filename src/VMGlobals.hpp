#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.hpp"

class Instancia{
	ClassFile * classe;
	void * atributos;
};

class Frame_type{
	Instancia * inst;
	u1 * PC_retorno;
	u4 * variaveis_locais;
};

u1 * PC;
std::stack<Frame_type> frame_stack;
std::stack<u4> stack;
ClassFile * method_area;  // vetor de ClassFile

bool global_path_set = 0;  // indica que "global_path" foi ou nao inicializado
char * global_path;

int class_counter = 0;