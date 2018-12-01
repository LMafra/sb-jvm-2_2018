
#include "ReaderFiles/ClassLoader.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#include "ViewerFiles/Exibidor.hpp"
#include "interpreter.hpp"
// #include "VMGlobals.hpp"
// #include "Instance/Instance.hpp"
#include <string>

unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}

void setup() {
  static bool flag = false;
  flag = flag ? throw "called setup twice" : true; 
  method_area = (ClassFile**)calloc(100, sizeof(ClassFile*));
}

/// \brief Retorna ponteiro para arquivo .class
/// ou lança excessão caso erro algum ocorra.

int main(int argc, char ** argv ) {
  setup();
  if (argc != 2){
    std::cout << "Voce esqueceu de digitar o nome do arquivo" << std::endl;
    return -1;
  }
  char * arquivo = argv[1];
  printf("file path :: %s\n", arquivo);
  ClassFile * cf;
  try {
    cf = ClassLoader::load_classfile(arquivo);
    cf = ClassLoader::load_classfile(arquivo);
  }catch(const char * e){
    return std::cerr << e << std::endl, -1;
  }
  Exibidor exib(*cf);
  exib.show();
  interpret(cf);
}
