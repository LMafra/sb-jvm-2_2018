#include <iostream>
#include <cstdio>
using namespace std;

void  (*funcs[10]);
int doisx(int x) {
	return 2*x;
}

int main(){
	funcs[0] = doisx;
	int (*f)(int) = funcs[0];
	printf("%d\n", f(123));
}