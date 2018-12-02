/// Header contendo as macros para
/// utilização de inteiros com tamanho padronizado.
#pragma once
#include <cstdint>
#include <stdio.h>

#ifdef DEBUG
  #ifndef DDEBUG_PRINT
    #define DDEBUG_PRINT
    auto DDprintf = printf;
  #endif
#else
  #define Dprintf 
#endif


#if DEBUG
  #ifndef DEBUG_PRINT
    #define DEBUG_PRINT
    auto Dprintf = printf;
  #endif
#else
  #define DDprintf 
#endif





using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;