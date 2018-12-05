#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include "instructions.hpp"

void exec_jvm_new() { 
  u2 index = (u2)offset16_from_stack();
  void * ref = (void*)Instance::instance_allocator(index);
  push_reference(ref);
  incpc(1);
}
void exec_jvm_newarray() { 
  u1 count = popcat1();
  u1 atype = instrparam(1);
  void * new_array = new Array_instance(count, atype_size_dict[atype]);
  jvm_push_reference(new_array);
  incpc(1+1);
}
void exec_jvm_anewarray() { 
  u1 count = pop_cat1();
  u2 index = offset16_from_instr();
  void * new_array = new Array_ref_instance(count);
  cp_info * symbolic_reference = &frame_stack.top().inst->my_class_ptr->constant_pool[index];
  // for(int i = 0; i < count; i++) new_array->data[i] = calloc(1, tamanho_da_classe);
  // resolver : alocar espaço, em cada elemento de new_array->data, para a classe
  jvm_push_reference(new_array);
  incpc(1+2);
}
void exec_jvm_arraylength() { 
  Array_instance * array_ref = (Array_instance *)pop_reference();
  push_cat1( array_ref->size );
  incpc(1+1);
}

void exec_jvm_athrow() { 
  void * ref = pop_reference();
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
  int index = offset16_from_instr();
  jvm_push_reference( &PC[3] );
  increment_pc( index );

}
void exec_jvm_breakpoint() { 

}
void exec_jvm_impdep1() { 

}
void exec_jvm_impdep2() { 

}
