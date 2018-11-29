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

// extern class Instance;
class Instance {public:
  static bool initDict;
  void init_dict();
  
  void * field_allocator(int);
  void * instance_allocator(int);
  Instance();
  ClassFile * my_class_ptr;
  void * my_attributes;
};

class Frame_type{public:
	Instance * inst;
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
extern ClassFile ** method_area;  // vetor de ClassFile

extern std::set<const char*> jvm_loaded_classes;
extern std::map<const char*, int> class_method_area_index;

extern bool global_path_set;  // indica que "global_path" foi ou nao inicializado
extern char * global_path;

extern int class_counter;

u4 pop_cat1();
u8 pop_cat2();
void * pop_address();

template <class T>
T jvm_push(T val);

void * jvm_push();
#include  "VMGlobals.cpp"