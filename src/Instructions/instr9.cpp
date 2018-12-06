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
  DDprintf("at exec_jvm_newarray\n");
  push_reference(new_array);
  incpc(1+1);
}
void exec_jvm_anewarray() { 
  u1 count = pop_cat1();
  u2 index = offset16_from_instr();
  void * new_array = new Array_ref_instance(count);
  cp_info * symbolic_reference = &frame_stack.top().inst->my_class_ptr->constant_pool[index];
  // for(int i = 0; i < count; i++) new_array->data[i] = calloc(1, tamanho_da_classe);
  // resolver : alocar espaço, em cada elemento de new_array->data, para a classe
  DDprintf("at exec_jvm_anewarray\n");
  push_reference(new_array);
  incpc(1+2);
}
void exec_jvm_arraylength() { 
  Array_instance * array_ref = (Array_instance *)pop_reference();
  push_cat1( array_ref->size );
  incpc(1+1);
}
static std::string resolve_class_name(cp_info*cp, int index) {
  if (index == 0) return std::string("object");
  // The unsigned indexbyte1 and indexbyte2 are 
  // used to construct an index into the run-time constant pool of the
  // current class
  if(index < 0) throw "NEGATIVE INDEX PASSED TO resolve_class_name"; //offset16_from_instr();  // nunca deve entrar aqui

  CONSTANT_Class_info * class_info = 
    (CONSTANT_Class_info *) &cp[index];
  u2 name_index = class_info->name_index;
  CONSTANT_Utf8_info * utf8_info = 
    (CONSTANT_Utf8_info *)&cp[name_index];
  // obs: se sizeof(char) != sizeof(u1), lascou xD
  return std::string((char*)utf8_info->bytes, utf8_info->length);
}

static bool is_instance_of_class(std::string S, std::string T) {
  bool res = false;
  // If S is an ORDINARY (NONARRAY) class, then:
  //   ◆ If T is a class type, then S must be the same class as T , or S
  //   must be a subclass of T ;
  //   ◆ If T is an interface type, then S must implement interface T .
  if(S[0] != '[') {
    // If T is a class type, then S must be the same class as T , or S must be a subclass of T ;
    
  }
  return res;
}

void exec_jvm_athrow() { 
  void * ref = pop_reference();
}
void exec_jvm_checkcast() { 
}
void exec_jvm_instanceof() { 
  Instance * objectref = (Instance *)pop_reference();
  ClassFile * current_class  = frame_stack.top().inst->my_class_ptr;

  u2 index = offset16_from_instr();
  // ... The run-time constant pool at the index Must be a symbolic reference to a class, array, or interface type.
  
  // if objectref is null , the instanceof instruction pushes an int result
  // of 0 as an int on the operand stack.
  if  (objectref == NULL)
    push_cat1((int)0); 
  else {    
    // Otherwise, the named class, array, or interface type is resolved
    std::string curr_class_name = 
      resolve_class_name(current_class->constant_pool, index);

    std::string resolved = resolve_class_name(objectref->my_class_ptr->constant_pool, objectref->my_class_ptr->this_class);
    if( resolved[0] == '['  //  entao object eh do tipo reference
        || false
        // || is_instance_of_class() //instancia da classe corrente
        )
        push_cat1((int)1);
  }    
  incpc(1+2);
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
  DDprintf("at exec_jvm_jsr_w\n");
  push_reference( &PC[3] );
  increment_pc( index );

}
void exec_jvm_breakpoint() { 

}
void exec_jvm_impdep1() { 

}
void exec_jvm_impdep2() { 

}
