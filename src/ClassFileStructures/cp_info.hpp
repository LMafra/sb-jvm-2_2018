#ifndef __cp_info_hpp__
#define __cp_info_hpp__
#include <vector>
class CONSTANT_Class_info {public:
  u1 tag;
  u2 name_index; 
};

class CONSTANT_Fieldref_info {public:
  u1 tag;
  u2 class_index; 
  u2 name_and_type_index; 
};

class CONSTANT_Methodref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
};

class CONSTANT_InterfaceMethodref_info {public:
  u1 tag;
  u2 class_index;
  u2 name_and_type_index;
};

class CONSTANT_String_info {public:
  u1 tag;
  u2 string_index;
};

class CONSTANT_Integer_info {public:
  u1 tag;
  u4 bytes;
};

class CONSTANT_Float_info {public:
  u1 tag;
  u4 bytes;
};

class CONSTANT_Long_info {public:
  u1 tag;
  u4 high_bytes;
  u4 low_bytes;
};

class CONSTANT_Double_info {public:
  u1 tag;
  u4 high_bytes;
  u4 low_bytes;
};

class CONSTANT_NameAndType_info {public:
  u1 tag;
  u2 name_index;
  u2 descriptor_index;
};

class CONSTANT_Utf8_info {public:
  u1 tag;
  u2 length;
  u1 * bytes;
  //std::vector<u1> bytes; //u1 bytes[length]
};

class CONSTANT_MethodHandle_info {public:
  u1 tag;
  u1 reference_kind;
  u2 reference_index;
};

class CONSTANT_MethodType_info {public:
  u1 tag;
  u2 descriptor_index;
};

class CONSTANT_InvokeDynamic_info {public:
  u1 tag;
  u2 bootstrap_method_attr_index;
  u2 name_and_type_index;
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


#endif