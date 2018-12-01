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
	int index =0;
	int count =0;
	while(descriptor[index]!= '('){index++;}
	index++;
	while(descriptor[index]!= ')' && descriptor[index]!= '\0'){
		char aux = descriptor[index];
		if(aux == 'L'){
			count ++;
			while(descriptor[index]!=';'){
				index++;
			}
		}
		else if(aux == 'J' || aux == 'D'){
			count+=2;
		}
		else{
			count++;
		}
		index++;
	}
	return count;
}
bool namescomp(CONSTANT_Utf8_info & nametry, char* metname){
	int i=0;
	while(i < nametry.length && metname[i]!='\0' && metname[i]==(char)nametry.bytes[i]){
		i++;
	}
	if(i == nametry.length && metname[i]=='\0'){
		return true;
	}
	else{
		return false;
	}
}
method_info * findmethodinclass(Instance * inst,char* metname){
	int index = 0;
	while(namescomp(*(CONSTANT_Utf8_info *)&(inst->my_class_ptr->constant_pool[inst->my_class_ptr->methods[index].name_index]),metname)==false && index<inst->my_class_ptr->methods_count-1){
		index++;
	}
	if (namescomp(*(CONSTANT_Utf8_info *)&(inst->my_class_ptr->constant_pool[inst->my_class_ptr->methods[index].name_index]),metname)==true){
		return &(inst->my_class_ptr->methods[index]);
	}
	return NULL;
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
	CONSTANT_Utf8_info * methodclassname = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodclass->name_index];
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
	if (condnotprintln(metname)==false){
		double auxing;
		((u4*)&auxing)[0]=args[1].val;
		((u4*)&auxing)[1]=args[0].val;
		printf("%lf\n", auxing);
		return;
	}

	int paramnum = ammountofparams(mettype);

	method_info * calledinfo = findmethodinclass(inst,metname);

	topush.variaveis_locais = (cat1*)malloc( (*(Code_attribute *)&calledinfo->attributes[0]).max_locals * sizeof(cat1) );

	if (calledinfo->access_flags & enum_method_access_flags::ACC_STATIC){
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
	topush.PC_base = (*(Code_attribute *)&calledinfo->attributes[0]).code;
	PC = topush.PC_base;
	topush.PC_final = &topush.PC_base[(*(Code_attribute *)&calledinfo->attributes[0]).code_length];
	frame_stack.push(topush);
	return;
}