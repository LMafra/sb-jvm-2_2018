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
  ~Code_attribute() {
    free(this->code);
    free(this->exception_table);
  }
};

// 4.7.4
// require "attribute_info_aux.hpp" cause of stack_map_frame
#include "attribute_info_aux.hpp"
class StackMapTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_entries;
  stack_map_frame * entries;
};

union  verification_type_info;

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

// 4.7.7
class EnclosingMethod_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 class_index;
  u2 method_index;
};

// 4.7.8
class Synthetic_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
};

// 4.7.9
class Signature_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 signature_index;
};

// 4.7.10
class SourceFile_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 sourcefile_index;
};

// 4.7.11
class SourceDebugExtension_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u1 * debug_extension;
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

// 4.7.14
class LocalVariableTypeTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 local_variable_type_table_length;
  Local_variable_type_table * local_variable_type_table;
};

// 4.7.15
class Deprecated_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
};

// 4.7.16
class RuntimeVisibleAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 num_annotations;
  annotation * annotations;
};

// 4.7.16.1
class element_value;
// class element_value {public:
//   u1 tag;
//   UnionValue value;
// };

// 4.7.17
class RuntimeInvisibleAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 num_annotations;
  annotation * annotations; // annotations[num_annotations]
};

// 4.7.18
class Parameter_annotations;  // depends on annotation
class RuntimeVisibleParameterAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u1 num_parameters;
  Parameter_annotations * parameter_annotations; // parameter_annotations[num_parameters]
  annotation * annotations; // annotations[num_annotations]
};

// 4.7.19
class RuntimeInvisibleParameterAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u1 num_parameters;
  Parameter_annotations * parameter_annotations; // parameter_annotations[num_parameters]
};

// 4.7.20
class AnnotationDefault_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  element_value default_value;
};
using namespace std;
/// \brief Esta classe é usada pela classes ClassFile,
/// field_info, method_info e Code_attributes.
class attribute_info;