#pragma once

#include <cstdio>

/**
 * @brief lê a quantidade n de bytes do arquivo f e salva no buffer buf
 * @param void * buf
 * @param int n
 * @param FILE * f
 */
void read_us(void* buf, int n , FILE * f) {
  u1* ptr = (u1*)buf;
  for(int i = n-1; i >= 0; i--) {
    fread( &ptr[i], 1, 1, f );
  }
}


/**
 * @brief lê a quantidade n de bytes do arquivo f e salva no buffer buf
 * @param void * buf
 * @param int n
 * @param FILE * f
 */
void read_usstring(void* buf, int n , FILE * f) {
  u1* ptr = (u1*)buf;
  for(int i = 0; i <= n-1; i++) {
    fread( &ptr[i], 1, 1, f );
  }
}