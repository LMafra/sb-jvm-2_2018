#include <stdint.h>
#include <vector>
#include <iostream>

using namespace std;
using u2 = uint16_t;
using AccessFlag = u2;
#define vec vector
#define IS_U6 typeid(uint16_t)
enum enum_access_flag
{
	ACC_PUBLIC = 0x0001,
	ACC_FINAL = 0x0010,
	ACC_SUPER = 0x0020,
	ACC_INTERFACE = 0x0200,
	ACC_ABSTRACT = 0x0400,
	ACC_SYNTHETIC = 0x2000,
	ACC_ENUM = 0x4000
};

vec<u2> access_flag_values {
	ACC_PUBLIC,
	ACC_FINAL,
	ACC_SUPER,
	ACC_INTERFACE,
	ACC_ABSTRACT,
	ACC_SYNTHETIC,
	ACC_ENUM
};

int main() {
	u2 val = 123;
	cout << typeid(val).name() << endl;
	cout << val << endl;
	cout << enum_access_flag::ACC_ENUM << endl;
	cout << enum_access_flag::ACC_PUBLIC << endl;
	cout << enum_access_flag::ACC_FINAL << endl;
}