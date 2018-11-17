#pragma once
#ifndef CLASSLOADER_HPP
#define CLASSLOADER_HPP

#include "ClassFileStructures§ClassFile.hpp"

class ClassLoader{public:
  static att_name_result which_att(CONSTANT_Utf8_info&);
  static void load_constant_pool(FILE*, ClassFile*);
  static void load_attribute(FILE *, ClassFile *, attribute_info * , int);
  static void load_classfile(FILE* f, ClassFile * cf = NULL, const char * path="double_aritmetica.class");
};

// #include "ClassLoader.cpp"
#endif