#include "ClassFile.cpp"
#include "cp_info.hpp"
#include "read_us.hpp"
#include <cstring>
unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
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
  read_us(&cf.minor_version, sizeof(cf.minor_version), f);
  read_us(&cf.major_version, sizeof(cf.major_version), f);
  read_us(&cf.constant_pool_count, sizeof(cf.constant_pool_count), f);
  cf.constant_pool = (cp_info*)malloc( cf.constant_pool_count * sizeof( cp_info ) );  // primeiro espaco sempre serah vazio
  for(size_t i = 1; i < cf.constant_pool_count; i++) {
    u1 tag;
    read_us(&tag, sizeof(tag), f);
    switch(tag) {
      // case //enum.xons_class : aux=new classinfo; aux.read();aux.tag=tag;break
      case enum_cp_tags :: CONSTANT_Class:
        CONSTANT_Class_info* obj = new CONSTANT_Class_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
        break;
      case enum_cp_tags :: CONSTANT_Fieldref:
        CONSTANT_Fieldref_info* obj = new CONSTANT_Fieldref_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
        break;
      case enum_cp_tags :: CONSTANT_Methodref:CONSTANT_Methodref:_info()

        CONSTANT_Methodref_info* obj = new CONSTANT_Methodref_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_InterfaceMethodref:CONSTANT_InterfaceMethodref:_info()

        CONSTANT_InterfaceMethodref_info* obj = new CONSTANT_InterfaceMethodref_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_String:CONSTANT_String:_info()

        CONSTANT_String_info* obj = new CONSTANT_String_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_Integer:CONSTANT_Integer:_info()

        CONSTANT_Integer_info* obj = new CONSTANT_Integer_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_Float:CONSTANT_Float:_info()

        CONSTANT_Float_info* obj = new CONSTANT_Float_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_Long:CONSTANT_Long:_info()

        CONSTANT_Long_info* obj = new CONSTANT_Long_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_Double:CONSTANT_Double:_info()

        CONSTANT_Double_info* obj = new CONSTANT_Double_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_NameAndType:CONSTANT_NameAndType:_info()

        CONSTANT_NameAndType_info* obj = new CONSTANT_NameAndType_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_Utf8:CONSTANT_Utf8:_info()

        CONSTANT_Utf8_info* obj = new CONSTANT_Utf8_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_MethodHandle:CONSTANT_MethodHandle:_info()

        CONSTANT_MethodHandle_info* obj = new CONSTANT_MethodHandle_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_MethodType:CONSTANT_MethodType:_info()

        CONSTANT_MethodType_info* obj = new CONSTANT_MethodType_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
      case enum_cp_tags :: CONSTANT_InvokeDynamic:CONSTANT_InvokeDynamic:_info()

        CONSTANT_InvokeDynamic_info* obj = new CONSTANT_InvokeDynamic_info();
        obj->read_from_file(f);  (mem( &cf.constant_pool[i], obj , sizeof(obj) ));
      break;
    default:
      // ler quantidade de bytes informada pela tag e ignorar
      break;

    }

  }

  read_us(cf.constant_pool,  (sizeof(cp_info) * cf.constant_pool_count-1) , f);
  read_us(cf.constant_pool,  sizeof() * cf.constant_pool_count-1) , f);
  // TODO: le perfeitamente bem o contant pool

  //
  read_us(&cf.access_flags, 2, 1, f);
  read_us();
  


}
