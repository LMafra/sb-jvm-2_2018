// #pragma once
// #include "ViewerFiles§Exibidor.hpp"
// void Exibidor::set_print_vet(){
//   print_vet[0] = &Exibidor::print_jvm_nop;
//   print_vet[1] = &Exibidor::print_jvm_aconst_null;
//   print_vet[2] = &Exibidor::print_jvm_iconst_m1;
//   print_vet[3] = &Exibidor::print_jvm_iconst_0;
//   print_vet[4] = &Exibidor::print_jvm_iconst_1;
//   print_vet[5] = &Exibidor::print_jvm_iconst_2;
//   print_vet[6] = &Exibidor::print_jvm_iconst_3;
//   print_vet[7] = &Exibidor::print_jvm_iconst_4;
//   print_vet[8] = &Exibidor::print_jvm_iconst_5;
//   print_vet[9] = &Exibidor::print_jvm_lconst_0;
//   print_vet[10] = &Exibidor::print_jvm_lconst_1;
//   print_vet[11] = &Exibidor::print_jvm_fconst_0;
//   print_vet[12] = &Exibidor::print_jvm_fconst_1;
//   print_vet[13] = &Exibidor::print_jvm_fconst_2;
//   print_vet[14] = &Exibidor::print_jvm_dconst_0;
//   print_vet[15] = &Exibidor::print_jvm_dconst_1;
//   print_vet[16] = &Exibidor::print_jvm_bipush;
//   print_vet[17] = &Exibidor::print_jvm_sipush;
//   print_vet[18] = &Exibidor::print_jvm_ldc;
//   print_vet[19] = &Exibidor::print_jvm_ldc_w;
//   print_vet[20] = &Exibidor::print_jvm_ldc2_w;
//   print_vet[21] = &Exibidor::print_jvm_iload;
//   print_vet[22] = &Exibidor::print_jvm_lload;
//   print_vet[23] = &Exibidor::print_jvm_fload;
//   print_vet[24] = &Exibidor::print_jvm_dload;
//   print_vet[25] = &Exibidor::print_jvm_aload;
//   print_vet[26] = &Exibidor::print_jvm_iload_0;
//   print_vet[27] = &Exibidor::print_jvm_iload_1;
//   print_vet[28] = &Exibidor::print_jvm_iload_2;
//   print_vet[29] = &Exibidor::print_jvm_iload_3;
//   print_vet[30] = &Exibidor::print_jvm_lload_0;
//   print_vet[31] = &Exibidor::print_jvm_lload_1;
//   print_vet[32] = &Exibidor::print_jvm_lload_2;
//   print_vet[33] = &Exibidor::print_jvm_lload_3;
//   print_vet[34] = &Exibidor::print_jvm_fload_0;
//   print_vet[35] = &Exibidor::print_jvm_fload_1;
//   print_vet[36] = &Exibidor::print_jvm_fload_2;
//   print_vet[37] = &Exibidor::print_jvm_fload_3;
//   print_vet[38] = &Exibidor::print_jvm_dload_0;
//   print_vet[39] = &Exibidor::print_jvm_dload_1;
//   print_vet[40] = &Exibidor::print_jvm_dload_2;
//   print_vet[41] = &Exibidor::print_jvm_dload_3;
//   print_vet[42] = &Exibidor::print_jvm_aload_0;
//   print_vet[43] = &Exibidor::print_jvm_aload_1;
//   print_vet[44] = &Exibidor::print_jvm_aload_2;
//   print_vet[45] = &Exibidor::print_jvm_aload_3;
//   print_vet[46] = &Exibidor::print_jvm_iaload;
//   print_vet[47] = &Exibidor::print_jvm_faload;
//   print_vet[48] = &Exibidor::print_jvm_daload;
//   print_vet[49] = &Exibidor::print_jvm_aaload;
//   print_vet[50] = &Exibidor::print_jvm_baload;
//   print_vet[51] = &Exibidor::print_jvm_caload;
//   print_vet[52] = &Exibidor::print_jvm_saload;
//   print_vet[54] = &Exibidor::print_jvm_istore;
//   print_vet[55] = &Exibidor::print_jvm_lstore;
//   print_vet[56] = &Exibidor::print_jvm_fstore;
//   print_vet[57] = &Exibidor::print_jvm_dstore;
//   print_vet[58] = &Exibidor::print_jvm_astore;
//   print_vet[59] = &Exibidor::print_jvm_istore_0;
//   print_vet[60] = &Exibidor::print_jvm_istore_1;
//   print_vet[61] = &Exibidor::print_jvm_istore_2;
//   print_vet[62] = &Exibidor::print_jvm_istore_3;
//   print_vet[63] = &Exibidor::print_jvm_lstore_0;
//   print_vet[64] = &Exibidor::print_jvm_lstore_1;
//   print_vet[65] = &Exibidor::print_jvm_lstore_2;
//   print_vet[66] = &Exibidor::print_jvm_lstore_3;
//   print_vet[67] = &Exibidor::print_jvm_fstore_0;
//   print_vet[68] = &Exibidor::print_jvm_fstore_1;
//   print_vet[69] = &Exibidor::print_jvm_fstore_2;
//   print_vet[70] = &Exibidor::print_jvm_fstore_3;
//   print_vet[71] = &Exibidor::print_jvm_dstore_0;
//   print_vet[72] = &Exibidor::print_jvm_dstore_1;
//   print_vet[73] = &Exibidor::print_jvm_dstore_2;
//   print_vet[74] = &Exibidor::print_jvm_dstore_3;
//   print_vet[75] = &Exibidor::print_jvm_astore_0;
//   print_vet[76] = &Exibidor::print_jvm_astore_1;
//   print_vet[77] = &Exibidor::print_jvm_astore_2;
//   print_vet[78] = &Exibidor::print_jvm_astore_3;
//   print_vet[79] = &Exibidor::print_jvm_iastore;
//   print_vet[80] = &Exibidor::print_jvm_lastore;
//   print_vet[81] = &Exibidor::print_jvm_fastore;
//   print_vet[82] = &Exibidor::print_jvm_dastore;
//   print_vet[83] = &Exibidor::print_jvm_aastore;
//   print_vet[84] = &Exibidor::print_jvm_bastore;
//   print_vet[85] = &Exibidor::print_jvm_castore;
//   print_vet[86] = &Exibidor::print_jvm_sastore;
//   print_vet[87] = &Exibidor::print_jvm_pop;
//   print_vet[88] = &Exibidor::print_jvm_pop2;
//   print_vet[89] = &Exibidor::print_jvm_dup;
//   print_vet[90] = &Exibidor::print_jvm_dup_x1;
//   print_vet[91] = &Exibidor::print_jvm_dup_x2;
//   print_vet[92] = &Exibidor::print_jvm_dup2;
//   print_vet[93] = &Exibidor::print_jvm_dup2_x1;
//   print_vet[94] = &Exibidor::print_jvm_dup2_x2;
//   print_vet[95] = &Exibidor::print_jvm_swap;
//   print_vet[96] = &Exibidor::print_jvm_iadd;
//   print_vet[97] = &Exibidor::print_jvm_ladd;
//   print_vet[98] = &Exibidor::print_jvm_fadd;
//   print_vet[99] = &Exibidor::print_jvm_dadd;
//   print_vet[100] = &Exibidor::print_jvm_isub;
//   print_vet[101] = &Exibidor::print_jvm_lsub;
//   print_vet[102] = &Exibidor::print_jvm_fsub;
//   print_vet[103] = &Exibidor::print_jvm_dsub;
//   print_vet[104] = &Exibidor::print_jvm_imul;
//   print_vet[105] = &Exibidor::print_jvm_lmul;
//   print_vet[106] = &Exibidor::print_jvm_fmul;
//   print_vet[107] = &Exibidor::print_jvm_dmul;
//   print_vet[108] = &Exibidor::print_jvm_idiv;
//   print_vet[109] = &Exibidor::print_jvm_ldiv;
//   print_vet[110] = &Exibidor::print_jvm_fdiv;
//   print_vet[111] = &Exibidor::print_jvm_ddiv;
//   print_vet[112] = &Exibidor::print_jvm_irem;
//   print_vet[113] = &Exibidor::print_jvm_lrem;
//   print_vet[114] = &Exibidor::print_jvm_frem;
//   print_vet[115] = &Exibidor::print_jvm_drem;
//   print_vet[116] = &Exibidor::print_jvm_ineg;
//   print_vet[117] = &Exibidor::print_jvm_lneg;
//   print_vet[118] = &Exibidor::print_jvm_fneg;
//   print_vet[119] = &Exibidor::print_jvm_dneg;
//   print_vet[120] = &Exibidor::print_jvm_ishl;
//   print_vet[121] = &Exibidor::print_jvm_lshl;
//   print_vet[122] = &Exibidor::print_jvm_ishr;
//   print_vet[123] = &Exibidor::print_jvm_lshr;
//   print_vet[124] = &Exibidor::print_jvm_iushr;
//   print_vet[125] = &Exibidor::print_jvm_lushr;
//   print_vet[126] = &Exibidor::print_jvm_iand;
//   print_vet[127] = &Exibidor::print_jvm_land;
//   print_vet[128] = &Exibidor::print_jvm_ior;
//   print_vet[129] = &Exibidor::print_jvm_lor;
//   print_vet[130] = &Exibidor::print_jvm_ixor;
//   print_vet[131] = &Exibidor::print_jvm_lxor;
//   print_vet[132] = &Exibidor::print_jvm_iinc;
//   print_vet[133] = &Exibidor::print_jvm_i2l;
//   print_vet[134] = &Exibidor::print_jvm_i2f;
//   print_vet[135] = &Exibidor::print_jvm_i2d;
//   print_vet[136] = &Exibidor::print_jvm_l2i;
//   print_vet[137] = &Exibidor::print_jvm_l2f;
//   print_vet[138] = &Exibidor::print_jvm_l2d;
//   print_vet[139] = &Exibidor::print_jvm_f2i;
//   print_vet[140] = &Exibidor::print_jvm_f2l;
//   print_vet[141] = &Exibidor::print_jvm_f2d;
//   print_vet[142] = &Exibidor::print_jvm_d2i;
//   print_vet[143] = &Exibidor::print_jvm_d2l;
//   print_vet[144] = &Exibidor::print_jvm_d2f;
//   print_vet[145] = &Exibidor::print_jvm_i2b;
//   print_vet[146] = &Exibidor::print_jvm_i2c;
//   print_vet[147] = &Exibidor::print_jvm_i2s;
//   print_vet[148] = &Exibidor::print_jvm_lcmp;
//   print_vet[149] = &Exibidor::print_jvm_fcmpl;
//   print_vet[150] = &Exibidor::print_jvm_fcmpg;
//   print_vet[151] = &Exibidor::print_jvm_dcmpl;
//   print_vet[152] = &Exibidor::print_jvm_dcmpg;
//   print_vet[153] = &Exibidor::print_jvm_ifeq;
//   print_vet[154] = &Exibidor::print_jvm_ifne;
//   print_vet[155] = &Exibidor::print_jvm_iflt;
//   print_vet[156] = &Exibidor::print_jvm_ifge;
//   print_vet[157] = &Exibidor::print_jvm_ifgt;
//   print_vet[158] = &Exibidor::print_jvm_ifle;
//   print_vet[159] = &Exibidor::print_jvm_if_icmpeq;
//   print_vet[160] = &Exibidor::print_jvm_if_icmpne;
//   print_vet[161] = &Exibidor::print_jvm_if_icmplt;
//   print_vet[162] = &Exibidor::print_jvm_if_icmpge;
//   print_vet[163] = &Exibidor::print_jvm_if_icmpgt;
//   print_vet[164] = &Exibidor::print_jvm_if_icmple;
//   print_vet[165] = &Exibidor::print_jvm_if_acmpeq;
//   print_vet[166] = &Exibidor::print_jvm_if_acmpne;
//   print_vet[167] = &Exibidor::print_jvm_goto;
//   print_vet[168] = &Exibidor::print_jvm_jsr;
//   print_vet[169] = &Exibidor::print_jvm_ret;
//   print_vet[170] = &Exibidor::print_jvm_tableswitch;
//   print_vet[171] = &Exibidor::print_jvm_lookupswitch;
//   print_vet[172] = &Exibidor::print_jvm_ireturn;
//   print_vet[173] = &Exibidor::print_jvm_lreturn;
//   print_vet[174] = &Exibidor::print_jvm_freturn;
//   print_vet[175] = &Exibidor::print_jvm_dreturn;
//   print_vet[176] = &Exibidor::print_jvm_areturn;
//   print_vet[177] = &Exibidor::print_jvm_return;
//   print_vet[178] = &Exibidor::print_jvm_getstatic;
//   print_vet[179] = &Exibidor::print_jvm_putstatic;
//   print_vet[180] = &Exibidor::print_jvm_getfield;
//   print_vet[181] = &Exibidor::print_jvm_putfield;
//   print_vet[182] = &Exibidor::print_jvm_invokevirtual;
//   print_vet[183] = &Exibidor::print_jvm_invokespecial;
//   print_vet[184] = &Exibidor::print_jvm_invokestatic;
//   print_vet[185] = &Exibidor::print_jvm_invokeinterface;
//   print_vet[186] = &Exibidor::print_jvm_invokedynamic;
//   print_vet[187] = &Exibidor::print_jvm_new;
//   print_vet[188] = &Exibidor::print_jvm_newarray;
//   print_vet[189] = &Exibidor::print_jvm_anewarray;
//   print_vet[190] = &Exibidor::print_jvm_arraylength;
//   print_vet[191] = &Exibidor::print_jvm_athrow;
//   print_vet[192] = &Exibidor::print_jvm_checkcast;
//   print_vet[193] = &Exibidor::print_jvm_instanceof;
//   print_vet[194] = &Exibidor::print_jvm_monitorenter;
//   print_vet[195] = &Exibidor::print_jvm_monitorexit;
//   print_vet[196] = &Exibidor::print_jvm_wide;
//   print_vet[197] = &Exibidor::print_jvm_multianewarray;
//   print_vet[198] = &Exibidor::print_jvm_ifnull;
//   print_vet[199] = &Exibidor::print_jvm_ifnonnull;
//   print_vet[200] = &Exibidor::print_jvm_goto_w;
//   print_vet[201] = &Exibidor::print_jvm_jsr_w;
//   print_vet[202] = &Exibidor::print_jvm_breakpoint;
//   print_vet[254] = &Exibidor::print_jvm_impdep1;
//   print_vet[255] = &Exibidor::print_jvm_impdep2;
//   return;
// }


// void Exibidor::displayClassFile(ClassFile & theclass){  // TODO encontrar this class e super class na constant pool para exibir
// 	/// imprime os dados gerais de class file.
// 	///
// 	std::cout << "class file:" << std::endl;
// 	std::cout << "  Minor version: " << theclass.minor_version << std::endl;
// 	std::cout << "  Major version: " << theclass.major_version << std::endl;
// 	std::cout << "  Constant Pool Count: " << theclass.constant_pool_count << std::endl;
// 	// TODO apresentar mnemonicos das flags
// 	std::cout << "  Access Flags: " << std::hex << std::showbase << std::uppercase << theclass.access_flags << " ";
// 	displayClassFileFlags(theclass);
// 	std::cout << std::endl << std::dec;
// 	std::cout << "  This Class: cp_info# " << theclass.this_class << " ";
// 	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theclass.this_class]);
// 	std::cout << std::endl;
// 	std::cout << "  Super Class: cp_info# " << theclass.super_class << " ";
// 	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theclass.super_class]);
// 	std::cout << std::endl;
// 	std::cout << "  Interfaces Count: " << theclass.interfaces_count << std::endl;
// 	std::cout << "  Fields Count: " << theclass.fields_count << std::endl;
// 	std::cout << "  Methods Count: " << theclass.methods_count << std::endl;
// 	std::cout << "  Attributes Count: " << theclass.attributes_count << std::endl;
// 	std::cout << std::endl << std::endl;
// }

// void Exibidor::displayClassFileFlags(ClassFile & theclass){
// 	if (theclass.access_flags & ClassFileFlags::ACC_PUBLIC){
// 		printf("[public]");
// 	}
// 	if (theclass.access_flags & ClassFileFlags::ACC_FINAL){
// 		printf("[final]");
// 	}
// 	if (theclass.access_flags & ClassFileFlags::ACC_SUPER){
// 		printf("[super]");
// 	}
// 	if (theclass.access_flags & ClassFileFlags::ACC_INTERFACE){
// 		printf("[interface]");
// 	}
// 	if (theclass.access_flags & ClassFileFlags::ACC_ABSTRACT){
// 		printf("[abstract]");
// 	}
// }

// void Exibidor::displayClassInfoString(CONSTANT_Class_info & theinfo){
// 	printf("EH O Q?\n");
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.name_index]);
// }
// void Exibidor::displayClassInfoStringRaw(CONSTANT_Class_info & theinfo){
// 	displayUtf8InfoStringRaw(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.name_index]);
// }


// void Exibidor::displayUtf8InfoString(CONSTANT_Utf8_info & theinfo){
// 	std::cout << "<";
// 	for(int i=0;i<theinfo.length;i++)
// 		std::cout << (u1)theinfo.bytes[i];
// 	std::cout << ">";
// }
// void Exibidor::displayUtf8InfoStringRaw(CONSTANT_Utf8_info & theinfo){
// 	for(int i=0;i<theinfo.length;i++)
// 		std::cout << (u1)theinfo.bytes[i];
// }

// void Exibidor::displayNameTypeInfoString(CONSTANT_NameAndType_info & theinfo){
// 	CONSTANT_Utf8_info & aux = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.name_index];
// 	CONSTANT_Utf8_info & aux2 = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.descriptor_index];
// 	std::cout << "<";
// 	for(int i=0;i<aux.length;i++)
// 		std::cout << (u1)aux.bytes[i];
// 	std::cout << " : ";
// 	for(int i=0;i<aux2.length;i++)
// 		std::cout << (u1)aux2.bytes[i];
// 	std::cout << ">";
// }

// void Exibidor::displayCONSTANT_Class_info(CONSTANT_Class_info & theclassinfo){
// 	std::cout << "   Class Name: cp_info# " << theclassinfo.name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theclassinfo.name_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Fieldref_info(CONSTANT_Fieldref_info & thefieldinfo){
// 	std::cout << "   Class/Interface Name: cp_info# " << thefieldinfo.class_index << " ";
// 	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[thefieldinfo.class_index]);
// 	std::cout << std::endl;
// 	std::cout << "   Name and Type: cp_info# " << thefieldinfo.name_and_type_index << " ";
// 	displayNameTypeInfoString(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[thefieldinfo.name_and_type_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_NameAndType_info(CONSTANT_NameAndType_info & thenameandtypeinfo){
// 	std::cout << "   Name: cp_info# " << thenameandtypeinfo.name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[thenameandtypeinfo.name_index]);
// 	std::cout << std::endl;
// 	std::cout << "   Type Descriptor: cp_info# " << thenameandtypeinfo.descriptor_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[thenameandtypeinfo.descriptor_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Utf8_info(CONSTANT_Utf8_info & theunistringinfo){
// 	std::cout << "   ";
// 	for(int i=0;i<theunistringinfo.length;i++)
// 		std::cout << (u1)theunistringinfo.bytes[i];
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Methodref_info(CONSTANT_Methodref_info & themethodinfo){
// 	std::cout << "   Class Name: cp_info# " << themethodinfo.class_index << " ";
// 	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[themethodinfo.class_index]);
// 	std::cout << std::endl;
// 	std::cout << "   Name and Type: cp_info# " << themethodinfo.name_and_type_index << " ";
// 	displayNameTypeInfoString(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[themethodinfo.name_and_type_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_InterfaceMethodref_info(CONSTANT_InterfaceMethodref_info & themethodinfo){
// 	std::cout << "   Interface Name: cp_info# " << themethodinfo.class_index << " ";
// 	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[themethodinfo.class_index]);
// 	std::cout << std::endl;
// 	std::cout << "   Name and Type: cp_info# " << themethodinfo.name_and_type_index << " ";
// 	displayNameTypeInfoString(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[themethodinfo.name_and_type_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_String_info(CONSTANT_String_info & thestringinfo){
// 	std::cout << "   String Text: cp_info# " << thestringinfo.string_index;
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[thestringinfo.string_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Integer_info(CONSTANT_Integer_info & theintinfo){
// 	std::cout << "   Value: " << theintinfo.bytes << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Float_info(CONSTANT_Float_info & thefloatinfo){
// 	float buff;
// 	std::memcpy(&buff, &thefloatinfo.bytes, sizeof(thefloatinfo.bytes));
// 	std::cout << "   Value: " << buff << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Long_info(CONSTANT_Long_info & thelonginfo){
// 	uint32_t buff[2];
// 	std::memcpy(&buff[1], &thelonginfo.high_bytes, sizeof(thelonginfo.high_bytes));
// 	std::memcpy(&buff[0], &thelonginfo.low_bytes, sizeof(thelonginfo.low_bytes));
// 	std::cout << "   Value: " << *((uint64_t*)buff) << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayCONSTANT_Double_info(CONSTANT_Double_info & thedoubleinfo){
// 	uint32_t buff[2];
// 	std::memcpy(&buff[1], &thedoubleinfo.high_bytes, sizeof(thedoubleinfo.high_bytes));
// 	std::memcpy(&buff[0], &thedoubleinfo.low_bytes, sizeof(thedoubleinfo.low_bytes));
// 	std::cout << "   High bytes: " << std::hex << buff[1] << endl;
// 	std::cout << "   Low bytes: " << std::hex << buff[0] << endl << std::dec;
// 	std::cout << "   Value: " << *((double*)buff) << std::endl;
// 	std::cout << std::endl;
// }

// void Exibidor::displayconstant_pool(ClassFile & theclass){  // TODO encontrar this class e super class na constant pool para exibir
// 	/// imprime as entradas.
//     std::cout << " Constant Pool:\n";
// 	for(size_t i = 1; i < theclass.constant_pool_count; i++) {
//     	u1 tag;
//     	memcpy(&tag, &theclass.constant_pool[i],sizeof(tag));
// 			std::cout << "  [" << i <<  "] ";
//     	switch(tag) {
//     	case enum_cp_tags::CONSTANT_Class:
// 				cout << "CONSTANT_Class_info" << std::endl;
//     		displayCONSTANT_Class_info(*(CONSTANT_Class_info *)&viewobj.constant_pool[i]);
//     		break;
//     	case enum_cp_tags::CONSTANT_Fieldref:
//     		cout << "CONSTANT_Fieldref_info" << std::endl;
//     		displayCONSTANT_Fieldref_info(*(CONSTANT_Fieldref_info *)&viewobj.constant_pool[i]);
//         	break;
//     	case enum_cp_tags::CONSTANT_Methodref:
//     		cout << "CONSTANT_Methodref_info" << std::endl;
//     		displayCONSTANT_Methodref_info(*(CONSTANT_Methodref_info *)&viewobj.constant_pool[i]);
//     		break;
//     	case enum_cp_tags::CONSTANT_InterfaceMethodref:
//     		cout << "CONSTANT_InterfaceMethodref_info" << std::endl;
//     		displayCONSTANT_InterfaceMethodref_info(*(CONSTANT_InterfaceMethodref_info *)&viewobj.constant_pool[i]);
// 			break;
//     	case enum_cp_tags::CONSTANT_String:
//     		cout << "CONSTANT_String_info" << std::endl;
//     		displayCONSTANT_String_info(*(CONSTANT_String_info *)&viewobj.constant_pool[i]);
//     		break;
//     	case enum_cp_tags::CONSTANT_Integer:
//     		cout << "CONSTANT_Integer_info" << std::endl;
//     		displayCONSTANT_Integer_info(*(CONSTANT_Integer_info *)&viewobj.constant_pool[i]);
//     		break;
//     	case enum_cp_tags::CONSTANT_Float:
//     		cout << "CONSTANT_Float_info" << std::endl;
//     		displayCONSTANT_Float_info(*(CONSTANT_Float_info *)&viewobj.constant_pool[i]);
//     		break;
//     	case enum_cp_tags::CONSTANT_Long:
//     		cout << "CONSTANT_Long_info" << std::endl;
//     		displayCONSTANT_Long_info(*(CONSTANT_Long_info *)&viewobj.constant_pool[i]);
//     		i++;
//     		std::cout << "  [" << i << "]" << " large numeric continued" << std::endl << std::endl;
//     		break;
//     	case enum_cp_tags::CONSTANT_Double:
//     		cout << "CONSTANT_Double_info" << std::endl;
//     		displayCONSTANT_Double_info(*(CONSTANT_Double_info *)&viewobj.constant_pool[i]);
//     		i++;
//     		std::cout << "  [" << i <<  "]" << " large numeric continued" << std::endl << std::endl;
//     		break;
//     	case enum_cp_tags::CONSTANT_NameAndType:
//     		cout << "CONSTANT_NameAndType_info" << std::endl;
//     		displayCONSTANT_NameAndType_info(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[i]);
//     		break;
//     	case enum_cp_tags::CONSTANT_Utf8:
//     		cout << "CONSTANT_Utf8_info" << std::endl;
//     		displayCONSTANT_Utf8_info(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[i]);
//     		break;
//     	default:
//     		cout << "broken link" << std::endl;
//     		break;
//     	}
// 	}
// }


// void Exibidor::displayConstantValueAtt(ConstantValue_attribute & theatt, int indent){
// 	printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	printindent(indent);
// 	std::cout << "Attribute Length: " << theatt.attribute_length << std::endl;
// 	printindent(indent);
// 	std::cout << "Value: cp_info# " << theatt.constantvalue_index << std::endl;
// 	std::cout << std::endl;
// }
// void Exibidor::displayInstructions(u1 * instructions, u4 length){
// 	PC = instructions;
// 	/*for(int i=0;i<length;i++){
// 		std::cout << std::hex << std::showbase << (int)PC[i] << std::dec << std::endl;
// 	}*/
//   std::cout << "     Instructions:";
//   std::cout << "\n";
//   unsigned ii = 0;
// 	while(((long long int)(&instructions[length-1]))>=((long long int)(&PC[0]))){
// 		u1 aux = PC[0];
// 		//std::cout << "\n" << (int)aux << "\n";
//     printf("     %4d ", ii++);
// 		(this->*(print_vet[aux]))();
//     std::cout << "\n";
// 		//std::cout << "\n" << (int)aux << "\n";
// 	}
//   std::cout << "\n";
// }

// void Exibidor::displayCodeExcepts(Exception_Table * exceptions, u4 length){
//   std::cout << "     Exceptions:";
//   std::cout << "\n";
//   for(int i=0;i<length;i++){
//     Exception_Table aux = exceptions[i];
//     std::cout << "     Start pc: " << aux.start_pc << "\n";
//     std::cout << "     End pc: " << aux.end_pc << "\n";
//     std::cout << "     Handler pc: " << aux.handler_pc << "\n";
//     std::cout << "     Catch type: #" << aux.catch_type;
//     displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[aux.catch_type]);
//     std::cout << "\n";
//     std::cout << "\n";
//   }
// }
// void Exibidor::displayCodeAtt(Code_attribute & theatt, int indent){
// 	printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	printindent(indent);
// 	std::cout << "Attribute Length: " << theatt.attribute_length << std::endl;
// 	printindent(indent);
// 	std::cout << "Max Stack: " << theatt.max_stack << std::endl;
// 	printindent(indent);
// 	std::cout << "Max Locals: " << theatt.max_locals << std::endl;
// 	printindent(indent);
// 	std::cout << "Code Length: " << theatt.code_length << std::endl;
// 	std::cout << std::endl;
// 	displayInstructions(theatt.code,theatt.code_length);
//   displayCodeExcepts(theatt.exception_table,theatt.exception_table_length);
// 	if(theatt.attributes_count > 0){
// 		displayAttributes(theatt.attributes, theatt.attributes_count, indent+1);
// 	}
// }
// void Exibidor::displayDeprecatedAtt(Deprecated_attribute & theatt, int indent){
//     printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }
// void Exibidor::displayExceptionsAtt(Exceptions_attribute & theatt, int indent){
//     printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	for(int i=0;i<theatt.number_of_exceptions;i++){
// 		printindent(indent);
// 		std::cout << "Exception #" << i << ": ";
// 		displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.exception_index_table[i]]);
// 		std::cout << std::endl;
// 		std::cout << std::endl;
// 	}
// 	std::cout << std::endl;
// }

// void Exibidor::displayInnerClassesFlags(u2 accflags){
// 	if (accflags & enum_inner_class_access_flags::ACC_PUBLIC){
// 		printf("[public]");
// 	}
// 	if (accflags & enum_inner_class_access_flags::ACC_PRIVATE){
// 		printf("[private]");
// 	}
// 	if (accflags & enum_inner_class_access_flags::ACC_PROTECTED){
// 		printf("[protected]");
// 	}
// 	if (accflags & enum_inner_class_access_flags::ACC_STATIC){
// 		printf("[static]");
// 	}
// 	if (accflags & enum_inner_class_access_flags::ACC_FINAL){
// 		printf("[final]");
// 	}
// 	if (accflags & enum_inner_class_access_flags::ACC_INTERFACE){
// 		printf("[interface]");
// 	}
// 	if (accflags & enum_inner_class_access_flags::ACC_ABSTRACT){
// 		printf("[abstract]");
// 	}
// }
// void Exibidor::displayInnerClassesAtt(InnerClasses_attribute & theatt, int indent){
//     printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	for(int i=0;i<theatt.number_of_classes;i++){
// 		if(theatt.classes[i].inner_class_info_index != 0){
// 			printindent(indent);
// 			std::cout << "Class" << i << ": ";
// 			displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.classes[i].inner_class_info_index]);
// 			std::cout << std::endl;
// 		}
// 		if(theatt.classes[i].outer_class_info_index != 0){
// 			printindent(indent);
// 			std::cout << "Member of: ";
// 			displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.classes[i].outer_class_info_index]);
// 			std::cout << std::endl;
// 		}
// 		if(theatt.classes[i].inner_name_index != 0){
// 			printindent(indent);
// 			std::cout << "Named: ";
// 			displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.classes[i].inner_name_index]);
// 			std::cout << std::endl;
// 		}
// 		printindent(indent);
// 		std::cout << "Access Flags: ";
// 		displayInnerClassesFlags(theatt.classes[i].inner_class_access_flags);
// 		std::cout << std::endl;
// 	}
// 	std::cout << std::endl;
// }
// void Exibidor::displaySourceFileAtt(SourceFile_attribute & theatt, int indent){
//     printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	printindent(indent);
// 	std::cout << "Source: cp_info# " << theatt.sourcefile_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.sourcefile_index]);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }
// void Exibidor::displayLineNumberTableAtt(LineNumberTable_attribute & theatt, int indent){
// 	printindent(indent);std::cout << "Attribute name index: cp_info#" << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	printindent(indent);std::cout << "Attribute length: " << theatt.attribute_length << std::endl << std::endl;
// 	for(int i=0;i<theatt.line_number_table_length;i++){
// 		auto aux = theatt.line_number_table[i];
// 		printindent(indent);std::cout << "Nr. " << i << std::endl;
// 		printindent(indent);std::cout << "Start PC: " << aux.start_pc << std::endl;
// 		printindent(indent);std::cout << "Line Number: " << aux.line_number << std::endl;
// 		std::cout << std::endl;
// 	}
// 	std::cout << std::endl;
// }
// void Exibidor::displayLocalVariableTableAtt(LocalVariableTable_attribute & theatt, int indent){
//     printindent(indent);
// 	std::cout << "Attribute Name: cp_info# " << theatt.attribute_name_index << " ";
// 	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
// 	std::cout << std::endl;
// 	for(int i=0;i<theatt.local_variable_table_length;i++){
// 		printindent(indent);
// 		std::cout << "Start PC: " << theatt.local_variable_table[i].start_pc << std::endl;
// 		printindent(indent);
// 		std::cout << "Length: " << theatt.local_variable_table[i].length << std::endl;
// 		printindent(indent);
// 		std::cout << "Name: ";
// 		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.local_variable_table[i].name_index]);
// 		std::cout << std::endl;
// 		printindent(indent);
// 		std::cout << "Descriptor: ";
// 		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.local_variable_table[i].descriptor_index]);
// 		std::cout << std::endl;
// 		printindent(indent);
// 		std::cout << "Variable Index: #" << theatt.local_variable_table[i].index << std::endl;

// 	}
// 	std::cout << std::endl;
// }
// void Exibidor::displayfields(ClassFile & theclass){
//     std::cout << " Fields:\n";
// 	for(size_t i = 0; i < theclass.fields_count; i++) {
//     	field_info & aux = theclass.fields[i];
//     	std::cout << "  ";
//     	std::cout << "[" << i << "]" << " ";
//     	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.name_index]);
//     	std::cout << std::endl;
// 		std::cout << "   Descriptor: cp_info# " << aux.descriptor_index << " ";
// 		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.descriptor_index]);
// 		std::cout << std::endl;
// 		if(aux.attributes_count > 0){
// 			displayAttributes(aux.attributes, aux.attributes_count, 3);
// 		}
// 	}
// }

// void Exibidor::displayMethodsFlags(u2 accflags){
// 	if (accflags & enum_method_access_flags::ACC_PUBLIC){
// 		printf("[public]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_PRIVATE){
// 		printf("[private]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_PROTECTED){
// 		printf("[protected]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_STATIC){
// 		printf("[static]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_FINAL){
// 		printf("[final]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_SYNCHRONIZED){
// 		printf("[synchronized]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_NATIVE){
// 		printf("[native]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_ABSTRACT){
// 		printf("[abstract]");
// 	}
// 	if (accflags & enum_method_access_flags::ACC_STRICT){
// 		printf("[strict]");
// 	}
// }
// void Exibidor::displaymethods(ClassFile & theclass){
//   std::cout << " Methods:\n";
// 	for(size_t i = 0; i < theclass.methods_count; i++) {
// 		method_info & aux = theclass.methods[i];
// 		std::cout << "  ";
// 		std::cout << "[" << i << "]" << " ";
// 		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.name_index]);
// 		std::cout << std::endl;
// 		std::cout << "   Name: cp_info# " << aux.name_index << " ";
// 		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.name_index]);
// 		std::cout << endl;
// 		std::cout << "   Descriptor: cp_info# " << aux.descriptor_index << " ";
// 		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.descriptor_index]);
// 		std::cout << std::endl;
// 		std::cout << "   Access Flags: " << std::hex << aux.access_flags << " ";
// 		displayMethodsFlags(aux.access_flags);
// 		std::cout << std::endl << std::dec;
// 		if(aux.attributes_count > 0){
// 			displayAttributes(aux.attributes, aux.attributes_count, 3);
// 		}
// 	}
// }