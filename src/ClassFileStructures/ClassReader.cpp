#include "ClassFile.cpp"

void read_us(void* buf, int n , FILE * f) {
  u1* ptr = (u1*)buf;
  for(int i = n-1; i >= 0; i--) {
    fread( &ptr[i], 1, 1, f );
  }
}