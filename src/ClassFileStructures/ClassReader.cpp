#include "ClassFile.hpp"
#include "cp_info.hpp"
#include "cp_info.cpp"
#include "field_info.hpp"
#include <cstring>
#include "../Exibidor.hpp"
unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}
int main() {
  Exibidor exib;
  FILE * f = fopen("double_aritmetica.class", "rb");
  ClassFile cf;
  u1 byte;
  read_us(&cf.magic, sizeof(cf.magic),f);
  if(cf.magic != 0xCAFEBABE){
    printf("Não é um .class válido (Not cafebabe).");
  }
  printf("li :: %x\n", cf.magic);
  read_us(&cf.minor_version, sizeof(cf.minor_version), f);
  read_us(&cf.major_version, sizeof(cf.major_version), f);
  read_us(&cf.constant_pool_count, sizeof(cf.constant_pool_count), f);
  cf.constant_pool = (cp_info*)malloc( cf.constant_pool_count * sizeof( cp_info ) );  // primeiro espaco sempre serah vazio
  for(size_t i = 1; i < cf.constant_pool_count; i++) {
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
  read_us(&cf.this_class, sizeof(cf.this_class), f);
  read_us(&cf.super_class, sizeof(cf.super_class), f);
  read_us(&cf.interfaces_count, sizeof(cf.interfaces_count), f);
  
  //  Implementar leitura do vetor interfaces  //
  u2 lim = cf.interfaces_count;  
  cf.interfaces = (u2*)malloc( lim * sizeof(u2) );
  for(u2 i = 0; i < lim; i++)
    read_us(&cf.interfaces[i], sizeof(u2), f);
  
  read_us(&cf.fields_count, sizeof(cf.fields_count), f);
  lim = cf.fields_count;
  //  Implementar leitura do vetor fields  //
  for(u2 i = 0; i < lim; i++){
    read_us(&cf.fields[i].access_flags, sizeof(cf.fields[i].access_flags), f);
    read_us(&cf.fields[i].name_index, sizeof(cf.fields[i].name_index), f);
    read_us(&cf.fields[i].descriptor_index, sizeof(cf.fields[i].descriptor_index), f);
    read_us(&cf.fields[i].attributes_count, sizeof(cf.fields[i].attributes_count), f);
    // Implementar leitura dos fields
  }

  read_us(&cf.methods_count, sizeof(cf.methods_count), f);

  read_us(&cf.attributes_count, sizeof(cf.attributes_count), f);
  
    printf("Leu cp! E tambem flag de acesso\n");
  fclose(f);

  exib.feed(cf);
  exib.show();
}
