#pragma once
#include "../UsingUs.hpp"
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/// Attributes are used in the ClassFile , field_info , method_info , and
/// Code_attribute structures of the class file format.

// 4.7.2
class attribute_info {public:

  /// typeof constant_pool[attribute_name_index] == CONSTANT_Utf8_info
  /// which represents the name of the attribute.
  u2 attribute_name_index;

  u4 attribute_length;

  
  u1 * info;  // Vetor de tamanho attribute_length*bytes,
  
  void fill_from(FILE*f);
};

enum att_name_result{
  ATT_CONSTANTVALUE=0,
  ATT_CODE,
  ATT_DEPRECATED,
  ATT_EXCEPTIONS,
  ATT_INNERCLASSES,
  ATT_SOURCEFILE,
  ATT_LINENUMBERTABLE,
  ATT_LOCALVARIABLETABLE,
  ATT_SYNTHETIC,
  ATT_INVALID
};

class ConstantValue_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 constantvalue_index;
  void fill_from(FILE*f);
};
class Exception_Table{public:    
  u2 start_pc;
  u2 end_pc;
  u2 handler_pc;
  u2 catch_type;
  void fill_from(FILE*f);
};
// 4.7.3
class Code_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 max_stack;
  u2 max_locals;
  u4 code_length;
  u1 * code;
  u2 exception_table_length;
  Exception_Table * exception_table;
  u2 attributes_count;
  attribute_info * attributes;
  void fill_from(FILE*f);
};

// 4.7.15
class Deprecated_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  void fill_from(FILE*f);
};

// 4.7.4
// require "attribute_info_aux.hpp" cause of stack_map_frame

// Exceptions Attributes
class Exceptions_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_exceptions;
  u2 * exception_index_table;
  void fill_from(FILE*f);
};

class Classes{public:
  u2 inner_class_info_index;
  u2 outer_class_info_index;
  u2 inner_name_index;
  u2 inner_class_access_flags;
  void fill_from(FILE*f);
};

class InnerClasses_attribute {
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_classes;
  Classes * classes;
  void fill_from(FILE*f);
};

// 4.7.10
class SourceFile_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 sourcefile_index;
  void fill_from(FILE*f);
};

// 4.7.12

class Line_number_table {public:
  u2 start_pc;
  u2 line_number;
  void fill_from(FILE*f);
};

class LineNumberTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 line_number_table_length;
  Line_number_table * line_number_table;
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

class LocalVariableTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 local_variable_table_length;
  Local_variable_table * local_variable_table; // local_variable_table[local_variable_table_length]
  void fill_from(FILE*f);
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

#include "attribute_info.cpp"

/// \brief Esta classe é usada pela classes ClassFile,
/// field_info, method_info e Code_attributes.