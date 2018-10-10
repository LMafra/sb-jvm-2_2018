#pragma once
#include <stdio.h>
#include "../UsingUs.hpp"

enum enum_inner_class_access_flags {
  ACC_PUBLIC = 0x0001,// Marked or implicitly public in source.
  ACC_PRIVATE = 0x0002,// Marked private in source.
  ACC_PROTECTED = 0x0004,// Marked protected in source.
  ACC_STATIC = 0x0008,// Marked or implicitly static in source.
  ACC_FINAL = 0x0010,// Marked final in source.
  ACC_INTERFACE = 0x0200,// Was an interface in source.
  ACC_ABSTRACT = 0x0400,// Marked or implicitly abstract in source.
  ACC_SYNTHETIC = 0x1000,// Declared synthetic; not present in the source code.
  ACC_ANNOTATION = 0x2000,// Declared as an annotation type.
  ACC_ENUM = 0x4000// Declared as an enum type.
};

class Line_number_table {public:
  u2 start_pc;
  u2 line_number;
  void fill_from(FILE*f);
};

class Local_variable_table {public:
  u2 start_pc;
  u2 length;
  u2 name_index;
  u2 descriptor_index;
  u2 index;
  void fill_from(FILE*f);
};
class attribute_info {public:

  /// typeof constant_pool[attribute_name_index] == CONSTANT_Utf8_info
  /// which represents the name of the attribute.
  u2 attribute_name_index;

  u4 attribute_length;

  
  u1 * info;  // Vetor de tamanho attribute_length*bytes,
  
  void fill_from(FILE*f);
};

#include "attribute_info_aux.cpp"