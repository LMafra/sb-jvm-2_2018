#include "frameloader.hpp"
#include "VMGlobals.hpp"
#include "Instructions/exec_vet.hpp"


//returns when out of bounds or return instruction sends to null
void instructions_Loop(){
	#if DEBUG
	printf("debug instrloop1\n");
	#endif
	while(PC!=NULL && ((long long int)(frame_stack.top().PC_final))>((long long int)(&PC[0]))){
		u1 aux = PC[0];
		#if DEBUG
		printf("%lli\n", (long long int)PC);
		#endif
		#if DEBUG
		printf("debug instropcode %d\n", aux);
		#endif
		(*(exec_vet[aux]))();
	}
	#ifdef DEBUG
	if (PC==NULL){
		printf("debug instr int nullpc\n");
	}
	if (((long long int)(frame_stack.top().PC_final))>=((long long int)(&PC[0]))){
		printf("debug instr int overflow\n");
	}
	printf("debug endinstr\n");
	#endif
}

void interpret(ClassFile * firstclass){
	set_exec_vet();
	PC=NULL;
	Frame_type firstframe;
	Instance * firstinstance = (Instance*)calloc(1,sizeof(Instance));
	firstinstance->my_class_ptr=firstclass;
	firstinstance->my_attributes=NULL;
	firstframe.inst=firstinstance;
  firstframe.initial_stack_size=jvm_stack.size();
	firstframe.PC_retorno=NULL;
	firstframe.PC_base=NULL;
	firstframe.variaveis_locais=NULL;
	firstframe.PC_final=NULL;
	frame_stack.push(firstframe);
	#if DEBUG
	printf("debug int3\n");
	#endif
	#ifdef DEBUG
	printf("debug int1\n");
	#endif
	{
		char metname[5] = "main";
		cat1 * params =  (cat1*)malloc(sizeof(cat1));
		params[0].ref_val=metname;
		int index = 0;
		while(namescomp(*(CONSTANT_Utf8_info *)&(firstinstance)->my_class_ptr->constant_pool[(firstinstance)->my_class_ptr->methods[index].name_index],metname)==false
				&& index<(firstinstance)->my_class_ptr->methods_count-1){
			index++;
		}
		if (namescomp(*(CONSTANT_Utf8_info *)&(firstinstance)->my_class_ptr->constant_pool
												[(firstinstance)->my_class_ptr->methods[index].name_index],metname)==false){
			return;
		}
		_();
		_();
		instance_frame_loader_interpreter((firstinstance)->my_class_ptr->methods[index].name_index, 
																			(firstinstance)->my_class_ptr->methods[index].descriptor_index,
																			(firstinstance)->my_class_ptr->this_class,
																			(firstinstance),
																			params);
		instructions_Loop();
		// free(params);
	}
	Dprintf("debug int2\n");
	
}