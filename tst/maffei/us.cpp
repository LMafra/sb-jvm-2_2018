#include <iostream>
#include <stdint.h>

using namespace std;

using u1 = uint8_t;
using u2 = uint16_t;
using u4 = uint32_t;
using u8 = uint64_t;

int main() {
	u8 tst = 0x8888888811111111;
	u4 low = tst;
	u4 high = tst>>32;
	u8 resembled;
	((u4*)&resembled) [0] = low;
	((u4*)&resembled) [1] = high;

	cout << hex << tst << endl;
	cout << "high =>" << hex << high << endl;
	cout << "low  =>" << hex << low << endl;
	cout << hex << resembled << endl;
}