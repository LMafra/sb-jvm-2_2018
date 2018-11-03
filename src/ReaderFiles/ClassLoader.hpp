#pragma once
#include "../ClassFileStructures/ClassFile.hpp"

class ClassLoader{public:
  static att_name_result which_att(CONSTANT_Utf8_info&);
  static void load_constant_pool(FILE*, ClassFile*);
  static void load_attribute(FILE *, ClassFile *, attribute_info * & , int);
  static void load(FILE*, ClassFile*);
};

#include "ClassLoader.cpp"