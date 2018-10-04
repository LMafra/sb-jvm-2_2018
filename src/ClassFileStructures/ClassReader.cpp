#include "ClassFile.hpp"
#include "cp_info.hpp"
#include <cstring>
unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}

void read_us(void* buf, int n , FILE * f) {
  u1* ptr = (u1*)buf;
  for(int i = n-1; i >= 0; i--)
    fread( &ptr[i], 1, 1, f );
}

int main() {
  FILE * f = fopen("double_aritmetica.class", "rb");
  ClassFile cf;
  u1 byte;
  read_us(&cf.magic, sizeof(cf.magic),f);
  if(cf.magic != 0xCAFEBABE){
    printf("Não é um .class válido (Not cafebabe).");
  }
  printf("li :: %x\n", cf.magic);
  return 0;
  read_us(&cf.minor_version, sizeof(cf.minor_version), f);
  read_us(&cf.major_version, sizeof(cf.major_version), f);
  read_us(&cf.constant_pool_count, sizeof(cf.constant_pool_count), f);
  cf.constant_pool = (cp_info*)malloc( cf.constant_pool_count * sizeof( cp_info ) );  // primeiro espaco sempre serah vazio
  for(size_t i = 1; i < cf.constant_pool_count; i++) {
    u1 tag;
    read_us(&tag, sizeof(tag), f);
    switch(tag) {
      // case //enum.xons_class : aux=new classinfo; aux.read();aux.tag=tag;break
      case enum_cp_tags::CONSTANT_Class:
        break;
      case enum_cp_tags::CONSTANT_Fieldref:
        break;
      case enum_cp_tags::CONSTANT_Methodref:
        break;
      case enum_cp_tags::CONSTANT_InterfaceMethodref:
        break;
      case enum_cp_tags::CONSTANT_String:
        break;
      case enum_cp_tags::CONSTANT_Integer:
        break;
      case enum_cp_tags::CONSTANT_Float:
        break;
      case enum_cp_tags::CONSTANT_Long:
        break;
      case enum_cp_tags::CONSTANT_Double:
        break;
      case enum_cp_tags::CONSTANT_NameAndType:
        break;
      case enum_cp_tags::CONSTANT_Utf8:
        break;
      default:
        break;
      // ler quantidade de bytes informada pela tag e ignorar
    }

  }
  // TODO: le perfeitamente bem o contant pool

  //
  read_us(&cf.access_flags, sizeof(cf.access_flags), f);
}
