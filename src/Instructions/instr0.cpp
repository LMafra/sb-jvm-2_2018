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
  push_cat1(-1);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_0(){
  push_cat1(0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_1(){
  push_cat1(1);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_2(){
  push_cat1(2);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_3(){
  push_cat1(3);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_4(){
  push_cat1(4);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_iconst_5(){
  push_cat1(5);
  incpc(1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_lconst_0(){
  push_cat2((long)0);
  incpc(1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_lconst_1(){
  jvm_push_u8((long)1);
  incpc(1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_fconst_0(){
  push_cat2((float)0.0);
  incpc(1);
}

// Gabiel Bessa 
void exec_jvm_fconst_1(){
  push_cat1((float)1.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_fconst_2(){
  push_cat1((float)2.0);
  incpc(1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_dconst_0(){
  push_cat2((double)0.0);
  incpc(1);
}

// Gabiel Bessa
void exec_jvm_dconst_1(){
  push_cat1((double)1.0);
  incpc(1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_bipush(){
  u1 par = instrparam(1);
  int32_t par_extended =(int16_t)par ;
  push_cat1(par_extended);
  incpc(1 + 1);
}

// Gabiel Bessa [fixed maffei]
void exec_jvm_sipush(){
  u1 b1 = instrparam(1), b2 = instrparam(2);
  u2 aux = b1;
  aux = aux << 8 | b2;
  int32_t result = (int16_t)aux;
  push_cat1(result);
  incpc(1 + 2);
}
