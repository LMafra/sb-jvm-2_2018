#pragma once
#include <stdlib.h>
#include "../ClassFileStructures/ClassFile.hpp"

class Instance {public:
  static bool initDict;
  ClassFile * class_pointer;
  void init_dict();
  void * atributos;
  void * field_allocator(int);
  Instance();
};
#include "Instance.cpp"