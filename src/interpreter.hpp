#include "frameloader.hpp"
#include "VMGlobals.hpp"
#include "Instructions/exec_vet.hpp"


//returns when out of bounds or return instruction sends to null
void instructions_Loop(){
	while(PC!=NULL && ((long long int)(frame_stack.top().PC_final))>((long long int)(&PC[0]))){
		u1 aux = PC[0];
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
	{
		char metname[7] = "<init>";
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
}