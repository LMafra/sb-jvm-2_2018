#pragma once
#include "instructions.hpp"
void (*exec_vet[256])();
/// \brief vetor que armazenara as instrucoes que serao chamadas posteriormente
 void set_exec_vet(){
   exec_vet[0] = exec_jvm_nop;
   exec_vet[1] = exec_jvm_aconst_null;
   exec_vet[2] = exec_jvm_iconst_m1;
   exec_vet[3] = exec_jvm_iconst_0;
   exec_vet[4] = exec_jvm_iconst_1;
   exec_vet[5] = exec_jvm_iconst_2;
   exec_vet[6] = exec_jvm_iconst_3;
   exec_vet[7] = exec_jvm_iconst_4;
   exec_vet[8] = exec_jvm_iconst_5;
   exec_vet[9] = exec_jvm_lconst_0;
   exec_vet[10] = exec_jvm_lconst_1;
   exec_vet[11] = exec_jvm_fconst_0;
   exec_vet[12] = exec_jvm_fconst_1;
   exec_vet[13] = exec_jvm_fconst_2;
   exec_vet[14] = exec_jvm_dconst_0;
   exec_vet[15] = exec_jvm_dconst_1;
   exec_vet[16] = exec_jvm_bipush;
   exec_vet[17] = exec_jvm_sipush;
   exec_vet[18] = exec_jvm_ldc;
   exec_vet[19] = exec_jvm_ldc_w;
   exec_vet[20] = exec_jvm_ldc2_w;
   exec_vet[21] = exec_jvm_iload;
   exec_vet[22] = exec_jvm_lload;
   exec_vet[23] = exec_jvm_fload;
   exec_vet[24] = exec_jvm_dload;
   exec_vet[25] = exec_jvm_aload;
   exec_vet[26] = exec_jvm_iload_0;
   exec_vet[27] = exec_jvm_iload_1;
   exec_vet[28] = exec_jvm_iload_2;
   exec_vet[29] = exec_jvm_iload_3;
   exec_vet[30] = exec_jvm_lload_0;
   exec_vet[31] = exec_jvm_lload_1;
   exec_vet[32] = exec_jvm_lload_2;
   exec_vet[33] = exec_jvm_lload_3;
   exec_vet[34] = exec_jvm_fload_0;
   exec_vet[35] = exec_jvm_fload_1;
   exec_vet[36] = exec_jvm_fload_2;
   exec_vet[37] = exec_jvm_fload_3;
   exec_vet[38] = exec_jvm_dload_0;
   exec_vet[39] = exec_jvm_dload_1;
   exec_vet[40] = exec_jvm_dload_2;
   exec_vet[41] = exec_jvm_dload_3;
   exec_vet[42] = exec_jvm_aload_0;
   exec_vet[43] = exec_jvm_aload_1;
   exec_vet[44] = exec_jvm_aload_2;
   exec_vet[45] = exec_jvm_aload_3;
   exec_vet[46] = exec_jvm_iaload;
   exec_vet[47] = exec_jvm_faload;
   exec_vet[48] = exec_jvm_daload;
   exec_vet[49] = exec_jvm_aaload;
   exec_vet[50] = exec_jvm_baload;
   exec_vet[51] = exec_jvm_caload;
   exec_vet[52] = exec_jvm_saload;
   exec_vet[54] = exec_jvm_istore;
   exec_vet[55] = exec_jvm_lstore;
   exec_vet[56] = exec_jvm_fstore;
   exec_vet[57] = exec_jvm_dstore;
   exec_vet[58] = exec_jvm_astore;
   exec_vet[59] = exec_jvm_istore_0;
   exec_vet[60] = exec_jvm_istore_1;
   exec_vet[61] = exec_jvm_istore_2;
   exec_vet[62] = exec_jvm_istore_3;
   exec_vet[63] = exec_jvm_lstore_0;
   exec_vet[64] = exec_jvm_lstore_1;
   exec_vet[65] = exec_jvm_lstore_2;
   exec_vet[66] = exec_jvm_lstore_3;
   exec_vet[67] = exec_jvm_fstore_0;
   exec_vet[68] = exec_jvm_fstore_1;
   exec_vet[69] = exec_jvm_fstore_2;
   exec_vet[70] = exec_jvm_fstore_3;
   exec_vet[71] = exec_jvm_dstore_0;
   exec_vet[72] = exec_jvm_dstore_1;
   exec_vet[73] = exec_jvm_dstore_2;
   exec_vet[74] = exec_jvm_dstore_3;
   exec_vet[75] = exec_jvm_astore_0;
   exec_vet[76] = exec_jvm_astore_1;
   exec_vet[77] = exec_jvm_astore_2;
   exec_vet[78] = exec_jvm_astore_3;
   exec_vet[79] = exec_jvm_iastore;
   exec_vet[80] = exec_jvm_lastore;
   exec_vet[81] = exec_jvm_fastore;
   exec_vet[82] = exec_jvm_dastore;
   exec_vet[83] = exec_jvm_aastore;
   exec_vet[84] = exec_jvm_bastore;
   exec_vet[85] = exec_jvm_castore;
   exec_vet[86] = exec_jvm_sastore;
   exec_vet[87] = exec_jvm_pop;
   exec_vet[88] = exec_jvm_pop2;
   exec_vet[89] = exec_jvm_dup;
   exec_vet[90] = exec_jvm_dup_x1;
   exec_vet[91] = exec_jvm_dup_x2;
   exec_vet[92] = exec_jvm_dup2;
   exec_vet[93] = exec_jvm_dup2_x1;
   exec_vet[94] = exec_jvm_dup2_x2;
   exec_vet[95] = exec_jvm_swap;
   exec_vet[96] = exec_jvm_iadd;
   exec_vet[97] = exec_jvm_ladd;
   exec_vet[98] = exec_jvm_fadd;
   exec_vet[99] = exec_jvm_dadd;
   exec_vet[100] = exec_jvm_isub;
   exec_vet[101] = exec_jvm_lsub;
   exec_vet[102] = exec_jvm_fsub;
   exec_vet[103] = exec_jvm_dsub;
   exec_vet[104] = exec_jvm_imul;
   exec_vet[105] = exec_jvm_lmul;
   exec_vet[106] = exec_jvm_fmul;
   exec_vet[107] = exec_jvm_dmul;
   exec_vet[108] = exec_jvm_idiv;
   exec_vet[109] = exec_jvm_ldiv;
   exec_vet[110] = exec_jvm_fdiv;
   exec_vet[111] = exec_jvm_ddiv;
   exec_vet[112] = exec_jvm_irem;
   exec_vet[113] = exec_jvm_lrem;
   exec_vet[114] = exec_jvm_frem;
   exec_vet[115] = exec_jvm_drem;
   exec_vet[116] = exec_jvm_ineg;
   exec_vet[117] = exec_jvm_lneg;
   exec_vet[118] = exec_jvm_fneg;
   exec_vet[119] = exec_jvm_dneg;
   exec_vet[120] = exec_jvm_ishl;
   exec_vet[121] = exec_jvm_lshl;
   exec_vet[122] = exec_jvm_ishr;
   exec_vet[123] = exec_jvm_lshr;
   exec_vet[124] = exec_jvm_iushr;
   exec_vet[125] = exec_jvm_lushr;
   exec_vet[126] = exec_jvm_iand;
   exec_vet[127] = exec_jvm_land;
   exec_vet[128] = exec_jvm_ior;
   exec_vet[129] = exec_jvm_lor;
   exec_vet[130] = exec_jvm_ixor;
   exec_vet[131] = exec_jvm_lxor;
   exec_vet[132] = exec_jvm_iinc;
   exec_vet[133] = exec_jvm_i2l;
   exec_vet[134] = exec_jvm_i2f;
   exec_vet[135] = exec_jvm_i2d;
   exec_vet[136] = exec_jvm_l2i;
   exec_vet[137] = exec_jvm_l2f;
   exec_vet[138] = exec_jvm_l2d;
   exec_vet[139] = exec_jvm_f2i;
   exec_vet[140] = exec_jvm_f2l;
   exec_vet[141] = exec_jvm_f2d;
   exec_vet[142] = exec_jvm_d2i;
   exec_vet[143] = exec_jvm_d2l;
   exec_vet[144] = exec_jvm_d2f;
   exec_vet[145] = exec_jvm_i2b;
   exec_vet[146] = exec_jvm_i2c;
   exec_vet[147] = exec_jvm_i2s;
   exec_vet[148] = exec_jvm_lcmp;
   exec_vet[149] = exec_jvm_fcmpl;
   exec_vet[150] = exec_jvm_fcmpg;
   exec_vet[151] = exec_jvm_dcmpl;
   exec_vet[152] = exec_jvm_dcmpg;
   exec_vet[153] = exec_jvm_ifeq;
   exec_vet[154] = exec_jvm_ifne;
   exec_vet[155] = exec_jvm_iflt;
   exec_vet[156] = exec_jvm_ifge;
   exec_vet[157] = exec_jvm_ifgt;
   exec_vet[158] = exec_jvm_ifle;
   exec_vet[159] = exec_jvm_if_icmpeq;
   exec_vet[160] = exec_jvm_if_icmpne;
   exec_vet[161] = exec_jvm_if_icmplt;
   exec_vet[162] = exec_jvm_if_icmpge;
   exec_vet[163] = exec_jvm_if_icmpgt;
   exec_vet[164] = exec_jvm_if_icmple;
   exec_vet[165] = exec_jvm_if_acmpeq;
   exec_vet[166] = exec_jvm_if_acmpne;
   exec_vet[167] = exec_jvm_goto;
   exec_vet[168] = exec_jvm_jsr;
   exec_vet[169] = exec_jvm_ret;
   exec_vet[170] = exec_jvm_tableswitch;
   exec_vet[171] = exec_jvm_lookupswitch;
   exec_vet[172] = exec_jvm_ireturn;
   exec_vet[173] = exec_jvm_lreturn;
   exec_vet[174] = exec_jvm_freturn;
   exec_vet[175] = exec_jvm_dreturn;
   exec_vet[176] = exec_jvm_areturn;
   exec_vet[177] = exec_jvm_return;
   exec_vet[178] = exec_jvm_getstatic;
   exec_vet[179] = exec_jvm_putstatic;
   exec_vet[180] = exec_jvm_getfield;
   exec_vet[181] = exec_jvm_putfield;
   exec_vet[182] = exec_jvm_invokevirtual;
   exec_vet[183] = exec_jvm_invokespecial;
   exec_vet[184] = exec_jvm_invokestatic;
   exec_vet[185] = exec_jvm_invokeinterface;
   exec_vet[186] = exec_jvm_invokedynamic;
   exec_vet[187] = exec_jvm_new;
   exec_vet[188] = exec_jvm_newarray;
   exec_vet[189] = exec_jvm_anewarray;
   exec_vet[190] = exec_jvm_arraylength;
   exec_vet[191] = exec_jvm_athrow;
   exec_vet[192] = exec_jvm_checkcast;
   exec_vet[193] = exec_jvm_instanceof;
   exec_vet[194] = exec_jvm_monitorenter;
   exec_vet[195] = exec_jvm_monitorexit;
   exec_vet[196] = exec_jvm_wide;
   exec_vet[197] = exec_jvm_multianewarray;
   exec_vet[198] = exec_jvm_ifnull;
   exec_vet[199] = exec_jvm_ifnonnull;
   exec_vet[200] = exec_jvm_goto_w;
   exec_vet[201] = exec_jvm_jsr_w;
   exec_vet[202] = exec_jvm_breakpoint;
   exec_vet[254] = exec_jvm_impdep1;
   exec_vet[255] = exec_jvm_impdep2;
   return;
 }
