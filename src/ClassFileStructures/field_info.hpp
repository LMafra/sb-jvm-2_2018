#pragma once
#include <vector>
#include <iostream>
#include "../UsingUs.hpp"
#include "attribute_info.hpp"

using namespace std;


// Ver paginas 95-9, ch. 4.5
/* DESTAQUES
""" a  specific field of a class may have at most one of its ACC_PRIVATE
, ACC_PROTECTED, and ACC_PUBLIC flags set and must not have both its
ACC_FINAL and ACC_VOLATILE flags set. """

""" All  fields  of  interfaces  must  have  their  
ACC_PUBLIC, ACC_STATIC, and ACC_FINAL flags set;
they may have their ACC_SYNTHETIC flag set and must not
have any of the other flags in Table 4.4(). """

*/

// MAps the Table 4.4.
// enum enum_access_flag {
// 	ACC_PUBLIC = 0x0001,
// 	ACC_PRIVATE = 0x0002,
// 	ACC_PROTECTED = 0x0004,
// 	ACC_STATIC = 0x0008,
// 	ACC_FINAL = 0x0010,
// 	ACC_VOLATILE = 0x0040,
// 	ACC_TRANSIENT = 0x0080,
// 	ACC_SYNTHETIC = 0x1000,
// 	ACC_ENUM = 0x4000
// };

class field_info {
	public:
		u2 access_flags;

		/// \Um indice valido na constant_pool tal que
		/// typeof constant_pool[name_index] == CONSTANT_Utf8_info
		/// que representa um unqualified name(4.2.2)
		u2 name_index;

		/// - índice válido na contant_pool
		/// - typeof constant_pool[descriptor_index] == CONSTANT_Utf8_info
		/// que representa uma field descriptor válid0 (4.3.2)
		u2 descriptor_index;


		u2 attributes_count;

		attribute_info* attributes;
};