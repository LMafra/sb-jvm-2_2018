#pragma once
#include "../UsingUs.hpp"

class ExceptionTable {public:
  u2 start_pc;
  u2 end_pc;
  u2 handler_pc;
  u2 catch_type;
};

// 4.7.4 (pg 109)
union stack_map_frame {
  same_frame a;
  same_locals_1_stack_item_frame b;
  same_locals_1_stack_item_frame_extended c;
  chop_frame d;
  same_frame_extended e;
  append_frame f;
  full_frame g;
};

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


class Classes {public:
  u2 inner_class_info_index;
  u2 outer_class_info_index;
  u2 inner_name_index;
  enum_inner_class_access_flags inner_class_access_flags;
};

class Line_number_table {public:
  u2 start_pc;
  u2 line_number;
};

class Local_variable_table {public:
  u2 start_pc;
  u2 length;
  u2 name_index;
  u2 descriptor_index;
  u2 index;
};
// 4.7.16.1

class Enum_const_value{public:
  u2 type_name_index;
  u2 const_name_index;
};

class Array_value{public:
  u2 num_values;
  element_value ** values;  // element_value value[num_values]; porem, isso dah da tamanho infinito!
};

union UnionValue {
  u2 const_value_index;
  Enum_const_value enum_const_value;
  u2 class_info_index;
  annotation annotation_value;
  Array_value array_value;
};

class element_value {public:
  u1 tag;
  UnionValue value;
};

class Element_value_pairs  {public:
  u2 element_name_index;
  element_value value;
};
// 4.7.16
class annotation {public:
  u2 type_index;
  u2 num_element_value_pairs;
  Element_value_pairs * element_value_pairs;
};

///////////////
class Enum_const_value {public:
  u2 type_name_index;
  u2 const_name_index;
};

class Array_value {public:
  u2 num_values;
  element_value values[num_values];
};

union UnionValue {
  u2 const_value_index;
  Enum_const_value enum_const_value;
  u2 class_info_index;
  annotation annotation_value;
  Array_value array_value;
};

// 4.7.19
class Parameter_annotations {public:
  u2 num_annotations;
  annotation * annotations;
};