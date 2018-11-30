#include "instructions.cpp"

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
  jvm_push(0.0);
  incpc(1);
}
 
void exec_jvm_fconst_1(){
  jvm_push(1.0);
  incpc(1);
}
 
void exec_jvm_fconst_2(){
  jvm_push(2.0);
  incpc(1);
}
 
void exec_jvm_dconst_0(){
  jvm_push(0.0);
  incpc(1);
}
 
void exec_jvm_dconst_1(){
  jvm_push(1.0);
  incpc(1);
}
 
void exec_jvm_bipush(){
  jvm_push((int) char)
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
  Instance * current_instance = frame_stack.top().inst;
  ClassFile * my_class = current_instance->my_class_ptr;
  u1 index = instrparam(1);
  cp_info * cp_entry = &my_class->constant_pool[index];
  u1 tag = (CONSTANT_Class*)cp_entry->tag; // vale ressaltar que nao se sabe qual o tipo de fato, mas
  switch (tag):
    case enum_cp_tags::CONSTANT_Integer:
    case enum_cp_tags::CONSTANT_Float:
      jvm_push( (CONSTANT_Float_info*)cp_entry->bytes ); break;
    case enum_cp_tags::CONSTANT_String: {
      jvm_push( & (CONSTANT_String_info*)cp_entry->string_index); break;
    case enum_cp_tags::CONSTANT_Class:
      jvm_push( & );
      // resolver nome 
    



}
 
void exec_jvm_ldc_w(){
 
}
 
void exec_jvm_ldc2_w(){
 
}
 
void exec_jvm_iload(){
 
}