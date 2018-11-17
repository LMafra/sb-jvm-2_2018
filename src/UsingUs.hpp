/// Header contendo as macros para
/// utilização de inteiros com tamanho padronizado.
#pragma once
#ifndef USING_US_HPP
#define USING_US_HPP
#include <cstdint>
#include <vector>
#include <stack>
#define vec std::vector
#define IS_U16 typeid(uint16_t)



using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;

#endif