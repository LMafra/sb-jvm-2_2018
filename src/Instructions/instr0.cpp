#include "instructions.hpp"
#include "exec_instr.hpp"
#include "../UsingUs.hpp"
#include "../VMGlobals.hpp"
#include <string.h>

// Gabiel Bessa
void exec_jvm_nop(){
}

// Gabiel Bessa [fixed maffei] [detected arthur]
void exec_jvm_aconst_null(){
  void * p = NULL;
  jvm_push_reference(p);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_m1(){
  jvm_push(-1);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_0(){
  jvm_push(0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_1(){
  jvm_push(1);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_2(){
  jvm_push(2);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_3(){
  jvm_push(3);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_4(){
  jvm_push(4);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_5(){
  jvm_push(5);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_lconst_0(){
  jvm_push((long)0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_lconst_1(){
  jvm_push((long)1);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_fconst_0(){
  jvm_push((float)0.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_fconst_1(){
  jvm_push((float)1.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_fconst_2(){
  jvm_push((float)2.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_dconst_0(){
  jvm_push((double)0.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_dconst_1(){
  jvm_push((double)1.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_bipush(){
  u1 par = instrparam(1);
  jvm_push((int) par);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_sipush(){
  unsigned int b1 = 0, b2 = 0;
  short intermediate;
  intermediate = short (b1 << 8) | b2;
  jvm_push(intermediate);
  incpc(1);
}
