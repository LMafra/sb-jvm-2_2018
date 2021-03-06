#include "../UsingUs.h"
#include "../VMGlobals.hpp"
#include <string.h>

// Rodrigo
void exec_jvm_lcmp(){
	u8 value2 = popcat2();
	u8 value1 = popcat2();
	int32_t result = 0;
	if(value1 == value2){
	}else if(value1 > value2){
		result = 1;
	}else{
		result = -1;
	}
	pushcat1(result);
	incpc(1);
}

// Rodrigo
// naN ==> fcmpl instruction pushes the int value -1 onto the operand stack.
void exec_jvm_fcmpl(){
	u4 f2 = popcat1();
	u4 f1 = popcat1();
	int32_t result = 0;
	float value1, value2;
	memcpy(&value1, &f1, sizeof(u4));
	memcpy(&value2, &f2, sizeof(u4));
	
	if (isunordered(value1, value2))result = -1;
	else if(value1 == value2)	result = 0;
	else if(value1 > value2)result = 1;
	else	result = -1;

	pushcat1(result);
	incpc(1);
}

// Rodrigo & maffei
// naN ==> fcmpl instruction pushes the int value 1 onto the operand stack.
void exec_jvm_fcmpg(){
	u4 f2 = popcat1();
	u4 f1 = popcat1();
	int32_t result = 0;
	float value1, value2;
	memcpy(&value1, &f1, sizeof(u4));
	memcpy(&value2, &f2, sizeof(u4));
	if (isunordered(value1, value2))result = 1;
	else if(value1 == value2)	result = 0;
	else if(value1 > value2)result = 1;
	else	result = -1;
	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_dcmpl(){
	u8 f2 = popcat2();
	u8 f1 = popcat2();
	int32_t result = 0;
	double value1,value2;
	memcpy(&value1, &f1, sizeof(u8));
	memcpy(&value2, &f2, sizeof(u8));
	if (isunordered(value1, value2))result = -1;
	else if(value1 == value2)	result = 0;
	else if(value1 > value2)result = 1;
	else	result = -1;	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_dcmpg(){
	u8 f2 = popcat2();
	u8 f1 = popcat2();
	int32_t result = 0;
	double value1, value2;
	memcpy(&value1, &f1, sizeof(u8));
	memcpy(&value2, &f2, sizeof(u8));
	if (isunordered(value1, value2))result = 1;
	else if(value1 == value2)	result = 0;
	else if(value1 > value2)result = 1;
	else	result = -1;

	pushcat1(result);
	incpc(1);
}

// Rodrigo
void exec_jvm_ifeq(){
	int32_t result = popcat1();
	if(result == 0){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);
		// ((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_ifne(){
	int32_t result = popcat1();
	if(result != 0){
	int16_t offset = offset16_from_instr();
	// ((u1 *)&offset)[0]=instrparam(2);	// ((u1 *)&offset)[1]=instrparam(1);
	incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_iflt(){
	int32_t result = popcat1();
	if(result < 0){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_ifge(){
	int32_t result = popcat1();
	if(result >= 0){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_ifgt(){
	int32_t result = popcat1();
	if(result > 0){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_ifle(){
	int32_t result = popcat1();
	if(result <= 0){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
  }
}

// Rodrigo
void exec_jvm_if_icmpeq(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 == value2){
		int16_t offset = offset16_from_instr();
    // ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_icmpne(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 != value2){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_icmplt(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 < value2){
		int16_t offset = offset16_from_instr();
    	// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_icmpge(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 >= value2){
		int16_t offset = offset16_from_instr();
    	// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_icmpgt(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 > value2){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_icmple(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 <= value2){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_acmpeq(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 == value2){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}

// Rodrigo
void exec_jvm_if_acmpne(){
	int32_t value2 = popcat1();
	int32_t value1 = popcat1();
	if (value1 != value2){
		int16_t offset = offset16_from_instr();
		// ((u1 *)&offset)[0]=instrparam(2);		((u1 *)&offset)[1]=instrparam(1);
		incpc(offset);
	}
	else{
		incpc(3);
	}
}
