#include "instructions.hpp"
#include "../VMGlobals.hpp"

void exec_jvm_aload(u1) {
  u4 index = instrparam(1);
  cat1 cat; cat.val = frame_stack.top().variaveis_locais[index].val;
  jvm_stack.push( cat );
}
void exec_jvm_aload_0() {}
void exec_jvm_aload_1() {}
void exec_jvm_aload_2() {}
void exec_jvm_aload_3() {}

void exec_jvm_iaload() {}
void exec_jvm_faload() {}
void exec_jvm_daload() {}
void exec_jvm_aaload() {}
void exec_jvm_baload() {}
void exec_jvm_caload() {}
void exec_jvm_saload() {}