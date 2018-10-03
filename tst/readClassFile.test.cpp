#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../src/UsingUs.hpp"
void read_us(void* buf, int n , FILE * f) {
  for(int i = n-1; i >= 0; i--) {
    fread( &((u1*)buf)[i], 1, 1, f );
  }
}

int main() {
  u2 buf;
  FILE * f;
  f = fopen("double_aritmetica.class", "rb");
  read_us(&buf, 2, f);
  std::cout << std::hex << std::showbase << std::uppercase << buf << std::endl;
}