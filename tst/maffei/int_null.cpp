#include <stdio.h>
#include "../../src/UsingUs.h"


int main() {
  u2 val;
  u1 v1 = 0x11;
  u1 v2 = 0x88;
  printf("v1 = %x\n", v1);
  printf("v2 = %x\n", v2);
  printf("(v1 << 8)|v2 = %x\n", (v1 << 8)|v2);
  if(NULL) {
    printf("NULL eh true\n");
  }
  else
    printf("NULL eh false\n");
}