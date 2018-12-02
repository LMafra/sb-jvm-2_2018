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
	if ( name.find("java/") != name.npos ) 
		return true;
	return false;
}
bool condnotprintln(char* methodname){
	std::string name(methodname);
	#ifdef DEBUG
	if(!(name.compare("println"))){
		printf("%s isnt println!\n", methodname);
	}
	else{
		printf("%s is println!\n", methodname);
	}
	#endif
	if (name.compare("println")==0){
		return false;
	}
	else{
		return true;
	}
	return !(name.compare("println"));
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
		#ifdef DEBUG
		printf("debug find method didnt find at %d, will look at %d\n", index-1, index);
		#endif
	}
	if (namescomp(*(CONSTANT_Utf8_info *)&(inst->my_class_ptr->constant_pool[inst->my_class_ptr->methods[index].name_index]),metname)==true){
		#ifdef DEBUG
		printf("debug find method found at %d\n", index);
		#endif
		return &(inst->my_class_ptr->methods[index]);
	}
	#ifdef DEBUG
	printf("debug find method didnt find anything\n");
	#endif
	return NULL;
}

void instance_frame_loader_interpreter(int indexname, int indextype, int indexclass, Instance * inst, cat1 * args){
	#ifdef DEBUG
	printf("debug fl1\n");
	#endif
	Frame_type topush;
	topush.inst=inst;
	topush.PC_retorno=PC;
	#ifdef DEBUG
	printf("%d is index classref\n",indexclass);
	#endif
	CONSTANT_Class_info * methodclass = (CONSTANT_Class_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[indexclass];
	#ifdef DEBUG
	printf("%d is index type\n",indextype);
	#endif
	CONSTANT_Utf8_info * methodtype = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[indextype];
	#ifdef DEBUG
	printf("%d is index\n",indexname);
	#endif
	CONSTANT_Utf8_info * methodname = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[indexname];
	CONSTANT_Utf8_info * methodclassname = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodclass->name_index];
	char mettype[methodtype->length+1];
	char metname[methodname->length+1];
	char classname[methodclassname->length+1];
	#ifdef DEBUG
	printf("debug fl2\n");
	printf("%d\n", methodname->length);
	printf("%c\n", methodname->bytes[0]);
	printf("%c\n", methodname->bytes[1]);
	printf("%c\n", methodname->bytes[2]);
	#endif
	for(int i=0;i<methodname->length;i++){
		#ifdef DEBUG
		printf("%d %c\n", i,methodname->bytes[i]);
		#endif
		metname[i]=methodname->bytes[i];
	}
	#ifdef DEBUG
	printf("debug fl3\n");
	#endif
	for(int i=0;i<methodtype->length;i++){
		mettype[i]=methodtype->bytes[i];
	}
	#ifdef DEBUG
	printf("debug fl4\n");
	#endif
	for(int i=0;i<methodclassname->length;i++){
		classname[i]=methodclassname->bytes[i];
	}
	metname[methodname->length]='\0';
	mettype[methodtype->length]='\0';
	classname[methodclassname->length]='\0';
	if(condjavaclass(classname)&&condnotprintln(metname)){
		return;
	}
	#ifdef DEBUG
	printf("debug fl5\n");
	#endif
	/*metname[0]='p';
	metname[1]='e';
	metname[2]='n';
	metname[3]='\0';*/
	printf("%s\n", metname);
	if (condnotprintln(metname)==false){
		#ifdef DEBUG
		printf("debug fl10\n");
		#endif
		double auxing;
		#ifdef DEBUG
		printf("debug fl11\n");
		#endif
		((u4*)(&auxing))[0]=args[1].val;
		#ifdef DEBUG
		printf("debug fl12\n");
		#endif
		((u4*)(&auxing))[1]=args[0].val;
		#ifdef DEBUG
		printf("debug fl13\n");
		#endif
		printf("%lf\n", auxing);
		#ifdef DEBUG
		printf("debug fl14\n");
		#endif
		return;
	}

	#ifdef DEBUG
	printf("debug fl6\n");
	#endif
	int paramnum = ammountofparams(mettype);

	method_info * calledinfo = findmethodinclass(inst,metname);

	topush.variaveis_locais = (cat1*)malloc( (*(Code_attribute *)&calledinfo->attributes[0]).max_locals * sizeof(cat1) );

	#ifdef DEBUG
	printf("debug fl7\n");
	#endif
	calledinfo;
	#ifdef DEBUG
	printf("debug fl7 2\n");
	#endif
	if (calledinfo->access_flags & enum_method_access_flags::ACC_STATIC){
		#ifdef DEBUG
		printf("debug fl static\n");
		#endif
		for(int i=0;i<paramnum;i++){
			topush.variaveis_locais[i]=args[i];
		}
	}
	else{
		#ifdef DEBUG
		printf("debug fl no static\n");
		#endif
		cat1 firstparam;
		firstparam.ref_val=inst;
		topush.variaveis_locais[0] = firstparam;
		for(int i=0;i<paramnum;i++){
			topush.variaveis_locais[i+1]=args[i];
		}
	}
	#ifdef DEBUG
	printf("debug fl8\n");
	#endif
	topush.PC_base = (*(Code_attribute *)&calledinfo->attributes[0]).code;
	PC = topush.PC_base;
	topush.PC_final = &topush.PC_base[(*(Code_attribute *)&calledinfo->attributes[0]).code_length];
	frame_stack.push(topush);
	#ifdef DEBUG
	printf("debug fl9\n");
	#endif
	return;
}

void instance_frame_loader(int index, Instance * inst, cat1 * args){
	#ifdef DEBUG
	printf("debug fl1\n");
	#endif
	Frame_type topush;
	topush.inst=inst;
	topush.PC_retorno=PC;
	#ifdef DEBUG
	printf("%d is index metref\n",index);
	#endif
	CONSTANT_Methodref_info * method = 
	(CONSTANT_Methodref_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[index];
	CONSTANT_Class_info * methodclass = (CONSTANT_Class_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[method->class_index];
	CONSTANT_NameAndType_info * methodnat = (CONSTANT_NameAndType_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[method->name_and_type_index];
	CONSTANT_Utf8_info * methodtype = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->descriptor_index];
	#ifdef DEBUG
	printf("%d is index\n",methodnat->name_index);
	#endif
	CONSTANT_Utf8_info * methodname = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->name_index];
	CONSTANT_Utf8_info * methodclassname = (CONSTANT_Utf8_info *)&frame_stack.top().inst->my_class_ptr->constant_pool[methodclass->name_index];
	char mettype[methodtype->length+1];
	char metname[methodname->length+1];
	char classname[methodclassname->length+1];
	#ifdef DEBUG
	printf("debug fl2\n");
	printf("%d\n", methodname->length);
	printf("%c\n", methodname->bytes[0]);
	printf("%c\n", methodname->bytes[1]);
	printf("%c\n", methodname->bytes[2]);
	#endif
	for(int i=0;i<methodname->length;i++){
		#ifdef DEBUG
		printf("%d %c\n", i,methodname->bytes[i]);
		#endif
		metname[i]=methodname->bytes[i];
	}
	#ifdef DEBUG
	printf("debug fl3\n");
	#endif
	for(int i=0;i<methodtype->length;i++){
		mettype[i]=methodtype->bytes[i];
	}
	#ifdef DEBUG
	printf("debug fl4\n");
	#endif
	for(int i=0;i<methodclassname->length;i++){
		classname[i]=methodclassname->bytes[i];
	}
	metname[methodname->length]='\0';
	mettype[methodtype->length]='\0';
	classname[methodclassname->length]='\0';
	if(condjavaclass(classname)&&condnotprintln(metname)){
		#ifdef DEBUG
		printf("debug java not println\n");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("debug fl5\n");
	#endif
	/*metname[0]='p';
	metname[1]='e';
	metname[2]='n';
	metname[3]='\0';*/
	printf("%s\n", metname);
	if (condnotprintln(metname)==false){
		#ifdef DEBUG
		printf("debug fl10\n");
		#endif
		double auxing;
		#ifdef DEBUG
		printf("debug fl11\n");
		#endif
		((u4*)(&auxing))[0]=args[1].val;
		#ifdef DEBUG
		printf("debug fl12\n");
		#endif
		((u4*)(&auxing))[1]=args[0].val;
		#ifdef DEBUG
		printf("debug fl13\n");
		#endif
		printf("%lf\n", auxing);
		#ifdef DEBUG
		printf("debug fl14\n");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("debug fl6\n");
	#endif
	int paramnum = ammountofparams(mettype);

	method_info * calledinfo = findmethodinclass(inst,metname);

	topush.variaveis_locais = (cat1*)malloc( (*(Code_attribute *)&calledinfo->attributes[0]).max_locals * sizeof(cat1) );

	#ifdef DEBUG
	printf("debug fl7\n");
	#endif
	calledinfo;
	#ifdef DEBUG
	printf("debug fl7 2\n");
	#endif
	if (calledinfo->access_flags & enum_method_access_flags::ACC_STATIC){
		#ifdef DEBUG
		printf("debug fl static\n");
		#endif
		for(int i=0;i<paramnum;i++){
			topush.variaveis_locais[i]=args[i];
		}
	}
	else{
		#ifdef DEBUG
		printf("debug fl no static\n");
		#endif
		cat1 firstparam;
		firstparam.ref_val=inst;
		topush.variaveis_locais[0] = firstparam;
		for(int i=0;i<paramnum;i++){
			topush.variaveis_locais[i+1]=args[i];
		}
	}
	#ifdef DEBUG
	printf("debug fl8\n");
	#endif
	topush.PC_base = (*(Code_attribute *)&calledinfo->attributes[0]).code;
	PC = topush.PC_base;
	topush.PC_final = &topush.PC_base[(*(Code_attribute *)&calledinfo->attributes[0]).code_length];
	frame_stack.push(topush);
	#ifdef DEBUG
	printf("debug fl9\n");
	#endif
	return;
}