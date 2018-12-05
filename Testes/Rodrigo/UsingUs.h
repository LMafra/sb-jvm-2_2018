/// Header contendo as macros para
/// utilização de inteiros com tamanho padronizado.
#pragma once
#include <stdint.h>
#include <stdio.h>
void inline _(const char * x, ...)noexcept{}


#ifdef DEBUG
  #ifndef DDEBUG_PRINT
    #define DDEBUG_PRINT
    auto DDprintf = printf;
  #endif
#else
  #define Dprintf _
#endif


#if DEBUG
  #ifndef DEBUG_PRINT
    #define DEBUG_PRINT
    auto Dprintf = printf;
  #endif
#else
  #define DDprintf _
#endif





typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;