
#include "ReaderFiles/ClassLoader.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#include "ViewerFiles/Exibidor.hpp"
#include "VMGlobals.hpp"
#include <string>

unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}

void setup() {
  static bool flag = false;
  flag = flag ? throw "called setup twice" : true; 
  method_area = (ClassFile*)calloc(100, sizeof(ClassFile));
}

/// \brief Retorna ponteiro para arquivo .class
/// ou lança excessão caso erro algum ocorra.
FILE * open_class_file( const char * arquivo ) {
  FILE * f = fopen(arquivo, "rb");
  if (!f){
    std::cout << "Arquivo .class não encontrado" << std::endl;
    throw "Arquivo .class não encontrado";
  }
  return f;
}

int main(int argc, char ** argv ) {
  setup();
  if (argc != 2){
    std::cout << "Voce esqueceu de digitar o nome do arquivo" << std::endl;
    return -1;
  }
  char * arquivo = argv[1];
  FILE * f = open_class_file( arquivo );
  ClassFile * cf = &method_area[0];
  try {
    ClassLoader::load_classfile(f);
  }catch(const char * e){
    return std::cerr << e << std::endl, -1;
  }
  fclose(f);

  Exibidor exib(*cf);
  exib.show();
}
