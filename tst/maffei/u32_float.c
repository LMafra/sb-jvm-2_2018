#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
  float f;
  uint32_t uu = 0x12345678;
  f = uu;
  printf("%f\n", f);  printf("%x\n", f);
  memcpy(&f, &uu, sizeof(float));
  printf("%f\n", f);  printf("%x\n", f);
  printf("\n\n");

  printf("%x\n", f);  printf("%u\n", f);
  printf("%x\n", uu);  printf("%u\n", uu);
}