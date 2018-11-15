#pragma once
#include "ExibidorDisplay.cpp"
#include "Exibidor.hpp"

att_name_result Exibidor::attributenamecompare(CONSTANT_Utf8_info & name){
	int size = name.length+1;
	int i;
	char namestring[size];
	for (i=0; i<name.length; i++){
		namestring[i] = (char)name.bytes[i];
	}
	namestring[i]='\0';
	if (std::strcmp(namestring, "ConstantValue")==0){
		return ATT_CONSTANTVALUE;
	}
	if (std::strcmp(namestring, "Code")==0){
		return ATT_CODE;
	}
	if (std::strcmp(namestring, "Deprecated")==0){
		return ATT_DEPRECATED;
	}
	if (std::strcmp(namestring, "Exceptions")==0){
		return ATT_EXCEPTIONS;
	}
	if (std::strcmp(namestring, "InnerClasses")==0){
		return ATT_INNERCLASSES;
	}
	if (std::strcmp(namestring, "SourceFile")==0){
		return ATT_SOURCEFILE;
	}
	if (std::strcmp(namestring, "LineNumberTable")==0){
		return ATT_LINENUMBERTABLE;
	}
	if (std::strcmp(namestring, "LocalVariableTable")==0){
		return ATT_LOCALVARIABLETABLE;
	}
	if (std::strcmp(namestring, "Synthetic")==0){
		return ATT_SYNTHETIC;
	}
	else return ATT_INVALID;
}
void Exibidor::printindent(int indent){
	for(int i=0; i<indent; i++){
		printf(" ");
	}
}
void Exibidor::displayAttributes(attribute_info * attlist, int length, int indent){
    printindent(indent);
    std::cout << "Attributes:" << std::endl;
	for(int i=0; i<length; i++){
    	u2 tag;
    	memcpy(&tag, &attlist[i],sizeof(tag));
    	int nameswitch = attributenamecompare(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[tag]);
		printindent(indent);
		std::cout << "[" << i << "] ";
    	switch(nameswitch) {
		case ATT_CONSTANTVALUE:    		
			cout << "ConstantValue" << std::endl;
			displayConstantValueAtt(*(ConstantValue_attribute *)&attlist[i], indent+1);
			break;
		case ATT_CODE:
			cout << "Code" << std::endl;
			displayCodeAtt(*(Code_attribute *)&attlist[i], indent+1);
			break;
		case ATT_DEPRECATED:
			cout << "Deprecated" << std::endl;
			displayDeprecatedAtt(*(Deprecated_attribute *)&attlist[i], indent+1);
			break;
		case ATT_EXCEPTIONS:
			cout << "Exceptions" << std::endl;
			displayExceptionsAtt(*(Exceptions_attribute *)&attlist[i], indent+1);
			break;
		case ATT_INNERCLASSES:
			cout << "InnerClasses" << std::endl;
			displayInnerClassesAtt(*(InnerClasses_attribute *)&attlist[i], indent+1);
			break;
		case ATT_SOURCEFILE:
			cout << "SourceFile" << std::endl;
			displaySourceFileAtt(*(SourceFile_attribute *)&attlist[i], indent+1);
			break;
		case ATT_LINENUMBERTABLE:
			cout << "LineNumberTable" << std::endl;
			displayLineNumberTableAtt(*(LineNumberTable_attribute *)&attlist[i], indent+1);
			break;
		case ATT_LOCALVARIABLETABLE:
			cout << "LocalVariableTable" << std::endl;
			displayLocalVariableTableAtt(*(LocalVariableTable_attribute *)&attlist[i], indent+1);
			break;
		default:
			cout << "invalid attribute" << std::endl;
			break;
    	}
	}
}

void Exibidor::control_class(){
	displayClassFile(viewobj);
	control_cp();
	if(viewobj.fields_count > 0){
		control_fields();
	}
	if(viewobj.methods_count > 0){
		control_methods();
	}
	if(viewobj.attributes_count > 0){
		displayAttributes(viewobj.attributes, viewobj.attributes_count, 1);
	}
}
void Exibidor::control_cp(){
	displayconstant_pool(viewobj);
}
void Exibidor::control_fields(){
	displayfields(viewobj);
}
void Exibidor::control_methods(){
	displaymethods(viewobj);
}
void Exibidor::control_attributes(){}
void Exibidor::printparammethodname(u2 index){
	CONSTANT_Methodref_info & methodinfo = *(CONSTANT_Methodref_info *)&viewobj.constant_pool[index];
	CONSTANT_Class_info & classname = *(CONSTANT_Class_info *)&viewobj.constant_pool[methodinfo.class_index];
	CONSTANT_NameAndType_info & nameandtype = *(CONSTANT_NameAndType_info *)&viewobj.constant_pool[methodinfo.name_and_type_index];
	CONSTANT_Utf8_info & methodname = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[nameandtype.name_index];
	std::cout << "<";
	displayClassInfoStringRaw(classname);
	std::cout << ".";
	displayUtf8InfoStringRaw(methodname);
	std::cout << ">";
}
void Exibidor::printparamfieldname(u2 index){
	CONSTANT_Fieldref_info & fieldinfo = *(CONSTANT_Fieldref_info *)&viewobj.constant_pool[index];
	CONSTANT_Class_info & classname = *(CONSTANT_Class_info *)&viewobj.constant_pool[fieldinfo.class_index];
	CONSTANT_NameAndType_info & nameandtype = *(CONSTANT_NameAndType_info *)&viewobj.constant_pool[fieldinfo.name_and_type_index];
	CONSTANT_Utf8_info & fieldname = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[nameandtype.name_index];
	std::cout << "<";
	displayClassInfoStringRaw(classname);
	std::cout << ".";
	displayUtf8InfoStringRaw(fieldname);
	std::cout << ">";
}
void Exibidor::printparamcat2value(u2 index){
	uint32_t buff[2];
    u1 tag;
    memcpy(&tag, &viewobj.constant_pool[index],sizeof(tag));
    switch(tag) {
    	case enum_cp_tags::CONSTANT_Long:{
    		CONSTANT_Long_info & thelonginfo = *(CONSTANT_Long_info *)&viewobj.constant_pool[index];
			std::memcpy(&buff[1], &thelonginfo.high_bytes, sizeof(thelonginfo.high_bytes));
			std::memcpy(&buff[0], &thelonginfo.low_bytes, sizeof(thelonginfo.low_bytes));
			std::cout << "<";
			std::cout << *((uint64_t*)buff);
			std::cout << ">";
		}
    	case enum_cp_tags::CONSTANT_Double:{
    		CONSTANT_Double_info & thedoubleinfo = *(CONSTANT_Double_info *)&viewobj.constant_pool[index];
			std::memcpy(&buff[1], &thedoubleinfo.high_bytes, sizeof(thedoubleinfo.high_bytes));
			std::memcpy(&buff[0], &thedoubleinfo.low_bytes, sizeof(thedoubleinfo.low_bytes));
			std::cout << "<";
			std::cout << *((double*)buff);
			std::cout << ">";
		}
    	default:
    		break;
    }
}

void Exibidor::print_jvm_nop(){
	std::cout << "nop";
}
void Exibidor::print_jvm_aconst_null(){
	std::cout << "aconst_null";
}
void Exibidor::print_jvm_iconst_m1(){
	std::cout << "iconst_m1";
}
void Exibidor::print_jvm_iconst_0(){
	std::cout << "iconst_0";
}
void Exibidor::print_jvm_iconst_1(){
	std::cout << "iconst_1";
}
void Exibidor::print_jvm_iconst_2(){
	std::cout << "iconst_2";
}
void Exibidor::print_jvm_iconst_3(){
	std::cout << "iconst_3";
}
void Exibidor::print_jvm_iconst_4(){
	std::cout << "iconst_4";
}
void Exibidor::print_jvm_iconst_5(){
	std::cout << "iconst_5";
}
void Exibidor::print_jvm_lconst_0(){
	std::cout << "lconst_0";
}
void Exibidor::print_jvm_lconst_1(){
	std::cout << "lconst_1";
}
void Exibidor::print_jvm_fconst_0(){
	std::cout << "fconst_0";
}
void Exibidor::print_jvm_fconst_1(){
	std::cout << "fconst_1";
}
void Exibidor::print_jvm_fconst_2(){
	std::cout << "fconst_2";
}
void Exibidor::print_jvm_dconst_0(){
	std::cout << "dconst_0";
}
void Exibidor::print_jvm_dconst_1(){
	std::cout << "dconst_1";
}
void Exibidor::print_jvm_bipush(){
	std::cout << "bipush";
}
void Exibidor::print_jvm_sipush(){
	std::cout << "sipush";
}
void Exibidor::print_jvm_ldc(){
	std::cout << "ldc";
}
void Exibidor::print_jvm_ldc_w(){
	std::cout << "ldc_w";
}
void Exibidor::print_jvm_ldc2_w(){
	std::cout << "ldc2_w";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparamcat2value(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_iload(){
	std::cout << "iload";
}
void Exibidor::print_jvm_lload(){
	std::cout << "lload";
}
void Exibidor::print_jvm_fload(){
	std::cout << "fload";
}
void Exibidor::print_jvm_dload(){
	std::cout << "dload";
}
void Exibidor::print_jvm_aload(){
	std::cout << "aload";
}
void Exibidor::print_jvm_iload_0(){
	std::cout << "iload_0";
}
void Exibidor::print_jvm_iload_1(){
	std::cout << "iload_1";
}
void Exibidor::print_jvm_iload_2(){
	std::cout << "iload_2";
}
void Exibidor::print_jvm_iload_3(){
	std::cout << "iload_3";
}
void Exibidor::print_jvm_lload_0(){
	std::cout << "lload_0";
}
void Exibidor::print_jvm_lload_1(){
	std::cout << "lload_1";
}
void Exibidor::print_jvm_lload_2(){
	std::cout << "lload_2";
}
void Exibidor::print_jvm_lload_3(){
	std::cout << "lload_3";
}
void Exibidor::print_jvm_fload_0(){
	std::cout << "fload_0";
}
void Exibidor::print_jvm_fload_1(){
	std::cout << "fload_1";
}
void Exibidor::print_jvm_fload_2(){
	std::cout << "fload_2";
}
void Exibidor::print_jvm_fload_3(){
	std::cout << "fload_3";
}
void Exibidor::print_jvm_dload_0(){
	std::cout << "dload_0";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_dload_1(){
	std::cout << "dload_1";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_dload_2(){
	std::cout << "dload_2";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_dload_3(){
	std::cout << "dload_3";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_aload_0(){
	std::cout << "aload_0";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_aload_1(){
	std::cout << "aload_1";
}
void Exibidor::print_jvm_aload_2(){
	std::cout << "aload_2";
}
void Exibidor::print_jvm_aload_3(){
	std::cout << "aload_3";
}
void Exibidor::print_jvm_iaload(){
	std::cout << "iaload";
}
void Exibidor::print_jvm_faload(){
	std::cout << "faload";
}
void Exibidor::print_jvm_daload(){
	std::cout << "daload";
}
void Exibidor::print_jvm_aaload(){
	std::cout << "aaload";
}
void Exibidor::print_jvm_baload(){
	std::cout << "baload";
}
void Exibidor::print_jvm_caload(){
	std::cout << "caload";
}
void Exibidor::print_jvm_saload(){
	std::cout << "saload";
}
void Exibidor::print_jvm_istore(){
	std::cout << "istore";
}
void Exibidor::print_jvm_lstore(){
	std::cout << "lstore";
}
void Exibidor::print_jvm_fstore(){
	std::cout << "fstore";
}
void Exibidor::print_jvm_dstore(){
	std::cout << "dstore";
}
void Exibidor::print_jvm_astore(){
	std::cout << "astore";
}
void Exibidor::print_jvm_istore_0(){
	std::cout << "istore_0";
}
void Exibidor::print_jvm_istore_1(){
	std::cout << "istore_1";
}
void Exibidor::print_jvm_istore_2(){
	std::cout << "istore_2";
}
void Exibidor::print_jvm_istore_3(){
	std::cout << "istore_3";
}
void Exibidor::print_jvm_lstore_0(){
	std::cout << "lstore_0";
}
void Exibidor::print_jvm_lstore_1(){
	std::cout << "lstore_1";
}
void Exibidor::print_jvm_lstore_2(){
	std::cout << "lstore_2";
}
void Exibidor::print_jvm_lstore_3(){
	std::cout << "lstore_3";
}
void Exibidor::print_jvm_fstore_0(){
	std::cout << "fstore_0";
}
void Exibidor::print_jvm_fstore_1(){
	std::cout << "fstore_1";
}
void Exibidor::print_jvm_fstore_2(){
	std::cout << "fstore_2";
}
void Exibidor::print_jvm_fstore_3(){
	std::cout << "fstore_3";
}
void Exibidor::print_jvm_dstore_0(){
	std::cout << "dstore_0";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_dstore_1(){
	std::cout << "dstore_1";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_dstore_2(){
	std::cout << "dstore_2";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_dstore_3(){
	std::cout << "dstore_3";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_astore_0(){
	std::cout << "astore_0";
}
void Exibidor::print_jvm_astore_1(){
	std::cout << "astore_1";
}
void Exibidor::print_jvm_astore_2(){
	std::cout << "astore_2";
}
void Exibidor::print_jvm_astore_3(){
	std::cout << "astore_3";
}
void Exibidor::print_jvm_iastore(){
	std::cout << "iastore";
}
void Exibidor::print_jvm_lastore(){
	std::cout << "lastore";
}
void Exibidor::print_jvm_fastore(){
	std::cout << "fastore";
}
void Exibidor::print_jvm_dastore(){
	std::cout << "dastore";
}
void Exibidor::print_jvm_aastore(){
	std::cout << "aastore";
}
void Exibidor::print_jvm_bastore(){
	std::cout << "bastore";
}
void Exibidor::print_jvm_castore(){
	std::cout << "castore";
}
void Exibidor::print_jvm_sastore(){
	std::cout << "sastore";
}
void Exibidor::print_jvm_pop(){
	std::cout << "pop";
}
void Exibidor::print_jvm_pop2(){
	std::cout << "pop2";
}
void Exibidor::print_jvm_dup(){
	std::cout << "dup";
}
void Exibidor::print_jvm_dup_x1(){
	std::cout << "dup_x1";
}
void Exibidor::print_jvm_dup_x2(){
	std::cout << "dup_x2";
}
void Exibidor::print_jvm_dup2(){
	std::cout << "dup2";
}
void Exibidor::print_jvm_dup2_x1(){
	std::cout << "dup2_x1";
}
void Exibidor::print_jvm_dup2_x2(){
	std::cout << "dup2_x2";
}
void Exibidor::print_jvm_swap(){
	std::cout << "swap";
}
void Exibidor::print_jvm_iadd(){
	std::cout << "iadd";
}
void Exibidor::print_jvm_ladd(){
	std::cout << "ladd";
}
void Exibidor::print_jvm_fadd(){
	std::cout << "fadd";
}
void Exibidor::print_jvm_dadd(){
	std::cout << "dadd";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_isub(){
	std::cout << "isub";
}
void Exibidor::print_jvm_lsub(){
	std::cout << "lsub";
}
void Exibidor::print_jvm_fsub(){
	std::cout << "fsub";
}
void Exibidor::print_jvm_dsub(){
	std::cout << "dsub";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_imul(){
	std::cout << "imul";
}
void Exibidor::print_jvm_lmul(){
	std::cout << "lmul";
}
void Exibidor::print_jvm_fmul(){
	std::cout << "fmul";
}
void Exibidor::print_jvm_dmul(){
	std::cout << "dmul";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_idiv(){
	std::cout << "idiv";
}
void Exibidor::print_jvm_ldiv(){
	std::cout << "ldiv";
}
void Exibidor::print_jvm_fdiv(){
	std::cout << "fdiv";
}
void Exibidor::print_jvm_ddiv(){
	std::cout << "ddiv";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_irem(){
	std::cout << "irem";
}
void Exibidor::print_jvm_lrem(){
	std::cout << "lrem";
}
void Exibidor::print_jvm_frem(){
	std::cout << "frem";
}
void Exibidor::print_jvm_drem(){
	std::cout << "drem";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_ineg(){
	std::cout << "ineg";
}
void Exibidor::print_jvm_lneg(){
	std::cout << "lneg";
}
void Exibidor::print_jvm_fneg(){
	std::cout << "fneg";
}
void Exibidor::print_jvm_dneg(){
	std::cout << "dneg";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_ishl(){
	std::cout << "ishl";
}
void Exibidor::print_jvm_lshl(){
	std::cout << "lshl";
}
void Exibidor::print_jvm_ishr(){
	std::cout << "ishr";
}
void Exibidor::print_jvm_lshr(){
	std::cout << "lshr";
}
void Exibidor::print_jvm_iushr(){
	std::cout << "iushr";
}
void Exibidor::print_jvm_lushr(){
	std::cout << "lushr";
}
void Exibidor::print_jvm_iand(){
	std::cout << "iand";
}
void Exibidor::print_jvm_land(){
	std::cout << "land";
}
void Exibidor::print_jvm_ior(){
	std::cout << "ior";
}
void Exibidor::print_jvm_lor(){
	std::cout << "lor";
}
void Exibidor::print_jvm_ixor(){
	std::cout << "ixor";
}
void Exibidor::print_jvm_lxor(){
	std::cout << "lxor";
}
void Exibidor::print_jvm_iinc(){
	std::cout << "iinc";
}
void Exibidor::print_jvm_i2l(){
	std::cout << "i2l";
}
void Exibidor::print_jvm_i2f(){
	std::cout << "i2f";
}
void Exibidor::print_jvm_i2d(){
	std::cout << "i2d";
}
void Exibidor::print_jvm_l2i(){
	std::cout << "l2i";
}
void Exibidor::print_jvm_l2f(){
	std::cout << "l2f";
}
void Exibidor::print_jvm_l2d(){
	std::cout << "l2d";
}
void Exibidor::print_jvm_f2i(){
	std::cout << "f2i";
}
void Exibidor::print_jvm_f2l(){
	std::cout << "f2l";
}
void Exibidor::print_jvm_f2d(){
	std::cout << "f2d";
}
void Exibidor::print_jvm_d2i(){
	std::cout << "d2i";
}
void Exibidor::print_jvm_d2l(){
	std::cout << "d2l";
}
void Exibidor::print_jvm_d2f(){
	std::cout << "d2f";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_i2b(){
	std::cout << "i2b";
}
void Exibidor::print_jvm_i2c(){
	std::cout << "i2c";
}
void Exibidor::print_jvm_i2s(){
	std::cout << "i2s";
}
void Exibidor::print_jvm_lcmp(){
	std::cout << "lcmp";
}
void Exibidor::print_jvm_fcmpl(){
	std::cout << "fcmpl";
}
void Exibidor::print_jvm_fcmpg(){
	std::cout << "fcmpg";
}
void Exibidor::print_jvm_dcmpl(){
	std::cout << "dcmpl";
}
void Exibidor::print_jvm_dcmpg(){
	std::cout << "dcmpg";
}
void Exibidor::print_jvm_ifeq(){
	std::cout << "ifeq";
}
void Exibidor::print_jvm_ifne(){
	std::cout << "ifne";
}
void Exibidor::print_jvm_iflt(){
	std::cout << "iflt";
}
void Exibidor::print_jvm_ifge(){
	std::cout << "ifge";
}
void Exibidor::print_jvm_ifgt(){
	std::cout << "ifgt";
}
void Exibidor::print_jvm_ifle(){
	std::cout << "ifle";
}
void Exibidor::print_jvm_if_icmpeq(){
	std::cout << "if_icmpeq";
}
void Exibidor::print_jvm_if_icmpne(){
	std::cout << "if_icmpne";
}
void Exibidor::print_jvm_if_icmplt(){
	std::cout << "if_icmplt";
}
void Exibidor::print_jvm_if_icmpge(){
	std::cout << "if_icmpge";
}
void Exibidor::print_jvm_if_icmpgt(){
	std::cout << "if_icmpgt";
}
void Exibidor::print_jvm_if_icmple(){
	std::cout << "if_icmple";
}
void Exibidor::print_jvm_if_acmpeq(){
	std::cout << "if_acmpeq";
}
void Exibidor::print_jvm_if_acmpne(){
	std::cout << "if_acmpne";
}
void Exibidor::print_jvm_goto(){
	std::cout << "goto";
}
void Exibidor::print_jvm_jsr(){
	std::cout << "jsr";
}
void Exibidor::print_jvm_ret(){
	std::cout << "ret";
}
void Exibidor::print_jvm_tableswitch(){
	std::cout << "tableswitch";
}
void Exibidor::print_jvm_lookupswitch(){
	std::cout << "lookupswitch";
}
void Exibidor::print_jvm_ireturn(){
	std::cout << "ireturn";
}
void Exibidor::print_jvm_lreturn(){
	std::cout << "lreturn";
}
void Exibidor::print_jvm_freturn(){
	std::cout << "freturn";
}
void Exibidor::print_jvm_dreturn(){
	std::cout << "dreturn";
}
void Exibidor::print_jvm_areturn(){
	std::cout << "areturn";
}
void Exibidor::print_jvm_return(){
	std::cout << "return";
	PC = &(PC[1]);
}
void Exibidor::print_jvm_getstatic(){
	std::cout << "getstatic";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparamfieldname(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_putstatic(){
	std::cout << "putstatic";
}
void Exibidor::print_jvm_getfield(){
	std::cout << "getfield";
}
void Exibidor::print_jvm_putfield(){
	std::cout << "putfield";
}
void Exibidor::print_jvm_invokevirtual(){
	std::cout << "invokevirtual";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparammethodname(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_invokespecial(){
	std::cout << "invokespecial";
	u2 aux;
	((u1 *)&aux)[0] = PC[2];
	((u1 *)&aux)[1] = PC[1];
	printf(" #%d ", (int)aux);
	printparammethodname(aux);
	PC = &(PC[3]);
}
void Exibidor::print_jvm_invokestatic(){
	std::cout << "invokestatic";
}
void Exibidor::print_jvm_invokeinterface(){
	std::cout << "invokeinterface";
}
void Exibidor::print_jvm_invokedynamic(){
	std::cout << "invokedynamic";
}
void Exibidor::print_jvm_new(){
	std::cout << "new";
}
void Exibidor::print_jvm_newarray(){
	std::cout << "newarray";
}
void Exibidor::print_jvm_anewarray(){
	std::cout << "anewarray";
}
void Exibidor::print_jvm_arraylength(){
	std::cout << "arraylength";
}
void Exibidor::print_jvm_athrow(){
	std::cout << "athrow";
}
void Exibidor::print_jvm_checkcast(){
	std::cout << "checkcast";
}
void Exibidor::print_jvm_instanceof(){
	std::cout << "instanceof";
}
void Exibidor::print_jvm_monitorenter(){
	std::cout << "monitorenter";
}
void Exibidor::print_jvm_monitorexit(){
	std::cout << "monitorexit";
}
void Exibidor::print_jvm_wide(){
	std::cout << "wide";
}
void Exibidor::print_jvm_multianewarray(){
	std::cout << "multianewarray";
}
void Exibidor::print_jvm_ifnull(){
	std::cout << "ifnull";
}
void Exibidor::print_jvm_ifnonnull(){
	std::cout << "ifnonnull";
}
void Exibidor::print_jvm_goto_w(){
	std::cout << "goto_w";
}
void Exibidor::print_jvm_jsr_w(){
	std::cout << "jsr_w";
}
void Exibidor::print_jvm_breakpoint(){
	std::cout << "breakpoint";
}
void Exibidor::print_jvm_impdep1(){
	std::cout << "impdep1";
}
void Exibidor::print_jvm_impdep2(){
	std::cout << "impdep2";
}

void Exibidor::feed(const ClassFile & toshow){
	viewobj = toshow;
}
void Exibidor::show(){
	set_print_vet();
	control_class();
}