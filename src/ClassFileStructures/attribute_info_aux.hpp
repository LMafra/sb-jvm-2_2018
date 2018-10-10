#pragma once
#include <stdio.h>
#include "../UsingUs.hpp"
class ExceptionTable;
class Top_variable_info;
class Integer_variable_info;
class Float_variable_info;
class Long_variable_info;
class Double_variable_info;
class Null_variable_info;
class UninitializedThis_variable_info;
class Object_variable_info;
class Uninitialized_variable_info;
class same_frame;
class same_locals_1_stack_item_frame;
class same_locals_1_stack_item_frame_extended;
class chop_frame;
class same_frame_extended;
class append_frame;
class full_frame;
class Classes;
class Line_number_table;
class Local_variable_table;
class Enum_const_value;
class element_value;
class Element_value_pairs;
class Array_value;
class Parameter_annotations;
class annotation; 
// class attribute_info;
class Local_variable_type_table;
// 4.7.3.0

// 4.7.14

class Local_variable_type_table{public:
  u2 start_pc;
  u2 length;
  u2 name_index;
  u2 signature_index;
  u2 index;
  void fill_from(FILE*f);
};

// 4.7.16
class annotation {public:
  u2 type_index;
  u2 num_element_value_pairs;
  Element_value_pairs * element_value_pairs;
  void fill_from(FILE*f);
};


class ExceptionTable {public:
  u2 start_pc;
  u2 end_pc;
  u2 handler_pc;
  u2 catch_type;
  void fill_from(FILE*f);
};

// 4.7.4 (pg 113)
enum v_info {
  Top = 0,Integer,Float,Long,Double,Null,
  UnitializedThis, Object, Uninitialized
};
class Top_variable_info{public: u1 tag;};  // 0
class Integer_variable_info{public: u1 tag;}; // 1
class Float_variable_info{public: u1 tag;}; // 2
class Long_variable_info{public: u1 tag;}; // 3
class Double_variable_info{public: u1 tag;};  // 4
class Null_variable_info{public: u1 tag;}; // 5
class UninitializedThis_variable_info{public: u1 tag;}; // 6 

class Object_variable_info{public:
  u1 tag;
  u2 cpool_index;
  void fill_from(FILE*f);
}; // 7
class Uninitialized_variable_info{public:
  u1 tag;
  u2 offset;
  void fill_from(FILE*f);
}; // 8


union  verification_type_info {
  Top_variable_info a;
  Integer_variable_info aa;
  Float_variable_info aaa;
  Long_variable_info aaaa;
  Double_variable_info aaaaa;
  Null_variable_info aaaaaaa;
  UninitializedThis_variable_info aaaaaaaa;
  Object_variable_info aaaaaaaaa;
  Uninitialized_variable_info aaaaaaaaaa;
};

// 4.7.4 (pg 109)


class same_frame {public: u1 frame_type; /* 0-63 */};

class same_locals_1_stack_item_frame {public:
  u1 frame_type; /* 64-127 */
  verification_type_info stack[1];
  void fill_from(FILE*f);
};

class same_locals_1_stack_item_frame_extended {public:
  u1 frame_type; /* 247 */
  u2 offset_delta;
  verification_type_info stack[1];
  void fill_from(FILE*f);
};

class chop_frame {public:
  u1 frame_type; /* 248-250 */
  u2 offset_delta;
  void fill_from(FILE*f);
};

class same_frame_extended {public:
  u1 frame_type; /* 251 */
  u2 offset_delta;
  void fill_from(FILE*f);
};

class append_frame {public:
  u1 frame_type; /* 252-254 */
  u2 offset_delta;
  // verification_type_info locals [ frame_type - append_frame::decrement ];
  verification_type_info * locals;
  void fill_from(FILE*f);
};

class full_frame {public:
  u1 frame_type; /* 255 */
  u2 offset_delta;
  u2 number_of_locals;
  verification_type_info * locals;
  u2 number_of_stack_items;
  verification_type_info * stack;
  void fill_from(FILE*f);
};

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
  void fill_from(FILE*f);
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
// 4.7.16.1

class Enum_const_value{public:
  u2 type_name_index;
  u2 const_name_index;
  void fill_from(FILE*f);
};

class Array_value{public:
  u2 num_values;
  element_value ** values;  // element_value value[num_values]; porem, isso dah da tamanho infinito!
  void fill_from(FILE*f);
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
  void fill_from(FILE*f);
};

class Element_value_pairs  {public:
  u2 element_name_index;
  element_value value;
  void fill_from(FILE*f);
};

///////////////

// 4.7.19
class Parameter_annotations {public:
  u2 num_annotations;
  annotation * annotations;
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