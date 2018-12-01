#include "instructions.hpp"
#include "exec_instr.hpp"
#include "../UsingUs.hpp"
#include "../VMGlobals.hpp"
#include <string.h>

void exec_jvm_istore(){}
void exec_jvm_istore_0(){}
void exec_jvm_istore_1(){}
void exec_jvm_istore_2(){}
void exec_jvm_istore_3(){}


void exec_jvm_lstore(){}
void exec_jvm_lstore_0(){}
void exec_jvm_lstore_1(){}
void exec_jvm_lstore_2(){}
void exec_jvm_lstore_3(){}


void exec_jvm_fstore(){}
void exec_jvm_fstore_0(){}
void exec_jvm_fstore_1(){}
void exec_jvm_fstore_2(){}
void exec_jvm_fstore_3(){}

static void dstore(int index) {
  cp_info * cp = frame_stack.top().inst->my_class_ptr->constant_pool;
  CONSTANT_Double_info * doublee = (CONSTANT_Double_info *)&cp[index];
  u8 res = doublee->high_bytes;
  res = res << 32 | doublee->low_bytes;
  push_cat2(res);
}
void exec_jvm_dstore(){
  u1 index = instrparam(1);
  dstore(index);
  incpc(1 + 1);
}
void exec_jvm_dstore_0(){dstore(0);incpc(1);}
void exec_jvm_dstore_1(){dstore(1);incpc(1);}
void exec_jvm_dstore_2(){dstore(2);incpc(1);}
void exec_jvm_dstore_3(){dstore(3);incpc(1);}



void exec_jvm_astore(){}
void exec_jvm_astore_0(){}
void exec_jvm_astore_1(){}
void exec_jvm_astore_2(){}
void exec_jvm_astore_3(){}


void exec_jvm_iastore(){}
void exec_jvm_lastore(){}
void exec_jvm_fastore(){}
void exec_jvm_dastore(){}


