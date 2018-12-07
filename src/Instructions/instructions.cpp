#include "../VMGlobals.hpp"
#include "instructions.hpp"
#include <limits.h>

/// Funcao auxiliar para obter o indice do vaetor de 
/// variáveis locais; demultiplexador na prática
static u2 get_index(Helper _wide) {
  u2 index = 0x0000;
  if(_wide == Helper::NOT_WIDE || _wide == Helper::WIDE) {
    index = instrparam(1); 
    if( _wide ==  Helper::WIDE)
      index = index << 8 | instrparam(2);
  }
  else index = _wide;
  return index;
}

void load_addr(Helper _wide = Helper::NOT_WIDE, cat1 * locais = frame_stack.top().variaveis_locais) {
  u2 index = get_index(_wide);
  void * ref = locais[index].ref_val;
  push_reference(ref);
}
void load_64(Helper _wide = Helper::NOT_WIDE, cat1 * locais = frame_stack.top().variaveis_locais) {
  u2 index = get_index(_wide);
  u8 value = locais[index].val; value = value << 32 | locais[index+1].val;
  push_cat2( value );
}
void load_32(Helper _wide = Helper::NOT_WIDE, cat1 * locais = frame_stack.top().variaveis_locais) {
  u2 index = get_index(_wide);
  u4 value = locais[index].val;
  push_cat1( value );
}



void store_addr(Helper _wide = Helper::NOT_WIDE, cat1 * locais = frame_stack.top().variaveis_locais) {
  u2 index = get_index(_wide);
  void * ref = pop_reference();
  locais[index].ref_val = ref;
}
void store_64(Helper _wide = Helper::NOT_WIDE, cat1 * locais = frame_stack.top().variaveis_locais) {
  Dprintf("EXTREME DEBUG S64\n");
  Dprintf("%d %d, %lli\n",frame_stack.size(),_wide,(int64_t)locais);
  Dprintf("EXTREME DEBUG S64\n");
  u2 index = get_index(_wide);
  Dprintf("EXTREME DEBUG S64\n");
	u4 value1;	u4 value2;
  Dprintf("EXTREME DEBUG S64 %d\n",jvm_stack.size());
	value2 = pop_cat1();
  Dprintf("EXTREME DEBUG S64 %d\n",jvm_stack.size());
  value1 = pop_cat1();
  Dprintf("EXTREME DEBUG S64\n");
  locais[index].val = value1;  locais[index+1].val = value2;
  Dprintf("EXTREME DEBUG S64\n");
}
void store_32(Helper _wide = Helper::NOT_WIDE, cat1 * locais = frame_stack.top().variaveis_locais) {
  u2 index = get_index(_wide);
	u4 value1;
	value1 = pop_cat1();
  locais[index].val = value1;
}

int _f2i(float ff) {
  int result;
	if( isnormal(ff) ) result = (int)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = INT_MAX;
	else result = INT_MIN;
  return result;
}

long _f2l(float ff) {
  long result;
	if( isnormal(ff) ) result = (long)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = LONG_MAX;
	else result = LONG_MIN;
  return result;
}
int _d2i(double ff) {
  int result;
	if( isnormal(ff) ) result = (int)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = INT_MAX;
	else result = INT_MIN;
  return result;
}

long _d2l(double ff) {
  long result;
	if( isnormal(ff) ) result = (long)ff;
	else if (isnan(ff)) result = 0;
	else if( !signbit(ff)) result = LONG_MAX;
	else result = LONG_MIN;
  return result;
}