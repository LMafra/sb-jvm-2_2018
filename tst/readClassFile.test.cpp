#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../src/UsingUs.hpp"
void read_us(void* buf, int n , FILE * f) {
  u1* ptr = (u1*)buf;
  for(int i = n-1; i >= 0; i--)
    fread( &ptr[i], 1, 1, f );
}

int main() {
  u4 buf;
  FILE * f;
  f = fopen("double_aritmetica.class", "rb");
  read_us(&buf, 4, f);
  std::cout << std::hex << std::showbase << std::uppercase << buf << std::endl;
}