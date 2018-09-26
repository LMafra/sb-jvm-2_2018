#include "UsingUs.hpp"
#include <vector>
using namespace std;
/// \brief Esta classe é usada pela classes ClassFile,
/// field_info, method_info e Code_attributes.
class attribute_info {
private:

public:

  /// typeof constant_pool[attribute_name_index] == CONSTANT_Utf8_info
  /// which represents the name of the attribute.
  u2 attribute_name_index;

  u4 attribute_length;

  // Vetor de tamanho attribute_length*bytes,
  vector<u1> info;

  attribute_info(u2 _attr_name_index, u4 attr_len, ) {
    attribute_info;
  }
}