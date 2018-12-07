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

float vetor[2] = {-3.14,2};

double vetor2[2] = {1,2};
int pc = 0;

u4 popcat1(){
	return vetor[0];
}

u8 popcat2(){
	return vetor2[1];
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
	double aux2;
	memcpy(&aux2,&aux,sizeof(u8));
	float aux3 = (float) aux2;
	u4 result;
	memcpy(&result,&aux3,sizeof(u4));
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_l2d(){
	u8 aux = popcat2();
	double aux2 = (double) aux;
	u8 result;
	memcpy(&result,&aux2,sizeof(u8));
	cout <<  type_name<decltype(result)>() << endl;////////////////////////////////////////
	pushcat2(result);
	incpc(1);
}

// Rodrigo

void exec_jvm_f2i(){

	auto x = popcat1();
	float ff = *(float*)&x;
	printf("it works !! => %f\n", ff);
}

void exec_jvm_f2i2(){
	
	u4 aux = float(-3.14);//popcat1();
	float aux2 = *(float *)&aux;
	cout <<  type_name<decltype(aux2)>() << ": " <<aux2 << endl;////////////////////////////////////////
	//memcpy(&aux2,&aux,sizeof(u4));
	int result = aux2;
	cout <<  type_name<decltype(result)>() << ": " <<result << endl;////////////////////////////////////////
/*
	u4 f = popcat1();
	float aux2;
	memcpy(&aux2,&f,sizeof(u4));
	int result = int(aux2);
	*//*
	if( isnormal(f) ) result = (int)f;
	else if (isnan(f)) result = 0;
	else if( !signbit(f)) result = INT_MAX;
	else result = INT_MIN;
	*/
	cout <<  type_name<decltype(result)>() << ": " <<result << endl;////////////////////////////////////////
	pushcat1(result);
	incpc(1);
	
}

// Rodrigo
void exec_jvm_f2l(){
	u4 aux = popcat1();
	float aux2;
	memcpy(&aux2,&aux,sizeof(u4));
	u8 result = aux2;
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_f2d(){
	u4 aux = popcat1();
	float aux2;
	memcpy(&aux2,&aux,sizeof(u4));
	double aux3 = aux2;
	u8 result;
	memcpy(&result,&aux3,sizeof(u8));
	pushcat2(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_d2i(){
	u8 aux = popcat2();
	cout <<  type_name<decltype(aux)>() << ": " <<aux << endl;////////////////////////////////////////
	double aux2;
	/*memcpy(&aux2,&aux,sizeof(u8));
	cout <<  type_name<decltype(aux2)>() << ": " <<aux2 << endl;////////////////////////////////////////
	*/u4 result = int(aux2);
	cout <<  type_name<decltype(result)>() << ": " <<result << endl;////////////////////////////////////////
	pushcat1(result);
	cout <<  type_name<decltype(vetor[0])>() << ": " <<vetor[0] << endl;////////////////////////////////////////
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

int main(){
	exec_jvm_f2i();
	//exec_jvm_d2i();
	return 0;

}
