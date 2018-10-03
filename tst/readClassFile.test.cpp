#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../src/UsingUs.hpp"
void read_us(u1* buf, size_t siz, size_t qtd, FILE * f) {
  auto n = siz * qtd;
  memset(buf, 0x00, n);
  u1 t;
  *buf = 0x12;
  *(buf+4) = 0x33;
  printf("%x\n", *buf << 8 | *(buf+4));
  return 0;
  for(size_t i = 0; i < n; i++) {
    fread( (buf+i*4), 1, 1, f );
    // *ptr = *ptr << 8 | t;
  }
}

int main() {
  u1* buf = (u1*)malloc( 100 * sizeof(u1));
  u2* buf2 = (u2*)malloc(50 * sizeof(u2));
  FILE * f;
  read_us(buf, sizeof(u1), 100, f);
  read_us((u1*)buf2, sizeof(u2), 50, f);

  return 0;

  *buf = 0x12;
  *(buf + 4) = 0x34;
  printf("%x\n", *buf << 8 | *(buf+4));
  memset(buf, 0x00, 1);
  printf("%x\n", *buf << 8 | *(buf+4));
  free(buf);
}