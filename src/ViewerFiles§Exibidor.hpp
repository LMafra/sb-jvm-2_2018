#pragma once
#ifndef EXIBIDOR_HPP
#define EXIBIDOR_HPP

#include "UsingUs.hpp"
#include "VMGlobals.hpp"
#include "ClassFileStructures§ClassFile.hpp"
#include "ClassFileStructures§cp_info.hpp"
#include "ClassFileStructures§attribute_info.hpp"
#include <iostream>
#include <cstring>
#include <cstdio>


class Exibidor{
	ClassFile viewobj;
	void (Exibidor::*print_vet[256])(void);
	void set_print_vet();
	/// \brief display para informacoes gerais da classse e opcoes de navegacao.
	///
	/// apresenta informacoes como magic number, versao, contadores e flags de acesso.
	/// mostra opcoes de navegacao para constant pool, metodos, atributos, fields e interfaces.
	void displayClassFile(ClassFile & theclass);
	void displayClassFileFlags(ClassFile & theclass);
	void displayClassInfoString(CONSTANT_Class_info & theinfo);
	void displayUtf8InfoString(CONSTANT_Utf8_info & theinfo);
	void displayClassInfoStringRaw(CONSTANT_Class_info & theinfo);
	void displayUtf8InfoStringRaw(CONSTANT_Utf8_info & theinfo);
	void displayNameTypeInfoString(CONSTANT_NameAndType_info & theinfo);
	/// \brief display para class info.
	///
	/// apresenta o cp info com o nome da classe.
	void displayCONSTANT_Class_info(CONSTANT_Class_info & theclassinfo);
	/// \brief display para fieldref info.
	///
	/// apresenta o cp info com o nome da classe que contem o field, e nome e tipo do field.
	void displayCONSTANT_Fieldref_info(CONSTANT_Fieldref_info & thefieldinfo);
	/// \brief display para name and type info.
	///
	/// apresenta o cp info com o nome do metodo/field e o tipo do metodo/field.
	void displayCONSTANT_NameAndType_info(CONSTANT_NameAndType_info & thenameandtypeinfo);
	/// \brief display para constantes utf8.
	///
	/// apresenta o cp info com o tamanho da string e a string em si.
	void displayCONSTANT_Utf8_info(CONSTANT_Utf8_info & theunistringinfo);
	/// \brief display para methodref info.
	///
	/// apresenta o cp info com o nome da classe que contem o metodo, e nome e tipo do metodo.
	void displayCONSTANT_Methodref_info(CONSTANT_Methodref_info & themethodinfo);
	/// \brief display para methodref info.
	///
	/// apresenta o cp info com o nome da classe que contem o metodo, e nome e tipo do metodo.
	void displayCONSTANT_InterfaceMethodref_info(CONSTANT_InterfaceMethodref_info & themethodinfo);
	/// \brief display para string info.
	///
	/// apresenta o cp info com o indice da string.
	void displayCONSTANT_String_info(CONSTANT_String_info & thestringinfo);
	/// \brief display para int info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Integer_info(CONSTANT_Integer_info & theintinfo);
	/// \brief display para float info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Float_info(CONSTANT_Float_info & thefloatinfo);
	/// \brief display para long info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Long_info(CONSTANT_Long_info & thelonginfo);
	/// \brief display para double info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Double_info(CONSTANT_Double_info & thedoubleinfo);
	/// \brief display para entradas na tabela de constantes.
	///
	/// apresenta lista de entradas da CP.
	/// mostra opcoes de navegacao para constant pool.
	void displayconstant_pool(ClassFile & theclass);


	void displayConstantValueAtt(ConstantValue_attribute & theatt, int indent);
	void displayInstructions(u1 * instructions, u4 length);
	void displayCodeExcepts(Exception_Table * exceptions, u4 length);
	void displayCodeAtt(Code_attribute & theatt, int indent);
	void displayDeprecatedAtt(Deprecated_attribute & theatt, int indent);
	void displayExceptionsAtt(Exceptions_attribute & theatt, int indent);
	void displayInnerClassesFlags(u2 accflags);
	void displayInnerClassesAtt(InnerClasses_attribute & theatt, int indent);
	void displaySourceFileAtt(SourceFile_attribute & theatt, int indent);
	void displayLineNumberTableAtt(LineNumberTable_attribute & theatt, int indent);
	void displayLocalVariableTableAtt(LocalVariableTable_attribute & theatt, int indent);

	void displayfields(ClassFile & theclass);
	void displayMethodsFlags(u2 accflags);
	void displaymethods(ClassFile & theclass);
	att_name_result attributenamecompare(CONSTANT_Utf8_info & name);
	void printindent(int indent);
	void displayAttributes(attribute_info * attlist, int length, int indent);
	/// \brief entrada do exibidor.
	///
	/// mostra opcoes na tela e controla fluxo de input/output.
	/// opcoes lidas como entrada numerica.
	void control_class();
	/// \brief arvore de constant pool.
	///
	/// lista todas as constantes e seleciona uma para mostrar.
	/// opcoes lidas como entrada numerica.
	void control_cp();
	void control_fields();
	void control_attributes();
	void control_methods();
	void printparammethodname(u2 index);
	void printparamfieldname(u2 index);
	void printparamcat2value(u2 index);
	void print_jvm_nop();
	void print_jvm_aconst_null();
	void print_jvm_iconst_m1();
	void print_jvm_iconst_0();
	void print_jvm_iconst_1();
	void print_jvm_iconst_2();
	void print_jvm_iconst_3();
	void print_jvm_iconst_4();
	void print_jvm_iconst_5();
	void print_jvm_lconst_0();
	void print_jvm_lconst_1();
	void print_jvm_fconst_0();
	void print_jvm_fconst_1();
	void print_jvm_fconst_2();
	void print_jvm_dconst_0();
	void print_jvm_dconst_1();
	void print_jvm_bipush();
	void print_jvm_sipush();
	void print_jvm_ldc();
	void print_jvm_ldc_w();
	void print_jvm_ldc2_w();
	void print_jvm_iload();
	void print_jvm_lload();
	void print_jvm_fload();
	void print_jvm_dload();
	void print_jvm_aload();
	void print_jvm_iload_0();
	void print_jvm_iload_1();
	void print_jvm_iload_2();
	void print_jvm_iload_3();
	void print_jvm_lload_0();
	void print_jvm_lload_1();
	void print_jvm_lload_2();
	void print_jvm_lload_3();
	void print_jvm_fload_0();
	void print_jvm_fload_1();
	void print_jvm_fload_2();
	void print_jvm_fload_3();
	void print_jvm_dload_0();
	void print_jvm_dload_1();
	void print_jvm_dload_2();
	void print_jvm_dload_3();
	void print_jvm_aload_0();
	void print_jvm_aload_1();
	void print_jvm_aload_2();
	void print_jvm_aload_3();
	void print_jvm_iaload();
	void print_jvm_faload();
	void print_jvm_daload();
	void print_jvm_aaload();
	void print_jvm_baload();
	void print_jvm_caload();
	void print_jvm_saload();
	void print_jvm_istore();
	void print_jvm_lstore();
	void print_jvm_fstore();
	void print_jvm_dstore();
	void print_jvm_astore();
	void print_jvm_istore_0();
	void print_jvm_istore_1();
	void print_jvm_istore_2();
	void print_jvm_istore_3();
	void print_jvm_lstore_0();
	void print_jvm_lstore_1();
	void print_jvm_lstore_2();
	void print_jvm_lstore_3();
	void print_jvm_fstore_0();
	void print_jvm_fstore_1();
	void print_jvm_fstore_2();
	void print_jvm_fstore_3();
	void print_jvm_dstore_0();
	void print_jvm_dstore_1();
	void print_jvm_dstore_2();
	void print_jvm_dstore_3();
	void print_jvm_astore_0();
	void print_jvm_astore_1();
	void print_jvm_astore_2();
	void print_jvm_astore_3();
	void print_jvm_iastore();
	void print_jvm_lastore();
	void print_jvm_fastore();
	void print_jvm_dastore();
	void print_jvm_aastore();
	void print_jvm_bastore();
	void print_jvm_castore();
	void print_jvm_sastore();
	void print_jvm_pop();
	void print_jvm_pop2();
	void print_jvm_dup();
	void print_jvm_dup_x1();
	void print_jvm_dup_x2();
	void print_jvm_dup2();
	void print_jvm_dup2_x1();
	void print_jvm_dup2_x2();
	void print_jvm_swap();
	void print_jvm_iadd();
	void print_jvm_ladd();
	void print_jvm_fadd();
	void print_jvm_dadd();
	void print_jvm_isub();
	void print_jvm_lsub();
	void print_jvm_fsub();
	void print_jvm_dsub();
	void print_jvm_imul();
	void print_jvm_lmul();
	void print_jvm_fmul();
	void print_jvm_dmul();
	void print_jvm_idiv();
	void print_jvm_ldiv();
	void print_jvm_fdiv();
	void print_jvm_ddiv();
	void print_jvm_irem();
	void print_jvm_lrem();
	void print_jvm_frem();
	void print_jvm_drem();
	void print_jvm_ineg();
	void print_jvm_lneg();
	void print_jvm_fneg();
	void print_jvm_dneg();
	void print_jvm_ishl();
	void print_jvm_lshl();
	void print_jvm_ishr();
	void print_jvm_lshr();
	void print_jvm_iushr();
	void print_jvm_lushr();
	void print_jvm_iand();
	void print_jvm_land();
	void print_jvm_ior();
	void print_jvm_lor();
	void print_jvm_ixor();
	void print_jvm_lxor();
	void print_jvm_iinc();
	void print_jvm_i2l();
	void print_jvm_i2f();
	void print_jvm_i2d();
	void print_jvm_l2i();
	void print_jvm_l2f();
	void print_jvm_l2d();
	void print_jvm_f2i();
	void print_jvm_f2l();
	void print_jvm_f2d();
	void print_jvm_d2i();
	void print_jvm_d2l();
	void print_jvm_d2f();
	void print_jvm_i2b();
	void print_jvm_i2c();
	void print_jvm_i2s();
	void print_jvm_lcmp();
	void print_jvm_fcmpl();
	void print_jvm_fcmpg();
	void print_jvm_dcmpl();
	void print_jvm_dcmpg();
	void print_jvm_ifeq();
	void print_jvm_ifne();
	void print_jvm_iflt();
	void print_jvm_ifge();
	void print_jvm_ifgt();
	void print_jvm_ifle();
	void print_jvm_if_icmpeq();
	void print_jvm_if_icmpne();
	void print_jvm_if_icmplt();
	void print_jvm_if_icmpge();
	void print_jvm_if_icmpgt();
	void print_jvm_if_icmple();
	void print_jvm_if_acmpeq();
	void print_jvm_if_acmpne();
	void print_jvm_goto();
	void print_jvm_jsr();
	void print_jvm_ret();
	void print_jvm_tableswitch();
	void print_jvm_lookupswitch();
	void print_jvm_ireturn();
	void print_jvm_lreturn();
	void print_jvm_freturn();
	void print_jvm_dreturn();
	void print_jvm_areturn();
	void print_jvm_return();
	void print_jvm_getstatic();
	void print_jvm_putstatic();
	void print_jvm_getfield();
	void print_jvm_putfield();
	void print_jvm_invokevirtual();
	void print_jvm_invokespecial();
	void print_jvm_invokestatic();
	void print_jvm_invokeinterface();
	void print_jvm_invokedynamic();
	void print_jvm_new();
	void print_jvm_newarray();
	void print_jvm_anewarray();
	void print_jvm_arraylength();
	void print_jvm_athrow();
	void print_jvm_checkcast();
	void print_jvm_instanceof();
	void print_jvm_monitorenter();
	void print_jvm_monitorexit();
	void print_jvm_wide();
	void print_jvm_multianewarray();
	void print_jvm_ifnull();
	void print_jvm_ifnonnull();
	void print_jvm_goto_w();
	void print_jvm_jsr_w();
	void print_jvm_breakpoint();
	void print_jvm_impdep1();
	void print_jvm_impdep2();
public:
	/// \brief fornece estrutura de ClassFile a ser exibida.
	///
	/// a estrutura e copiada e armazenada pelo exibidor.
	/// futuros feeds substituem a estrutura.
	void feed(const ClassFile & toshow);
	/// \brief inicia a exibicao da classe armazenada.
	///
	/// o fluxo de exibicao inclui input e output.
	/// a output inclui as "telas" que mostram informacao e opcoes.
	/// a input inclui selecao de opcoes de navegacao pelo usuario
	void show();
	Exibidor(){}
	Exibidor(const ClassFile & cf){
		feed(cf);
	}
};

// #include "Exibidor.cpp"

#endif