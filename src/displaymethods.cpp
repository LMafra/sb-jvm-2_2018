#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.cpp"
#include "ClassFileStructures/cp_info.hpp"
#include <iostream>



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

int main(){
	ClassFile obj;
	//CONSTANT_Utf8_info stringy;
	//stringy.length = 14;
	//stringy.bytes = (u1 *)"attemptstring";
	displayClassFile(obj);
	//displayCONSTANT_Utf8_info(stringy);
	return 0;
}