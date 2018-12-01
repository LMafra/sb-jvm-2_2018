#pragma once
#include "../UsingUs.hpp"
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
void exec_jvm_ldc_w();
void exec_jvm_ldc2_w();
void exec_jvm_iload();
void exec_jvm_iload_0();  // Ok, not tested.
void exec_jvm_iload_1();  // Ok, not tested.
void exec_jvm_iload_2();  // Ok, not tested.
void exec_jvm_iload_3();  // Ok, not tested.
void exec_jvm_lload(u1);  // Ok, not tested.
void exec_jvm_lload_0();  // Ok, not tested.
void exec_jvm_lload_1();  // Ok, not tested.
void exec_jvm_lload_2();  // Ok, not tested.
void exec_jvm_lload_3();  // Ok, not tested.
void exec_jvm_fload(u1);  // Ok, not tested.
void exec_jvm_fload_0();  // Ok, not tested.
void exec_jvm_fload_1();  // Ok, not tested.
void exec_jvm_fload_2();  // Ok, not tested.
void exec_jvm_fload_3();  // Ok, not tested.
void exec_jvm_dload(u1);  // Ok, not tested.
void exec_jvm_dload_0();  // Ok, not tested.
void exec_jvm_dload_1();  // Ok, not tested.
void exec_jvm_dload_2();  // Ok, not tested.
void exec_jvm_dload_3();  // Ok, not tested.
#include "instr1.cpp"

// 2
void exec_jvm_aload(u1);
void exec_jvm_aload_0();
void exec_jvm_aload_1();
void exec_jvm_aload_2();
void exec_jvm_aload_3();
void exec_jvm_iaload();
void exec_jvm_faload();
void exec_jvm_daload();
void exec_jvm_aaload();
void exec_jvm_baload();
void exec_jvm_caload();
void exec_jvm_saload();
#include "instr2.cpp"

// 3
void exec_jvm_istore();
void exec_jvm_lstore();
void exec_jvm_fstore();
void exec_jvm_dstore();
void exec_jvm_astore();
void exec_jvm_istore_0();
void exec_jvm_istore_1();
void exec_jvm_istore_2();
void exec_jvm_istore_3();
void exec_jvm_lstore_0();
void exec_jvm_lstore_1();
void exec_jvm_lstore_2();
void exec_jvm_lstore_3();
void exec_jvm_fstore_0();
void exec_jvm_fstore_1();
void exec_jvm_fstore_2();
void exec_jvm_fstore_3();
void exec_jvm_dstore_0();
void exec_jvm_dstore_1();
void exec_jvm_dstore_2();
void exec_jvm_dstore_3();
void exec_jvm_astore_0();
void exec_jvm_astore_1();
void exec_jvm_astore_2();
void exec_jvm_astore_3();
void exec_jvm_iastore();
void exec_jvm_lastore();
void exec_jvm_fastore();
void exec_jvm_dastore();
#include "instr3.cpp"

// 4
void exec_jvm_aastore();
void exec_jvm_bastore();
void exec_jvm_castore();
void exec_jvm_sastore();
void exec_jvm_pop();
void exec_jvm_pop2();
void exec_jvm_dup();
void exec_jvm_dup_x1();
void exec_jvm_dup_x2();
void exec_jvm_dup2();
void exec_jvm_dup2_x1();
void exec_jvm_dup2_x2();
void exec_jvm_swap();
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
void exec_jvm_iinc();  // Ok, not tested.
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
void exec_jvm_goto();
void exec_jvm_jsr();
void exec_jvm_ret();
void exec_jvm_tableswitch();
void exec_jvm_lookupswitch();
void exec_jvm_ireturn();
void exec_jvm_lreturn();
void exec_jvm_freturn();
void exec_jvm_dreturn();
void exec_jvm_areturn();
void exec_jvm_return();
void exec_jvm_getstatic();
void exec_jvm_putstatic();
void exec_jvm_getfield();
void exec_jvm_putfield();
void exec_jvm_invokevirtual();
void exec_jvm_invokespecial();
void exec_jvm_invokestatic();
void exec_jvm_invokeinterface();
void exec_jvm_invokedynamic();
#include "instr8.cpp"

// 9
void exec_jvm_new();
void exec_jvm_newarray();
void exec_jvm_anewarray();
void exec_jvm_arraylength();
void exec_jvm_athrow();
void exec_jvm_checkcast();
void exec_jvm_instanceof();
void exec_jvm_monitorenter();
void exec_jvm_monitorexit();
void exec_jvm_wide();
void exec_jvm_multianewarray();
void exec_jvm_ifnull();
void exec_jvm_ifnonnull();
void exec_jvm_goto_w();
void exec_jvm_jsr_w();
void exec_jvm_breakpoint();
void exec_jvm_impdep1();
void exec_jvm_impdep2();
#include "instr9.cpp"