#include <iostream>
#include <stdint.h>

using namespace std;

using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;

void ** gen;
int x = 99;
int main() {
  gen = (void**)calloc(10, sizeof(void*));
  gen[3] = &x;

  printf("%d\n", *(int*)gen[3]);
}