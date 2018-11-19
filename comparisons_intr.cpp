#include <math.h>
#include "exec_instr.hpp"

void exec_jvm_lcmp(){
	u8 value2 = popcat2();
	u8 value1 = popcat2();
	u4 result = 0;
	if(value1 == value2){
		pushcat1(result);
	}else if(value1 > value2){
		result = 1;
		pushcat1(result);
	}else{
		result = -1;
		pushcat1(result);
	}
}

void exec_jvm_fcmpl(){
	u4 f2 = popcat1();
	u4 f1 = popcat1();
	u4 result = 0;
	float value1, value2;
	memcpy(&value1, &f1, sizeof(u4));
	memcpy(&value2, &f2, sizeof(u4));
	if(value1 == value2){
		pushcat1(result);
	}else if(value1 > value2){
		result = 1;
		pushcat1(result);
	}else{
		result = -1;
		pushcat1(result);
	}
}

void exec_jvm_fcmpg(){
	u4 f2 = popcat1();
	u4 f1 = popcat1();
	u4 result = 0;
	float value1, value2;
	memcpy(&value1, &f1, sizeof(u4));
	memcpy(&value2, &f2, sizeof(u4));
	if(value1 == value2){
		pushcat1(result);
	}else if(value1 > value2){
		result = 1;
		pushcat1(result);
	}else if(value1 < value2){
		result = -1;
		pushcat1(result);
	}else{
		result = -1;
		pushcat1(result);
	}
}

void exec_jvm_dcmpl(){
	u8 f2 = popcat2();
	u8 f1 = popcat2();
	u4 result = 0;
	double value1,value2;
	memcpy(&value1, &f1, sizeof(u8));
	memcpy(&value2, &f2, sizeof(u8));
	if(value1 == value2){
		pushcat1(result);
	}else if(value1 > value2){
		result = 1;
		pushcat1(result);
	}else{
		result = -1;
		pushcat1(result);
	}
}
void exec_jvm_dcmpg(){
	u8 f2 = popcat2();
	u8 f1 = popcat2();
	u4 result = 0;
	double value1, value2;
	memcpy(&value1, &f1, sizeof(u8));
	memcpy(&value2, &f2, sizeof(u8));
	if(value1 == value2){
		pushcat1(result);
	}else if(value1 > value2){
		result = 1;
		pushcat1(result);
	}else if(value1 < value2){
		result = -1;
		pushcat1(result);
	}else{
		result = -1;
		pushcat1(result);
	}
}

void exec_jvm_ifeq(){
    u4 result = popcat1();
    if(result == 0){
		u2 offset = (((u2)index1)<<8)+index2;
		frame->pc += (offset - 3);
    }
}

void exec_jvm_ifne();
void exec_jvm_iflt();
void exec_jvm_ifge();
void exec_jvm_ifgt();
void exec_jvm_ifle();
void exec_jvm_if_icmpeq();
void exec_jvm_if_icmpne();
void exec_jvm_if_icmplt();
void exec_jvm_if_icmpge();
void exec_jvm_if_icmpgt();
void exec_jvm_if_icmple();
void exec_jvm_if_acmpeq();
void exec_jvm_if_acmpne();