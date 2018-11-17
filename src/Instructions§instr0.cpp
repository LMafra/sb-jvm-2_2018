#include "Instructions§instructions.hpp"

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
 
void exec_jvm_ldc(){
 
}
 
void exec_jvm_ldc_w(){
 
}
 
void exec_jvm_ldc2_w(){
 
}
 
void exec_jvm_iload(){
 
}