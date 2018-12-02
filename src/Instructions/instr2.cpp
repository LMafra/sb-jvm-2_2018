#include "instructions.hpp"
#include "../VMGlobals.hpp"
#pragma once
// maffei
static void aload_X(u1 index) {
  cat1 cat; cat.ref_val = frame_stack.top().variaveis_locais[index].ref_val;
  jvm_stack.push( cat );
}
// maffei
void exec_jvm_aload(){
  u1 index = instrparam(1);
  aload_X(index); incpc(1);
  incpc(1);
}
// maffei
void exec_jvm_aload_0() {DDprintf("debug aload0\n"); aload_X((u1)0);incpc(1);}
void exec_jvm_aload_1() {aload_X((u1)1);incpc(1);}
void exec_jvm_aload_2() {aload_X((u1)2);incpc(1);}
void exec_jvm_aload_3() {aload_X((u1)3);incpc(1);}

// maffei
void exec_jvm_iaload() {load_32();incpc(1);}
void exec_jvm_faload() {exec_jvm_iaload();}
void exec_jvm_daload() {load_64();incpc(1);}
void exec_jvm_aaload() {load_addr();incpc(1);}
void exec_jvm_baload() {exec_jvm_iaload();}
void exec_jvm_caload() {exec_jvm_iaload();}
void exec_jvm_saload() {exec_jvm_iaload();}