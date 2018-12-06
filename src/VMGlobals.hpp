#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <array>
#include "UsingUs.h"
#include "ClassFileStructures/ClassFile.hpp"
#define popcat1 pop_cat1
#define popcat2 pop_cat2
#define pushcat1 push_cat1
#define pushcat2 push_cat2
#define jvm_push_cat1 push_cat1
#define jvm_push_cat2 push_cat2
#define incpc increment_pc
#define jvm_pop_reference pop_reference 
#define jvm_pop_address pop_reference 
#define pop_address pop_reference
#define jvm_push_reference push_reference
#define jvm_push_u4 push_cat1
#define jvm_push_u8 push_cat2
#define jvm_push_reference push_reference
const double NaN = nan("");
// extern class Instance;
class Array_instance {public:
  const int32_t size;
  void * data;
  Array_instance(int32_t qtd, size_t my_type_size):size(qtd){data = calloc(size, my_type_size);}
};

class Array_ref_instance {public:
  const int32_t size;
  void ** data;
  Array_ref_instance(int32_t qtd):size(qtd){data = (void**)calloc(size, sizeof(void*));}
};
// cuidar vetor de bool
class Array_bool {public:
  const int32_t size;
  u1 * data;
  Array_bool(int32_t qtd):size(qtd){data = (u1*)calloc(  size, sizeof(u1));}
};


class Instance {public:
  static Instance * instance_allocator(int);

  void * field_allocator(int);
  static bool initDict;
  void init_dict();
  Instance();
  ClassFile * my_class_ptr;
  void * my_attributes;
};

union cat1 {
	u4 val;
	void * ref_val;
};

class Frame_type{public:
  int initial_stack_size; // tamanho da pilha quanto o frame froi criado. Utilizado pelas instrucoes de retorno.
	Instance * inst;
	u1 * PC_retorno;
	u1 * PC_base;
	cat1 * variaveis_locais;
	u1 * PC_final;
};


extern u1 * PC;
extern std::stack<Frame_type> frame_stack;
extern std::stack<cat1> jvm_stack;
extern ClassFile ** method_area;  // vetor de ClassFile

extern std::set<const char*> jvm_loaded_classes;
extern std::map<const char*, int> class_method_area_index;

extern bool global_path_set;  // indica que "global_path" foi ou nao inicializado
extern char * global_path;

extern int class_counter;

u1 instrparam(int);
void increment_pc(int);

cat1 pop_cat1raw();
u4 pop_cat1();
u8 pop_cat2();

template <typename T>
void push_cat1(T);

template <typename T>
void push_cat2(T);

void * pop_reference();
int16_t offset16_from_stack();int32_t offset32_from_stack();
int16_t offset16_from_instr(int);int32_t offset32_from_instr(int);

// template <class T>
// void jvm_push_u4(T val);
// template <class T>
// void jvm_push_u8(T val);

template <class T>
void push_reference(T * val);

// #############################
#include  "VMGlobals.cpp"
