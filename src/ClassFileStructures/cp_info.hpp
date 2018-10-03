#pragma once
#include "../UsingUs.hpp"
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

class CONSTANT_Class_info {public:
  u1 tag;
  u2 name_index; 
  read_from_file(FILE* f);
};

class CONSTANT_Fieldref_info {public:
  u1 tag;
  u2 class_index; 
  u2 name_and_type_index; 
  read_from_file(FILE* f);
};

class CONSTANT_Methodref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
  void read_from_file(FILE* f);
};

class CONSTANT_InterfaceMethodref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
  read_from_file(FILE* f);
};

class CONSTANT_String_info {public:
  u1 tag;
  u2 string_index;
  read_from_file(FILE* f);
};

class CONSTANT_Integer_info {public:
  u1 tag;
  u4 bytes;
  read_from_file(FILE* f);
};

class CONSTANT_Float_info {public:
  u1 tag;
  u4 bytes;
  read_from_file(FILE* f);
};

class CONSTANT_Long_info {public:
  u1 tag;
  u4 high_bytes;
  u4 low_bytes;
  read_from_file(FILE* f);
};

class CONSTANT_Double_info {public:
  u1 tag;
  u4 high_bytes;
  u4 low_bytes;
  read_from_file(FILE* f);
};

class CONSTANT_NameAndType_info {public:
  u1 tag;
  u2 name_index;
  u2 descriptor_index;
  read_from_file(FILE* f);
};

class CONSTANT_Utf8_info {public:
  u1 tag;
  u2 length;
  u1 * bytes;
  read_from_file(FILE* f);
};

class CONSTANT_MethodHandle_info {public:
  u1 tag;
  u1 reference_kind;
  u2 reference_index;
  read_from_file(FILE* f);
};

class CONSTANT_MethodType_info {public:
  u1 tag;
  u2 descriptor_index;
  read_from_file(FILE* f);
};

class CONSTANT_InvokeDynamic_info {public:
  u1 tag;
  u2 bootstrap_method_attr_index;
  u2 name_and_type_index;
  read_from_file(FILE* f);
};

union cp_info{
  u1 tag;
  CONSTANT_Class_info  Class;
  CONSTANT_Fieldref_info  Fieldref;
  CONSTANT_Methodref_info  Methodref;
  CONSTANT_InterfaceMethodref_info  InterfaceMethodref;
  CONSTANT_String_info  String;
  CONSTANT_Integer_info  Integer;
  CONSTANT_Float_info  Float;
  CONSTANT_Long_info  Long;
  CONSTANT_Double_info  Double;
  CONSTANT_NameAndType_info  NameAndType;
  CONSTANT_Utf8_info  Utf8;
  CONSTANT_MethodHandle_info  MethodHandle;
  CONSTANT_MethodType_info  MethodType;
  CONSTANT_InvokeDynamic_info  InvokeDynamic;
};

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

//std::memcpy(&constant_pool[1],&Class_info,sizeof(help));
//displayCONSTANT_Class_info(TO_CLASS_INFO constant_pool[1]);