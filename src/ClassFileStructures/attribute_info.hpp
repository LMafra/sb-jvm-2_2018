#pragma once
#include "../UsingUs.hpp"
#include "attribute_info_aux.hpp"
#include <stdlib.h>
using namespace std;
/// Attributes are used in the ClassFile , field_info , method_info , and
/// Code_attribute structures of the class file format.

// 4.7.2
class ConstantValue_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 constantvalue_index;
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
  ExceptionTable * exception_table;
  u2 attributes_count;
  attribute_info * attributes;
};

// 4.7.15
class Deprecated_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
};

// 4.7.4
// require "attribute_info_aux.hpp" cause of stack_map_frame
#include "attribute_info_aux.hpp"


// Exceptions Attributes
class Exceptions_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_exceptions;
  u2 * exception_index_table;
};


class InnerClasses_attribute {
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_classes;
  Classes * classes;
};


// 4.7.10
class SourceFile_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 sourcefile_index;
};

// 4.7.12
class LineNumberTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 line_number_table_length;
  Line_number_table * line_number_table;
};

class LocalVariableTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 local_variable_table_length;
  Local_variable_table * local_variable_table; // local_variable_table[local_variable_table_length]
};

/// \brief Esta classe é usada pela classes ClassFile,
/// field_info, method_info e Code_attributes.