#pragma once
#include <stdlib.h>
#include "../ClassFileStructures/ClassFile.hpp"

struct Instance {
  static bool initDict;
  void init_dict();
  
  void * field_allocator(int);
  void * instance_allocator(int);
  Instance();
  ClassFile * my_class_pointer;
  void * my_attributes;
};
#include "Instance.cpp"