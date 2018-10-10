#pragma once
#include "../UsingUs.hpp"
#include "field_info.hpp"
#include "cp_info.hpp"
#include <iostream>

/// definicoes temporarias, soh pra compilar
class method_info{};
// attribute_info_aux.hpp
// enum enum_access_flag;

class ClassFile {
public:
/// The magic item supplies the magic number identifying the class file format;
/// it has the value 0xCAFEBABE .
  u4 magic;

  u2 minor_version;

  u2 major_version;

/// The value of the constant_pool_count item is equal to the number of entries
/// in the constant_pool table plus one.
  u2 constant_pool_count;  // A constant_pool index is considered
                           // valid if it is greater than zero and less than constant_pool_count.

/// The constant_pool table is indexed from
/// 1 to constant_pool_count -1. (farse-à com [0,constant_pool_count])
/// cp_info constant_pool[constant_pool_count-1];
  cp_info* constant_pool;

/// Define se é classe/interface, abstrata ou concreta, asbtrata ou nao...
  u2 access_flags;


/// Indice VALIDO da constant_pool
/// (portanto de 0 a constant_pool_count)
  u2 this_class;


/// Para classe, super_class == 0  (superclasse == Object)
///				OU
///				eh um <i> tal que
///	typeof(constant_pool[i]) == CONSTANT_Class_info,
///		o que representa a superclasse da classe definida
///		nesse ClassFile
  /*
  Neither the direct superclass nor any of
	its superclasses may have the ACC_FINAL flag set in the access_flags item of
	its ClassFile structure. (nao se procupar com isso! javac resolve)
  ///*///
  u2 super_class;

  /*
	the number of direct
	superinterfaces of this class or interface type.
  *///*//
  u2 interfaces_count;

  /*
	Array com elementos que sao INDICES VALIDOS
	na constant_pool.
	Cada elemento indexado deve ser CONSTANT_Class_info
	"representing an interface that is a
	direct superinterface of this class or interface type, in the
	left-to-right order given in the source for the type."
  */
/// u2 interfaces[interfaces_count];
  u2* interfaces;


  u2 fields_count;


/// field_info fields[fields_count];
  field_info* fields;


  u2 methods_count;


/// method_info methods[methods_count];
  method_info* methods;


  u2 attributes_count;


/// attribute_info attributes[attributes_count];
  attribute_info* attributes;

};
