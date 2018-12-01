#include "instructions.hpp"
#include "exec_instr.hpp"
#include "src/UsingUs.hpp"
#include "src/VMGlobals.hpp"
#include <string.h>

void exec_jvm_nop(){
}
 
void exec_jvm_aconst_null(){
  jvm_push(NULL);
  incpc(1);
}
 
void exec_jvm_iconst_m1(){
  jvm_push(-1);
  incpc(1);
}
 
void exec_jvm_iconst_0(){
  jvm_push(0);
  incpc(1);
}
 
void exec_jvm_iconst_1(){
  jvm_push(1);
  incpc(1);
}
 
void exec_jvm_iconst_2(){
  jvm_push(2);
  incpc(1);
}
 
void exec_jvm_iconst_3(){
  jvm_push(3);
  incpc(1);
}
 
void exec_jvm_iconst_4(){
  jvm_push(4);
  incpc(1);
}
 
void exec_jvm_iconst_5(){
  jvm_push(5);
  incpc(1);
}
 
void exec_jvm_lconst_0(){
  jvm_push(0);
  incpc(1);
}
 
void exec_jvm_lconst_1(){
  jvm_push(1);
  incpc(1);
}
 
void exec_jvm_fconst_0(){
  jvm_push((float)0.0);
  incpc(1);
}
 
void exec_jvm_fconst_1(){
  jvm_push((float)1.0);
  incpc(1);
}
 
void exec_jvm_fconst_2(){
  jvm_push((float)2.0);
  incpc(1);
}
 
void exec_jvm_dconst_0(){
  jvm_push((double)0.0);
  incpc(1);
}
 
void exec_jvm_dconst_1(){
  jvm_push((double)1.0);
  incpc(1);
}
 
void exec_jvm_bipush(){
  u1 par = instrparam(1);
  jvm_push((int) par);
  incpc(1);
}
 
void exec_jvm_sipush(){
  unsigned int b1 = 0, b2 = 0;
  short intermediate;
  intermediate = short (b1 << 8) | b2;
  jvm_push(intermediate)
  incpc(1);
}

/// Push item from run-time constant pool.
// maffei
void exec_jvm_ldc(){
  cat1 auxie;
  Instance * current_instance = frame_stack.top().inst;
  ClassFile * my_class = current_instance->my_class_ptr;
  u1 index = instrparam(1);
  cp_info * cp_entry = &my_class->constant_pool[index];
  u1 tag = ((CONSTANT_Class_info*)cp_entry)->tag;
  switch (tag) {
    case enum_cp_tags::CONSTANT_Integer:
      jvm_push( ((CONSTANT_Integer_info*)cp_entry)->bytes ); break;
    case enum_cp_tags::CONSTANT_Float:
      jvm_push( ((CONSTANT_Float_info*)cp_entry)->bytes ); break;
    case enum_cp_tags::CONSTANT_String:
      auxie.ref_val = (my_class->constant_pool[(CONSTANT_String_info*)cp_entry->string_index].bytes);
      jvm_stack.push(auxie); break;
    default:
      throw "ERROR! where: exec_jvm_ldc";
  }
}
 
void exec_jvm_ldc_w(){
 
}
 
void exec_jvm_ldc2_w(){
 
}
 
void exec_jvm_iload(){
 
}