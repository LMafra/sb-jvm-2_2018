#include "instructions.hpp"
#include "../VMGlobals.hpp"
#pragma once
static void exec_jvm_aload_X(u1 index) {
  cat1 cat; cat.ref_val = frame_stack.top().variaveis_locais[index].ref_val;
  jvm_stack.push( cat );
}

void exec_jvm_aload(){
  u1 index = instrparam(1);
  exec_jvm_aload_X(index); incpc(1);
  incpc(1);
}
void exec_jvm_aload_0() {printf("debug aload0\n"); exec_jvm_aload_X((u1)0);incpc(1);}
void exec_jvm_aload_1() {exec_jvm_aload_X((u1)1);incpc(1);}
void exec_jvm_aload_2() {exec_jvm_aload_X((u1)2);incpc(1);}
void exec_jvm_aload_3() {exec_jvm_aload_X((u1)3);incpc(1);}

void exec_jvm_iaload() {}
void exec_jvm_faload() {}
void exec_jvm_daload() {}
void exec_jvm_aaload() {}
void exec_jvm_baload() {}
void exec_jvm_caload() {}
void exec_jvm_saload() {}