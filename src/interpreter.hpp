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
	Instance firstinstance;
	firstinstance.my_class_ptr=firstclass;
	firstframe.inst=&firstinstance;
	frame_stack.push(firstframe);
	Instance * executed_object = Instance::instance_allocator(firstclass->this_class);
	frame_stack.pop();
	firstframe.inst=executed_object;
	frame_stack.push(firstframe);
	#if DEBUG
	printf("debug int3\n");
	#endif
	{
		char metname[7] = "<init>";
		Dprintf("debug int4\n");
		int index = 0;
		while(namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false && index<executed_object->my_class_ptr->methods_count-1){
			index++;
		}
		Dprintf("debug int5\n");
		if (namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false){
			return;
		}
		Dprintf("debug int6\n");
		instance_frame_loader_interpreter(executed_object->my_class_ptr->methods[index].name_index, executed_object->my_class_ptr->methods[index].descriptor_index, executed_object->my_class_ptr->this_class,executed_object,NULL);
		Dprintf("debug int7\n");
		instructions_Loop();
		Dprintf("debug int8\n");
	}
	#ifdef DEBUG
	printf("debug int1\n");
	#endif
	{
		char metname[5] = "main";
		cat1 * params =  (cat1*)malloc(sizeof(cat1));
		params[0].ref_val=metname;
		int index = 0;
		while(namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false && index<executed_object->my_class_ptr->methods_count-1){
			index++;
		}
		if (namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false){
			return;
		}
		instance_frame_loader_interpreter(executed_object->my_class_ptr->methods[index].name_index, executed_object->my_class_ptr->methods[index].descriptor_index, executed_object->my_class_ptr->this_class,executed_object,params);
		instructions_Loop();
	}
	
	Dprintf("debug int2\n");
	
}