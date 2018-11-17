#pragma once
#ifndef CP_INFO_CPP
#define CP_INFO_CPP

#include "ReaderFiles§read_us.hpp"
#include <cstdio>
void CONSTANT_Class_info :: fill_from(FILE * f) {
  read_us(&this->name_index, sizeof(this->name_index), f);
}
void CONSTANT_Fieldref_info :: fill_from(FILE * f) {
  read_us(&this->class_index, sizeof(this->class_index), f);
  read_us(&this->name_and_type_index, sizeof(this->name_and_type_index), f);
}
void CONSTANT_Methodref_info :: fill_from(FILE * f) {
  read_us(&this->class_index, sizeof(this->class_index), f);
  read_us(&this->name_and_type_index, sizeof(this->name_and_type_index), f);
}
void CONSTANT_InterfaceMethodref_info :: fill_from(FILE * f) {
  read_us(&this->class_index, sizeof(this->class_index), f);
  read_us(&this->name_and_type_index, sizeof(this->name_and_type_index), f);
}
void CONSTANT_String_info :: fill_from(FILE * f) {
  read_us(&this->string_index, sizeof(this->string_index), f);
}
void CONSTANT_Integer_info :: fill_from(FILE * f) {
  read_us(&this->bytes, sizeof(this->bytes), f);
}
void CONSTANT_Float_info :: fill_from(FILE * f) {
  read_us(&this->bytes, sizeof(this->bytes), f);
}
void CONSTANT_Long_info :: fill_from(FILE * f) {
  read_us(&this->high_bytes, sizeof(this->high_bytes), f);
  read_us(&this->low_bytes, sizeof(this->low_bytes), f);
}
void CONSTANT_Double_info :: fill_from(FILE * f) {
  read_us(&this->high_bytes, sizeof(this->high_bytes), f);
  read_us(&this->low_bytes, sizeof(this->low_bytes), f);
}
void CONSTANT_NameAndType_info :: fill_from(FILE * f) {
  read_us(&this->name_index, sizeof(this->name_index), f);
  read_us(&this->descriptor_index, sizeof(this->descriptor_index), f);
}
// Ver essa leitura de ponteiro... Alocar espaco antes!
void CONSTANT_Utf8_info :: fill_from(FILE * f) {
  read_us(&length, sizeof(length), f);
  bytes = (u1*)malloc(sizeof(u1) * length);
  read_usstring(bytes, length, f);
}

#endif