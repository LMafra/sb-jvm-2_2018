#pragma once
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#include "ClassFileStructures/cp_info.hpp"
#include <iostream>
#include <cstring>
#include <cstdio>

/// \brief display para informacoes gerais da classse e opcoes de navegacao.
///
/// apresenta informacoes como magic number, versao, contadores e flags de acesso.
/// mostra opcoes de navegacao para constant pool, metodos, atributos, fields e interfaces.
void displayClassFile(ClassFile theclass){  // TODO encontrar this class e super class na constant pool para exibir
	/// imprime os dados gerais de class file.
	///
	std::cout << "class file:" << std::endl;
	std::cout << "  magic: " << std::hex << std::showbase <<std::uppercase << theclass.magic << std::endl << std::dec;
	std::cout << "  minor version: " << theclass.minor_version << std::endl;
	std::cout << "  major version: " << theclass.major_version << std::endl;
	std::cout << "  constant pool count: " << theclass.constant_pool_count << std::endl;
	// TODO apresentar mnemonicos das flags
	std::cout << "  access flags: " << std::hex << std::showbase << std::uppercase << theclass.access_flags << std::endl << std::dec;
	std::cout << "  this class: cp_info# " << theclass.this_class << std::endl;
	std::cout << "  super class: cp_info# " << theclass.super_class << std::endl;
	std::cout << "  interfaces count: " << theclass.interfaces_count << std::endl;
	std::cout << "  fields count: " << theclass.fields_count << std::endl;
	std::cout << "  methods count: " << theclass.methods_count << std::endl;
	std::cout << "  attributes count: " << theclass.attributes_count << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcoes de navegacao.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- constant pool" << std::endl;
	std::cout << "2- interfaces" << std::endl;
	std::cout << "3- fields" << std::endl;
	std::cout << "4- methods" << std::endl;
	std::cout << "5- attributes" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para class info.
///
/// apresenta o cp info com o nome da classe.
void displayCONSTANT_Class_info(CONSTANT_Class_info theclassinfo){
	/// imprime o indice da string nome.
	///
	std::cout << "class info:" << std::endl;
	std::cout << "  class name: cp_info# " << theclassinfo.name_index << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de abrir nome.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- class name" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para fieldref info.
///
/// apresenta o cp info com o nome da classe que contem o field, e nome e tipo do field.
void displayCONSTANT_Fieldref_info(CONSTANT_Fieldref_info thefieldinfo){
	/// imprime o indice da classe/inferface do field e o indice do tipo e nome.
	///
	std::cout << "field ref info:" << std::endl;
	std::cout << "  class/interface name: cp_info# " << thefieldinfo.class_index << std::endl;
	std::cout << "  name and type: cp_info# " << thefieldinfo.name_and_type_index << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de abrir nome da classe/interface ou nome e tipo do field.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- class/interface name" << std::endl;
	std::cout << "2- field name and type" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para name and type info.
///
/// apresenta o cp info com o nome do metodo/field e o tipo do metodo/field.
void displayCONSTANT_NameAndType_info(CONSTANT_NameAndType_info thenameandtypeinfo){
	/// imprime o indice do nome do field/metodo e o indice do tipo.
	///
	std::cout << "name and type info:" << std::endl;
	std::cout << "  name: cp_info# " << thenameandtypeinfo.name_index << std::endl;
	std::cout << "  type descriptor: cp_info# " << thenameandtypeinfo.descriptor_index << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de abrir nome do field/metodo ou tipo do field/metodo.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- name" << std::endl;
	std::cout << "2- type descriptor" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para constantes utf8.
///
/// apresenta o cp info com o tamanho da string e a string em si.
void displayCONSTANT_Utf8_info(CONSTANT_Utf8_info theunistringinfo){
	/// imprime o tamanho em bytes da string e a string em si.
	///
	std::cout << "utf8 info:" << std::endl;
	std::cout << "  length: " << theunistringinfo.length << std::endl;
	std::cout << "  string: " << (char*)theunistringinfo.bytes << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de voltar, ja que strings nao levam a nada.
	///
	std::cout << "options:" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para methodref info.
///
/// apresenta o cp info com o nome da classe que contem o metodo, e nome e tipo do metodo.
void displayCONSTANT_Methodref_info(CONSTANT_Methodref_info themethodinfo){
	/// imprime o indice da classe/inferface do metodo e o indice do tipo e nome.
	///
	std::cout << "method ref info:" << std::endl;
	std::cout << "  class name: cp_info# " << themethodinfo.class_index << std::endl;
	std::cout << "  name and type: cp_info# " << themethodinfo.name_and_type_index << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de abrir nome da classe/interface ou nome e tipo do metodo.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- class name" << std::endl;
	std::cout << "2- method name and type" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para methodref info.
///
/// apresenta o cp info com o nome da classe que contem o metodo, e nome e tipo do metodo.
void displayCONSTANT_InterfaceMethodref_info(CONSTANT_InterfaceMethodref_info themethodinfo){
	/// imprime o indice da classe/inferface do metodo e o indice do tipo e nome.
	///
	std::cout << "method ref info:" << std::endl;
	std::cout << "  interface name: cp_info# " << themethodinfo.class_index << std::endl;
	std::cout << "  name and type: cp_info# " << themethodinfo.name_and_type_index << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de abrir nome da classe/interface ou nome e tipo do metodo.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- interface name" << std::endl;
	std::cout << "2- method name and type" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para string info.
///
/// apresenta o cp info com o indice da string.
void displayCONSTANT_String_info(CONSTANT_String_info thestringinfo){
	/// imprime o indice da string.
	///
	std::cout << "string info:" << std::endl;
	std::cout << "  string text: cp_info# " << thestringinfo.string_index << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de abrir texto.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- text" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para int info.
///
/// apresenta o cp info com o numero constante.
void displayCONSTANT_Integer_info(CONSTANT_Integer_info theintinfo){
	/// imprime o numero.
	///
	std::cout << "integer info:" << std::endl;
	std::cout << "  value: " << theintinfo.bytes << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de sair, inteiros nao levam a nada.
	///
	std::cout << "options:" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para float info.
///
/// apresenta o cp info com o numero constante.
void displayCONSTANT_Float_info(CONSTANT_Float_info thefloatinfo){
	/// imprime o numero.
	///
	float buff;
	std::memcpy(&buff, &thefloatinfo.bytes, sizeof(thefloatinfo.bytes));
	std::cout << "float info:" << std::endl;
	std::cout << "  value: " << buff << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de sair, floats nao levam a nada.
	///
	std::cout << "options:" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para long info.
///
/// apresenta o cp info com o numero constante.
void displayCONSTANT_Long_info(CONSTANT_Long_info thelonginfo){
	/// imprime o numero.
	///
	uint32_t buff[2];
	std::memcpy(&buff[1], &thelonginfo.high_bytes, sizeof(thelonginfo.high_bytes));
	std::memcpy(&buff[0], &thelonginfo.low_bytes, sizeof(thelonginfo.low_bytes));
	std::cout << "long info:" << std::endl;
	std::cout << "  value: " << ((uint64_t*)buff)[0] << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de sair, longs nao levam a nada.
	///
	std::cout << "options:" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para double info.
///
/// apresenta o cp info com o numero constante.
void displayCONSTANT_Double_info(CONSTANT_Double_info thedoubleinfo){
	/// imprime o numero.
	///
	uint32_t buff[2];
	std::memcpy(&buff[1], &thedoubleinfo.high_bytes, sizeof(thedoubleinfo.high_bytes));
	std::memcpy(&buff[0], &thedoubleinfo.low_bytes, sizeof(thedoubleinfo.low_bytes));
	std::cout << "double info:" << std::endl;
	std::cout << "  value: " << ((double)buff)[0] << std::endl;
	std::cout << std::endl << std::endl;

	/// imprime opcao de sair, doubles nao levam a nada.
	///
	std::cout << "options:" << std::endl;
	std::cout << "0- exit" << std::endl;
}

/// \brief display para entradas na tabela de constantes.
///
/// apresenta lista de entradas da CP.
/// mostra opcoes de navegacao para constant pool.
void displayconstant_pool(ClassFile theclass){  // TODO encontrar this class e super class na constant pool para exibir
	/// imprime as entradas.
	for(size_t i = 1; i < cf.constant_pool_count; i++) {
    	u1 tag;
    	memcpy(&tag, &theclass.constant_pool[i],sizeof(tag));
    	switch(tag) {
    	case enum_cp_tags::CONSTANT_Class:
    		std::cout << i << "- CONSTANT_Class_info" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Fieldref:
    		std::cout << i << "- CONSTANT_Fieldref_info" << std::endl;
        	break;
    	case enum_cp_tags::CONSTANT_Methodref:
    		std::cout << i << "- CONSTANT_Methodref_info" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_InterfaceMethodref:
    		std::cout << i << "- CONSTANT_InterfaceMethodref_info" << std::endl;
			break;
    	case enum_cp_tags::CONSTANT_String:
    		std::cout << i << "- CONSTANT_String_info" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Integer:
    		std::cout << i << "- CONSTANT_Integer_info" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Float:
    		std::cout << i << "- CONSTANT_Float_info" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Long:
    		std::cout << i << "- CONSTANT_Long_info" << std::endl;
    		i++;
    		std::cout << i << "- large numeric continued" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Double:
    		std::cout << i << "- CONSTANT_Double_info" << std::endl;
    		i++;
    		std::cout << i << "- large numeric continued" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_NameAndType:
    		std::cout << i << "- CONSTANT_NameAndType_info" << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Utf8:
    		std::cout << i << "- CONSTANT_Utf8_info" << std::endl;
    		break;
    	default:
    		std::cout << i << "- broken link" << std::endl;
    		break;
    	}
	}
	/// imprime opcoes de navegacao.
	///
	std::cout << "options:" << std::endl;
	std::cout << "1- constant pool" << std::endl;
	std::cout << "2- interfaces" << std::endl;
	std::cout << "3- fields" << std::endl;
	std::cout << "4- methods" << std::endl;
	std::cout << "5- attributes" << std::endl;
	std::cout << "0- exit" << std::endl;
}
