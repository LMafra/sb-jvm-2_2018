#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#define popcat1 pop_cat1
#define popcat2 pop_cat2
#define pushcat1 push_cat1
#define pushcat2 push_cat2
#define incpc increment_pc
// extern class Instance;



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

u4 pop_cat1();
u8 pop_cat2();
void push_cat1(u4);
void push_cat2(u8);
void * pop_address();


template <class T>
void jvm_push(T val);

template <class T>
void jvm_push_reference(T * val);


// #############################
#include  "VMGlobals.cpp"
