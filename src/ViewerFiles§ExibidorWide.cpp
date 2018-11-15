#include "Exibidor.hpp"

void Exibidor::print_jvm_wide_nop(){
	std::cout << "wide_nop";
}
void Exibidor::print_jvm_wide_aconst_null(){
	std::cout << "wide_aconst_null";
}
void Exibidor::print_jvm_wide_iconst_m1(){
	std::cout << "wide_iconst_m1";
}
void Exibidor::print_jvm_wide_iconst_0(){
	std::cout << "wide_iconst_0";
}
void Exibidor::print_jvm_wide_iconst_1(){
	std::cout << "wide_iconst_1";
}
void Exibidor::print_jvm_wide_iconst_2(){
	std::cout << "wide_iconst_2";
}
void Exibidor::print_jvm_wide_iconst_3(){
	std::cout << "wide_iconst_3";
}
void Exibidor::print_jvm_wide_iconst_4(){
	std::cout << "wide_iconst_4";
}
void Exibidor::print_jvm_wide_iconst_5(){
	std::cout << "wide_iconst_5";
}
void Exibidor::print_jvm_wide_lconst_0(){
	std::cout << "wide_lconst_0";
}
void Exibidor::print_jvm_wide_lconst_1(){
	std::cout << "wide_lconst_1";
}
void Exibidor::print_jvm_wide_fconst_0(){
	std::cout << "wide_fconst_0";
}
void Exibidor::print_jvm_wide_fconst_1(){
	std::cout << "wide_fconst_1";
}
void Exibidor::print_jvm_wide_fconst_2(){
	std::cout << "wide_fconst_2";
}
void Exibidor::print_jvm_wide_dconst_0(){
	std::cout << "wide_dconst_0";
}
void Exibidor::print_jvm_wide_dconst_1(){
	std::cout << "wide_dconst_1";
}
void Exibidor::print_jvm_wide_bipush(){
	std::cout << "wide_bipush";
}
void Exibidor::print_jvm_wide_sipush(){
	std::cout << "wide_sipush";
}
void Exibidor::print_jvm_wide_ldc(){
	std::cout << "wide_ldc";
}
void Exibidor::print_jvm_wide_ldc_w(){
	std::cout << "wide_ldc_w";
}
void Exibidor::print_jvm_wide_ldc2_w(){
	std::cout << "wide_ldc2_w";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparamcat2value(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_wide_iload(){
	std::cout << "wide_iload";
}
void Exibidor::print_jvm_wide_lload(){
	std::cout << "wide_lload";
}
void Exibidor::print_jvm_wide_fload(){
	std::cout << "wide_fload";
}
void Exibidor::print_jvm_wide_dload(){
	std::cout << "wide_dload";
}
void Exibidor::print_jvm_wide_aload(){
	std::cout << "wide_aload";
}
void Exibidor::print_jvm_wide_iload_0(){
	std::cout << "wide_iload_0";
}
void Exibidor::print_jvm_wide_iload_1(){
	std::cout << "wide_iload_1";
}
void Exibidor::print_jvm_wide_iload_2(){
	std::cout << "wide_iload_2";
}
void Exibidor::print_jvm_wide_iload_3(){
	std::cout << "wide_iload_3";
}
void Exibidor::print_jvm_wide_lload_0(){
	std::cout << "wide_lload_0";
}
void Exibidor::print_jvm_wide_lload_1(){
	std::cout << "wide_lload_1";
}
void Exibidor::print_jvm_wide_lload_2(){
	std::cout << "wide_lload_2";
}
void Exibidor::print_jvm_wide_lload_3(){
	std::cout << "wide_lload_3";
}
void Exibidor::print_jvm_wide_fload_0(){
	std::cout << "wide_fload_0";
}
void Exibidor::print_jvm_wide_fload_1(){
	std::cout << "wide_fload_1";
}
void Exibidor::print_jvm_wide_fload_2(){
	std::cout << "wide_fload_2";
}
void Exibidor::print_jvm_wide_fload_3(){
	std::cout << "wide_fload_3";
}
void Exibidor::print_jvm_wide_dload_0(){
	std::cout << "wide_dload_0";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_dload_1(){
	std::cout << "wide_dload_1";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_dload_2(){
	std::cout << "wide_dload_2";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_dload_3(){
	std::cout << "wide_dload_3";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_aload_0(){
	std::cout << "wide_aload_0";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_aload_1(){
	std::cout << "wide_aload_1";
}
void Exibidor::print_jvm_wide_aload_2(){
	std::cout << "wide_aload_2";
}
void Exibidor::print_jvm_wide_aload_3(){
	std::cout << "wide_aload_3";
}
void Exibidor::print_jvm_wide_iaload(){
	std::cout << "wide_iaload";
}
void Exibidor::print_jvm_wide_faload(){
	std::cout << "wide_faload";
}
void Exibidor::print_jvm_wide_daload(){
	std::cout << "wide_daload";
}
void Exibidor::print_jvm_wide_aaload(){
	std::cout << "wide_aaload";
}
void Exibidor::print_jvm_wide_baload(){
	std::cout << "wide_baload";
}
void Exibidor::print_jvm_wide_caload(){
	std::cout << "wide_caload";
}
void Exibidor::print_jvm_wide_saload(){
	std::cout << "wide_saload";
}
void Exibidor::print_jvm_wide_istore(){
	std::cout << "wide_istore";
}
void Exibidor::print_jvm_wide_lstore(){
	std::cout << "wide_lstore";
}
void Exibidor::print_jvm_wide_fstore(){
	std::cout << "wide_fstore";
}
void Exibidor::print_jvm_wide_dstore(){
	std::cout << "wide_dstore";
}
void Exibidor::print_jvm_wide_astore(){
	std::cout << "wide_astore";
}
void Exibidor::print_jvm_wide_istore_0(){
	std::cout << "wide_istore_0";
}
void Exibidor::print_jvm_wide_istore_1(){
	std::cout << "wide_istore_1";
}
void Exibidor::print_jvm_wide_istore_2(){
	std::cout << "wide_istore_2";
}
void Exibidor::print_jvm_wide_istore_3(){
	std::cout << "wide_istore_3";
}
void Exibidor::print_jvm_wide_lstore_0(){
	std::cout << "wide_lstore_0";
}
void Exibidor::print_jvm_wide_lstore_1(){
	std::cout << "wide_lstore_1";
}
void Exibidor::print_jvm_wide_lstore_2(){
	std::cout << "wide_lstore_2";
}
void Exibidor::print_jvm_wide_lstore_3(){
	std::cout << "wide_lstore_3";
}
void Exibidor::print_jvm_wide_fstore_0(){
	std::cout << "wide_fstore_0";
}
void Exibidor::print_jvm_wide_fstore_1(){
	std::cout << "wide_fstore_1";
}
void Exibidor::print_jvm_wide_fstore_2(){
	std::cout << "wide_fstore_2";
}
void Exibidor::print_jvm_wide_fstore_3(){
	std::cout << "wide_fstore_3";
}
void Exibidor::print_jvm_wide_dstore_0(){
	std::cout << "wide_dstore_0";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_dstore_1(){
	std::cout << "wide_dstore_1";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_dstore_2(){
	std::cout << "wide_dstore_2";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_dstore_3(){
	std::cout << "wide_dstore_3";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_astore_0(){
	std::cout << "wide_astore_0";
}
void Exibidor::print_jvm_wide_astore_1(){
	std::cout << "wide_astore_1";
}
void Exibidor::print_jvm_wide_astore_2(){
	std::cout << "wide_astore_2";
}
void Exibidor::print_jvm_wide_astore_3(){
	std::cout << "wide_astore_3";
}
void Exibidor::print_jvm_wide_iastore(){
	std::cout << "wide_iastore";
}
void Exibidor::print_jvm_wide_lastore(){
	std::cout << "wide_lastore";
}
void Exibidor::print_jvm_wide_fastore(){
	std::cout << "wide_fastore";
}
void Exibidor::print_jvm_wide_dastore(){
	std::cout << "wide_dastore";
}
void Exibidor::print_jvm_wide_aastore(){
	std::cout << "wide_aastore";
}
void Exibidor::print_jvm_wide_bastore(){
	std::cout << "wide_bastore";
}
void Exibidor::print_jvm_wide_castore(){
	std::cout << "wide_castore";
}
void Exibidor::print_jvm_wide_sastore(){
	std::cout << "wide_sastore";
}
void Exibidor::print_jvm_wide_pop(){
	std::cout << "wide_pop";
}
void Exibidor::print_jvm_wide_pop2(){
	std::cout << "wide_pop2";
}
void Exibidor::print_jvm_wide_dup(){
	std::cout << "wide_dup";
}
void Exibidor::print_jvm_wide_dup_x1(){
	std::cout << "wide_dup_x1";
}
void Exibidor::print_jvm_wide_dup_x2(){
	std::cout << "wide_dup_x2";
}
void Exibidor::print_jvm_wide_dup2(){
	std::cout << "wide_dup2";
}
void Exibidor::print_jvm_wide_dup2_x1(){
	std::cout << "wide_dup2_x1";
}
void Exibidor::print_jvm_wide_dup2_x2(){
	std::cout << "wide_dup2_x2";
}
void Exibidor::print_jvm_wide_swap(){
	std::cout << "wide_swap";
}
void Exibidor::print_jvm_wide_iadd(){
	std::cout << "wide_iadd";
}
void Exibidor::print_jvm_wide_ladd(){
	std::cout << "wide_ladd";
}
void Exibidor::print_jvm_wide_fadd(){
	std::cout << "wide_fadd";
}
void Exibidor::print_jvm_wide_dadd(){
	std::cout << "wide_dadd";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_isub(){
	std::cout << "wide_isub";
}
void Exibidor::print_jvm_wide_lsub(){
	std::cout << "wide_lsub";
}
void Exibidor::print_jvm_wide_fsub(){
	std::cout << "wide_fsub";
}
void Exibidor::print_jvm_wide_dsub(){
	std::cout << "wide_dsub";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_imul(){
	std::cout << "wide_imul";
}
void Exibidor::print_jvm_wide_lmul(){
	std::cout << "wide_lmul";
}
void Exibidor::print_jvm_wide_fmul(){
	std::cout << "wide_fmul";
}
void Exibidor::print_jvm_wide_dmul(){
	std::cout << "wide_dmul";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_idiv(){
	std::cout << "wide_idiv";
}
void Exibidor::print_jvm_wide_ldiv(){
	std::cout << "wide_ldiv";
}
void Exibidor::print_jvm_wide_fdiv(){
	std::cout << "wide_fdiv";
}
void Exibidor::print_jvm_wide_ddiv(){
	std::cout << "wide_ddiv";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_irem(){
	std::cout << "wide_irem";
}
void Exibidor::print_jvm_wide_lrem(){
	std::cout << "wide_lrem";
}
void Exibidor::print_jvm_wide_frem(){
	std::cout << "wide_frem";
}
void Exibidor::print_jvm_wide_drem(){
	std::cout << "wide_drem";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_ineg(){
	std::cout << "wide_ineg";
}
void Exibidor::print_jvm_wide_lneg(){
	std::cout << "wide_lneg";
}
void Exibidor::print_jvm_wide_fneg(){
	std::cout << "wide_fneg";
}
void Exibidor::print_jvm_wide_dneg(){
	std::cout << "wide_dneg";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_ishl(){
	std::cout << "wide_ishl";
}
void Exibidor::print_jvm_wide_lshl(){
	std::cout << "wide_lshl";
}
void Exibidor::print_jvm_wide_ishr(){
	std::cout << "wide_ishr";
}
void Exibidor::print_jvm_wide_lshr(){
	std::cout << "wide_lshr";
}
void Exibidor::print_jvm_wide_iushr(){
	std::cout << "wide_iushr";
}
void Exibidor::print_jvm_wide_lushr(){
	std::cout << "wide_lushr";
}
void Exibidor::print_jvm_wide_iand(){
	std::cout << "wide_iand";
}
void Exibidor::print_jvm_wide_land(){
	std::cout << "wide_land";
}
void Exibidor::print_jvm_wide_ior(){
	std::cout << "wide_ior";
}
void Exibidor::print_jvm_wide_lor(){
	std::cout << "wide_lor";
}
void Exibidor::print_jvm_wide_ixor(){
	std::cout << "wide_ixor";
}
void Exibidor::print_jvm_wide_lxor(){
	std::cout << "wide_lxor";
}
void Exibidor::print_jvm_wide_iinc(){
	std::cout << "wide_iinc";
}
void Exibidor::print_jvm_wide_i2l(){
	std::cout << "wide_i2l";
}
void Exibidor::print_jvm_wide_i2f(){
	std::cout << "wide_i2f";
}
void Exibidor::print_jvm_wide_i2d(){
	std::cout << "wide_i2d";
}
void Exibidor::print_jvm_wide_l2i(){
	std::cout << "wide_l2i";
}
void Exibidor::print_jvm_wide_l2f(){
	std::cout << "wide_l2f";
}
void Exibidor::print_jvm_wide_l2d(){
	std::cout << "wide_l2d";
}
void Exibidor::print_jvm_wide_f2i(){
	std::cout << "wide_f2i";
}
void Exibidor::print_jvm_wide_f2l(){
	std::cout << "wide_f2l";
}
void Exibidor::print_jvm_wide_f2d(){
	std::cout << "wide_f2d";
}
void Exibidor::print_jvm_wide_d2i(){
	std::cout << "wide_d2i";
}
void Exibidor::print_jvm_wide_d2l(){
	std::cout << "wide_d2l";
}
void Exibidor::print_jvm_wide_d2f(){
	std::cout << "wide_d2f";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_i2b(){
	std::cout << "wide_i2b";
}
void Exibidor::print_jvm_wide_i2c(){
	std::cout << "wide_i2c";
}
void Exibidor::print_jvm_wide_i2s(){
	std::cout << "wide_i2s";
}
void Exibidor::print_jvm_wide_lcmp(){
	std::cout << "wide_lcmp";
}
void Exibidor::print_jvm_wide_fcmpl(){
	std::cout << "wide_fcmpl";
}
void Exibidor::print_jvm_wide_fcmpg(){
	std::cout << "wide_fcmpg";
}
void Exibidor::print_jvm_wide_dcmpl(){
	std::cout << "wide_dcmpl";
}
void Exibidor::print_jvm_wide_dcmpg(){
	std::cout << "wide_dcmpg";
}
void Exibidor::print_jvm_wide_ifeq(){
	std::cout << "wide_ifeq";
}
void Exibidor::print_jvm_wide_ifne(){
	std::cout << "wide_ifne";
}
void Exibidor::print_jvm_wide_iflt(){
	std::cout << "wide_iflt";
}
void Exibidor::print_jvm_wide_ifge(){
	std::cout << "wide_ifge";
}
void Exibidor::print_jvm_wide_ifgt(){
	std::cout << "wide_ifgt";
}
void Exibidor::print_jvm_wide_ifle(){
	std::cout << "wide_ifle";
}
void Exibidor::print_jvm_wide_if_icmpeq(){
	std::cout << "wide_if_icmpeq";
}
void Exibidor::print_jvm_wide_if_icmpne(){
	std::cout << "wide_if_icmpne";
}
void Exibidor::print_jvm_wide_if_icmplt(){
	std::cout << "wide_if_icmplt";
}
void Exibidor::print_jvm_wide_if_icmpge(){
	std::cout << "wide_if_icmpge";
}
void Exibidor::print_jvm_wide_if_icmpgt(){
	std::cout << "wide_if_icmpgt";
}
void Exibidor::print_jvm_wide_if_icmple(){
	std::cout << "wide_if_icmple";
}
void Exibidor::print_jvm_wide_if_acmpeq(){
	std::cout << "wide_if_acmpeq";
}
void Exibidor::print_jvm_wide_if_acmpne(){
	std::cout << "wide_if_acmpne";
}
void Exibidor::print_jvm_wide_goto(){
	std::cout << "wide_goto";
}
void Exibidor::print_jvm_wide_jsr(){
	std::cout << "wide_jsr";
}
void Exibidor::print_jvm_wide_ret(){
	std::cout << "wide_ret";
}
void Exibidor::print_jvm_wide_tableswitch(){
	std::cout << "wide_tableswitch";
}
void Exibidor::print_jvm_wide_lookupswitch(){
	std::cout << "wide_lookupswitch";
}
void Exibidor::print_jvm_wide_ireturn(){
	std::cout << "wide_ireturn";
}
void Exibidor::print_jvm_wide_lreturn(){
	std::cout << "wide_lreturn";
}
void Exibidor::print_jvm_wide_freturn(){
	std::cout << "wide_freturn";
}
void Exibidor::print_jvm_wide_dreturn(){
	std::cout << "wide_dreturn";
}
void Exibidor::print_jvm_wide_areturn(){
	std::cout << "wide_areturn";
}
void Exibidor::print_jvm_wide_return(){
	std::cout << "wide_return";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_wide_getstatic(){
	std::cout << "wide_getstatic";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparamfieldname(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_wide_putstatic(){
	std::cout << "wide_putstatic";
}
void Exibidor::print_jvm_wide_getfield(){
	std::cout << "wide_getfield";
}
void Exibidor::print_jvm_wide_putfield(){
	std::cout << "wide_putfield";
}
void Exibidor::print_jvm_wide_invokevirtual(){
	std::cout << "wide_invokevirtual";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparammethodname(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_wide_invokespecial(){
	std::cout << "wide_invokespecial";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparammethodname(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_wide_invokestatic(){
	std::cout << "wide_invokestatic";
}
void Exibidor::print_jvm_wide_invokeinterface(){
	std::cout << "wide_invokeinterface";
}
void Exibidor::print_jvm_wide_invokedynamic(){
	std::cout << "wide_invokedynamic";
}
void Exibidor::print_jvm_wide_new(){
	std::cout << "wide_new";
}
void Exibidor::print_jvm_wide_newarray(){
	std::cout << "wide_newarray";
}
void Exibidor::print_jvm_wide_anewarray(){
	std::cout << "wide_anewarray";
}
void Exibidor::print_jvm_wide_arraylength(){
	std::cout << "wide_arraylength";
}
void Exibidor::print_jvm_wide_athrow(){
	std::cout << "wide_athrow";
}
void Exibidor::print_jvm_wide_checkcast(){
	std::cout << "wide_checkcast";
}
void Exibidor::print_jvm_wide_instanceof(){
	std::cout << "wide_instanceof";
}
void Exibidor::print_jvm_wide_monitorenter(){
	std::cout << "wide_monitorenter";
}
void Exibidor::print_jvm_wide_monitorexit(){
	std::cout << "wide_monitorexit";
}
void Exibidor::print_jvm_wide_wide(){
	std::cout << "wide_wide";
}
void Exibidor::print_jvm_wide_multianewarray(){
	std::cout << "wide_multianewarray";
}
void Exibidor::print_jvm_wide_ifnull(){
	std::cout << "wide_ifnull";
}
void Exibidor::print_jvm_wide_ifnonnull(){
	std::cout << "wide_ifnonnull";
}
void Exibidor::print_jvm_wide_goto_w(){
	std::cout << "wide_goto_w";
}
void Exibidor::print_jvm_wide_jsr_w(){
	std::cout << "wide_jsr_w";
}
void Exibidor::print_jvm_wide_breakpoint(){
	std::cout << "wide_breakpoint";
}
void Exibidor::print_jvm_wide_impdep1(){
	std::cout << "wide_impdep1";
}
void Exibidor::print_jvm_wide_impdep2(){
	std::cout << "wide_impdep2";
}

void Exibidor::feed(const ClassFile & toshow){
	viewobj = toshow;
}
void Exibidor::show(){
	set_print_vet();
	control_class();
}