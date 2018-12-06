#pragma once
#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include <map>
/// enum usada pelas instruções Xstore, para evitar replicação de código
enum Helper{
  ZERO = 0,
  ONE = 1,
  TWO = 2,
  THREE = 3,
  NOT_WIDE = 4,
  WIDE = 5
};
/// enum usado para decidir o tipo de variavel
enum Type {
	BYTE=0, CHAR, SHORT, INT,	FLOAT,	DOUBLE, LONG, REFERENCE
};

/// enum para decidir qual tipo de arrayref deve ser criado.
enum enum_atype {
  T_BOOLEAN = 4, T_CHAR = 5, T_FLOAT = 6, T_DOUBLE = 7, T_BYTE = 8,
  T_SHORT = 9, T_INT = 10, T_LONG = 11
};

std::map<int, size_t> atype_size_dict;
// Cuidar caso específico de array de bytes.
void _init_atype_size_dict() {
  atype_size_dict[enum_atype::T_BOOLEAN] = sizeof(u1);
  atype_size_dict[enum_atype::T_CHAR] = sizeof(u1);
  atype_size_dict[enum_atype::T_FLOAT] = sizeof(u4);
  atype_size_dict[enum_atype::T_DOUBLE] = sizeof(u8);
  atype_size_dict[enum_atype::T_BYTE] = sizeof(u1);
  atype_size_dict[enum_atype::T_SHORT] = sizeof(u2);
  atype_size_dict[enum_atype::T_INT] = sizeof(u4);
  atype_size_dict[enum_atype::T_LONG] = sizeof(u8);
}
void load_addr(Helper, cat1 * );
void load_64(Helper, cat1 * );
void load_32(Helper, cat1 * );
auto load_16 = load_32;
auto load_8 = load_32;

void store_addr(Helper, cat1 * );
void store_64(Helper, cat1 * );
void store_32(Helper, cat1 * );
auto store_16 = store_32;
auto store_8 = store_32;

void _resolve_class_name(CONSTANT_Class_info * class_info) {

}

#include "instructions.cpp"

// 0
void exec_jvm_nop();  // Ok, not tested
void exec_jvm_aconst_null();  // Ok, not tested.
void exec_jvm_iconst_m1();  // Ok, not tested.
void exec_jvm_iconst_0(); // Ok, not tested.
void exec_jvm_iconst_1(); // Ok, not tested.
void exec_jvm_iconst_2(); // Ok, not tested.
void exec_jvm_iconst_3(); // Ok, not tested.
void exec_jvm_iconst_4(); // Ok, not tested.
void exec_jvm_iconst_5(); // Ok, not tested.
void exec_jvm_lconst_0(); // Ok, not tested.
void exec_jvm_lconst_1(); // Ok, not tested.
void exec_jvm_fconst_0(); // Ok, not tested.
void exec_jvm_fconst_1(); // Ok, not tested.
void exec_jvm_fconst_2(); // Ok, not tested.
void exec_jvm_dconst_0(); // Ok, not tested.
void exec_jvm_dconst_1(); // Ok, not tested.
void exec_jvm_bipush(); // Ok, not tested.
void exec_jvm_sipush(); // Ok, not tested.
#include "instr0.cpp"

// 1. Maffei. Testar
void exec_jvm_ldc();  // Ok, not tested.
void exec_jvm_ldc_w();  // Ok, not tested.
void exec_jvm_ldc2_w(); // Ok, worked.
void exec_jvm_iload();  // Ok, not tested.
void exec_jvm_iload_0();  // Ok, not tested.
void exec_jvm_iload_1();  // Ok, not tested.
void exec_jvm_iload_2();  // Ok, not tested.
void exec_jvm_iload_3();  // Ok, not tested.
void exec_jvm_lload();  // Ok, not tested.
void exec_jvm_lload_0();  // Ok, not tested.
void exec_jvm_lload_1();  // Ok, not tested.
void exec_jvm_lload_2();  // Ok, not tested.
void exec_jvm_lload_3();  // Ok, not tested.
void exec_jvm_fload();  // Ok, not tested.
void exec_jvm_fload_0();  // Ok, not tested.
void exec_jvm_fload_1();  // Ok, not tested.
void exec_jvm_fload_2();  // Ok, not tested.
void exec_jvm_fload_3();  // Ok, not tested.
void exec_jvm_dload();  // Ok, not tested.
void exec_jvm_dload_0();  // Ok, not tested.
void exec_jvm_dload_1();  // Ok, not tested.
void exec_jvm_dload_2();  // Ok, not tested.
void exec_jvm_dload_3();  // Ok, not tested.
#include "instr1.cpp"

// 2
void exec_jvm_aload();  // Ok, not tested.
void exec_jvm_aload_0();  // Ok, not tested.
void exec_jvm_aload_1();  // Ok, not tested.
void exec_jvm_aload_2();  // Ok, not tested.
void exec_jvm_aload_3();  // Ok, not tested.
void exec_jvm_iaload(); // Ok, tested.
void exec_jvm_faload(); // Ok, not tested.
void exec_jvm_daload(); // Ok, not tested.
void exec_jvm_aaload(); // Ok, not tested.
void exec_jvm_baload(); // Ok, not tested.
void exec_jvm_caload(); // Ok, not tested.
void exec_jvm_saload(); // Ok, not tested.
#include "instr2.cpp"

// 3
void exec_jvm_istore(); // Ok, not tested.
void exec_jvm_istore_0(); // Ok, not tested.
void exec_jvm_istore_1(); // Ok, not tested.
void exec_jvm_istore_2(); // Ok, not tested.
void exec_jvm_istore_3(); // Ok, not tested.
void exec_jvm_lstore(); // Ok, not tested.
void exec_jvm_lstore_0(); // Ok, not tested.
void exec_jvm_lstore_1(); // Ok, not tested.
void exec_jvm_lstore_2(); // Ok, not tested.
void exec_jvm_lstore_3(); // Ok, not tested.
void exec_jvm_fstore(); // Ok, not tested.
void exec_jvm_fstore_0(); // Ok, not tested.
void exec_jvm_fstore_1(); // Ok, not tested.
void exec_jvm_fstore_2(); // Ok, not tested.
void exec_jvm_fstore_3(); // Ok, not tested.
void exec_jvm_astore();  // Ok, not tested.
void exec_jvm_astore_0();  // Ok, not tested.
void exec_jvm_astore_1();  // Ok, not tested.
void exec_jvm_astore_2();  // Ok, not tested.
void exec_jvm_astore_3();  // Ok, not tested.
void exec_jvm_dstore(); // Ok, not tested.
void exec_jvm_dstore_0(); // Ok, not tested.
void exec_jvm_dstore_1(); // Ok, not tested.
void exec_jvm_dstore_2(); // Ok, not tested.
void exec_jvm_dstore_3(); // Ok, not tested.
#include "instr3.cpp"

// 4
void exec_jvm_iastore();  // Ok, not tested.
void exec_jvm_lastore();  // Ok, not tested.
void exec_jvm_fastore();  // Ok, not tested.
void exec_jvm_dastore();  // Ok, not tested.
void exec_jvm_aastore();  // Ok, not tested.
void exec_jvm_bastore();  // Ok, not tested.
void exec_jvm_castore();  // Ok, not tested.
void exec_jvm_sastore();  // Ok, not tested.
void exec_jvm_pop();  // Ok, not tested.
void exec_jvm_pop2(); // Ok, not tested.
void exec_jvm_dup();  // Ok, not tested.
void exec_jvm_dup_x1(); // Ok, not tested.
void exec_jvm_dup_x2(); // Ok, not tested.
void exec_jvm_dup2(); // Ok, not tested.
void exec_jvm_dup2_x1();  // Ok, not tested.
void exec_jvm_dup2_x2();  // Ok, not tested.
void exec_jvm_swap(); // Ok, not tested.
#include "instr4.cpp"

// 5 math_instructions
void exec_jvm_iadd();  // Ok, not tested.
void exec_jvm_ladd();  // Ok, not tested.
void exec_jvm_fadd();  // Ok, not tested.
void exec_jvm_dadd();  // Ok, not tested.
void exec_jvm_isub();  // Ok, not tested.
void exec_jvm_lsub();  // Ok, not tested.
void exec_jvm_fsub();  // Ok, not tested.
void exec_jvm_dsub();  // Ok, not tested.
void exec_jvm_imul();  // Ok, not tested.
void exec_jvm_lmul();  // Ok, not tested.
void exec_jvm_fmul();  // Ok, not tested.
void exec_jvm_dmul();  // Ok, not tested.
void exec_jvm_idiv();  // Ok, not tested.
void exec_jvm_ldiv();  // Ok, not tested.
void exec_jvm_fdiv();  // Ok, not tested.
void exec_jvm_ddiv();  // Ok, not tested.
void exec_jvm_irem();  // Ok, not tested.
void exec_jvm_lrem();  // Ok, not tested.
void exec_jvm_frem();  // Ok, not tested.
void exec_jvm_drem();  // Ok, not tested.
void exec_jvm_ineg();  // Ok, not tested.
void exec_jvm_lneg();  // Ok, not tested.
void exec_jvm_fneg();  // Ok, not tested.
void exec_jvm_dneg();  // Ok, not tested.
void exec_jvm_ishl();  // Ok, not tested.
void exec_jvm_lshl();  // Ok, not tested.
void exec_jvm_ishr();  // Ok, not tested.
void exec_jvm_lshr();  // Ok, not tested.
void exec_jvm_iushr();  // Ok, not tested.
void exec_jvm_lushr();  // Ok, not tested.
void exec_jvm_iand();  // Ok, not tested.
void exec_jvm_land();  // Ok, not tested.
void exec_jvm_ior();  // Ok, not tested.
void exec_jvm_lor();  // Ok, not tested.
void exec_jvm_ixor();  // Ok, not tested.
void exec_jvm_lxor();  // Ok, not tested.
void exec_jvm_iinc();  // Ok, not tested. [Fixed 2443]
#include "instr5.cpp"

// 6
void exec_jvm_i2l(); // Ok, not tested.
void exec_jvm_i2f(); // Ok, not tested.
void exec_jvm_i2d(); // Ok, not tested.
void exec_jvm_l2i(); // Ok, not tested.
void exec_jvm_l2f(); // Ok, not tested.
void exec_jvm_l2d(); // Ok, not tested.
void exec_jvm_f2i(); // Ok, not tested.
void exec_jvm_f2l(); // Ok, not tested.
void exec_jvm_f2d(); // Ok, not tested.
void exec_jvm_d2i(); // Ok, not tested.
void exec_jvm_d2l(); // Ok, not tested.
void exec_jvm_d2f(); // Ok, not tested.
void exec_jvm_i2b(); // Ok, not tested.
void exec_jvm_i2c(); // Ok, not tested.
void exec_jvm_i2s(); // Ok, not tested.
#include "instr6.cpp"

// 7
void exec_jvm_lcmp(); // Ok, not tested.
void exec_jvm_fcmpl();  // Ok, not tested.
void exec_jvm_fcmpg();  // Ok, not tested.
void exec_jvm_dcmpl();  // Ok, not tested.
void exec_jvm_dcmpg();  // Ok, not tested.
void exec_jvm_ifeq(); // Ok, not tested.
void exec_jvm_ifne(); // Ok, not tested.
void exec_jvm_iflt(); // Ok, not tested.
void exec_jvm_ifge(); // Ok, not tested.
void exec_jvm_ifgt(); // Ok, not tested.
void exec_jvm_ifle(); // Ok, not tested.
void exec_jvm_if_icmpeq();  // Ok, not tested.
void exec_jvm_if_icmpne();  // Ok, not tested.
void exec_jvm_if_icmplt();  // Ok, not tested.
void exec_jvm_if_icmpge();  // Ok, not tested.
void exec_jvm_if_icmpgt();  // Ok, not tested.
void exec_jvm_if_icmple();  // Ok, not tested.
void exec_jvm_if_acmpeq();  // Ok, not tested.
void exec_jvm_if_acmpne();  // Ok, not tested.
#include "instr7.cpp"

// 8
void exec_jvm_goto(); // Ok, not tested
void exec_jvm_jsr();  // Ok, not tested
void exec_jvm_ret();  // Ok, not tested
void exec_jvm_tableswitch();  // TO FINISH
void exec_jvm_lookupswitch();
void exec_jvm_ireturn();  // Ok, not tested.
void exec_jvm_lreturn();  // Ok, not tested.
void exec_jvm_freturn();  // Ok, not tested.
void exec_jvm_dreturn();  // Ok, not tested.
void exec_jvm_areturn();  // Ok, not tested.
void exec_jvm_return(); // Ok, not tested.
void exec_jvm_getstatic();  // TO FIX
void exec_jvm_putstatic();
void exec_jvm_getfield();
void exec_jvm_putfield(); // Doing...
void exec_jvm_invokevirtual();
void exec_jvm_invokespecial();
void exec_jvm_invokestatic();
void exec_jvm_invokeinterface();
void exec_jvm_invokedynamic();  // nao precisa fazer
#include "instr8.cpp"

// 9
void exec_jvm_new();  // Ok, not tested
void exec_jvm_newarray(); // Ok, not tested.
void exec_jvm_anewarray();  // TO FINISH.
void exec_jvm_arraylength();  // Ok, not tested.
void exec_jvm_athrow();
void exec_jvm_checkcast();
void exec_jvm_instanceof();
void exec_jvm_monitorenter();  // nao precisa fazer
void exec_jvm_monitorexit();  // nao precisa fazer
void exec_jvm_wide();
void exec_jvm_multianewarray();
void exec_jvm_ifnull(); // Ok, not tested
void exec_jvm_ifnonnull();  // Ok, not tested
void exec_jvm_goto_w(); // Ok, not tested
void exec_jvm_jsr_w();  // Ok, not tested
void exec_jvm_breakpoint(); // Reservado
void exec_jvm_impdep1();  // Reservado
void exec_jvm_impdep2();  // Reservado
#include "instr9.cpp"
