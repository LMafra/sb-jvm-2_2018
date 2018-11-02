/// Header contendo as macros para
/// utilização de inteiros com tamanho padronizado.
#pragma once
#include <cstdint>
#include <vector>
#define vec std::vector
#define IS_U16 typeid(uint16_t)

using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;

extern u1 * PC;
extern u4 * SP;
extern u4 stack[];
extern u4 * frame_pointer;
extern void * method_area;
extern int class_counter;

#include "UsingUs.cpp"