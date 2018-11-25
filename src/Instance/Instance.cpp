#include "Instance.hpp"
#include "../ClassFileStructures/attribute_info.hpp"
#include "../ClassFileStructures/cp_info.hpp"
#include "../ClassFileStructures/field_info.hpp"
#include "../ClassFileStructures/method_info.hpp"
#include "../VMGlobals.hpp"
#include <map>
#include <string>

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
	
	CONSTANT_Utf8_info * has_field_descriptor  = 
	(CONSTANT_Utf8_info *)&class_pointer->constant_pool[idx3] ;
	std::string FieldDescriptor((const char*)has_field_descriptor->bytes , has_field_descriptor->length);
	
	char c = FieldDescriptor[0];
	// Falta aidna retornar o espaço necessário de memória que deve ser alocado
	if( c != 'L' and c != '[')
		return calloc(1, FieldTypeSizeDict[c]);
	else {
		return NULL;
		// processamento para alocar espaço necessario para arrays e 
		// objetos.
	}

}

void * Instance :: instance_allocator(int class_info_index ) {
	Frame_type * aux = &frame_stack.top();	
	
	ClassFile * class_pointer = aux->inst->classe;
	CONSTANT_Class_info * class_info = 
	(CONSTANT_Class_info*)&class_pointer->constant_pool[class_info_index];
	
	CONSTANT_Utf8_info * class_name = 
	(CONSTANT_Utf8_info *)&class_pointer->constant_pool[class_info->name_index];
	
	string str( (char*)class_name->bytes, class_name->length );
	std::cerr << " Allocating space for instance of ==> " << str << std::endl;
	
	

}