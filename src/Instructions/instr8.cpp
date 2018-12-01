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

}

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
}
void exec_jvm_putstatic(){

}
void exec_jvm_getfield(){

}
void exec_jvm_putfield(){

}
void exec_jvm_invokevirtual(){

}
void exec_jvm_invokespecial(){

}
void exec_jvm_invokestatic(){

}
void exec_jvm_invokeinterface(){

}
void exec_jvm_invokedynamic(){

}