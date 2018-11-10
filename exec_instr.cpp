#include "exec_instr.hpp"
#include "exec_vet.hpp"
#include "./src/UsingUs.cpp"
#include "./src/ClassFileStructures/method_info.hpp"
#include <iostream>

// pushcat1 e pushcat2 sao pseudofuncoes que serao implementadas
// pushcat1: boolean, byte, char, short, int, float, reference, return_address
// pushcat2: long, double

void exec_jvm_nop(){ 
}

void exec_jvm_aconst_null(){
  jvm_push(NULL);
  incpc(1);
}

void exec_jvm_iconst_m1(){
  pushcat1(-1);
  incpc(1);
}

void exec_jvm_iconst_0(){
  pushcat1(0);
  incpc(1);
}

void exec_jvm_iconst_1(){
  pushcat1(1);
  incpc(1);
}

void exec_jvm_iconst_2(){
  pushcat1(2);
  incpc(1);
}

void exec_jvm_iconst_3(){
  pushcat1(3);
  incpc(1);
}

void exec_jvm_iconst_4(){
  pushcat1(4);
  incpc(1);
}

void exec_jvm_iconst_5(){
  pushcat1(5);
  incpc(1);
}

void exec_jvm_lconst_0(){
  pushcat2(0);
  incpc(1);
}

void exec_jvm_lconst_1(){
  pushcat2(1);
  incpc(1);
}

void exec_jvm_fconst_0(){
  pushcat1(0.0);
  incpc(1);
}

void exec_jvm_fconst_1(){
  pushcat1(1.0);
  incpc(1);
}

void exec_jvm_fconst_2(){
  pushcat1(2.0);
  incpc(1);
}

void exec_jvm_dconst_0(){
  pushcat2(0.0);
  incpc(1);
}

void exec_jvm_dconst_1(){
  pushcat2(1.0);
  incpc(1);
}

void exec_jvm_bipush(){
  pushcat1((int) char)
  incpc(1);
}

void exec_jvm_sipush(){
  unsigned int b1 = 0, b2 = 0;
  short intermediate;
  intermediate = short (b1 << 8) | b2;
  pushcat1(intermediate)
  incpc(1);
}

// 75 Primeiras instruções - Rofl
//-----------------------------------------------------------------------------------------------------------------------------//