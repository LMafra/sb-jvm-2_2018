#include "instructions.hpp"
// #include "exec_instr.hpp"
#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include <string.h>
// maffei
void exec_jvm_istore(){store_32(); incpc(1+1);}
void exec_jvm_istore_0(){store_32(Helper::ZERO); incpc(1);}
void exec_jvm_istore_1(){store_32(Helper::ONE); incpc(1);}
void exec_jvm_istore_2(){store_32(Helper::TWO); incpc(1);}
void exec_jvm_istore_3(){store_32(Helper::THREE); incpc(1);}
// maffei
void exec_jvm_lstore(){store_64(); incpc(1+1);}
void exec_jvm_lstore_0(){store_64(Helper::ZERO); incpc(1);}
void exec_jvm_lstore_1(){store_64(Helper::ONE); incpc(1);}
void exec_jvm_lstore_2(){store_64(Helper::TWO); incpc(1);}
void exec_jvm_lstore_3(){store_64(Helper::THREE); incpc(1);}
// maffei
void exec_jvm_fstore(){store_32(); incpc(1+1);}
void exec_jvm_fstore_0(){store_32(Helper::ZERO); incpc(1);}
void exec_jvm_fstore_1(){store_32(Helper::ONE); incpc(1);}
void exec_jvm_fstore_2(){store_32(Helper::TWO); incpc(1);}
void exec_jvm_fstore_3(){store_32(Helper::THREE); incpc(1);}
// maffei
void exec_jvm_astore(){load_addr();incpc(1+1);}
void exec_jvm_astore_0(){load_addr(Helper::ZERO);incpc(1);}
void exec_jvm_astore_1(){load_addr(Helper::ONE);incpc(1);}
void exec_jvm_astore_2(){load_addr(Helper::TWO);incpc(1);}
void exec_jvm_astore_3(){load_addr(Helper::THREE);incpc(1);}

// Não maii necessário;
// arthur
static void dstore(int index) {
	u4 value1;	u4 value2;
	value2 = pop_cat1();
	value1 = pop_cat1();
	frame_stack.top().variaveis_locais[index].val=value1;
	frame_stack.top().variaveis_locais[index+1].val=value2;
	double auxiedb;
	((u4*)&auxiedb)[0]=value2;
	((u4*)&auxiedb)[1]=value1;
	Dprintf("debug dstore %lf\n", auxiedb);
}
// maffei
void exec_jvm_dstore(){store_64();incpc(1+1);}
void exec_jvm_dstore_0(){store_64(Helper::ZERO);incpc(1);}
void exec_jvm_dstore_1(){store_64(Helper::ONE);incpc(1);}
void exec_jvm_dstore_2(){store_64(Helper::TWO);incpc(1);}
void exec_jvm_dstore_3(){store_64(Helper::THREE);incpc(1);}


