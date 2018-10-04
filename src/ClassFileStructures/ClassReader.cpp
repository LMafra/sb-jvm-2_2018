#include "ClassFile.hpp"
#include "cp_info.hpp"
#include "CONSTANT_Utf8_info.cpp"
#include "cp_info.cpp"
#include <cstring>
unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
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
  // return 0;
  read_us(&cf.minor_version, sizeof(cf.minor_version), f);
  read_us(&cf.major_version, sizeof(cf.major_version), f);
  read_us(&cf.constant_pool_count, sizeof(cf.constant_pool_count), f);
  cf.constant_pool = (cp_info*)malloc( cf.constant_pool_count * sizeof( cp_info ) );  // primeiro espaco sempre serah vazio
  for(size_t i = 1; i <= cf.constant_pool_count; i++) {
    u1 tag;
    read_us(&tag, sizeof(tag), f);
    switch(tag) {
      // case //enum.xons_class : aux=new classinfo; aux.read();aux.tag=tag;break
      case enum_cp_tags::CONSTANT_Class:{
        CONSTANT_Class_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_Fieldref:{
        CONSTANT_Fieldref_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_Methodref:{
        CONSTANT_Methodref_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_InterfaceMethodref:{
        CONSTANT_InterfaceMethodref_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_String:{
        CONSTANT_String_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_Integer:{
        CONSTANT_Integer_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_Float:{
        CONSTANT_Float_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_Long:{
        CONSTANT_Long_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        i++;
        break;
      case enum_cp_tags::CONSTANT_Double:{
        CONSTANT_Double_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        i++;
        break;
      case enum_cp_tags::CONSTANT_NameAndType:{
        CONSTANT_NameAndType_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      case enum_cp_tags::CONSTANT_Utf8:{
        CONSTANT_Utf8_info aux;
        aux.tag = tag;
        aux.fill_from(f);
        std::memcpy(&cf.constant_pool[i], &aux, sizeof(aux));
        }
        break;
      default:
        break;
      // ler quantidade de bytes informada pela tag e ignorar
    }

  }
  // TODO: le perfeitamente bem o contant pool

  //
  read_us(&cf.access_flags, sizeof(cf.access_flags), f);
  printf("Leu cp! E tambem flag de acesso\n");
  fclose(f);
}
