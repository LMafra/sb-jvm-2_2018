#include <stdint.h>
#include <stdio.h>
#include "../../src/UsingUs.h"
int pi(int32_t x){printf("%d\n",x);}
int pu(unsigned x){printf("%u\n",x);}
int ps(short x){printf("%d\n",x);}

int main() {
  u2 u = 0xffff;
  u4 uu = 0xffffffff;
  int32_t x = (short)u;
  short sh = u;
  pi(u);
  pi(uu);
  pu(uu);
  pi(x);
  ps(sh);

}
