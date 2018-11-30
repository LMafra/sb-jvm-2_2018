#include "exec_instr.hpp"
#include "exec_vet.hpp"
#include "./src/UsingUs.cpp"
#include "./src/ClassFileStructures/method_info.hpp"
#include "./src/ClassFileStructures/cp_info.hpp"
#include <iostream>
#include <typeinfo>


// pushcat1 e pushcat2 sao pseudofuncoes que serao implementadas
// pushcat1: boolean, byte, char, short, int, float, reference, return_address
// pushcat2: long, double

void exec_jvm_nop(){ 
}

void exec_jvm_aconst_null(){
  jvm_push(NULL);
  incpc(1);
}

void exec_jvm_iconst_m1(){
  pushcat1(-1);
  incpc(1);
}

void exec_jvm_iconst_0(){
  pushcat1(0);
  incpc(1);
public Base {};

using namespace std;
int main() {
 
public Base {};

using namespace std;
int main() {
 
public Base {};

using namespace std;
int main() {
 
public Base {};

using namespace std;
int main() {
 
public Base {};

using namespace std;
int main() {
 
public Base {};

using namespace std;
int main() {
 
public Base {};

using namespace std;
int main() {
 
void exec_jvm_iconst_2(){
  pushcat1(2);
  incpc(1);
}

void exec_jvm_iconst_3(){
  pushcat1(3);
  incpc(1);
}

void exec_jvm_iconst_4(){
  pushcat1(4);
  incpc(1);
}

void exec_jvm_iconst_5(){
  pushcat1(5);
  incpc(1);
}

void exec_jvm_lconst_0(){
  pushcat2(0);
  incpc(1);
}

void exec_jvm_lconst_1(){
  pushcat2(1);
  incpc(1);
}

void exec_jvm_fconst_0(){
  pushcat1(0.0);
  incpc(1);
}

void exec_jvm_fconst_1(){
  pushcat1(1.0);
  incpc(1);
}

void exec_jvm_fconst_2(){
  pushcat1(2.0);
  incpc(1);
}

void exec_jvm_dconst_0(){
  pushcat2(0.0);
  incpc(1);
}

void exec_jvm_dconst_1(){
  pushcat2(1.0);
  incpc(1);
}

void exec_jvm_bipush(){
  pushcat1((int) char)
  incpc(1);
}

void exec_jvm_sipush(){
  unsigned int b1 = 0, b2 = 0;
  short intermediate;
  intermediate = short (b1 << 8) | b2;
  pushcat1(intermediate)
  incpc(1);
}

void exec_jvm_ldc(){ // duvida
  index = CONSTANT_Class_info::name_index;
  if (typeid(index) == int || typeid(index) == float){
    
  }
}

void exec_jvm_ldc_w(){}

void exec_jvm_ldc2_w(){}

void exec_jvm_iload(){
  
}

void exec_jvm_lload(){}

void exec_jvm_fload(){}

void exec_jvm_dload(){}

void exec_jvm_aload(){}

void exec_jvm_iload_0(){}

void exec_jvm_iload_1(){}

void exec_jvm_iload_2(){}

void exec_jvm_iload_3(){}

void exec_jvm_lload_0(){}

void exec_jvm_lload_1(){}

void exec_jvm_lload_2(){}

void exec_jvm_lload_3(){}

void exec_jvm_fload_0(){}

void exec_jvm_fload_1(){}

void exec_jvm_fload_2(){}

void exec_jvm_fload_3(){}

void exec_jvm_dload_0(){}

void exec_jvm_dload_1(){}

void exec_jvm_dload_2(){}

void exec_jvm_dload_3(){}

void exec_jvm_aload_0(){}

void exec_jvm_aload_1(){}

void exec_jvm_aload_2(){}

void exec_jvm_aload_3(){}

void exec_jvm_iaload(){}

void exec_jvm_faload(){}

void exec_jvm_daload(){}

void exec_jvm_aaload(){}

void exec_jvm_baload(){}

void exec_jvm_caload(){}

void exec_jvm_saload(){}

void exec_jvm_istore(){}

void exec_jvm_lstore(){}

void exec_jvm_fstore(){}

void exec_jvm_dstore(){}

void exec_jvm_astore(){}

void exec_jvm_istore_0(){}

void exec_jvm_istore_1(){}

void exec_jvm_istore_2(){}

void exec_jvm_istore_3(){}

void exec_jvm_lstore_0(){}

void exec_jvm_lstore_1(){}

void exec_jvm_lstore_2(){}

void exec_jvm_lstore_3(){}

void exec_jvm_fstore_0(){}

void exec_jvm_fstore_1(){}

void exec_jvm_fstore_2(){}

void exec_jvm_fstore_3(){}

void exec_jvm_dstore_0(){}

void exec_jvm_dstore_1(){}

void exec_jvm_dstore_2(){}

void exec_jvm_dstore_3(){}

void exec_jvm_astore_0(){}

void exec_jvm_astore_1(){}

void exec_jvm_astore_2(){}

void exec_jvm_astore_3(){}
