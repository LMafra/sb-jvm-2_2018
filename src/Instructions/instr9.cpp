#include "../UsingUs.hpp"
#include "../VMGlobals.hpp"

void exec_jvm_new() { 

}
void exec_jvm_newarray() { 

}
void exec_jvm_anewarray() { 

}
void exec_jvm_arraylength() { 

}
void exec_jvm_athrow() { 

}
void exec_jvm_checkcast() { 

}
void exec_jvm_instanceof() { 

}
void exec_jvm_monitorenter() { 

}
void exec_jvm_monitorexit() { 

}
void exec_jvm_wide() { 

}
void exec_jvm_multianewarray() { 

}

/// Branch if reference is null
void exec_jvm_ifnull() { 
  void * ref = pop_address();
  if (!ref) incpc( offset16_from_stack() );
  else      incpc(3);  // opcode, branchbyte1, branchbyte2
}
/// Branch if reference is not null
void exec_jvm_ifnonnull() {
  void * ref = pop_address();
  if (!ref) incpc(3);  // opcode, branchbyte1, branchbyte2
  else      incpc( offset16_from_stack() );

}

// maffei
void exec_jvm_goto_w() { 
  incpc( offset32_from_instr() );
}
void exec_jvm_jsr_w() { 

}
void exec_jvm_breakpoint() { 

}
void exec_jvm_impdep1() { 

}
void exec_jvm_impdep2() { 

}
