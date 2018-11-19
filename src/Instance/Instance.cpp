#include "Instance.hpp"
#include "../ClassFileStructures/attribute_info.hpp"
#include "../ClassFileStructures/cp_info.hpp"
#include "../ClassFileStructures/field_info.hpp"
#include "../ClassFileStructures/method_info.hpp"
#include <map>
std::map <char, int> FieldTypeSizeDict;

bool Instance :: initDict = false;
Instance :: Instance() {
	init_dict();
}

void Instance :: init_dict() {
	if(initDict) return;
	initDict = true;
	FieldTypeSizeDict['B'] = sizeof(char);
	FieldTypeSizeDict['C'] = sizeof(char);
	FieldTypeSizeDict['D'] = sizeof(double);
	FieldTypeSizeDict['F'] = sizeof(float);
	FieldTypeSizeDict['I'] = sizeof(int);
	FieldTypeSizeDict['J'] = sizeof(long);
	FieldTypeSizeDict['L'] = -1;
	FieldTypeSizeDict['S'] = sizeof(short);
	FieldTypeSizeDict['Z'] = sizeof(bool);  // duvida: JVM nao trata bools como fossem inteiros? a menos de vetor deles
	FieldTypeSizeDict['['] = sizeof(void*); // tamanho de uma referencia
}

void * Instance :: field_allocator(int idx) {
	CONSTANT_Fieldref_info * aux = 
				(CONSTANT_Fieldref_info *)&class_pointer->constant_pool[idx];
	int idx2 = aux->name_and_type_index;
	CONSTANT_NameAndType_info * aux2 = 
				(CONSTANT_NameAndType_info*) &class_pointer->constant_pool[idx2];
	int idx3 = aux2->descriptor_index;
	CONSTANT_Utf8_info * has_field_descriptor  = (CONSTANT_Utf8_info *)&class_pointer->constant_pool[idx3] ;
// Falta aidna retornar o espaço necessário de memória que deve ser alocado
}