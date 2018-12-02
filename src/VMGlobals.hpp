#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <array>
#include "UsingUs.hpp"
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
const double NaN = nan("");
// extern class Instance;

struct Array_instance {
  int size;
  void * data;
  Array_instance(int qtd, int ){size=qtd; data = calloc(size, sizeof(void*));}
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
void push_cat1(u4);
void push_cat2(u8);
void * pop_reference();
u2 offset16_from_stack();u4 offset32_from_stack();
u2 offset16_from_instr(int);u4 offset32_from_instr(int);

template <class T>
void jvm_push(T val);

template <class T>
void push_reference(T * val);

// #############################
#include  "VMGlobals.cpp"
