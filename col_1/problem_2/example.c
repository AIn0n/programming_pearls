#include <stdio.h>
#include <stdint.h>
#include "bit_vector.h"
int
main (void)
{
	uint64_t a[100] = {0};
	printf("%i\n", set_bit(a, 100, 61));
	printf("%u\n", get_bit(a, 100, 61, NULL));	
	return 0;
}