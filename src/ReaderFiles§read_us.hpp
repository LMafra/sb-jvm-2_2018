#pragma once
#ifndef READ_US_HPP
#define READ_US_HPP

#include <cstdio>
/// \brief Lê quantidade n de bytes do arquivo f e salva no buffer buf.
void read_us(void* buf, int n , FILE * f);

void read_usstring(void* buf, int n , FILE * f);

#endif