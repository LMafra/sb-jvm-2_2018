#include "frameloader.hpp"
#include "VMGlobals.hpp"
#include "Instructions/exec_vet.hpp"


//returns when out of bounds or return instruction sends to null
void instructions_Loop(){
	printf("debug instrloop1\n");
	while(PC!=NULL && ((long long int)(frame_stack.top().PC_final))>((long long int)(&PC[0]))){
		u1 aux = PC[0];
		printf("debug instropcode %d\n", aux);
		(*(exec_vet[aux]))();
	}
}

void interpret(ClassFile * firstclass){
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
	printf("debug int3\n");
	{
		char metname[7] = "<init>";
		printf("debug int4\n");
		int index = 0;
		while(namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false && index<executed_object->my_class_ptr->methods_count-1){
			index++;
		}
		printf("debug int5\n");
		if (namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false){
			return;
		}
		printf("debug int6\n");
		instance_frame_loader_interpreter(executed_object->my_class_ptr->methods[index].name_index, executed_object->my_class_ptr->methods[index].descriptor_index, executed_object->my_class_ptr->this_class,executed_object,NULL);
		printf("debug int7\n");
		instructions_Loop();
		printf("debug int8\n");
	}
	printf("debug int1\n");
	{
		char metname[5] = "main";
		int index = 0;
		while(namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false && index<executed_object->my_class_ptr->methods_count-1){
			index++;
		}
		if (namescomp(*(CONSTANT_Utf8_info *)&executed_object->my_class_ptr->constant_pool[executed_object->my_class_ptr->methods[index].name_index],metname)==false){
			return;
		}
		instance_frame_loader(index,executed_object,NULL);
		instructions_Loop();
	}
	printf("debug int2\n");
}