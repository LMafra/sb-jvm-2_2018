#pragma once
#include <iostream>
#include "../UsingUs.hpp"
#include <vector>
#include "cp_info.hpp"
using namespace std;
enum enum_cp_tags {
  CONSTANT_Class = 7,
  CONSTANT_Fieldref = 9,
  CONSTANT_Methodref = 10,
  CONSTANT_InterfaceMethodref = 11,
  CONSTANT_String = 8,
  CONSTANT_Integer = 3,
  CONSTANT_Float = 4,
  CONSTANT_Long = 5,
  CONSTANT_Double = 6,
  CONSTANT_NameAndType = 12,
  CONSTANT_Utf8 = 1,
  CONSTANT_MethodHandle = 15,
  CONSTANT_MethodType = 16,
  CONSTANT_InvokeDynamic = 18
};

vector<u1> cp_tags_values {
  CONSTANT_Class,
  CONSTANT_Fieldref,
  CONSTANT_Methodref,
  CONSTANT_InterfaceMethodref,
  CONSTANT_String,
  CONSTANT_Integer,
  CONSTANT_Float,
  CONSTANT_Long,
  CONSTANT_Double,
  CONSTANT_NameAndType,
  CONSTANT_Utf8,
  CONSTANT_MethodHandle,
  CONSTANT_MethodType,
  CONSTANT_InvokeDynamic
};

int main(){}