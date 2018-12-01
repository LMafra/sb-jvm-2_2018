#include "../UsingUs.hpp"
#include "../VMGlobals.hpp"

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
void exec_jvm_ireturn(){

}
void exec_jvm_lreturn(){

}
void exec_jvm_freturn(){

}
void exec_jvm_dreturn(){

}
void exec_jvm_areturn(){

}
void exec_jvm_return(){
	PC = frame_stack.top().PC_retorno;
	if(PC==NULL){
		printf("debug null pointer return\n");
	}
	frame_stack.pop();
}
void exec_jvm_getstatic(){

}
void exec_jvm_putstatic(){

}
void exec_jvm_getfield(){

}
void exec_jvm_putfield(){

}
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
void exec_jvm_invokevirtual(){
	printf("debug invokespecial\n");
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
void exec_jvm_invokespecial(){
	printf("debug invokespecial\n");
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