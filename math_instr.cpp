#include <math.h>
#include "exec_instr.hpp"


void exec_jvm_iadd(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = value1+value2;
    pushcat1(result);
    incpc(1);
}
void exec_jvm_ladd(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = value1+value2;
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_fadd(){
	u4 aux2 = popcat1();
    u4 aux1 = popcat1();
    float fvalue2;
    float fvalue1;
    memcpy(&fvalue2,&aux2,sizeof(u4));
    memcpy(&fvalue1,&aux1,sizeof(u4));
    float fresult = fvalue1+fvalue2;
	u4 result;
	memcpy(&result,&fresult,sizeof(u4));
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_dadd(){
	u8 aux2 = popcat2();
    u8 aux1 = popcat2();
    double dvalue2;
    double dvalue1;
    memcpy(&dvalue2,&aux2,sizeof(u8));
    memcpy(&fdalue1,&aux1,sizeof(u8));
    double dresult = dvalue1+dvalue2;
	u8 result;
	memcpy(&result,&dresult,sizeof(u8));
    pushcat2(result);
    incpc(1);		
}
void exec_jvm_isub(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = value1-value2;
    pushcat1(result);
    incpc(1);
}
void exec_jvm_lsub(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = value1-value2;
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_fsub(){
	u4 aux2 = popcat1();
    u4 aux1 = popcat1();
    float fvalue2;
    float fvalue1;
    memcpy(&fvalue2,&aux2,sizeof(u4));
    memcpy(&fvalue1,&aux1,sizeof(u4));
    float fresult = fvalue1-fvalue2;
	u4 result;
	memcpy(&result,&fresult,sizeof(u4));
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_dsub(){
	u8 aux2 = popcat2();
    u8 aux1 = popcat2();
    double dvalue2;
    double dvalue1;
    memcpy(&dvalue2,&aux2,sizeof(u8));
    memcpy(&fdalue1,&aux1,sizeof(u8));
    double dresult = dvalue1+dvalue2;
	u8 result;
	memcpy(&result,&dresult,sizeof(u8));
    pushcat2(result);
    incpc(1);
}
void exec_jvm_imul(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = value1*value2;
    pushcat1(result);
    incpc(1);
}
void exec_jvm_lmul(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = value1*value2;
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_fmul(){
	u4 aux2 = popcat1();
    u4 aux1 = popcat1();
    float fvalue2;
    float fvalue1;
    memcpy(&fvalue2,&aux2,sizeof(u4));
    memcpy(&fvalue1,&aux1,sizeof(u4));
    float fresult = fvalue1*fvalue2;
	u4 result;
	memcpy(&result,&fresult,sizeof(u4));
    pushcat1(result);
    incpc(1);		
}
void exec_jvm_dmul(){
	u8 aux2 = popcat2();
    u8 aux1 = popcat2();
    double dvalue2;
    double dvalue1;
    memcpy(&dvalue2,&aux2,sizeof(u8));
    memcpy(&fdalue1,&aux1,sizeof(u8));
    double dresult = dvalue1*dvalue2;
	u8 result;
	memcpy(&result,&dresult,sizeof(u8));
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_idiv(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = value1/value2;
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_ldiv(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = value1/value2;
    pushcat2(result);
    incpc(1);		
}
void exec_jvm_fdiv(){
	u4 aux2 = popcat1();
    u4 aux1 = popcat1();
    float fvalue2;
    float fvalue1;
    memcpy(&fvalue2,&aux2,sizeof(u4));
    memcpy(&fvalue1,&aux1,sizeof(u4));
    float fresult = fvalue1/fvalue2;
	u4 result;
	memcpy(&result,&fresult,sizeof(u4));
    pushcat1(result);
    incpc(1);
}
void exec_jvm_ddiv(){
	u8 aux2 = popcat2();
    u8 aux1 = popcat2();
    double dvalue2;
    double dvalue1;
    memcpy(&dvalue2,&aux2,sizeof(u8));
    memcpy(&fdalue1,&aux1,sizeof(u8));
    double dresult = dvalue1/dvalue2;
	u8 result;
	memcpy(&result,&dresult,sizeof(u8));
    pushcat2(result);
    incpc(1);		
}
void exec_jvm_irem(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = value1%value2;
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_lrem(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = value1%value2;
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_frem(){
	u4 aux2 = popcat1();
    u4 aux1 = popcat1();
    float fvalue2;
    float fvalue1;
    memcpy(&fvalue2,&aux2,sizeof(u4));
    memcpy(&fvalue1,&aux1,sizeof(u4));
    float fresult = fvalue1%fvalue2;
	u4 result;
	memcpy(&result,&fresult,sizeof(u4));
    pushcat1(result);
    incpc(1);
}
void exec_jvm_drem(){
	u8 aux2 = popcat2();
    u8 aux1 = popcat2();
    double dvalue2;
    double dvalue1;
    memcpy(&dvalue2,&aux2,sizeof(u8));
    memcpy(&fdalue1,&aux1,sizeof(u8));
    double dresult = dvalue1%dvalue2;
	u8 result;
	memcpy(&result,&dresult,sizeof(u8));
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_ineg(){
    u4 value = popcat1();
	u4 result = ~value
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_lneg(){
    u8 value = popcat2();
	u8 result = ~value
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_fneg(){
    u4 aux = popcat1();
    float fvalue;
    memcpy(&fvalue,&aux,sizeof(u4));
    float fresult = fvalue*(-1);
	u4 result;
	memcpy(&result,&fresult,sizeof(u4));
    pushcat1(result);
    incpc(1);
}
void exec_jvm_dneg(){
    u8 aux = popcat2();
    double dvalue;
    memcpy(&dvalue,&aux,sizeof(u8));
    double dresult = dvalue*(-1);
	u8 result;
	memcpy(&result,&dresult,sizeof(u8));
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_ishl(){
	u4 value = popcat1();
    u4 shift = popcat1() &0x1F;
    value = (value << shift);
    u4 result;
    memcpy(&result,&value,sizeof(u4));
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_lshl(){
	u8 value = popcat2();
    u4 shift = popcat1() &0x1F;
    value = (value << shift);
    u8 result;
    memcpy(&result,&value,sizeof(u8));
    pushcat2(result);
    incpc(1);		
}
void exec_jvm_ishr(){
	u4 value = popcat1();
    u4 shift = popcat1() &0x1F;
    value = (value >> shift);
    u4 result;
    memcpy(&result,&value,sizeof(u4));
    pushcat1(result);
    incpc(1);		
}
void exec_jvm_lshr(){
	u8 value = popcat2();
    u4 shift = popcat1() &0x1F;
    value = (value >> shift);
    u8 result;
    memcpy(&result,&value,sizeof(u8));
    pushcat2(result);
    incpc(1);
}
void exec_jvm_iushr(){
	u4 value = popcat1();
    u4 shift = popcat1() &0x1F;
    value = (value >> shift);
    pushcat1(value);
    incpc(1);		
}
void exec_jvm_lushr(){
	u8 value = popcat2();
    u4 shift = popcat1() &0x1F;
    value = (value >> shift);
    pushcat2(value);
    incpc(1);
}
void exec_jvm_iand(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = (value1 & value2);
    pushcat1(result);
    incpc(1);
}
void exec_jvm_land(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = (value1 & value2);
    pushcat2(result);
    incpc(1);		
}
void exec_jvm_ior(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = (value1 | value2);
    pushcat1(result);
    incpc(1);	
}
void exec_jvm_lor(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = (value1 | value2);
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_ixor(){
	u4 value2 = popcat1();
    u4 value1 = popcat1();
	u4 result = (value1 ^ value2);
    pushcat1(result);
    incpc(1);		
}
void exec_jvm_lxor(){
	u8 value2 = popcat2();
    u8 value1 = popcat2();
	u8 result = (value1 | value2);
    pushcat2(result);
    incpc(1);	
}
void exec_jvm_iinc(){
    u4 value = popcat1();
	u4 result = value++;
    pushcat1(result);
    incpc(1);		
}