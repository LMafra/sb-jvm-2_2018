#include <stdio.h>
#include <iostream>

struct Array_instance {
  void _outBounds(int i) {
    if( i < 0 || i > siz  ) {
      std::cout << "Index out of bounds" <<std::endl; 
      throw "ArrayIndexOutOfBounds";
    }
  }
  int siz;
  void * data; 
  void* &operator[](int i) {
    this->_outBounds(i);
    int * nd = (int*)data;
    return &nd[i];
  }
};

int main() {
  Array_instance x;
  x.siz = 192;;
  x.data = calloc(1, x.siz);
  x[0] = 123;
}