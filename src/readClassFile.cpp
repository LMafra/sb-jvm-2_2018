#include <iostream>
#include <cstdio>
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.cpp"
#include  "displaymethods.cpp"
#define M m&0xff
using namespace std;

unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}
unsigned long only_ones64(int x){
  return (unsigned int)(-1) >> (64 - x);
}


int main() {
  FILE * f = fopen("double_aritmetica.class", "rb");
  ClassFile cf;
  u1 byte;
  u1 a,b,c,d;
  fread(&a, 1, 1, f);if(a != 0xca) printf("Não é um .class válido [Not cafebabe");
  fread(&b, 1, 1, f);if(b != 0xfe) printf("Não é um .class válido [Not cafebabe");
  fread(&c, 1, 1, f);if(c != 0xba) printf("Não é um .class válido [Not cafebabe");
  fread(&d, 1, 1, f);if(d != 0xbe) printf("Não é um .class válido [Not cafebabe");
  printf("li :: %x\n", (unsigned int)a << 24 | 
                      (unsigned int)b << 16 |
                      (unsigned int)c << 8 |
                      (unsigned int)d);
  return 0;
  fread(&cf.minor_version, 2, 1, f); cf.minor_version = (cf.minor_version << 8) | (cf.minor_version >> 8);
  fread(&cf.major_version, 2, 1, f); cf.major_version = (cf.major_version << 8) | (cf.major_version >> 8);
  fread(&cf.constant_pool_count, 2, 1, f); cf.constant_pool_count = (cf.constant_pool_count << 8) | (cf.constant_pool_count >> 8);
  u1* tmp = (cp_info*)malloc( cf.constant_pool_count * sizeof( cp_info ) );
  fread(cf.constant_pool,  sizeof(cp_info), cf.constant_pool_count-1, f);
  fread(&cf.access_flags, 2, 1, f); cf.access_flags = (cf.access_flags << 8) | (cf.access_flags >> 8);
  
  


  free(tmp);
}

void old(int argc, char** argv) {
  // u4 x = 0xfff;
  // // printf("%x\n", x);
  // x = only_ones32(8);
  // printf("%x\n", x);

  // u8 xx = 0x0000ffffffffffff;
  // xx = only_ones64(40);
  // x = 0x0;
  // printf("%lx\n", xx);

  // printf("%d\n", argc);
  // FILE * f = fopen("test.class", "rb");
  // FILE * f2 = fopen("write.tst", "wb");
  // u4 m;
  // fwrite(&xx, 64, 1, f2);
  // // printf("%s\n", argv[0]);
  // // printf("%s\n", argv[1]);
  // // printf("%s\n", argv[2]);
  // fread(&m, 1, 1, f);printf("%x\n", M);
  // fread(&m, 1, 1, f);printf("%x\n", M);
  // fread(&m, 1, 1, f);printf("%x\n", M);
  // fread(&m, 1, 1, f);printf("%x\n", M);

  // fclose(f);
  // fclose(f2);
  ClassFile clfl;
  
}
