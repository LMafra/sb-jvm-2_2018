#pragma once
#include <stdlib.h>
#include "../ClassFileStructures/ClassFile.hpp"

class Instance {public:
  static bool initDict;
  void * field_allocator(int);
  void * instance_allocator(int);
  
  ClassFile * class_pointer;
  void init_dict();
  void * atributos;
  Instance();
};
#include "Instance.cpp"