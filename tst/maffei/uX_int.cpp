#include <stdio.h>
#include "../../src/UsingUs.h"

void foo(int x){
  printf("x as hexa ==> %x\n", x);
}

int main() {
  u2 u= 0xFFFF;
  u4 menos1 = -1;
  int less1 = menos1;
  printf("%u\n", menos1);
  printf("%d\n", less1);


return;
  short i = u;
  int x = u;
  printf("u2 u= 0xFFFF;\n");
  printf("int x = u;\n");
  foo(u);
  // printf("x as hexa => %x\n", x);
  // printf("%d\n", u);
  // printf("%u\n", u);
  // printf("i as unsigned=> %x\n", i);
  // printf("i as int => %x\n", i);
  // printf("u as unsigned=> %x\n", u);
  // printf("u as int => %x\n", u);
}