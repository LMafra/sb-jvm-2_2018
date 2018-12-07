#include "instructions.hpp"
#include "../VMGlobals.hpp"


// maffei & arthur
/// Push item from run-time constant pool.
static void ldc_X(u2 index) {
  cat1 auxie;
  Instance * current_instance = frame_stack.top().inst;
  ClassFile * my_class = current_instance->my_class_ptr;

  cp_info * cp_entry = &my_class->constant_pool[index];
  u1 tag = ((CONSTANT_Class_info*)cp_entry)->tag;
  switch (tag) {
    case enum_cp_tags::CONSTANT_Integer:
      push_cat1( ((CONSTANT_Integer_info*)cp_entry)->bytes ); break;
    case enum_cp_tags::CONSTANT_Float:
      push_cat1( ((CONSTANT_Float_info*)cp_entry)->bytes ); break;
    case enum_cp_tags::CONSTANT_String:
      auxie.ref_val = ((CONSTANT_Utf8_info*)
        &my_class->constant_pool[((CONSTANT_String_info*)cp_entry)->string_index ] 
      );
      jvm_stack.push(auxie); break;
    case enum_cp_tags::CONSTANT_Class:
      
    default:
      throw "ERROR! where: exec_jvm_ldc";
  }
}

void exec_jvm_ldc(){
  u1 index = instrparam(1);
  ldc_X(index);
  incpc(1+1);
}

void exec_jvm_ldc_w(){
  u2 index = instrparam(1);
  index = index << 8 | instrparam(2);
  ldc_X(index);
  incpc(1+2);
}

void exec_jvm_ldc2_w(){
  cp_info * cp = (cp_info *)frame_stack.top().inst->my_class_ptr->constant_pool;
  u2 index = offset16_from_instr();
  Dprintf("debug ldc2_w index %d\n", index);
  CONSTANT_Double_info * double_info = (CONSTANT_Double_info *)&cp[index];
  push_cat1(double_info->high_bytes);  push_cat1(double_info->low_bytes);
  incpc(3);
}


// maffei
/// Empilha em jvm_stack a variável na N-ehsima posicao do vetor de variaveis locais.
/// É chamada pelas instruções iload_<n> da jvm.
inline static void iload_X(u1 N) {
  push_cat1( frame_stack.top().variaveis_locais[N] );
}
void exec_jvm_iload() {
  u1 index = instrparam(1);
  iload_X(index);
  incpc(1 + 1);
}
void exec_jvm_iload_0() {iload_X((u1)0);incpc(1);}
void exec_jvm_iload_1() {iload_X((u1)1);incpc(1);}
void exec_jvm_iload_2() {iload_X((u1)2);incpc(1);}
void exec_jvm_iload_3() {iload_X((u1)3);incpc(1);}

// maffei
/// empilha um long do vetor de variaveis locais
inline static void exec_jvm_lload_X(u1 N) {iload_X(N); iload_X(N+1);}

void exec_jvm_lload() {u1 index = instrparam(1);lload_X(index);incpc(1 + 1);}
void exec_jvm_lload_0(){exec_jvm_lload_X((u1)0);incpc(1);}
void exec_jvm_lload_1(){exec_jvm_lload_X((u1)1);incpc(1);}
void exec_jvm_lload_2(){exec_jvm_lload_X((u1)2);incpc(1);}
void exec_jvm_lload_3(){exec_jvm_lload_X((u1)3);incpc(1);}

// maffei
/// empilha um float do vetor de variaveis locais
inline static void exec_jvm_fload_X(u1 N) {iload_X(N);}
void exec_jvm_fload() {
  exec_jvm_iload();
}
void exec_jvm_fload_0() {exec_jvm_fload_X(0);incpc(1);}
void exec_jvm_fload_1() {exec_jvm_fload_X(1);incpc(1);}
void exec_jvm_fload_2() {exec_jvm_fload_X(2);incpc(1);}
void exec_jvm_fload_3() {exec_jvm_fload_X(3);incpc(1);}

// maffei
/// empilha um double do vetor de variaveis locais
void exec_jvm_dload_X(u1 N){
  double auxdb;
  ((u4*)&auxdb)[1]=frame_stack.top().variaveis_locais[N].val;
  ((u4*)&auxdb)[0]=frame_stack.top().variaveis_locais[N+1].val;
  Dprintf("%lf\n", auxdb);
  iload_X(N);
  iload_X(N+1);
}
void exec_jvm_dload(){
  u1 index = instrparam(1);
  exec_jvm_dload_X(index);
  incpc(1 + 1);
}
void exec_jvm_dload_0(){exec_jvm_dload_X(0);incpc(1);}
void exec_jvm_dload_1(){exec_jvm_dload_X(1);incpc(1);}
void exec_jvm_dload_2(){exec_jvm_dload_X(2);incpc(1);}
void exec_jvm_dload_3(){exec_jvm_dload_X(3);incpc(1);}
