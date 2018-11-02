#include "UsingUs.hpp"

u1 * PC;
u4 * SP;
u4 stack[0x10000];
u4 * frame_pointer;
void * method_area;
int class_counter;