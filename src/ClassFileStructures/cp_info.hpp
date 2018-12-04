#pragma once
#include "../UsingUs.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
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
#define DOUBLE_FREE "error: DOUBLE FREE AT "

class CONSTANT_Class_info {public:
  u1 tag;
  u2 name_index;
  void fill_from(FILE* f);
};

class CONSTANT_Fieldref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
  void fill_from(FILE* f);
};

class CONSTANT_Methodref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
  void fill_from(FILE* f);
};

class CONSTANT_InterfaceMethodref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
  void fill_from(FILE* f);
};

class CONSTANT_String_info {public:
  u1 tag;
  u2 string_index;
  void fill_from(FILE* f);
};

class CONSTANT_Integer_info {public:
  u1 tag;
  u4 bytes;
  void fill_from(FILE* f);
};

class CONSTANT_Float_info {public:
  u1 tag;
  u4 bytes;
  void fill_from(FILE* f);
};

class CONSTANT_Long_info {public:
  u1 tag;
  u4 high_bytes;
  u4 low_bytes;
  void fill_from(FILE* f);
};

class CONSTANT_Double_info {public:
  u1 tag;
  u4 high_bytes;
  u4 low_bytes;
  void fill_from(FILE* f);
};

class CONSTANT_NameAndType_info {public:
  u1 tag;
  u2 name_index;
  u2 descriptor_index;
  void fill_from(FILE* f);
};

class CONSTANT_Utf8_info {public:
  u1 tag;
  u2 length;
  u1 * bytes;
  void fill_from(FILE* f);
};

class cp_info{public:
  u8 padding1;
  u8 padding2;
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
#include "cp_info.cpp"
