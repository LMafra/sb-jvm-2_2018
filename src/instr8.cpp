#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include "../frameloader.hpp"

void exec_jvm_goto(){
  incpc( offset16_from_instr() );
}
// maffei
void exec_jvm_jsr(){
  int index = (int)offset16_from_instr();
  jvm_push_reference( &PC[3] );
  increment_pc( index );
}

// maffei
void exec_jvm_ret(){
  u1 index = instrparam(1);
  PC = (u1*)frame_stack.top().variaveis_locais[index].ref_val;
}
// TODO: CORRIGIR !!!
void exec_jvm_tableswitch(){
  int32_t index = pop_cat1();
  u1 * instr_pc = PC;
  u1 diff_pc = PC - frame_stack.top().PC_base;
  u1 padding = diff_pc % 4; incpc(padding);
  int32_t default_val = offset32_from_instr();incpc(4);
  int32_t low_val = offset32_from_instr();  incpc(4);
  int32_t high_val = offset32_from_instr();  incpc(4);
  if ( index < low_val or index > high_val)
    PC = instr_pc + default_val;
  else
    PC = instr_pc + PC[index - low_val];
}
void exec_jvm_lookupswitch(){
	u1 * pcaux = PC;
  int padnum = ((u8)pcaux) - ((u8)frame_stack.top().PC_base);
  if (padnum%4 == 0){
    pcaux = &(pcaux[4]);
  }
  else if (padnum%4 == 1){
    pcaux = &(pcaux[3]);
  }
  else if (padnum%4 == 2){
    pcaux = &(pcaux[2]);
  }
  else if (padnum%4 == 3){
    pcaux = &(pcaux[1]);
  }
  int32_t defa;
  int32_t npairs;
  ((u1 *)&defa)[3] = pcaux[0];
  ((u1 *)&defa)[2] = pcaux[1];
  ((u1 *)&defa)[1] = pcaux[2];
  ((u1 *)&defa)[0] = pcaux[3];
  pcaux = &(pcaux[4]);
  ((u1 *)&npairs)[3] = pcaux[0];
  ((u1 *)&npairs)[2] = pcaux[1];
  ((u1 *)&npairs)[1] = pcaux[2];
  ((u1 *)&npairs)[0] = pcaux[3];
  pcaux = &(pcaux[4]);
  int32_t match[npairs];
  int32_t offset[npairs];
  for(int i = 0;i < npairs;i++){
    ((u1 *)&match[i])[3] = pcaux[0];
    ((u1 *)&match[i])[2] = pcaux[1];
    ((u1 *)&match[i])[1] = pcaux[2];
    ((u1 *)&match[i])[0] = pcaux[3];
    pcaux = &(pcaux[4]);
    ((u1 *)&offset[i])[3] = pcaux[0];
    ((u1 *)&offset[i])[2] = pcaux[1];
    ((u1 *)&offset[i])[1] = pcaux[2];
    ((u1 *)&offset[i])[0] = pcaux[3];
    pcaux = &(pcaux[4]);
  }
  u4 keyaux = popcat1();
  int32_t key = *((int32_t *)(&keyaux));
   for(int i=0;i<npairs;i++){
   	if(key==match[i]){
   		Dprintf("debug lookupswitch %d %d: %d\n", key,match[i],offset[i]);
   		u8 pcnew = ((u8)PC)+offset[i];
   		PC = *((u1**)(&pcnew));
   		return;
   	}
   }
   		Dprintf("debug lookupswitch %d %d: %d\n", key,defa,defa);
 	u8 pcnew = ((u8)PC)+defa;
   	PC = *((u1**)(&pcnew));
   	return;
}

static void _return() {
	Frame_type * frame = &frame_stack.top();	// Variavel auxiliar
	PC = frame->PC_retorno;	// restaura pc para funcao que o chamou
	size_t remove_qtd = jvm_stack.size() - frame->initial_stack_size;	
	Dprintf("Se deu segfault logo apohs essa linha, faltou inicializar o valor initial_stac_size do frame corrente :/\n");
	Dprintf("Esta mensagem se encontra no arquivo instr8.cpp\n");
	for(int i = 0; i < remove_qtd; i++) jvm_stack.pop();
	if(PC==NULL)Dprintf("debug null pointer return\n");
	frame_stack.pop();
}
static void _return32() {
	u4 ret = popcat1();	_return();	push_cat1(ret);
}
static void _return64() {
	u8 ret = popcat2();	_return();	push_cat2(ret);
}

// maffei
void exec_jvm_ireturn(){_return32();}
void exec_jvm_lreturn(){_return64();}
void exec_jvm_freturn(){_return32();}
void exec_jvm_dreturn(){_return64();}
void exec_jvm_areturn(){
	void * ref = pop_reference();	_return();push_reference(ref);
}
void exec_jvm_return(){_return();}

//
void exec_jvm_getstatic(){
  u2 index = offset16_from_instr();
  Frame_type * frame = &frame_stack.top();
  cp_info * cp = frame->inst->my_class_ptr->constant_pool;
  CONSTANT_Fieldref_info * symbolic_reference_to_field =
   (CONSTANT_Fieldref_info*)&cp[index];
  // The constant_pool entry at that index must be a
  // CONSTANT_Class_info (§4.4.1) structure representing a class or
  //  interface type
  u2 class_index = symbolic_reference_to_field->class_index;
  CONSTANT_Class_info * class_info = (CONSTANT_Class_info *)&cp[class_index];
  u2 name_index = class_info->name_index;
  // The constant_pool entry at that index must be a
  // CONSTANT_Utf8_info (§4.4.7) structure representing 
  // a valid binary class or interface name encoded in internal form (§4.2.1).
  CONSTANT_Utf8_info * utf8_info = (CONSTANT_Utf8_info *)&cp[name_index];

  // gambiarra pq essa porcaria tá mal descrita e bem ruim de entender
  jvm_push_reference((void*)NULL);
  incpc(1 + 2);
}

void exec_jvm_putstatic(){

	
}

int findfieldinclass(Instance * inst,char* metname){
	int index = 0;
	while(namescomp(*(CONSTANT_Utf8_info *)&(inst->my_class_ptr->constant_pool[inst->my_class_ptr->fields[index].name_index]),metname)==false && index<inst->my_class_ptr->fields_count-1){
		index++;
		DDprintf("debug find field didnt find at %d, will look at %d\n", index-1, index);
	}
	if (namescomp(*(CONSTANT_Utf8_info *)&(inst->my_class_ptr->constant_pool[inst->my_class_ptr->fields[index].name_index]),metname)==true){
		DDprintf("debug find field found at %d\n", index);
		return index;
	}
	
	Dprintf("debug find field didnt find anything\n");
	return 0;
}
void exec_jvm_getfield(){
	cp_info * cp = frame_stack.top().inst->my_class_ptr->constant_pool;
	u2 index = offset16_from_instr();
	// The run-time constant pool item at that index must be a symbolic
	// reference to a field (§5.1)
	CONSTANT_Fieldref_info * field_ref = 
		(CONSTANT_Fieldref_info *) &cp[index];

	u2 class_index = field_ref->class_index;
	
	CONSTANT_Utf8_info * utf8_info = 
		(CONSTANT_Utf8_info *) &cp[class_index];
	CONSTANT_NameAndType_info * name_and_type =
		(CONSTANT_NameAndType_info*)&cp[field_ref->name_and_type_index];

	
	CONSTANT_Utf8_info * field_descriptor = 
		(CONSTANT_Utf8_info *)&cp[name_and_type->descriptor_index];
	CONSTANT_Utf8_info * field_name = (CONSTANT_Utf8_info *)&cp[name_and_type->name_index];
	
	std::string string_field_descriptor((char*)field_descriptor->bytes, field_descriptor->length);
	char string_name_field[field_name->length+1];
	for(int i=0;i<field_name->length;i++){
		Dprintf("%d %c\n", i,field_name->bytes[i]);
		string_name_field[i]=field_name->bytes[i];
	}
	string_name_field[field_name->length]='\0';

	Dprintf("exec_jvm_putfield gonna loop FOREVER ! \n");
	if(string_field_descriptor[0] == 'I'){
		Instance * objectref = (Instance *)pop_reference();
		int32_t aux = ((int32_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat1(aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'B'){
		Instance * objectref = (Instance *)pop_reference();
		int8_t aux = ((int8_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat1((int32_t)aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'C'){
		Instance * objectref = (Instance *)pop_reference();
		u8 aux = ((u8*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat2(aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'D'){
		Instance * objectref = (Instance *)pop_reference();
		double aux = ((double*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat2(aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'F'){
		Instance * objectref = (Instance *)pop_reference();
		u4 aux = ((u4*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat1(aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'J'){
		Instance * objectref = (Instance *)pop_reference();
		int64_t aux = ((int64_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat2(aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'L'){
		Instance * objectref = (Instance *)pop_reference();
		void * aux = ((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)];
		push_reference(aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'S'){
		Instance * objectref = (Instance *)pop_reference();
		int16_t aux = ((int16_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0];
		pushcat1((int32_t)aux);
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == '['){
		Instance * objectref = (Instance *)pop_reference();
		void * aux = ((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)];
		push_reference(aux);
		incpc(3);
		return;
	}

}

void exec_jvm_putfield(){
	cp_info * cp = frame_stack.top().inst->my_class_ptr->constant_pool;
	u2 index = offset16_from_instr();
	// The run-time constant pool item at that index must be a symbolic
	// reference to a field (§5.1)
	CONSTANT_Fieldref_info * field_ref = 
		(CONSTANT_Fieldref_info *) &cp[index];

	u2 class_index = field_ref->class_index;
	
	CONSTANT_Utf8_info * utf8_info = 
		(CONSTANT_Utf8_info *) &cp[class_index];
	CONSTANT_NameAndType_info * name_and_type =
		(CONSTANT_NameAndType_info*)&cp[field_ref->name_and_type_index];

	
	CONSTANT_Utf8_info * field_descriptor = 
		(CONSTANT_Utf8_info *)&cp[name_and_type->descriptor_index];
	CONSTANT_Utf8_info * field_name = (CONSTANT_Utf8_info *)&cp[name_and_type->name_index];
	
	std::string string_field_descriptor((char*)field_descriptor->bytes, field_descriptor->length);
	char string_name_field[field_name->length+1];
	for(int i=0;i<field_name->length;i++){
		Dprintf("%d %c\n", i,field_name->bytes[i]);
		string_name_field[i]=field_name->bytes[i];
	}
	string_name_field[field_name->length]='\0';

	Dprintf("exec_jvm_putfield gonna loop FOREVER ! \n");
	if(string_field_descriptor[0] == 'I'){
		int32_t aux = popcat1();
		Instance * objectref = (Instance *)pop_reference();
		((int32_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'B'){
		int8_t aux = popcat1();
		Instance * objectref = (Instance *)pop_reference();
		((int8_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'C'){
		u8 aux = popcat2();
		Instance * objectref = (Instance *)pop_reference();
		((u8*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'D'){
		double aux = popcat2();
		Instance * objectref = (Instance *)pop_reference();
		((double*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'F'){
		u4 aux = popcat1();
		Instance * objectref = (Instance *)pop_reference();
		((u4*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'J'){
		int64_t aux = popcat2();
		Instance * objectref = (Instance *)pop_reference();
		((int64_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'L'){
		void * aux = pop_reference();
		Instance * objectref = (Instance *)pop_reference();
		((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == 'S'){
		int16_t aux = popcat1();
		Instance * objectref = (Instance *)pop_reference();
		((int16_t*)(((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]))[0]=aux;
		incpc(3);
		return;
	}
	if(string_field_descriptor[0] == '['){
		void * aux = pop_reference();
		Instance * objectref = (Instance *)pop_reference();
		((void **)(objectref->my_attributes))[findfieldinclass(objectref,string_name_field)]=aux;
		incpc(3);
		return;
	}
}
// arthur
cat1 * argument_prepare(char * descriptor){
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
	cat1 * args = (cat1 *)malloc(count*sizeof(cat1));
	for (int i=1;i<=count;i++){
		args[count-i]=pop_cat1raw();
	}
	return args;
}
// arthur
void exec_jvm_invokevirtual(){
	Dprintf("debug invokespecial\n");
	u1 indexbyte1 = instrparam(1);
	u1 indexbyte2 = instrparam(2);
	u2 index;
	((u1*)&index)[0]=indexbyte2;
	((u1*)&index)[1]=indexbyte1;

	CONSTANT_Methodref_info * methodcalled = 
		(CONSTANT_Methodref_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[index]);
	CONSTANT_NameAndType_info * methodnat = 
		(CONSTANT_NameAndType_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodcalled->name_and_type_index]);
	CONSTANT_Utf8_info * methodtype = 
		(CONSTANT_Utf8_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->descriptor_index]);
	char mettype[methodtype->length+1];

	memcpy( mettype, methodtype->bytes,  sizeof(char) * methodtype->length);
	// for(int i=0;i<methodtype->length;i++){
	// 	mettype[i]=methodtype->bytes[i];
	// }
	mettype[methodtype->length]='\0';

	cat1 * args_to_pass = argument_prepare(mettype);

	Instance * object_ref = (Instance *)pop_address();
	incpc(3);
	instance_frame_loader(index, object_ref, args_to_pass);

}
// arthur
void exec_jvm_invokespecial(){
	Dprintf("debug invokespecial\n");
	u1 indexbyte1 = instrparam(1);
	u1 indexbyte2 = instrparam(2);
	u2 index;
	((u1*)&index)[0]=indexbyte2;
	((u1*)&index)[1]=indexbyte1;

	CONSTANT_Methodref_info * methodcalled = (CONSTANT_Methodref_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[index]);
	CONSTANT_NameAndType_info * methodnat = (CONSTANT_NameAndType_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodcalled->name_and_type_index]);
	CONSTANT_Utf8_info * methodtype = (CONSTANT_Utf8_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->descriptor_index]);
	char mettype[methodtype->length+1];
	for(int i=0;i<methodtype->length;i++){
		mettype[i]=methodtype->bytes[i];
	}
	mettype[methodtype->length]='\0';

	cat1 * argstopass = argument_prepare(mettype);

	Instance * objectref = (Instance *)pop_address();
	incpc(3);
	instance_frame_loader(index, objectref, argstopass);
}
void exec_jvm_invokestatic(){
	Dprintf("debug invokestatic\n");
	u1 indexbyte1 = instrparam(1);
	u1 indexbyte2 = instrparam(2);
	u2 index;
	((u1*)&index)[0]=indexbyte2;
	((u1*)&index)[1]=indexbyte1;

	CONSTANT_Methodref_info * methodcalled = (CONSTANT_Methodref_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[index]);
	CONSTANT_NameAndType_info * methodnat = (CONSTANT_NameAndType_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodcalled->name_and_type_index]);
	CONSTANT_Utf8_info * methodtype = (CONSTANT_Utf8_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->descriptor_index]);
  	
  	CONSTANT_Class_info * classcalled = (CONSTANT_Class_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodcalled->class_index]);

  	CONSTANT_Utf8_info * classcalledname = (CONSTANT_Utf8_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[classcalled->name_index]);

	char classname[classcalledname->length+1];
	for(int i=0;i<classcalledname->length;i++){
		classname[i]=classcalledname->bytes[i];
	}
	classname[classcalledname->length]='\0';

  	ClassFile * cf;
    cf = ClassLoader::load_classfile(classname);
    Instance * inst = (Instance *)malloc(sizeof(Instance));
    inst->my_class_ptr = cf;
    inst->my_attributes = NULL;
	char mettype[methodtype->length+1];
	for(int i=0;i<methodtype->length;i++){
		mettype[i]=methodtype->bytes[i];
	}
	mettype[methodtype->length]='\0';

	cat1 * argstopass = argument_prepare(mettype);
	incpc(3);
	instance_frame_loader(index, inst, argstopass);
}
void exec_jvm_invokeinterface(){

}
void exec_jvm_invokedynamic(){

}