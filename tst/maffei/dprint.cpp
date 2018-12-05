// #include <functional>
#include <iostream>
#include <stdarg.h>
int foo(int x) {
  return x;
}

void inline _(const char * x, ...){}

#ifdef DEBUG
  #ifndef DEBUG_PRINT
    #define DEBUG_PRINT
    auto Dprintf = printf;
  #endif
#else
  #define Dprintf _
#endif

int main() {
  auto d = foo;
  Dprintf("nada a dizer %d\n", 1, 2, 3); printf("CHUPS CHUPS\n");
  // std:: cout << dprintf()(1) << std::endl;;
}