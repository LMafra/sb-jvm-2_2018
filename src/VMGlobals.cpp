#pragma once

#include "UsingUs.h"
#include "VMGlobals.hpp"
#include "ClassFileStructures/attribute_info.hpp"
#include "ClassFileStructures/cp_info.hpp"
#include "ClassFileStructures/field_info.hpp"
#include "ClassFileStructures/method_info.hpp"
#include <map>
#include <string>
#include <string.h>


std::stack<Frame_type> frame_stack;
std::stack<cat1> jvm_stack;
u1 * PC;

bool global_path_set = 0;
extern char * global_path;
ClassFile ** method_area ;
std::set<const char*> jvm_loaded_classes;
std::map<const char*, int> jvm_class_method_area_index;

int class_counter = 0;

u1 instrparam(int n) {return PC[n];}
void incpc(int n) {PC = &PC[n];}


cat1 pop_cat1raw() {
	cat1 top = jvm_stack.top();
	jvm_stack.pop();
	return top;
}

u4 pop_cat1() {
	u4 top = jvm_stack.top().val;
	jvm_stack.pop();
	return top;
}

u8 pop_cat2() {
	u4 low = jvm_stack.top().val; jvm_stack.pop();
	u4 high = jvm_stack.top().val; jvm_stack.pop();
	u8 buffer;
	((u4*)&buffer)[0]=low;
	((u4*)&buffer)[1]=high;

	return buffer;
}
template <typename T>
void push_cat1(T val) {
	cat1 cat; cat.val = *(u4*)&val;
	jvm_stack.push( cat );
}

template <typename T>
void push_cat2(T val) {
	u8 _val; _val = *(u8*)&val;
	u4 low = _val, high = _val >> 32;
	push_cat1(high); push_cat1( low );
}

void * pop_reference() {
	cat1 c1 = pop_cat1raw();
	void * addr = c1.ref_val;	jvm_stack.pop();
	return addr;
}

int16_t offset16_from_stack() {
	u2 branch = 0; for(int i = 0; i < 2; i++)branch = branch << 8 | pop_cat1();
	return branch;  // u2 branch = pop_cat1(); branch = branch << 8 | pop_cat1();
}

int32_t offset32_from_stack() {
	u4 branch = 0; for(int i = 0; i < 4; i++)branch = branch << 8 | pop_cat1();
	return branch;  // return pop_cat1()<<24|pop_cat1()<<16|pop_cat1()<<8|pop_cat1();
}

int16_t offset16_from_instr(int add = 0) {
	u2 branch = 0; for(int i = 1; i < 3; i++)branch = branch << 8 | instrparam(i);
  return instrparam(1) << 8|instrparam(2);
  // u1 branchbyte1 = pop_cat1();u1 branchbyte2 = pop_cat1(); 
}

int32_t offset32_from_instr(int add = 0) {
	u4 branch = 0; for(int i = 1; i < 3; i++)branch = branch << 8 | instrparam(i);
	return branch;
  // return instrparam(1)<<24|instrparam(1)<<16|instrparam(2)<<8|instrparam(4);
}


template <typename T>
void push_reference(T * ref_val) {
	cat1 top; top.ref_val = ref_val;
	jvm_stack.push( top );
}


// #############################

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
/// Recebe um índice para a constant pool da classe base para field_ref_info
/// e ponteiro com espaço alocado para o field em questão.
void * Instance :: field_allocator(int idx) {

	CONSTANT_Utf8_info * has_field_descriptor;

	CONSTANT_Fieldref_info * aux =
				(CONSTANT_Fieldref_info *)&this->my_class_ptr->constant_pool[idx];

	if(aux->tag == enum_cp_tags::CONSTANT_Fieldref){
		int idx2 = aux->name_and_type_index;
		CONSTANT_NameAndType_info * aux2 =
					(CONSTANT_NameAndType_info*) &this->my_class_ptr->constant_pool[idx2];
		int idx3 = aux2->descriptor_index;
		has_field_descriptor =
			(CONSTANT_Utf8_info *)&this->my_class_ptr->constant_pool[idx3] ;
	}
	else {
		has_field_descriptor = (CONSTANT_Utf8_info*)&my_class_ptr->constant_pool[idx];
	}

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
Instance * Instance::instance_allocator(int class_info_index ) {
	Frame_type * aux = &frame_stack.top();	// pega contexto corrente
	ClassFile * class_current_frame = aux->inst->my_class_ptr;

	Instance * neww = (Instance *)calloc(1, sizeof(Instance));
	neww->my_class_ptr = class_current_frame;

	CONSTANT_Class_info * class_info =
	(CONSTANT_Class_info*)&class_current_frame->constant_pool[class_info_index];

	CONSTANT_Utf8_info * class_name =
	(CONSTANT_Utf8_info *)&class_current_frame->constant_pool[class_info->name_index];

	string str( (char*)class_name->bytes, class_name->length );
	#ifdef DEBUG
	std::cerr << " Allocating space for instance of ==> " << str << std::endl;
	#endif

	Dprintf("debug seg1\n");

	if(method_area[ jvm_class_method_area_index[str.c_str()] ] != class_current_frame) {
	#if DEBUG
		printf("debug seg2\n");
		printf("DEU RUIM NO INSTANCE ALLOCATOR!! Ponteiro do frame corrente não bate com method_area\n");
	#endif
	throw "DEU RUIM NO INSTANCE ALLOCATOR!! Ponteiro do frame corrente não bate com method_area\n";

	}
	Dprintf("debug seg3\n");
	neww->my_class_ptr = method_area[ jvm_class_method_area_index[str.c_str()] ];

	field_info * neww_fields =
		(field_info*)calloc( neww->my_class_ptr->fields_count, sizeof(field_info) );
	field_info * my_class_fields = (field_info *)neww->my_class_ptr->fields;

	Dprintf("debug seg4\n");
	for(auto i = 0 ; i < neww->my_class_ptr->fields_count; i++) {
		// neww_fields[i] = (field_info*) calloc(1, sizeof(field_info));

		memcpy( &neww_fields[i], &neww->my_class_ptr->fields[i],  sizeof(field_info));

		neww_fields[i].attributes =
		(attribute_info*) calloc(my_class_fields[i].attributes_count, sizeof(attribute_info));

		for(int jj = 0; jj < my_class_fields[i].attributes_count; jj++) {
			memcpy(&neww_fields[i].attributes[jj], &my_class_fields[i].attributes[jj], sizeof(attribute_info));
		}
	}
	Dprintf("debug seg5\n");
	neww->my_attributes = neww_fields;

	Dprintf("debug seg6\n");
	return neww;
}
