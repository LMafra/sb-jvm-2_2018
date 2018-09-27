#ifndef __method_info_hpp__
#define __method_info_hpp__

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

class CONSTANT_Utf8_info {
  u1 tag;
  u2 length;
  vector<u1> bytes; //u1 bytes[length]
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

#endif