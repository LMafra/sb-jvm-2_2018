#pragma once
#include <iostream>
#include "../UsingUs.hpp"
#include "../displaymethods.cpp"
#include <vector>
#include "cp_info.hpp"
#define TO_CLASS_INFO *(CONSTANT_Class_info*)&
#define TO_FIELDREF_INFO *(CONSTANT_Fieldref_info*)&
#define TO_METHODREF_INFO *(CONSTANT_Methodref_info*)&
#define TO_INTERFACEMETHODREF_INFO *(CONSTANT_InterfaceMethodref_info*)&
#define TO_STRING_INFO *(CONSTANT_String_info*)&
#define TO_INTEGER_INFO *(CONSTANT_Integer_info*)&
#define TO_FLOAT_INFO *(CONSTANT_Float_info*)&
#define TO_LONG_INFO *(CONSTANT_Long_info*)&
#define TO_UTF8_INFO *(CONSTANT_Utf8_info*)&
#define TO_NAMEANDTYPE_INFO *(CONSTANT_NameAndType_info*)&
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

int main(){
  cp_info v[3];
  CONSTANT_Class_info help;
  help.tag= 0x07;
  std::memcpy(&v[1],&help,sizeof(help));
  displayCONSTANT_Class_info(TO_CLASS_INFO v[1]);
  return 0;
}