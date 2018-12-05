#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include <string.h>

// Rodrigo
void exec_jvm_i2l(){
	u8 result = popcat1();
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2f(){
	u4 aux = popcat1();
	float aux2 = (float)aux;
	u4 result;
	memcpy(&result,&aux2,sizeof(u4));
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2d(){
	u4 aux = popcat1();
	double aux2 = (double)aux;
	u8 result;
	memcpy(&result,&aux2,sizeof(u8));
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2i(){
	u4 result = popcat2();
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2f(){
	u8 aux = popcat2();
	float aux2 = (float) aux;
	u4 result;
	memcpy(&result,&aux2,sizeof(u4));
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2d(){
	u8 aux = popcat2();
	double aux2 = (double) aux;
	u8 result;
	memcpy(&result,&aux2,sizeof(u8));
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_f2i(){
	u4 aux = popcat1();
	float aux2;
	memcpy(&aux2,&aux,sizeof(u4));
	u4 result = aux;
	pushcat1(result);
	incpc(1);
}

// Rodrigo \ maffei
void exec_jvm_f2l(){
	float aux = popcat1();
	long result = aux;
	pushcat2(result);
	incpc(1);
}

// Rodrigo \ maffei
void exec_jvm_f2d(){
	float f = popcat1();
	double d = f;
	pushcat2(d);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2i(){
	u8 aux = popcat2();
	double aux2;
	memcpy(&aux2,&aux,sizeof(u8));
	u4 result = aux2;
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2l(){
	u8 aux = popcat2();
	double aux2;
	memcpy(&aux2,&aux,sizeof(u8));
	u8 result = aux2;
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2f(){
	double aux = popcat2();
	float aux2 = aux;
	u4 result;
	memcpy(&result,&aux2,sizeof(u4));
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2b(){
	u4 aux = popcat1();
	u1 aux2 = (u1)aux;
	u4 result = aux2;
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2c(){
	u4 aux =  popcat1();
	u2 aux2 = (u2)aux;
	u4 result = aux2;
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2s(){
	u4 aux =  popcat1();
	u2 aux2 = (u2)aux;
	u4 result = aux2;
	pushcat1(result);
	incpc(1);
}
