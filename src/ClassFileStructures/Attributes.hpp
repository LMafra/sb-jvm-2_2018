#include "UsingUs.hpp"
using namespace std;
/// Attributes are used in the ClassFile , field_info , method_info , and
/// Code_attribute structures of the class file format.
class ConstantValue_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 constantvalue_index;
}

class Code_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 max_stack;
  u2 max_locals;
  u4 code_length;
  u1 code[code_length];
  u2 exception_table_length;
  {
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
  } exception_table[exception_table_length];
  u2 attributes_count;
  attribute_info attributes[attributes_count];
}

class StackMapTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_entries;
  stack_map_frame entries[number_of_entries];
}

union stack_map_frame {
  same_frame,
  same_locals_1_stack_item_frame,
  same_locals_1_stack_item_frame_extended,
  chop_frame,
  same_frame_extended,
  append_frame,
  full_frame
}

class same_frame {public:
  u1 frame_type = SAME; /* 0-63 */
}

class same_locals_1_stack_item_frame {public:
  u1 frame_type = SAME_LOCALS_1_STACK_ITEM; /* 64-127 */
  verification_type_info stack[1];
}

class same_locals_1_stack_item_frame_extended {public:
  u1 frame_type = SAME_LOCALS_1_STACK_ITEM_EXTENDED; /* 247 */
  u2 offset_delta;
  verification_type_info stack[1];
}

class chop_frame {public:
  u1 frame_type = CHOP; /* 248-250 */
  u2 offset_delta;
}

class same_frame_extended {public:
  u1 frame_type = SAME_FRAME_EXTENDED; /* 251 */
  u2 offset_delta;
}

class append_frame {public:
  u1 frame_type = APPEND; /* 252-254 */
  u2 offset_delta;
  verification_type_info locals[frame_type - 251];
}

class full_frame {public:
  u1 frame_type = FULL_FRAME; /* 255 */
  u2 offset_delta;
  u2 number_of_locals;
  verification_type_info locals[number_of_locals];
  u2 number_of_stack_items;
  verification_type_info stack[number_of_stack_items];
}

union  verification_type_info {
  Top_variable_info,
  Integer_variable_info,
  Float_variable_info,
  Long_variable_info,
  Double_variable_info,
  Null_variable_info,
  UninitializedThis_variable_info,
  Object_variable_info,
  Uninitialized_variable_info
}

class Top_variable_info {public:
  u1 tag = ITEM_Top; /* 0 */
}

class Integer_variable_info {public:
  u1 tag = ITEM_Integer; /* 1 */
}

class Float_variable_info {public:
  u1 tag = ITEM_Float; /* 2 */
}

class Long_variable_info {public:
  u1 tag = ITEM_Long; /* 4 */
}

class Double_variable_info {public:
  u1 tag = ITEM_Double; /* 3 */
}

class Null_variable_info {public:
  u1 tag = ITEM_Null; /* 5 */
}
class UninitializedThis_variable_info {public:
  u1 tag = ITEM_UninitializedThis; /* 6 */
}

class Object_variable_info {public:
  u1 tag = ITEM_Object; /* 7 */
  u2 cpool_index;
}
// Exceptions Attributes
class Exceptions_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_exceptions;
  u2 exception_index_table[number_of_exceptions];
}

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

class InnerClasses_attribute {
  u2 attribute_name_index;
  u4 attribute_length;
  u2 number_of_classes;
  {
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    enum_inner_class_access_flags 
      inner_class_access_flags;
  } classes[number_of_classes];
}

// 4.7.7
class EnclosingMethod_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 class_index;
  u2 method_index;
}

// 4.7.8
class Synthetic_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
}

// 4.7.9
class Signature_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 signature_index;
}

// 4.7.10
class SourceFile_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 sourcefile_index;
}

// 4.7.11
class SourceDebugExtension_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u1 debug_extension[attribute_length];
}

// 4.7.12
class LineNumberTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 line_number_table_length;
  {
    u2 start_pc;
    u2 line_number;
  } line_number_table[line_number_table_length];
}

class LocalVariableTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 local_variable_table_length;
  {
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
  } local_variable_table[local_variable_table_length];
}

// 4.7.14
class LocalVariableTypeTable_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 local_variable_type_table_length;
  {
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 signature_index;
    u2 index;
  } local_variable_type_table[local_variable_type_table_length];
}

// 4.7.15
class Deprecated_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
}

// 4.7.16
class RuntimeVisibleAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 num_annotations;
  annotation annotations[num_annotations];
}

// 4.7.16.1
class element_value {public:
  u1 tag;
  union {
    u2 const_value_index;
    {
      u2 type_name_index;
      u2 const_name_index;
    } enum_const_value;
    u2 class_info_index;
    annotation annotation_value;
    {
      u2 num_values;
      element_value values[num_values];
    } array_value;
  } value;
}

// 4.7.17
class RuntimeInvisibleAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 num_annotations;
  annotation annotations[num_annotations];
}

// 4.7.18
class RuntimeInvisibleAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u2 num_annotations;
  annotation annotations[num_annotations];
}

// 4.7.19
class RuntimeInvisibleParameterAnnotations_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  u1 num_parameters;
  {
    u2  num_annotations;
    annotation annotations[num_annotations];
  } parameter_annotations[num_parameters];
}

// 4.7.20
class AnnotationDefault_attribute {public:
  u2 attribute_name_index;
  u4 attribute_length;
  element_value default_value;
}