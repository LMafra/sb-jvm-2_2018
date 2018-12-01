#include <iostream>
void printint(int d){printf("%d\n", d);}
void printchar(char d){printf("%d\n", d);}


using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;
u4 a = 0x88888888;
u4 b = 0x33333333;
u8 c = a | b;

using namespace std;
int main() {
	cout << hex << c<< endl;
	c = 0;	c = a;	c = c << 32 | b;
	cout << hex << c<< endl;

}