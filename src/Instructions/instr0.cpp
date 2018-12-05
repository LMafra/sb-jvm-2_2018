#include "instructions.hpp"
#include "exec_instr.hpp"
#include "../UsingUs.h"
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

// Gabiel Bessa [fixed maffei]
void exec_jvm_dconst_0(){
  double zero = 0.0;
  push_cat2(zero);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_dconst_1(){
  jvm_push((double)1.0);
  incpc(1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_bipush(){
  u1 par = instrparam(1);
  int32_t intt = (int16_t)par;
  jvm_push(intt);
  incpc(1 + 1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_sipush(){
  u1 b1 = instrparam(1), b2 = instrparam(2);
  u2 intermediate = b1;
  intermediate = intermediate << 8 | b2;
  int32_t result = (int16_t)intermediate;
  jvm_push(result);
  incpc(1 + 2);
}
