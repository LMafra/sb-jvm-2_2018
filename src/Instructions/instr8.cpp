#include "../UsingUs.hpp"
#include "../VMGlobals.hpp"
#include "../frameloader.hpp"

void exec_jvm_goto(){
  incpc( offset16_from_instr() );
}
// maffei
void exec_jvm_jsr(){
  u2 index = offset16_from_instr();
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
  int index = pop_cat1();
  u1 * instr_pc = PC;
  u1 diff_pc = PC - frame_stack.top().PC_base;
  u1 padding = diff_pc % 4; incpc(padding);
  int default_val = offset32_from_instr();incpc(4);
  int low_val = offset32_from_instr();  incpc(4);
  int high_val = offset32_from_instr();  incpc(4);
  if ( index < low_val or index > high_val)
    PC = instr_pc + default_val;
  else
    PC = instr_pc + PC[index - low_val];
}
void exec_jvm_lookupswitch(){

}

static void _return() {
	Frame_type * frame = &frame_stack.top();	// Variavel auxiliar
	PC = frame->PC_retorno;	// restaura pc para funcao que o chamou
	size_t remove_qtd = jvm_stack.size() - frame->initial_stack_size;	
	printf("Se deu segfault logo apohs essa linha, faltou inicializar o valor initial_stac_size do frame corrente :/\n");
	printf("Esta mensagem se encontra no arquivo instr8.cpp\n");
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
void exec_jvm_getfield(){

}
void exec_jvm_putfield(){

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

	CONSTANT_Methodref_info * methodcalled = (CONSTANT_Methodref_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[index]);
	CONSTANT_NameAndType_info * methodnat = (CONSTANT_NameAndType_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodcalled->name_and_type_index]);
	CONSTANT_Utf8_info * methodtype = (CONSTANT_Utf8_info *)&(frame_stack.top().inst->my_class_ptr->constant_pool[methodnat->descriptor_index]);
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
}
void exec_jvm_invokeinterface(){

}
void exec_jvm_invokedynamic(){

}