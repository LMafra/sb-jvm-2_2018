#pragma once

#include "ClassFileStructures/attribute_info.hpp"
#include "ClassFileStructures/cp_info.hpp"
#include "ClassFileStructures/field_info.hpp"
#include "ClassFileStructures/method_info.hpp"
#include <map>
#include <string>


std::stack<Frame_type> frame_stack;
std::stack<cat1> jvm_stack;
u1 * PC;

bool global_path_set = 0;
extern char * global_path;
ClassFile ** method_area ;
std::set<const char*> jvm_loaded_classes;
std::map<const char*, int> jvm_class_method_area_index;

int class_counter = 0;
u4 pop_cat1() {
	u4 top = jvm_stack.top().val;
	jvm_stack.pop();
	return top;
}

u8 pop_cat2() {
	u4 first = jvm_stack.top().val; jvm_stack.pop();
	u4 second = jvm_stack.top().val; jvm_stack.pop();
	return (*(u8*)&first) << 32 | *(u8*)&second;
}

void * pop_address() {
	void * addr = jvm_stack.top().ref_val;	jvm_stack.pop();
	return addr;
}

template <typename T>
void jvm_push(T val) {
	cat1 top; top.val = *(u4*)&val;
	jvm_stack.push( top );
}

template <typename T>
void * jvm_push_reference(T * ref_val) {
	cat1 top; top.ref_val = ref_val;
	jvm_stack.push( top );
}

std::map <char, int> FieldTypeSizeDict;

bool Instance :: initDict = false;
Instance :: Instance() {
	init_dict();
}

void Instance :: init_dict() {
	if(initDict) return;
	initDict = true;
	// Table 4.2. Interpretation of FieldType characters
	FieldTypeSizeDict['B'] = sizeof(u1); //sizeof(char);
	FieldTypeSizeDict['C'] = sizeof(u1); //sizeof();
	FieldTypeSizeDict['D'] = sizeof(u8); //sizeof(double);
	FieldTypeSizeDict['F'] = sizeof(u4); //sizeof(float);
	FieldTypeSizeDict['I'] = sizeof(u4); //sizeof(int);
	FieldTypeSizeDict['J'] = sizeof(u8); //sizeof(long);
	FieldTypeSizeDict['L'] = -1;
	FieldTypeSizeDict['S'] = sizeof(u2); //sizeof(short);
	FieldTypeSizeDict['Z'] = sizeof(u4); //sizeof(bool);  // duvida: JVM nao trata bools como fossem inteiros? a menos de vetor deles
	FieldTypeSizeDict['['] = sizeof(void*); //sizeof(void*); // tamanho de uma referencia
}

void * Instance :: field_allocator(int idx) {
	CONSTANT_Fieldref_info * aux = 
				(CONSTANT_Fieldref_info *)&my_class_pointer->constant_pool[idx];
	int idx2 = aux->name_and_type_index;
	CONSTANT_NameAndType_info * aux2 = 
				(CONSTANT_NameAndType_info*) &my_class_pointer->constant_pool[idx2];
	int idx3 = aux2->descriptor_index;
	
	CONSTANT_Utf8_info * has_field_descriptor  = 
	(CONSTANT_Utf8_info *)&my_class_pointer->constant_pool[idx3] ;
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

// [23:17] Arthur UnB /CM: Instância aponta pra classe e pra um vetor de ponteiros
// [23:17] Arthur UnB /CM: Cada ponteiro aponta pra um dos fields do objeto
// [23:18] Arthur UnB /CM: O obj alocator aloca o espaço da instância
// [23:18] Arthur UnB /CM: Onde tem os dois ponteiros
// [23:18] Arthur UnB /CM: Depois aloca o vetor de ponteiros
// [23:19] Arthur UnB /CM: E pra cada ponteiro do vetor ele manda o field alocator alocar um field
// [23:19] Arthur UnB /CM: Em ordem

// WARNING :: UNTESTED!!!
// Testar assim que possível!!!!!!!!!!!!!!!!!
void * Instance :: instance_allocator(int class_info_index ) {
	Frame_type * aux = &frame_stack.top();	// pega contexto corrente
	
	ClassFile * class_pointer = aux->inst->my_class_pointer;
	CONSTANT_Class_info * class_info = 
	(CONSTANT_Class_info*)&class_pointer->constant_pool[class_info_index];
	
	CONSTANT_Utf8_info * class_name = 
	(CONSTANT_Utf8_info *)&class_pointer->constant_pool[class_info->name_index];
	
	string str( (char*)class_name->bytes, class_name->length );
	std::cerr << " Allocating space for instance of ==> " << str << std::endl;

	my_class_pointer = method_area[ jvm_class_method_area_index[str.c_str()] ];

	field_info * fields_pointer = 
		(field_info*)calloc( my_class_pointer->fields_count, sizeof(field_info) );
	field_info * my_class_fields = (field_info *)my_class_pointer->fields;

	for(auto i = 0 ; i < my_class_pointer->fields_count; i++) {
		// fields_pointer[i] = (field_info*) calloc(1, sizeof(field_info));

		memcpy( &fields_pointer[i], &my_class_pointer[i],  sizeof(field_info));

		fields_pointer[i].attributes = 
		(attribute_info*) calloc(my_class_fields[i].attributes_count, sizeof(attribute_info));
		for(int jj = 0; jj < my_class_fields[i].attributes_count; jj++) {
			memcpy(&fields_pointer[i].attributes[jj], &my_class_fields[i].attributes[jj], sizeof(attribute_info));
			// fields_pointer[i].attributes[jj].info = 
			// (u1*)calloc(fields_pointer[i].attributes[jj].attribute_length, sizeof(u1));
		}
	}
	my_attributes = fields_pointer;

}