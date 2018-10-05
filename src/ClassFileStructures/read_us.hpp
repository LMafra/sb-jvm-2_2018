#include <cstdio>
/// \brief Lê quantidade n de bytes do arquivo f e salva no buffer buf.
void read_us(void* buf, int n , FILE * f) {
  u1* ptr = (u1*)buf;
  for(int i = n-1; i >= 0; i--) {
    fread( &ptr[i], 1, 1, f );
  }
}