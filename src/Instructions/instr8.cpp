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