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
	u4 value1;
	u4 value2;
	value2 = pop_cat1();
	value1 = pop_cat1();
	frame_stack.top().variaveis_locais[index].val=value1;
	frame_stack.top().variaveis_locais[index+1].val=value2;
	double auxiedb;
	((u4*)&auxiedb)[0]=value2;
	((u4*)&auxiedb)[1]=value1;
	Dprintf("debug dstore %lf\n", auxiedb);
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


