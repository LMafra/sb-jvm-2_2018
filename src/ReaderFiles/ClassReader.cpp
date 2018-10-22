#include "../ClassFileStructures/ClassFile.hpp"
#include "../ClassFileStructures/cp_info.hpp"
#include "../ClassFileStructures/field_info.hpp"
#include "../ClassFileStructures/attribute_info.hpp"
#include "../ClassFileStructures/method_info.hpp"
#include <cstring>
#include "../ViewerFiles/Exibidor.hpp"
#include "read_us.hpp"
unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}

att_name_result attcmp(CONSTANT_Utf8_info & name){
  int size = name.length+1;
  int i;
  char namestring[size];
  for (i=0; i<name.length; i++){
    namestring[i] = (char)name.bytes[i];
  }
  namestring[i]='\0';
  if (std::strcmp(namestring, "ConstantValue")==0){
    return ATT_CONSTANTVALUE;
  }
  if (std::strcmp(namestring, "Code")==0){
    return ATT_CODE;
  }
  if (std::strcmp(namestring, "Deprecated")==0){
    return ATT_DEPRECATED;
  }
  if (std::strcmp(namestring, "Exceptions")==0){
    return ATT_EXCEPTIONS;
  }
  if (std::strcmp(namestring, "InnerClasses")==0){
    return ATT_INNERCLASSES;
  }
  if (std::strcmp(namestring, "SourceFile")==0){
    return ATT_SOURCEFILE;
  }
  if (std::strcmp(namestring, "LineNumberTable")==0){
    return ATT_LINENUMBERTABLE;
  }
  if (std::strcmp(namestring, "LocalVariableTable")==0){
    return ATT_LOCALVARIABLETABLE;
  }
  if (std::strcmp(namestring, "Synthetic")==0){
    return ATT_SYNTHETIC;
  }
  else return ATT_INVALID;
}

void loadconstantpool(FILE *f, ClassFile & cf){
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
}
void load_attribute(FILE *f, ClassFile & cf, attribute_info * & atributos, int n){
  for(size_t i = 0; i < n; i++){
    u2 tag;
    read_us(&tag, sizeof(tag), f);
    int nameswitch = attcmp(*(CONSTANT_Utf8_info *)&cf.constant_pool[tag]);
    switch(nameswitch) {
      case ATT_CONSTANTVALUE:{
        ConstantValue_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_CODE:{
        Code_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        aux.attributes = (attribute_info*)malloc( n * sizeof( attribute_info ) );
        load_attribute(f, cf, aux.attributes, aux.attributes_count);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_DEPRECATED:{
        Deprecated_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_EXCEPTIONS:{
        Exceptions_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_INNERCLASSES:{
        InnerClasses_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_SOURCEFILE:{
        SourceFile_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_LINENUMBERTABLE:{
        LineNumberTable_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      case ATT_LOCALVARIABLETABLE:{
        LocalVariableTable_attribute aux;
        aux.attribute_name_index = tag;
        aux.fill_from(f);
        std::memcpy(&atributos[i], &aux, sizeof(aux));
        }
        break;
      default:
        break;
      // ler quantidade de bytes informada pela tag e ignorar
    }
  }
}


int main(int argc, char ** argv ) {
  Exibidor exib;
  char * arquivo = argv[1];
  if (argc != 2){
    std::cout << "Voce esqueceu de digitar o nome do arquivo" << endl;
    return 0;
  }
  FILE * f = fopen(arquivo, "rb");
  if (!f){
    std::cout << "Arquivo .class não encontrado" << endl;
    return 0;
  }
  ClassFile cf;
  read_us(&cf.magic, sizeof(cf.magic),f);
  if(cf.magic != 0xCAFEBABE){
    printf("Não é um .class válido (Not cafebabe).\n");
    return 0;
  }
  printf("li :: %x\n", cf.magic);
  read_us(&cf.minor_version, sizeof(cf.minor_version), f);
  read_us(&cf.major_version, sizeof(cf.major_version), f);
  read_us(&cf.constant_pool_count, sizeof(cf.constant_pool_count), f);
  loadconstantpool(f,cf);
  // TODO: le perfeitamente bem o contant pool

  //
  read_us(&cf.access_flags, sizeof(cf.access_flags), f);
  read_us(&cf.this_class, sizeof(cf.this_class), f);
  read_us(&cf.super_class, sizeof(cf.super_class), f);
  read_us(&cf.interfaces_count, sizeof(cf.interfaces_count), f);
  
  //  Implementar leitura do vetor interfaces  //
  cf.interfaces = (u2*)malloc( cf.interfaces_count * sizeof(u2) );
  for(int i = 0; i < cf.interfaces_count; i++)
    read_us(&cf.interfaces[i], sizeof(u2), f);
  
  read_us(&cf.fields_count, sizeof(cf.fields_count), f);
  cf.fields = (field_info*)malloc( cf.fields_count * sizeof(field_info) );
  //  Implementar leitura do vetor fields  //
  for(int i = 0; i < cf.fields_count; i++){
    read_us(&cf.fields[i].access_flags, sizeof(cf.fields[i].access_flags), f);
    read_us(&cf.fields[i].name_index, sizeof(cf.fields[i].name_index), f);
    read_us(&cf.fields[i].descriptor_index, sizeof(cf.fields[i].descriptor_index), f);
    read_us(&cf.fields[i].attributes_count, sizeof(cf.fields[i].attributes_count), f);
    cf.fields[i].attributes = (attribute_info*)malloc( cf.fields[i].attributes_count * sizeof( attribute_info ) );
    load_attribute(f, cf, cf.fields[i].attributes, cf.fields[i].attributes_count);
  }

  read_us(&cf.methods_count, sizeof(cf.methods_count), f);
  cf.methods = (method_info*)malloc( cf.methods_count * sizeof(method_info) );
  for(int i = 0; i < cf.methods_count; i++){
    read_us(&cf.methods[i].access_flags, sizeof(cf.methods[i].access_flags), f);
    read_us(&cf.methods[i].name_index, sizeof(cf.methods[i].name_index), f);
    read_us(&cf.methods[i].descriptor_index, sizeof(cf.methods[i].descriptor_index), f);
    read_us(&cf.methods[i].attributes_count, sizeof(cf.methods[i].attributes_count), f);
    cf.methods[i].attributes = (attribute_info*)malloc( cf.methods[i].attributes_count * sizeof( attribute_info ) );
    load_attribute(f, cf, cf.methods[i].attributes, cf.methods[i].attributes_count);
  }

  read_us(&cf.attributes_count, sizeof(cf.attributes_count), f);
  cf.attributes = (attribute_info*)malloc( cf.attributes_count * sizeof( attribute_info ) );
  load_attribute(f, cf, cf.attributes, cf.attributes_count);

  fclose(f);

  exib.feed(cf);
  exib.show();
}
