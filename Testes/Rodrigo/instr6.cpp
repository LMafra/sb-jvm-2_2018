#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#define dprintf printf
template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}
#include "UsingUs.h"
#include <string.h>
#include <iostream>
using namespace std;

int vetor[2] = {-3,300};

double vetor2[2] = {-3.14,2};
int pc = 0;

uint32_t popcat1() {
	return vetor[1];
	//return 0xC048F5C3;
	 //return 0x41430A3D;
}

uint64_t popcat2(){
	//return vetor2[0];
	return 0xC0091EB851EB851F;
}

void pushcat1(int result){
	vetor[0] = result;
}

void pushcat2(int result){
	vetor2[1] = result;
}

void incpc(int i){
	pc += i;
}

int instrparam(int i){
	return vetor[i-1];
}

// Rodrigo
void exec_jvm_i2l(){
	u8 result = popcat1();
	dprintf("Result: %ld\n",result);
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_i2f(){
	auto x = popcat1();
	float result;
	int ff = *(int*)&x;
	result = (float)ff;
	dprintf("Result: %f\n",result);
	pushcat1(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_i2d(){

	auto x = popcat1();
	double result;
	int ff = *(int*)&x;
	result = (double)ff;
	dprintf("Result: %lf\n",result);
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2i(){
	u4 result = popcat2();
	dprintf("Result: %d\n",result);
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2f(){
	auto x = popcat2();
	long ff = *(long*)&x;
	float result;
	result = (float)ff;
	dprintf("Result: %f\n",result);
	pushcat1(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_l2d(){
	auto x = popcat2();
	long ff = *(long*)&x;
	double result;
	result = (double)ff;
	dprintf("Result: %lf\n",result);
	pushcat2(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_f2i(){
	auto x = popcat1();
	float ff = *(float*)&x;
	int result;
	if( isnormal(ff) ) result = (int)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = INT_MAX;
	else result = INT_MIN;	
	dprintf("Result: %d\n",result);
	pushcat1(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_f2l(){
	auto x = popcat1();
	float ff = *(float*)&x;
	long result;
	if( isnormal(ff) ) result = (long)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = LONG_MAX;
	else result = LONG_MIN;	
	dprintf("Result: %ld\n",result);
	pushcat2(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_f2d(){
	auto x = popcat1();
	float ff = *(float*)&x;
	double result;
	result = (double)ff;
	dprintf("Result: %lf\n",result);
	pushcat2(result);
	incpc(1);
}


// Rodrigo
void exec_jvm_d2i(){
	auto x = popcat2();
	double ff = *(double*)&x;
	printf("Result: %f\n", ff);
	int result;
	if( isnormal(ff) ) result = (int)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = INT_MAX;
	else result = INT_MIN;
	dprintf("Result: %d\n",result);
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2l(){
	auto x = popcat2();
	double ff = *(double*)&x;
	long result;
	if( isnormal(ff) ) result = (long)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = LONG_MAX;
	else result = LONG_MIN;	
	dprintf("Result: %ld\n",result);
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2f(){
	auto x = popcat2();
	double ff = *(double*)&x;
	float result;
	if( isnormal(ff) ) result = (float)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = INFINITY;
	else result = -INFINITY;	
	dprintf("Result: %f\n",result);
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

int main(){
	//exec_jvm_f2i();
	exec_jvm_i2d();
	//exec_jvm_d2i();
	return 0;

}
