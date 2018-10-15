#pragma once
#include "../UsingUs.hpp"
#include "attribute_info.hpp"

class method_info {public:
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info * attributes;
};