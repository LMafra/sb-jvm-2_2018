#include <iostream>
#include <stdint.h>

using namespace std;

using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;

int main() {
	u8 tst = 0x8888888811111111;
	u4 x = tst;
	u4 h = tst>>32;
	cout << hex << tst << endl;
	cout << "high =>" << hex << h << endl;
	cout << "low  =>" << hex << x << endl;
}