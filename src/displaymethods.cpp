#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.cpp"
#include <iostream>



/// \brief display para informacoes gerais da classse e opcoes de navegacao.
///
/// apresenta informacoes como magic number, versao, contadores e flags de acesso.
/// mostra opcoes de navegacao para constant pool, metodos, atributos, fields e interfaces.
void displayClass(ClassFile theclass){  // TODO encontrar this class e super class na constant pool para exibir
	std::cout << "class file:" << std::endl;
	std::cout << "  magic: " << std::hex << std::showbase <<std::uppercase << theclass.magic << std::endl << std::dec;
	std::cout << "  minor version: " << theclass.minor_version << std::endl;
	std::cout << "  major version: " << theclass.major_version << std::endl;
	std::cout << "  constant pool count: " << theclass.constant_pool_count << std::endl;
	// TODO apresentar mnemonicos das flags
	std::cout << "  access flags: " << std::hex << std::showbase << std::uppercase << theclass.access_flags << std::endl << std::dec;
	std::cout << "  this class: " << theclass.this_class << std::endl;
	std::cout << "  super class: " << theclass.super_class << std::endl;
	std::cout << "  interfaces count: " << theclass.interfaces_count << std::endl;
	std::cout << "  fields count: " << theclass.fields_count << std::endl;
	std::cout << "  methods count: " << theclass.methods_count << std::endl;
	std::cout << "  attributes count: " << theclass.attributes_count << std::endl;
}

int main(){
	ClassFile obj;
	displayClass(obj);
	return 0;
}