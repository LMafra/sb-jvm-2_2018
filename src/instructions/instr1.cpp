#include "instructions.hpp"
#include "../VMGlobals.hpp"

void exec_jvm_ldc() {

}

void exec_jvm_ldc_w() {

}
void exec_jvm_ldc2_w() {

}

// maffei
/// Empilha em jvm_stack a variável na N-ehsima posicao do vetor de variaveis locais
void exec_jvm_iload(u1 N) {jvm_push( frame_stack.top()->variaveis_locais[N] );}
void exec_jvm_iload_0() {exec_jvm_iload(0);}
void exec_jvm_iload_1() {exec_jvm_iload(1);}
void exec_jvm_iload_2() {exec_jvm_iload(2);}
void exec_jvm_iload_3() {exec_jvm_iload(3);}

// maffei
/// empilha um long do vetor de variaveis locais
void exec_jvm_lload(u1 N) {exec_jvm_iload(N); exec_jvm_iload(N+1);}
void exec_jvm_lload_0() {exec_jvm_lload(0);}
void exec_jvm_lload_1() {exec_jvm_lload(1);}
void exec_jvm_lload_2() {exec_jvm_lload(2);}
void exec_jvm_lload_3() {exec_jvm_lload(3);}

// maffei
/// empilha um float do vetor de variaveis locais
void exec_jvm_fload(u1 N) {exec_jvm_iload(N);}
void exec_jvm_fload_0() {exec_jvm_fload(0);}
void exec_jvm_fload_1() {exec_jvm_fload(1);}
void exec_jvm_fload_2() {exec_jvm_fload(2);}
void exec_jvm_fload_3() {exec_jvm_fload(3);}

// maffei
/// empilha um double do vetor de variaveis locais
void exec_jvm_dload(u1 N){exec_jvm_iload(N);exec_jvm_iload(N+1);}
void exec_jvm_dload_0(){exec_jvm_dload(0);}
void exec_jvm_dload_1(){exec_jvm_dload(1);}
void exec_jvm_dload_2(){exec_jvm_dload(2);}
void exec_jvm_dload_3(){exec_jvm_dload(3);}
