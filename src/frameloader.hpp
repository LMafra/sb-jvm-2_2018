#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#include  "VMGlobals.hpp"

bool condjavaclass(char* classname){
	std::string name(classname);
	if ( name.find("/java/") != name.npos ) 
		return true;
	return false;
}
bool condnotprintln(char* methodname){
	std::string name(methodname);
	return !name.compare("println");
}
int ammountofparams(char* descriptor){
	return 0;
}
method_info * findmethodinclass(Instance * inst,char* metname){
	return null;
}

void instance_frame_loader(int index, Instance * inst, cat1 * args){
	Frame_type topush;
	topush.inst=inst;
	topush.PC_retorno=PC;
	CONSTANT_Methodref_info * method = 
	(CONSTANT_Methodref_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[index];
	CONSTANT_Class_info * methodclass = (CONSTANT_Class_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[method->class_index];
	CONSTANT_NameAndType_info * methodnat = (CONSTANT_NameAndType_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[method->name_and_type_index];
	CONSTANT_Utf8_info * methodtype = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->descriptor_index];
	CONSTANT_Utf8_info * methodname = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->name_index];
	CONSTANT_Utf8_info * methodclassname = (CONSTANT_Utf8_info *)frame_stack.top().inst->my_class_ptr->constant_pool[methodclass->nameindex];
	char mettype[methodtype->length+1];
	char metname[methodname->length+1];
	char classname[methodclassname->length+1];
	for(int i=0;i<methodname->length;i++){
		metname[i]=methodname->bytes[i];
	}
	for(int i=0;i<methodtype->length;i++){
		mettype[i]=methodtype->bytes[i];
	}
	for(int i=0;i<methodclassname->length;i++){
		classname[i]=methodclassname->bytes[i];
	}
	metname[methodname->length]='\0';
	mettype[methodtype->length]='\0';
	classname[methodclassname->length]='\0';
	if(condjavaclass(classname)&&condnotprintln(metname)){
		return;
	}

	int paramnum = ammountofparams(mettype);

	method_info * calledinfo = findmethodinclass(inst,metname);

	topush.variaveis_locais = (cat1*)malloc( calledinfo->attributes[0].max_locals * sizeof(cat1) );

	if (accflags & enum_method_access_flags::ACC_STATIC){
		for(int i=0;i<paramnum;i++){
			topush.variaveis_locais[i]=args[i];
		}
	}
	else{
		cat1 firstparam;
		firstparam.ref_val=inst;
		topush.variaveis_locais[0] = firstparam;
		for(int i=0;i<paramnum;i++){
			topush.variaveis_locais[i+1]=args[i];
		}
	}
	topush.PC_base = calledinfo->attributes[0].code;
	frame_stack.push(topush);
	return;
}