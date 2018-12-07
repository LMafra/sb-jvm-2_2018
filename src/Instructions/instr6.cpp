#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include <string.h>
#include <math.h>

// Rodrigo
void exec_jvm_i2l(){
	u8 result = popcat1();
	Dprintf("Result: %ld\n",result);
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2f(){
	auto x = popcat1();
	float result;
	int ff = *(int*)&x;
	result = (float)ff;
	Dprintf("Result: %f\n",result);
	pushcat1(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_i2d(){

	auto x = popcat1();
	double result;
	int ff = *(int*)&x;
	result = (double)ff;
	Dprintf("Result: %lf\n",result);
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2i(){
	u4 result = popcat2();
	Dprintf("Result: %d\n",result);
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2f(){
	auto x = popcat2();
	long ff = *(long*)&x;
	float result;
	result = (float)ff;
	Dprintf("Result: %f\n",result);
	pushcat1(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_l2d(){
	auto x = popcat2();
	long ff = *(long*)&x;
	double result;
	result = (double)ff;
	Dprintf("Result: %lf\n",result);
	pushcat2(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_f2i(){
	auto x = popcat1();
	float ff = *(float*)&x;
	int result = _f2i(ff);
	Dprintf("Result: %d\n",result);
	pushcat1(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_f2l(){
	auto x = popcat1();
	float ff = *(float*)&x;
	long result = _f2l(ff);
	Dprintf("Result: %ld\n",result);
	pushcat2(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_f2d(){
	auto x = popcat1();
	float ff = *(float*)&x;
	double result;
	result = (double)ff;
	Dprintf("Result: %lf\n",result);
	pushcat2(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_d2i(){
	auto x = popcat2();
	double ff = *(double*)&x;
	printf("Result: %f\n", ff);
	int result = _d2i(ff);
	Dprintf("Result: %d\n",result);
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2l(){
	auto x = popcat2();
	double ff = *(double*)&x;
	long result = _d2l();	
	Dprintf("Result: %ld\n",result);
	pushcat2(result);
	incpc(1);
}

// Rodrigo [nso sei se estah correta 100%]
void exec_jvm_d2f(){
	auto x = popcat2();
	double ff = *(double*)&x;
	float result;
	if( isnormal(ff) ) result = (float)ff;
	else if (isnan(ff)) result = NaN;	// nan do tipo float
	else if( !signbit(ff)) result = INFINITY;
	else result = -INFINITY;
	Dprintf("Result: %f\n",result);
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2b(){
	u4 aux = popcat1();
	u1 aux2 = (u1)aux;
	// u4 result = aux2;
	pushcat1(aux2);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2c(){
	u4 aux =  popcat1();
	aux = aux & 0x11;
	// u2 aux2 = (u2)aux;
	// u4 result = aux2;
	// pushcat1(result);
	pushcat1(aux);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2s(){
	int32_t aux =  popcat1();
	aux = (short)aux;
	int32_t result = (int32_t)aux;
	pushcat1(result);
	incpc(1);
}