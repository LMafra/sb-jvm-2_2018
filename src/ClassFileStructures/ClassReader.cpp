#include "ClassFile.hpp"
#include "cp_info.hpp"
#include "cp_info.cpp"
#include "field_info.hpp"
#include <cstring>
#include "../Exibidor.hpp"
unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}
/*
void load_attribute(FILE *f, ClassFile * cf, attribute_info *atributo)
{
    char *tipoAtributo;
    u4 attribute_length;
    read_us(&atributo.attribute_name_index, sizeof(atributo.attribute_name_index), f);
    read_us(&atributo.attribute_length, sizeof(atributo.attribute_length), f);
    attribute_length = atributo->attribute_length;
    u2 index = atributo->attribute_name_index - 1;
    tipoAtributo = (char *) malloc((cf.constant_pool[index].info.Utf8.length+1) * sizeof(char));
    for (int l = 0; l < cf.constant_pool[index].info.Utf8.length; l++)
        tipoAtributo[l] = cf.constant_pool[index].info.Utf8.bytes[l];
  tipoAtributo[cf.constant_pool[index].info.Utf8.length] = '\0';

    if (!strcmp(tipoAtributo, "ConstantValue"))
    {
        read_us(&atributo.info.ConstantValue.constantvalue_index, sizeof(u2), f);
        atributo->tag = ATTRTAG_Constantvalue;
    }
    else if (!strcmp(tipoAtributo, "Code"))
    {
        u4 code_length;
        read_us(&atributo.info.CodeAttribute.max_stack, sizeof(u2), f);
        read_us(&atributo.info.CodeAttribute.max_locals, sizeof(u2), f);
        read_us(&atributo.info.CodeAttribute.code_length, sizeof(u4), f);
        code_length = atributo->info.CodeAttribute.code_length;
        atributo->info.CodeAttribute.code = (u1 *) malloc(code_length * sizeof(u1));
        for (int i = 0; i < code_length; i++)
        {
            read_us(&atributo.info.CodeAttribute.code[i], sizeof(u1), f);
        }
        u2 exception_table_length;
        read_us(&atributo.info.CodeAttribute.exception_table_length, sizeof(u2), f);
        exception_table_length = atributo->info.CodeAttribute.exception_table_length;
        atributo->info.CodeAttribute.exception_table = (struct et *) malloc(exception_table_length * sizeof(struct et));
        for (int i = 0; i < exception_table_length; i++)
        {
            read_us(&atributo.info.CodeAttribute.exception_table[i].start_pc, sizeof(u2), f);
            read_us(&atributo.info.CodeAttribute.exception_table[i].end_pc, sizeof(u2), f);
            read_us(&atributo.info.CodeAttribute.exception_table[i].handler_pc, sizeof(u2), f);
            read_us(&atributo.info.CodeAttribute.exception_table[i].catch_type, sizeof(u2), f);
        }
        u2 attributes_count;
        read_us(&atributo.info.CodeAttribute.attributes_count, sizeof(u2), f);
        attributes_count = atributo->info.CodeAttribute.attributes_count;
        atributo->info.CodeAttribute.attributes = (attribute_info *) malloc(attributes_count * sizeof(attribute_info));
        for (int k = 0; k < attributes_count; k++)
        {
            load_attribute(f, cf, atributo->info.CodeAttribute.attributes);
        }
        atributo->tag = ATTRTAG_Code;
    }
    else if (!strcmp(tipoAtributo, "Exceptions"))
    {
        u2 number_of_exceptions;
        read_us(&atributo.info.Exception.number_of_exceptions, sizeof(u2), f);
        number_of_exceptions = atributo->info.Exception.number_of_exceptions;
        atributo->info.Exception.exception_index_table = (u2 *) malloc(number_of_exceptions * sizeof(u2));
        for (int i = 0; i < number_of_exceptions; i++)
        {
            read_us(&atributo.info.exception_index_table[i], sizeof(u2), f);
        }
        atributo->tag = ATTRTAG_Exception;
    }
    else if (!strcmp(tipoAtributo, "InnerClasses"))
    {
        u2 number_of_classes;
        read_us(&atributo.info.InnerClasses.number_of_classes, sizeof(u2), f);
        number_of_classes = atributo->info.InnerClasses.number_of_classes;
        atributo->info.InnerClasses.classes = (struct ic *) malloc(number_of_classes * sizeof(struct ic));
        for (int i = 0; i < number_of_classes; i++)
        {
            read_us(&atributo.info.InnerClasses.classes[i].inner_class_info_index, sizeof(u2), f);
            read_us(&atributo.info.InnerClasses.classes[i].outer_class_info_index, sizeof(u2), f);
            read_us(&atributo.info.InnerClasses.classes[i].inner_name_index, sizeof(u2), f);
            read_us(&atributo.info.InnerClasses.classes[i].inner_class_access_flags, sizeof(u2), f);
        }
        atributo->tag = ATTRTAG_Innerclasses;
    }
    else if (!strcmp(tipoAtributo, "SourceFile"))
    {
        read_us(&atributo.info.sourcefile_index, sizeof(u2), f);
        atributo->tag = ATTRTAG_Sourcefile;
    }
    else if (!strcmp(tipoAtributo, "LineNumberTable"))
    {
        read_us(&atributo.info.line_number_table_length, sizeof(u2), f);
        u2 atributo_tamanho = atributo->info.LineNumberTable.line_number_table_length;
        atributo->info.LineNumberTable.line_number_table = (struct lnt *) malloc(atributo_tamanho * sizeof(struct lnt));
        for (int i = 0; i < atributo_tamanho; i++)
        {
            read_us(&atributo.info.LineNumberTable.line_number_table[i].start_pc, sizeof(u2), f);
            read_us(&atributo.info.LineNumberTable.line_number_table[i].line_number, sizeof(u2), f);
        }
        atributo->tag = ATTRTAG_Linenumbertable;
    }
    else if (!strcmp(tipoAtributo, "LocalVariableTable"))
    {
        u2 local_variable_table_length;
        read_us(&atributo.info.LocalVariableTable.local_variable_table_length, sizeof(u2), f);
        local_variable_table_length = atributo->info.LocalVariableTable.local_variable_table_length;
        atributo->info.LocalVariableTable.local_variable_table = (struct lvt *) malloc(
                    local_variable_table_length * sizeof(struct lvt *));
        for (int i = 0; i < local_variable_table_length; i++)
        {
            read_us(&atributo.info.LocalVariableTable.local_variable_table[i].start_pc, sizeof(u2), f);
            read_us(&atributo.info.LocalVariableTable.local_variable_table[i].length, sizeof(u2), f);
            read_us(&atributo.info.LocalVariableTable.local_variable_table[i].name_index, sizeof(u2), f);
            read_us(&atributo.info.LocalVariableTable.local_variable_table[i].descriptor_index, sizeof(u2), f);
            read_us(&atributo.info.LocalVariableTable.local_variable_table[i].index, sizeof(u2), f);
        }
        atributo->tag = ATTRTAG_Localvariabletable;
    }
    else
    {
        atributo->info.Default.data = (u1 *) malloc(attribute_length * sizeof(u1));
        for (int i = 0; i < attribute_length; i++)
        {
            read_us(&atributo.info.Default.data[i], sizeof(u1), f);
        }
        atributo->tag = ATTRTAG_Default;
    }
    free(tipoAtributo); 
}
/**/
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
  cf.fields = (field_info*)malloc( lim * sizeof(field_info) );
  //  Implementar leitura do vetor fields  //
  for(u2 i = 0; i < lim; i++){
    read_us(&cf.fields[i].access_flags, sizeof(cf.fields[i].access_flags), f);
    read_us(&cf.fields[i].name_index, sizeof(cf.fields[i].name_index), f);
    read_us(&cf.fields[i].descriptor_index, sizeof(cf.fields[i].descriptor_index), f);
    read_us(&cf.fields[i].attributes_count, sizeof(cf.fields[i].attributes_count), f);
    u2 lim2 = cf.fields[i].attributes_count;
    cf.fields[i].attributes = (attribute_info*)malloc( lim2 * sizeof(attribute_info) );
    
    for(u2 j = 0; j < lim2; j++){
      //load_attribute(f, cf, &(cf.fields[i].attributes[j]) );
    }
    // Implementar leitura dos fields

  }

  read_us(&cf.methods_count, sizeof(cf.methods_count), f);

  read_us(&cf.attributes_count, sizeof(cf.attributes_count), f);
  
  printf("Leu cp! E tambem flag de acesso\n");
  fclose(f);

  exib.feed(cf);
  exib.show();
}
