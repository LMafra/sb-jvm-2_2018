#include <stack>
#include <stdio.h>
using namespace std;

int t;

class Pt {public:
  void * p;
};

stack<Pt> st;

template <typename T>
void* push(T * t){
  Pt p; p.p = t;
  st.push( p );
}

int main() {
  t = 128;
  Pt p;
  p.p = &t;
  printf("%d\n", *(int*)p.p);
  st.push(p);
  t = 1111;
  Pt pp = st.top();
  printf("%d\n", *(int*)pp.p);
  return 0;
}
