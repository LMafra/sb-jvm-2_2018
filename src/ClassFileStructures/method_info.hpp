#pragma once
#include "../UsingUs.h"
#include "attribute_info.hpp"
/// \brief classe que define os atributos que serao chamados dentro das instrucoes
class method_info {public:
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info * attributes;
};

namespace enum_method_access_flags{
enum enum_method_access_flags {
  ACC_PUBLIC = 0x0001,// Marked or implicitly public in source.
  ACC_PRIVATE = 0x0002,// Marked private in source.
  ACC_PROTECTED = 0x0004,// Marked protected in source.
  ACC_STATIC = 0x0008,// Marked or implicitly static in source.
  ACC_FINAL = 0x0010,// Marked final in source.
  ACC_SYNCHRONIZED = 0x0020,// Marked final in source.
  ACC_NATIVE = 0x0100,// Was an interface in source.
  ACC_ABSTRACT = 0x0400,// Marked or implicitly abstract in source.
  ACC_STRICT = 0x0800,// Marked final in source.
};}