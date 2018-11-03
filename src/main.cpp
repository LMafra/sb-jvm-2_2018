
#include "ReaderFiles/ClassLoader.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#include "ViewerFiles/Exibidor.hpp"

unsigned int only_ones32(int x) {
  return (unsigned int)(-1) >> (32 - x);
}


int main(int argc, char ** argv ) {
  if (argc != 2){
    std::cout << "Voce esqueceu de digitar o nome do arquivo" << std::endl;
    return 0;
  }
  char * arquivo = argv[1];
  FILE * f = fopen(arquivo, "rb");
  if (!f){
    std::cout << "Arquivo .class não encontrado" << std::endl;
    return 0;
  }
  
  ClassFile cf;
  try {
    ClassLoader::load(f, &cf);
  }catch(const char * e){
    return std::cerr << e << std::endl, -1;
  }
  fclose(f);

  Exibidor exib(cf);
  exib.show();
}
