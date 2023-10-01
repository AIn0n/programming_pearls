#include <stdint.h>
#include <stdlib.h>
#ifndef __BIT_VECTOR_H_
#define __BIT_VECTOR_H_
/*
* set <n> bit in array, assuming that <size> is total size in terms of uint64_t numbers, 
* and <n> index is overall bit index.
* Returns 0 in case of sucess, 1 otherwise.
*/
uint8_t
set_bit(uint64_t* arr, const uint32_t size, const uint32_t n)
{
	/* assume that by stab I mean single uint64_t number */
	const uint32_t stab_idx = n / 64;
	if (stab_idx > size)
		return 1;

	const uint64_t bit = 1LLU << (63 - n % 64);
	arr[stab_idx] |= bit;
	return 0;
}

uint8_t
get_bit(const uint64_t* arr, const uint32_t size, const uint32_t n, uint8_t* err)
{
	const uint32_t stab_idx = n / 64;
	if (stab_idx > size) {
		if (err != NULL)
			*err = 1;
		return 0;
	}
	const uint64_t bit = 1LLU << (63 - n % 64);
	return arr[stab_idx] & bit ? 1 : 0;
}

#endif