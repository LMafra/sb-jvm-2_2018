#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../src/UsingUs.hpp"
template <class T>
void ttt(T* buf, size_t to_read, FILE * f) {
  // f = fopen("double_aritmetica.class", "rb");
  size_t size_T = sizeof(T); size_t idx = 0;
  u1 mini_buf;
  for(; to_read > 0; to_read--){
    T tmp_buf = 0b0;  // buffer temporário, que será depois salvo no vetor.
    for(size_t i = 0; i < size_T; i++) {
      fread( &mini_buf, 1, 1, f );
      tmp_buf = tmp_buf << 8 | mini_buf;
      readd++;
    }
    buf[idx] = tmp_buf;
  }
  // fclose(f);
}



int main() {
  printf("sizeof(u1) ==> %lu\n", sizeof(u1));
  printf("sizeof(int) ==> %lu\n", sizeof(int));
  return 0;
  u1* buf = (u1*)malloc( 100 * sizeof(u1));
  u2* buf2 = (u2*)malloc(50 * sizeof(u2));
  FILE * f;
  ttt(buf, sizeof(u1), 100, f);
  ttt(buf2, sizeof(u2), 50, f);

  printf("Printando buf2[u2] :: ");
  for(int i = 0; i < 7; i++)
    buf2[i] == 0 ? printf("*") : printf("%x", buf2[i]);
  printf("\n");
  printf("Printando buf[u1] :: ");
  for(int i = 0; i < 7; i++)
    buf[i] == 0 ? printf("#") : printf("%x", buf[i]);
  printf("\n");
  
  ttt(buf2, sizeof(u2), 50, f);
  for(int i = 0; i < 7; i++)
    buf2[i] == 0 ? printf("*") : printf("%x", buf2[i]);
  printf("\n");

  ttt(buf, sizeof(u2), 50, f);
  for(int i = 0; i < 7; i++)
    buf[i] == 0 ? printf("*") : printf("%x", buf[i]);
  printf("\n");

  // printf("%x", *buf2);
  // printf("%x\n", *(buf2+2));
  // printf("%x\n", *(buf2+4));
  // printf("%x\n", *(buf2+6));
  free(buf2);
  free(buf);
  return 0;
}