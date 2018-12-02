#include "instructions.hpp"
#include "../VMGlobals.hpp"
#pragma once
static void aload_X(u1 index) {
  cat1 cat; cat.ref_val = frame_stack.top().variaveis_locais[index].ref_val;
  jvm_stack.push( cat );
}

void exec_jvm_aload(){
  u1 index = instrparam(1);
  aload_X(index); incpc(1);
  incpc(1);
}
void exec_jvm_aload_0() {DDprintf("debug aload0\n"); aload_X((u1)0);incpc(1);}
void exec_jvm_aload_1() {aload_X((u1)1);incpc(1);}
void exec_jvm_aload_2() {aload_X((u1)2);incpc(1);}
void exec_jvm_aload_3() {aload_X((u1)3);incpc(1);}

static void load_addr(cat1 * locais = frame_stack.top().variaveis_locais) {
  u1 index = pop_cat1(); cat1 * ref = (cat1 *)pop_reference(); 
  push_reference( locais[index].ref_val );
}
static void load_32(cat1 * locais = frame_stack.top().variaveis_locais) {
  u1 index = pop_cat1(); cat1 * ref = (cat1 *)pop_reference(); 
  if (!ref) {
    throw "NullPointerException";
  }
  int32_t result = locais[index].val;
  push_cat1( result );
}
static void load_16(cat1 * locais = frame_stack.top().variaveis_locais) {
  load_32();
}
static void load_8(cat1 * locais = frame_stack.top().variaveis_locais) {
  load_32();
}
static void load_64(cat1 * locais = frame_stack.top().variaveis_locais) {
  u1 index = pop_cat1(); cat1 * ref = (cat1 *)pop_reference(); 
  u8 value = locais[index].val;
  value = value << 32 | locais[index+1].val; 
  push_cat1( value );
}

void exec_jvm_iaload() {load_32();incpc(1);}
void exec_jvm_faload() {exec_jvm_iaload();}
void exec_jvm_daload() {load_64();incpc(1);}
void exec_jvm_aaload() {load_addr();incpc(1);}
void exec_jvm_baload() {exec_jvm_iaload();}
void exec_jvm_caload() {exec_jvm_baload();}
void exec_jvm_saload() {exec_jvm_iaload();}